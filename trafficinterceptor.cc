#include "trafficinterceptor.h"
#include "ui_trafficinterceptor.h"

TrafficInterceptor::TrafficInterceptor(PacketTable* packettable, PacketFactory* factory, QWidget *parent)
    : QDialog(parent),
      packettable_(packettable),
      packetfactory_(factory),
      ui_(new Ui::TrafficInterceptor),
      tracking_(false)
{
  ui_->setupUi(this);
}

int TrafficInterceptor::InitSocket()
{
  if (WSAStartup(MAKEWORD(1,1), &wsadata_))
  {
    ui_->textEdit->append("WSA failed!\n");
    return -1;
  }
  socketid_ = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
  if (socketid_ == INVALID_SOCKET || wsadata_.iMaxSockets == 0)
  {
    ui_->textEdit->append("Socket creating failed!\n");
    return -1;
  }
  char hostname[100];
  struct in_addr addr;
  if (gethostname(hostname, sizeof(hostname)) == SOCKET_ERROR)
  {
    ui_->textEdit->append("Failed to get local connections\n");
    return -1;
  }
  ui_->textEdit->append("Host name : " + QString(hostname) + '\n');
  struct hostent* localconnections = gethostbyname(hostname);
  if (localconnections == NULL)
  {
    ui_->textEdit->append("\nFailed to initialize local connecctions list\n");
    return -1;
  }
  ui_->textEdit->append("Available Network Connections : \n");

  for (int i = 0; localconnections->h_addr_list[i] != 0; ++i)
  {
    memcpy(&addr, localconnections->h_addr_list[i], sizeof(struct in_addr));
    ui_->textEdit->append("\nNetwork connection #" + QString::number(i) + " Address : " + QString(inet_ntoa(addr)));
    ui_->listWidget->addItem(QString(inet_ntoa(addr)));
  }
  ui_->textEdit->append("Choose the network connection you would like to sniff : ");
  address_.sin_family = AF_INET;
  address_.sin_port = 0;
  return 0;
}

int TrafficInterceptor::BindToConnection()
{
  int choice = ui_->listWidget->currentRow();
  if (choice < 0)
  {
    ui_->textEdit->append("\nPlease, select the connection first!");
    return -1;
  }
  char hostname[100];
  gethostname(hostname, sizeof(hostname));
  struct hostent* localconnections = gethostbyname(hostname);
  memcpy(&address_.sin_addr.s_addr, localconnections->h_addr_list[choice], sizeof(address_.sin_addr.s_addr));
  if (bind(socketid_, (struct sockaddr *)&address_, sizeof(address_)) == SOCKET_ERROR)
  {
    ui_->textEdit->append("\nFailed to bind socket!");
    return -1;
  }
  int magic = 1;
  if (WSAIoctl(socketid_, SIO_RCVALL, &magic, sizeof(magic), 0, 0, (LPDWORD)&choice, 0, 0) == SOCKET_ERROR)
  {
    ui_->textEdit->append("\nError calling WSAIoctl() occured!");
    return -1;
  }
  ui_->textEdit->append("\nCompleted!");
  hide();
  emit SetupFinished();
  return 0;
}
void TrafficInterceptor::TrackPackets()
{
  int bytesread = 0;
  static time_t startedtracking = clock(), currentpackettime;
  while (tracking_)
  {
    bytesread = recvfrom(socketid_, buffer, BUF_SIZE, 0, 0, 0);
    if (bytesread > 0 && tracking_)
    {
      IPv4Header* data = (IPv4Header*)buffer;
      Packet* newpacket;
      switch (data->ipprotocol)
      {
        case 6:  newpacket = packetfactory_->MakeTCPpacket();break;
        case 17: newpacket = packetfactory_->MakeUDPpacket();break;
        default: newpacket = packetfactory_->MakeOtherPacket();break;
      }
      currentpackettime = clock() - startedtracking;
      std::string strbuffer(buffer, bytesread);
      newpacket->SetInfo(strbuffer, currentpackettime); // in milliseconds
      if (packettable_->NewPacketCorrespondsToFilters(newpacket)) { packettable_->AddPacket(newpacket); }
      else { delete newpacket; }
    }
  }
}

void TrafficInterceptor::StartSniffing()
{
  tracking_ = true;
  std::thread tracking(&TrafficInterceptor::TrackPackets,this);
  tracking.detach();
}

void TrafficInterceptor::PauseSniffing()
{
  tracking_ = false;
}

void TrafficInterceptor::on_pushButton_clicked(bool)
{
  BindToConnection();
}

TrafficInterceptor::~TrafficInterceptor()
{
  WSACleanup();
  closesocket(socketid_);
  delete ui_;
}
