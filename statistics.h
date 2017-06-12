#ifndef STATISTICS_H
#define STATISTICS_H
#include "observer.h"
#include "packettable.h"
#include <QMainWindow>
#include <QDialog>

namespace Ui
{
  class Statistics;
}

class Statistics : public QDialog, public Observer
{
    Q_OBJECT
 public:
  explicit Statistics(PacketTable*, QWidget *parent = 0);
  ~Statistics();
  virtual void Update();
 signals:

 public slots:

 private:
  size_t tcppackets_;
  size_t udppackets_;
  size_t otherpackets_;
  Ui::Statistics* ui_;
  PacketTable* packettable_;
};

#endif // ! STATISTICS_H
