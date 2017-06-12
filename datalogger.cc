#include "datalogger.h"

DataLogger::DataLogger(PacketTable* table) : packettable_(table), autolog_(true)
{
}

int DataLogger::PrepareLogFile()
{
  logfile_.open("log.txt", std::ios::out | std::ios::app);
  if (logfile_.is_open())
  {
    std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    logfile_ << "\nLog started at " << std::ctime(&time) << '\n';
    return 0;
  }
  else { return -1; }
}

bool DataLogger::IsAutoLogging()
{
  return autolog_;
}

void DataLogger::Update()
{
  Packet* newpacket = packettable_->GetLastPacket();
  newpacket->PrintPacketBriefly(logfile_);
}

DataLogger::~DataLogger()
{
  if(logfile_.is_open()) { logfile_.close(); }
}
