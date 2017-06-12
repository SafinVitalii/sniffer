#ifndef OTHERPACKET_H
#define OTHERPACKET_H
#include "packet.h"
class OtherPacket : public Packet
{
 public:
  OtherPacket(size_t id);
  virtual ~OtherPacket();
  virtual void PrintPacketBriefly(std::ostream& os = std::cout);
  virtual void PrintProtocolHeader(QTextEdit* textedit, size_t offset);
  virtual void PrintPacketData(QTextEdit* textedit, size_t offset);
  virtual std::string GetProtocol();
};
#endif // OTHERPACKET_H
