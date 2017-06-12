#include "packetfactory.h"

PacketFactory::PacketFactory() : currentpacketid_(0)
{
}

TCPpacket* PacketFactory::MakeTCPpacket()
{
  return new TCPpacket(++currentpacketid_);
}

UDPpacket* PacketFactory::MakeUDPpacket()
{
  return new UDPpacket(++currentpacketid_);
}

OtherPacket* PacketFactory::MakeOtherPacket()
{
  return new OtherPacket(++currentpacketid_);
}

PacketFactory::~PacketFactory()
{
}
