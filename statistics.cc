#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(PacketTable *ptable, QWidget *parent)
    : QDialog(parent),
      Observer(),
      ui_(new Ui::Statistics),
      packettable_(ptable)
{
  ui_->setupUi(this);
}

void Statistics::Update()
{

}

Statistics::~Statistics()
{
  delete ui_;
}
