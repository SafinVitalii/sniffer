#ifndef PACKET_H
#define PACKET_H
#include <winsock2.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <QTextEdit>
#include "protocolheaders.h"
#define BUF_SIZE 65536
class Packet
{
 public:
  Packet(size_t id);
  virtual ~Packet();
  virtual void PrintPacketBriefly(std::ostream& os = std::cout);
  virtual void PrintProtocolHeader(QTextEdit* textedit, size_t offset) = 0;
  virtual void PrintPacketData(QTextEdit* textedit, size_t offset) = 0;
  virtual std::string GetProtocol();
  void SetInfo(std::string &buffer, time_t timetracked);
  size_t GetId();
  size_t GetLength();
  double GetTime();
  std::string GetSource();
  std::string GetDestination();
  std::string GetData();

 protected:
  size_t id_;
  double timetracked_;
  std::string source_;
  std::string destination_;
  size_t length_;
  std::string data_;
};
#endif // ! PACKET_H
