#include "otherpacket.h"

OtherPacket::OtherPacket(size_t id) : Packet(id)
{
}

void OtherPacket::PrintPacketBriefly(std::ostream& os)
{
  Packet::PrintPacketBriefly(os);
  os << " | Other \n";
}

std::string OtherPacket::GetProtocol()
{
  return "Other";
}

void OtherPacket::PrintProtocolHeader(QTextEdit* textedit, size_t offset)
{
  textedit->append("\n-------- Other packet --------");
  textedit->append("No header representation available");
}

void OtherPacket::PrintPacketData(QTextEdit *textedit, size_t offset)
{
  textedit->append("\n-------- DATA --------");
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

OtherPacket::~OtherPacket()
{
}
