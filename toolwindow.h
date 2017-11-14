#ifndef TOOLWINDOW_H
#define TOOLWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QKeyEvent>
#include "keylineedit.h"
#include "src/type.h"

class ToolWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ToolWindow(QWidget *parent = 0);

private:
    QLabel **labels;
    KeyLineEdit **lineEdits;
    QLabel *textOutput;
    int _numRows;

signals:
    void FieldChanged(QString name, QString value);
    
public slots:
    void EditChanged(QString);
    void UpdateFields(FlyData);
};

#endif // TOOLWINDOW_H
