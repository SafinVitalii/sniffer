#ifndef PACKETFACTORY_H
#define PACKETFACTORY_H
#include "otherpacket.h"
#include "tcppacket.h"
#include "udppacket.h"

class PacketFactory
{
 public:
  PacketFactory();
  ~PacketFactory();
  TCPpacket*   MakeTCPpacket();
  UDPpacket*   MakeUDPpacket();
  OtherPacket* MakeOtherPacket();
 private:
  size_t currentpacketid_;
};
#endif // ! PACKETFACORY_H
