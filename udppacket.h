#ifndef UDPPACKET_H
#define UDPPACKET_H
#include "packet.h"
class UDPpacket : public Packet
{
 public:
  UDPpacket(size_t id);
  virtual ~UDPpacket();
  virtual void PrintPacketBriefly(std::ostream& os = std::cout);
  virtual void PrintProtocolHeader(QTextEdit* textedit, size_t offset);
  virtual void PrintPacketData(QTextEdit* textedit, size_t offset);
  virtual std::string GetProtocol();
};
#endif // ! UDPPACKET_H

