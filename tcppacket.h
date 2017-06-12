#ifndef TCPPACKET_H
#define TCPPPACKET_H
#include "packet.h"
class TCPpacket : public Packet
{
 public:
  TCPpacket(size_t id);
  virtual ~TCPpacket();
  virtual void PrintPacketBriefly(std::ostream& os = std::cout);
  virtual void PrintProtocolHeader(QTextEdit* textedit, size_t offset);
  virtual void PrintPacketData(QTextEdit* textedit, size_t offset);
  virtual std::string GetProtocol();
};
#endif // ! TCPPACKET_H

