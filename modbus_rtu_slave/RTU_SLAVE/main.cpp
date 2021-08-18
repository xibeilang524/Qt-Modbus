#include "slave.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SLAVE w;
    w.show();
    return a.exec();
}
