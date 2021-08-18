#include "slave.h"
#include "ui_slave.h"

SLAVE::SLAVE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SLAVE)
{
    ui->setupUi(this);
}

SLAVE::~SLAVE()
{
    delete ui;
}

