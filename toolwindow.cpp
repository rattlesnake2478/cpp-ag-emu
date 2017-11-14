#include "toolwindow.h"
#include <QLabel>
#include <QGridLayout>

ToolWindow::ToolWindow(QWidget *parent) :
    QDialog(parent)
{
    const QString labelNames[] = {"Pitch", "Roll", "Yaw", "BarSpeed", "Altitude", "Ball", "RotorRPM", "EngineRPM", "EngineTemp1", "ExhaustTemp1", "EngineTemp2", "ExhaustTemp2"};
    _numRows = sizeof(labelNames) / sizeof(QString);

    // Set window params
    this->setWindowTitle("Information");
    this->setWindowFlags(Qt::WindowTitleHint | Qt::MSWindowsFixedSizeDialogHint);

    //Create labels and lineEdits
    labels = new QLabel *[_numRows];
    lineEdits = new KeyLineEdit *[_numRows];

    //Show labels and lineEdits
    QGridLayout *layout = new QGridLayout;
    for (int row = 0; row < _numRows; row++) {
        QString name = labelNames[row];
        labels[row] = new QLabel(name);
        lineEdits[row] = new KeyLineEdit();
        lineEdits[row]->setObjectName(name);
        this->connect(lineEdits[row], SIGNAL(textChanged(QString)), SLOT(EditChanged(QString)));
        layout->addWidget(labels[row], row, 0);
        layout->addWidget(lineEdits[row], row, 1);
    }

    this->setLayout(layout);
}

void ToolWindow::EditChanged(QString text) {
    QObject *sender = QObject::sender();
    emit FieldChanged(sender->objectName(), text);
}

void ToolWindow::UpdateFields(FlyData Params) {
    // TODO: Опять корявая реализация. Переделать к чертовой матери
    for (int row = 0; row < _numRows; row++) {
        if (!lineEdits[row]->objectName().compare(QString("Pitch"))) {
            lineEdits[row]->setText(QString::number(Params.Pitch));
        }
        if (!lineEdits[row]->objectName().compare(QString("Roll"))) {
            lineEdits[row]->setText(QString::number(Params.Roll));
        }
    }
}

