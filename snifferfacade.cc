#include "snifferfacade.h"
#include "ui_snifferfacade.h"

SnifferFacade::SnifferFacade
    (DataLogger* logger, PacketTable* ptable, TrafficInterceptor* interceptor, Statistics *stats, QWidget *parent)
    : QMainWindow(parent),
      Observer(),
      ui_(new Ui::SnifferFacade),
      logger_(logger),
      packettable_(ptable),
      interceptor_(interceptor),
      statistics_(stats)
{
  ui_->setupUi(this);
  ui_->packetlist->setHorizontalHeaderLabels
    (QStringList{"Id","Time","Source","Destination","Packet length","Protocol"});
  helpinfo_.setText("Help appears here.\n");
  helpinfo_.hide();
}

SnifferFacade::~SnifferFacade()
{
  delete ui_;
}

void SnifferFacade::Update()
{
  Packet* newpacket = packettable_->GetLastPacket();
  AddToTable(newpacket);
}

void SnifferFacade::AddToTable(Packet* packet)
{
  const size_t rowcount = ui_->packetlist->rowCount();
  ui_->packetlist->setRowCount(rowcount + 1);
  ui_->packetlist->setItem(rowcount, 0, new QTableWidgetItem(QString::number(packet->GetId())));
  ui_->packetlist->setItem(rowcount, 1, new QTableWidgetItem(QString::number(packet->GetTime())));
  ui_->packetlist->setItem(rowcount, 2, new QTableWidgetItem(QString::fromStdString(packet->GetSource())));
  ui_->packetlist->setItem(rowcount, 3, new QTableWidgetItem(QString::fromStdString(packet->GetDestination())));
  ui_->packetlist->setItem(rowcount, 4, new QTableWidgetItem(QString::number(packet->GetLength())));
  ui_->packetlist->setItem(rowcount, 5, new QTableWidgetItem(QString::fromStdString(packet->GetProtocol())));
}

void SnifferFacade::AddFilter()
{
  Filter* newfilter = new Filter(std::string(ui_->filtersedit->text().toUtf8().constData()));
  packettable_->AddFilter(newfilter);
  delete newfilter;
}

void SnifferFacade::on_startbutton_clicked(bool)
{
  interceptor_->StartSniffing();
}

void SnifferFacade::on_stopbutton_clicked(bool)
{
  interceptor_->PauseSniffing();
}

void SnifferFacade::on_applyfiltersbutton_clicked(bool)
{
  AddFilter();
}

void SnifferFacade::on_helpbutton_clicked(bool)
{
  helpinfo_.show();
}

void SnifferFacade::on_logbutton_clicked(bool)
{
  system("notepad.exe log.txt");
  //ShellExecute(NULL, LPCWSTR("open"), LPCWSTR("../log.txt"), NULL, NULL, SW_SHOW);
}

void SnifferFacade::on_firstpacketbutton_clicked(bool)
{
  ui_->packetlist->scrollToTop();
}

void SnifferFacade::on_lastpacketbutton_clicked(bool)
{
  ui_->packetlist->scrollToBottom();
}

void SnifferFacade::on_zoominbutton_clicked(bool)
{
  for (size_t i = 0; i < ui_->packetlist->columnCount(); ++i)
  {
    ui_->packetlist->setColumnWidth(i, 1.1 * ui_->packetlist->columnWidth(i));
  }
  QFont font = ui_->packetlist->font();
  font.setPointSizeF(font.pointSize() * 1.1);
  ui_->packetlist->setFont(font);
  for (size_t i = 0; i < ui_->packetlist->rowCount(); ++i)
  {
    ui_->packetlist->setRowHeight(i, 1.1 * ui_->packetlist->rowHeight(i));
  }
}

void SnifferFacade::on_zoomoutbutton_clicked(bool)
{
  for (size_t i = 0; i < ui_->packetlist->columnCount(); ++i)
  {
    ui_->packetlist->setColumnWidth(i, 0.9 * ui_->packetlist->columnWidth(i));
  }
  QFont font = ui_->packetlist->font();
  font.setPointSizeF(font.pointSize() * 0.9);
  ui_->packetlist->setFont(font);
  for (size_t i = 0; i < ui_->packetlist->rowCount(); ++i)
  {
    ui_->packetlist->setRowHeight(i, 0.9 * ui_->packetlist->rowHeight(i));
  }
}

void SnifferFacade::on_packetlist_cellClicked(int row, int column)
{
  Packet* packet = packettable_->GetPacket(row);
  char data[BUF_SIZE];
  strcpy(data, packet->GetData().c_str());
  PrintIpHeader((IPv4Header*)data);
  packet->PrintProtocolHeader(ui_->detailsview, ((IPv4Header*)data)->ipheaderlength * 4);
  packet->PrintPacketData(ui_->detailsview, ((IPv4Header*)data)->ipheaderlength * 4);
}

void SnifferFacade::on_statsbutton_clicked(bool)
{
  statistics_->show();
}

void SnifferFacade::PrintIpHeader(IPv4Header *data)
{
  ui_->detailsview->clear();
  struct sockaddr_in source,destination;
  memset(&source, 0, sizeof(source));
  source.sin_addr.s_addr = data->ipsourceaddress;
  memset(&destination, 0, sizeof(destination));
  destination.sin_addr.s_addr = data->ipdestinationaddress;
  ui_->detailsview->append("-------- IP Header: --------");
  ui_->detailsview->append("IP Version: " + QString::number((size_t)data->ipversion));
  ui_->detailsview->append("IP Header Length: " + QString::number((size_t)data->ipheaderlength) + " bytes");
  ui_->detailsview->append("Type of Service: " + QString::number((size_t)data->iptype));
  ui_->detailsview->append("IP Total Length: " + QString::number(ntohs(data->iptotallength)));
  ui_->detailsview->append("Identification: " + QString::number(ntohs(data->ipid)));
  ui_->detailsview->append("Reserved ZERO field: " + QString::number((size_t)data->ipreservedzero));
  ui_->detailsview->append("Don\'t fragment field: " + QString::number((size_t)data->ipdontfragment));
  ui_->detailsview->append("More fragments: " + QString::number((size_t)data->ipmorefragment));
  ui_->detailsview->append("Time to live: " + QString::number((size_t)data->iptime));
  ui_->detailsview->append("Protocol: " + QString::number((size_t)data->ipprotocol));
  ui_->detailsview->append("Checksum: " + QString::number(ntohs(data->ipchecksum)));
  ui_->detailsview->append("Source IP: " + QString(inet_ntoa(source.sin_addr)));
  ui_->detailsview->append("Destination IP: " + QString(inet_ntoa(destination.sin_addr)));
}
