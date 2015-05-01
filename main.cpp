#include "mainwindow.h"
#include "toolwindow.h"
#include <QApplication>
#include <QToolBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ToolWindow t;

    w.setAttribute(Qt::WA_DeleteOnClose, true);

    QObject::connect(&w, SIGNAL(destroyed()), &a, SLOT(quit()));
    QObject::connect(&t, SIGNAL(FieldChanged(QString,QString)), &w, SLOT(parameterChanged(QString,QString)));
    QObject::connect(&w, SIGNAL(updateToolbox(FlyData)), &t, SLOT(UpdateFields(FlyData)));

    w.show();
    QPoint position = w.pos();
    position.rx() += 665;
    position.ry() += 5;
    t.move(position);
    t.show();

    return a.exec();
}
