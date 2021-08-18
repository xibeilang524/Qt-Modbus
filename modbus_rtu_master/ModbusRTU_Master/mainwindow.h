#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include "config.h"
#include "modbus.h"
#include "modbus-rtu.h"
#include "modbus-private.h"
#include "modbus-rtu-private.h"





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

#define max_dy 2

//    QStringList faultCode;

//    QString decTobin(QString strDec);

private slots:

    void repeatSend();

//    void on_btnConnectDevice_clicked();

//    void on_btnReadMoreReg_clicked();

//    void on_btnReadSingleReg_clicked();

//    void on_btnWriteSingleReg_clicked();

//    void on_btnWriteMoreReg_clicked();

//    void on_btnCloseDevice_clicked();

//    void on_btnReadCoil_clicked();

//    void on_btnWriteCoil_clicked();

//    void on_pushButton_01_clicked();

//    void on_pushButton_02_clicked();

//    void on_pushButton_03_clicked();

//    void on_pushButton_04_clicked();

//    void on_pushButton_05_clicked();

//    void on_pushButton_06_clicked();

//    void on_pushButton_0f_clicked();

//    void on_pushButton_10_clicked();

//    void on_btnKeyConfirm_clicked();

    void on_btnConnectDevice_clicked();

    void on_btnConfirm_clicked();

    void on_btnCancel_clicked();

    void on_btnUp_clicked();

    void on_btnDown_clicked();

    void on_btnLeft_clicked();

    void on_btnRight_clicked();

    void on_btnViewPlate_clicked();

    void on_btnViewPlc_clicked();

private:
    Ui::MainWindow *ui;

    modbus_t *mb;
    QTimer *timer;

};
#endif // MAINWINDOW_H
