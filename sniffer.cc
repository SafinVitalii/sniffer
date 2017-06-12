#include "snifferfacade.h"
#include "trafficinterceptor.h"
#include "datalogger.h"
#include "statistics.h"
#include <QApplication>
#include <QStackedWidget>
#include <iostream>
#include <thread>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resource);
  QApplication a(argc, argv);
  PacketTable ptable;
  PacketFactory pfactory;
  DataLogger logger(&ptable);
  Statistics stats(&ptable);
  logger.PrepareLogFile();
  ptable.AttachObserver(&logger);
  ptable.AttachObserver(&stats);
  TrafficInterceptor inc(&ptable, &pfactory);
  inc.InitSocket();
  SnifferFacade facade(&logger, &ptable, &inc, &stats);
  ptable.AttachObserver(&facade);
  inc.show();
  QObject::connect(&inc,SIGNAL(SetupFinished()),&facade,SLOT(show()));
  return a.exec();
}
