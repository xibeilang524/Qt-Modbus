#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <inc/config.h>
#include <inc/modbus-private.h>
#include <inc/modbus-tcp-private.h>
#include <inc/modbus-tcp.h>
#include <inc/modbus-version.h>
#include <inc/modbus.h>


#define OCOIL_ADDR_START 0
#define OCOIL_LEN        8
#define INPUT_ADDR_START 0
#define INPUT_LEN        8
#define OREGS_ADDR_START 0
#define OREGS_LEN        8
#define IREGS_ADDR_START 0
#define IREGS_LEN        8

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRIBS_clicked();

    void on_btnRBS_clicked();

    void on_btnRRGS_clicked();

    void on_btnWRGS_clicked();

private:
    Ui::MainWindow *ui;

    modbus_t *ctx;
    modbus_mapping_t *mb_mapping;

};
#endif // MAINWINDOW_H
