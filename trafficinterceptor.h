#ifndef TRAFFICINTERCEPTOR_H
#define TRAFFICINTERCEPTOR_H
#include <iostream>
#include <winsock2.h>
#include <nettypes.h>
#include <sys/types.h>
#include <ws2tcpip.h>
#include <QMainWindow>
#include <QDialog>
#include <thread>
#include "packetfactory.h"
#include "protocolheaders.h"
#include "packettable.h"
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)
#define BUF_SIZE 65536

namespace Ui
{
  class TrafficInterceptor;
}

class TrafficInterceptor : public QDialog
{
    Q_OBJECT
 public:
  TrafficInterceptor(PacketTable* table, PacketFactory* factory, QWidget* parent = 0);
  ~TrafficInterceptor();
  int  InitSocket();

 public slots:
  void StartSniffing();
  void PauseSniffing();

 private slots:
  int  BindToConnection();
  void TrackPackets();
  void on_pushButton_clicked(bool);

signals:
  void SetupFinished();

 private:
  PacketTable* packettable_;
  PacketFactory* packetfactory_;
  WSADATA wsadata_;
  int socketid_;
  char buffer[BUF_SIZE];
  struct sockaddr_in address_;
  Ui::TrafficInterceptor* ui_;
  bool tracking_;
};
#endif // ! TRAFFICINTERCEPTOR_H
