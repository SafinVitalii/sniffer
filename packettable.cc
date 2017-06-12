#include "packettable.h"

PacketTable::PacketTable()
{
}

void PacketTable::AddPacket(Packet* packet)
{
  packets_.push_back(packet);
  NotifyObservers();
}

void PacketTable::AttachObserver(Observer* observer)
{
  observers_.push_back(observer);
}

void PacketTable::DetachObserver(Observer* observer)
{
  observers_.erase(std::find(observers_.begin(), observers_.end(), observer));
}

void PacketTable::NotifyObservers()
{
  for (auto It = observers_.cbegin(); It != observers_.cend(); ++It)
  {
    (*It)->Update();
  }
}

void PacketTable::AddFilter(Filter* filter)
{
  filters_.clear();
  std::string filtervalue = filter->GetValue();
  if (std::find(filtervalue.begin(), filtervalue.end(), ';') != filtervalue.end())
  {
    std::istringstream parsestream(filtervalue);
    std::string partofstring;
    while (std::getline(parsestream, partofstring, ';'))
    {
      filters_.push_back(new Filter(partofstring));
    }
  }
  else //one filter (no delimiter ';')
  {
    filters_.push_back(new Filter(filtervalue));
  }
}

bool PacketTable::NewPacketCorrespondsToFilters(Packet* packet)
{
  if (!filters_.size()) { return true; }
  for (auto It = filters_.begin(); It != filters_.end(); ++It)
  {
     if ((*It)->GetValue() == packet->GetProtocol()) { return true; }
     if (strstr(packet->GetSource().c_str(), (*It)->GetValue().c_str())) { return true; }
     if (strstr(packet->GetDestination().c_str(), (*It)->GetValue().c_str())) { return true; }
  }
  return false;
}

Packet* PacketTable::GetPacket(int index)
{
  if (index < 0 || index > packets_.size()) { return nullptr; }
  return packets_.at(index);
}

Packet* PacketTable::GetLastPacket()
{
  return packets_.back();
}

PacketTable::~PacketTable()
{
}
