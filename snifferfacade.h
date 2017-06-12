#ifndef SNIFFERFACADE_H
#define SNIFFERFACADE_H
#include "datalogger.h"
#include "packettable.h"
#include "trafficinterceptor.h"
#include "observer.h"
#include "filter.h"
#include "protocolheaders.h"
#include "statistics.h"
#include <QMainWindow>
#include <QTextEdit>

namespace Ui
{
  class SnifferFacade;
}

class SnifferFacade : public QMainWindow, public Observer
{
   Q_OBJECT
 public:
  SnifferFacade(DataLogger*, PacketTable*, TrafficInterceptor*, Statistics*, QWidget *parent = 0);
  ~SnifferFacade();
  virtual void Update();

 private slots: //buttons or table cell clicked
  void on_startbutton_clicked(bool);
  void on_stopbutton_clicked(bool);
  void on_applyfiltersbutton_clicked(bool);
  void on_helpbutton_clicked(bool);
  void on_packetlist_cellClicked(int row, int column);
  void on_logbutton_clicked(bool);
  void on_firstpacketbutton_clicked(bool);
  void on_lastpacketbutton_clicked(bool);
  void on_zoominbutton_clicked(bool);
  void on_zoomoutbutton_clicked(bool);
  void on_statsbutton_clicked(bool);

private:
  void AddToTable(Packet*);
  void AddFilter();
  void PrintIpHeader(IPv4Header*);
  Ui::SnifferFacade *ui_;
  DataLogger* logger_;
  PacketTable* packettable_;
  TrafficInterceptor* interceptor_;
  Statistics* statistics_;
  QTextEdit helpinfo_;
};

#endif // SNIFFERFACADE_H
