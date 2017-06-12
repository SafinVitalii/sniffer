#ifndef PACKETTABLE_H
#define PACKETTABLE_H
#include "packetfactory.h"
#include "observer.h"
#include "filter.h"
#include <algorithm>
#include <vector>
class PacketTable
{
 public:
  PacketTable();
  ~PacketTable();
  void AddPacket(Packet* packet);
  void AddFilter(Filter* filter);
  void AttachObserver(Observer* obs);
  void DetachObserver(Observer* obs);
  void NotifyObservers();
  bool NewPacketCorrespondsToFilters(Packet* packet);
  Packet* GetLastPacket();
  Packet* GetPacket(int index);

 private:
  std::vector<Packet*> packets_;
  std::vector<Observer*> observers_;
  std::vector<Filter*> filters_;
};
#endif // ! PACKETTABLE_H
