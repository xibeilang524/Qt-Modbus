#ifndef SLAVE_H
#define SLAVE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SLAVE; }
QT_END_NAMESPACE

class SLAVE : public QMainWindow
{
    Q_OBJECT

public:
    SLAVE(QWidget *parent = nullptr);
    ~SLAVE();

private:
    Ui::SLAVE *ui;
};
#endif // SLAVE_H
