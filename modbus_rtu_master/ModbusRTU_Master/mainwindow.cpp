#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mb = modbus_new_rtu("COM4", 38400, 'N', 8, 1);
    modbus_set_slave(mb, 1); //设置modbus从机地址
    modbus_set_response_timeout(mb, 0, 1000000);/* 超时时间1s */

    timer = new QTimer;
    timer->setInterval(300);
    connect(timer, &QTimer::timeout, this, &MainWindow::repeatSend);

    timer->start();
}

MainWindow::~MainWindow()
{
    modbus_close(mb);
    modbus_free(mb);
    delete ui;
}

void MainWindow::repeatSend()
{
    uint16_t tab_reg[15] = {0, 0, 1, 0, 0,0,0,0,0, 0,0,0,0,0,0};
    modbus_write_registers(mb, 360, 15, tab_reg); /* 判断写入的数据长度是不是5个，点对点通信时从站是有返回值的 */
}


void MainWindow::on_btnConnectDevice_clicked()
{
    if(modbus_connect(mb) < 0)
    {
        ui->textEdit->append(QString::fromLocal8Bit("连接失败"));
    }
    else {
        ui->textEdit->append(QString::fromLocal8Bit("连接成功"));
    }
}

void MainWindow::on_btnConfirm_clicked()
{
    byte keyValue = 1 << 5;
    qDebug() << keyValue;
    byte mode = ui->comboBoxMode->currentIndex(); /* 0 1 2 3 */
    qDebug() << mode;
    int plateNum = ui->lineEditNum->text().toUInt();
    qDebug() << plateNum;
    byte cmode = 0;
    switch (mode) {
    case 0: cmode = 1 << 0; break;
    case 1: cmode = 1 << 1; break;
    case 2: cmode = 1 << 2; break;
    case 3: cmode = 1 << 3; break;
    default:cmode = 0;      break;
    }
    qDebug() << cmode;
    uint16_t tab_reg[15] = {plateNum, 0, cmode, keyValue, 0,0,0,0,0, 0,0,0,0,0,0};/* 数组实际为如 101，0，1，32，0 */
    qDebug() << modbus_write_registers(mb, 360, 15, tab_reg); /* 判断写入的数据长度是不是5个，点对点通信时从站是有返回值的 */


   // timer->start();
}

void MainWindow::on_btnCancel_clicked()
{
    uint16_t tab_reg[15] = {0, 0, 0, 16, 0,0,0,0,0, 0,0,0,0,0,0};
    qDebug() <<modbus_write_registers(mb, 360, 15, tab_reg); /* 判断写入的数据长度是不是5个，点对点通信时从站是有返回值的 */

}

void MainWindow::on_btnUp_clicked()
{
    uint16_t tab_reg[15] = {0, 0, 1, 0, 0,0,0,0,0, 0,0,0,0,0,0};
    qDebug() <<modbus_write_registers(mb, 360, 15, tab_reg); /* 判断写入的数据长度是不是5个，点对点通信时从站是有返回值的 */

}

void MainWindow::on_btnDown_clicked()
{

}

void MainWindow::on_btnLeft_clicked()
{

}

void MainWindow::on_btnRight_clicked()
{

}

void MainWindow::on_btnViewPlate_clicked() /* 查看扩展板输入输出状态 */
{
    uint16_t reg[2];
    int rc = modbus_read_registers(mb, 0, 2, reg);

    for(byte i = 0; i < rc; i++){
        ui->textEdit->append(QString::fromLocal8Bit("扩展板0%1").arg(i+1));
        ui->textEdit->append("----------------------------");
        for(byte j = 0; j < 16; j++){
            QString str = QString("%1 : %2").arg(j+1).arg( (reg[rc] >> j) & 0x0001);/* 获取位状态 */
            ui->textEdit->append(str);
        }
    }


}

void MainWindow::on_btnViewPlc_clicked()  /* 查看PLC输入输出点状态 */
{
    uint8_t dest[8] = {0};
    byte rc = modbus_read_input_bits(mb, 0, 8, dest); /* 读输入端 */

    for(byte i = 0; i < rc; i++){

        QString in = QString("IX0.%1 = %2").arg(i).arg(dest[i]);
        ui->textEdit->append(in);
    }

    memset(dest, '\0', sizeof (dest));
    ui->textEdit->append("---------------------------");
    rc = modbus_read_bits(mb, 0, 8, dest);

    for(byte i = 0; i < rc; i++){

        QString in = QString("QX0.%1 = %2").arg(i).arg(dest[i]);
        ui->textEdit->append(in);
    }
    memset(dest, '\0', sizeof (dest));
}











