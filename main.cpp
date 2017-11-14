#include "mainwindow.h"
#include "toolwindow.h"
#include "debugwindow.h"
#include <QApplication>
#include <QToolBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    ToolWindow t;
    DebugWindow d;

    w.setAttribute(Qt::WA_DeleteOnClose, true);

    QObject::connect(&w, SIGNAL(destroyed()), &a, SLOT(quit()));
    QObject::connect(&t, SIGNAL(FieldChanged(QString,QString)), &w, SLOT(parameterChanged(QString,QString)));
    QObject::connect(&w, SIGNAL(updateToolbox(FlyData)), &t, SLOT(UpdateFields(FlyData)));
    QObject::connect(&w, SIGNAL(sendDebugText(QString)), &d, SLOT(outputText(QString)));

    w.show();
    QPoint position = w.pos();
    position.rx() += 665;
    t.move(position);
    t.show();
    position.rx() -= 1100;
    d.move(position);
    d.show();

    return a.exec();
}
