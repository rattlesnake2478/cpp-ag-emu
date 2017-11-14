#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include "src/type.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTimer *paintTimer;
    QImage *mainImage;

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
    void updateToolbox(FlyData);
    void sendDebugText(QString text);

public slots:
    void parameterChanged(QString name, QString text);
};

#endif // MAINWINDOW_H
