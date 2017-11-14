#include "debugwindow.h"
#include <QLabel>
#include <QGridLayout>

DebugWindow::DebugWindow(QWidget *parent) :
    QDialog(parent)
{

    // Set window params
    this->setWindowTitle("Debug Output");
    this->setWindowFlags(Qt::WindowTitleHint | Qt::MSWindowsFixedSizeDialogHint);


    //Show labels and lineEdits
    QGridLayout *layout = new QGridLayout;
    textOutput = new QLabel("Waiting data...");
    textOutput->setFixedHeight(600);
    textOutput->setFixedWidth(400);
    textOutput->setScaledContents(true);
    textOutput->setAlignment(Qt::AlignTop);

    layout->addWidget(textOutput, 0, 0);
    this->setLayout(layout);
}

void DebugWindow::outputText(QString text) {
    QString target = textOutput->text() + QString("\n") + text;
    textOutput->setText(target);
}



