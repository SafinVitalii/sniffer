#include "packet.h"

Packet::Packet(size_t id) : id_(id)
{
}

void Packet::PrintPacketBriefly(std::ostream& os)
{
  os  << std::setw(6) << id_ << " | "
      << std::left << std::setw(10)<< timetracked_ << " | " << std::right
      << std::setw(16)<< source_ << " | "
      << std::setw(16)<< destination_ << " | "
      << std::setw(6) << length_ ;
}

void Packet::SetInfo(std::string& buffer, time_t timetracked)
{
  IPv4Header* data = (IPv4Header*)buffer.c_str();
  timetracked_ = double(timetracked) / 1000.0;
  struct sockaddr_in source, destination;
  source.sin_addr.s_addr = data->ipsourceaddress;
  destination.sin_addr.s_addr = data->ipdestinationaddress;
  source_ = inet_ntoa(source.sin_addr);
  destination_ = inet_ntoa(destination.sin_addr);
  length_ = ntohs(data->iptotallength);
  data_ = buffer;
}

std::string Packet::GetProtocol()
{
  return "Non-specified";
}

std::string Packet::GetData()
{
  return data_;
}

std::string Packet::GetDestination()
{
  return destination_;
}

std::string Packet::GetSource()
{
  return source_;
}

size_t Packet::GetId()
{
  return id_;
}

size_t Packet::GetLength()
{
  return length_;
}

double Packet::GetTime()
{
  return timetracked_;
}

Packet::~Packet()
{
}
