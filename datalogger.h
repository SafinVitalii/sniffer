#ifndef DATALOGGER_H
#define DATALOGGER_H
#include <fstream>
#include <iostream>
#include <ios>
#include <chrono>
#include <ctime>
#include "observer.h"
#include "packettable.h"
class DataLogger : public Observer
{
 public:
  DataLogger(PacketTable* table);
  ~DataLogger();
  int  PrepareLogFile();
  bool IsAutoLogging();
  virtual void Update();
 private:
  PacketTable* packettable_;
  bool autolog_;
  std::fstream logfile_;
};
#endif // DATALOGGER_H
