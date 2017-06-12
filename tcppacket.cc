#include "tcppacket.h"

TCPpacket::TCPpacket(size_t id) : Packet(id)
{
}

void TCPpacket::PrintPacketBriefly(std::ostream& os)
{
  Packet::PrintPacketBriefly(os);
  os << " | TCP \n";
}

std::string TCPpacket::GetProtocol()
{
  return "TCP";
}

void TCPpacket::PrintProtocolHeader(QTextEdit* textedit, size_t offset)
{
  textedit->append("\n-------- TCP packet --------");
  const char* tcpdata = data_.c_str() + offset;
  TCPHeader* header = (TCPHeader*)tcpdata;
  textedit->append("Source port : " + QString::number(ntohs(header->sourceport)));
  textedit->append("Destination port: " + QString::number(ntohs(header->destinationport)));
  textedit->append("Sequence number: " + QString::number(ntohs(header->sequence)));
  textedit->append("Acknowledge number: " + QString::number(ntohs(header->acknowledge)));
  textedit->append("Header length: " + QString::number((size_t)header->dataoffset*4) + " bytes");
  textedit->append("CWR Flag: " + QString::number((size_t)header->cwr));
  textedit->append("ECN Flag: " + QString::number((size_t)header->ecnecho));
  textedit->append("Urgent Flag: " + QString::number((size_t)header->urgent));
  textedit->append("Acknowledgement Flag: " + QString::number((size_t)header->acknowledgement));
  textedit->append("Push Flag: " + QString::number((size_t)header->push));
  textedit->append("Reset Flag: " + QString::number((size_t)header->reset));
  textedit->append("Synchronise Flag: " + QString::number((size_t)header->sync));
  textedit->append("Finish Flag: " + QString::number((size_t)header->finish));
  textedit->append("Window: " + QString::number(ntohs(header->window)));
  textedit->append("Checksum: " + QString::number(ntohs(header->checksum)));
  textedit->append("Urgent Pointer: " + QString::number(header->urgentppointer));
}

void TCPpacket::PrintPacketData(QTextEdit* textedit, size_t offset)
{
  textedit->append("\n-------- DATA --------");
  offset+=sizeof(TCPHeader);
  const char* data = data_.c_str() + offset;
  uchar a, c; //service
  size_t len = strlen(data);
  std::stringstream hexstream, charstream;
  for(size_t i = 0; i < len; ++i)
  {
    c = data[i];
    hexstream << std::hex << (uchar)data[i];
    a = ( data[i] >=32 && data[i] <=128) ? (uchar) data[i] : '.';
    charstream << a;
    if ((i!=0 && (i+1)%16==0) || i == data_.size() - 1)
    {
      QString oneline = QString::fromStdString(hexstream.str())
                        + "          "
                        + QString::fromStdString(charstream.str());
      textedit->append(oneline);
      hexstream.str("");
      charstream.str("");
    }
  }
}

TCPpacket::~TCPpacket()
{
}
