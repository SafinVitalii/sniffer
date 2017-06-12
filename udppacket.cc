#include "udppacket.h"

UDPpacket::UDPpacket(size_t id) : Packet(id)
{
}

void UDPpacket::PrintPacketBriefly(std::ostream& os)
{
  Packet::PrintPacketBriefly(os);
  os << " | UDP \n";
}

std::string UDPpacket::GetProtocol()
{
  return "UDP";
}

void UDPpacket::PrintProtocolHeader(QTextEdit* textedit, size_t offset)
{
  textedit->append("\n-------- UDP packet --------");
  const char* udpdata = data_.c_str() + offset;
  UDPHeader* header = (UDPHeader*)udpdata;
  textedit->append("Source port:" + QString::number(ntohs(header->sourceport)));
  textedit->append("Destination port: " + QString::number(ntohs(header->destinationport)));
  textedit->append("UDP Length: " + QString::number(ntohs(header->udppacketlength)));
  textedit->append("Checksum: " + QString::number(ntohs(header->udpchecksum)));
}

void UDPpacket::PrintPacketData(QTextEdit *textedit, size_t offset)
{
  textedit->append("\n-------- DATA --------");
  offset+=sizeof(UDPHeader);
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

UDPpacket::~UDPpacket()
{
}
