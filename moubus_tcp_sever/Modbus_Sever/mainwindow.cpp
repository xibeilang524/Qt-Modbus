#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ctx = modbus_new_tcp("192.168.1.1", 502);
//    modbus_set_debug(ctx, TRUE);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n",
        modbus_strerror(errno));
        modbus_free(ctx);
        exit(0);
    }
/* 客户端 服务端 */

//    mb_mapping = modbus_mapping_new_start_address(OCOIL_ADDR_START,
//                                                                    OCOIL_LEN,
//                                                                    INPUT_ADDR_START,
//                                                                    INPUT_LEN,
//                                                                    OREGS_ADDR_START,
//                                                                    OREGS_LEN,
//                                                                    IREGS_ADDR_START,
//                                                                    IREGS_LEN);



//    if(mb_mapping == NULL) {
//        qDebug() << QString("Failed to allocate the mapping: %1\n.").arg(modbus_strerror(errno));
//        modbus_free(ctx);
//        exit(0);
//    }

//    int socket = modbus_tcp_listen(ctx, 1);
//    if(socket == (-1)) {
//        qDebug() << QString("Failed to established listen: %1\n.").arg(modbus_strerror(errno));
//        modbus_free(ctx);
//        exit(0);
//    }

//    if(modbus_tcp_accept(ctx, &socket) == (-1)) {
//        qDebug() << QString("Failed to accept listen: %1\n.").arg(modbus_strerror(errno));
//        modbus_free(ctx);
//        exit(0);
//    }

    qDebug() << "init success";

//    for (;;) {
//        uint8_t query[MODBUS_TCP_MAX_ADU_LENGTH];
//        int rc = modbus_receive(ctx, query);
//        if(rc > 0) {
//            modbus_reply(ctx, query, rc, mb_mapping);
//        } else if(rc == -1) {
//            break;
//        }

//    }



//    if(socket != -1)





}

MainWindow::~MainWindow()
{
    qDebug() << QString("Quit the loop: %1\n").arg(modbus_strerror(errno));
    modbus_mapping_free(mb_mapping);
    modbus_close(ctx);
    modbus_free(ctx);

    exit(0);
    delete ui;
}


void MainWindow::on_btnRIBS_clicked()
{

}

/* modbus_read_bits */
void MainWindow::on_btnRBS_clicked()
{

}

/* modbus_read_registers */
void MainWindow::on_btnRRGS_clicked()
{
    uint16_t *tab_rq_registers;
    tab_rq_registers = (uint16_t *) malloc(OREGS_LEN * sizeof(uint16_t));
    memset(tab_rq_registers, 0, OREGS_LEN * sizeof(uint16_t));

    tab_rq_registers[0] = 10;
    tab_rq_registers[1] = 11;
    tab_rq_registers[2] = 12;
    tab_rq_registers[3] = 13;
    tab_rq_registers[4] = 14;
    tab_rq_registers[5] = 15;
    tab_rq_registers[6] = 16;

    int rc = modbus_write_registers(ctx, OREGS_ADDR_START, OREGS_LEN, tab_rq_registers);
    if(rc > 0) qDebug() << "write success";
    else qDebug() << "failed write.";
    free(tab_rq_registers);

}
/* modbus_write_registers */
void MainWindow::on_btnWRGS_clicked()
{

}
