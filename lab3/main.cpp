#include "mainwidget.h"
#include <QApplication>
#include <QDateTime>
#include "dataworker.h"

QDebug operator<< (QDebug d,Message &message)
{
    d.nospace()<<message.l1<<message.l2;
    return d;
}

int main(int argc, char *argv[])
{

    qRegisterMetaType< QList<QDateTime> >("QList<QDateTime>");
    qRegisterMetaType< Message >("Message");

    //Message l;
    //qDebug()<<l;

    QApplication a(argc, argv);
    mainWidget w;
    w.show();

    return a.exec();
}
