#include "keylineedit.h"

KeyLineEdit::KeyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    shiftPressed = false;
    this->setText(QString("0"));
}

void KeyLineEdit::keyPressEvent(QKeyEvent *e) {
     float value = this->text().toFloat();

     float step = 1;
     if (shiftPressed) {
         step = 0.1;
     } else if (controlPressed) {
         step = 10;
     }

     if (e->key() == Qt::Key_Up) {
         value += step;
     }
     if (e->key() == Qt::Key_Down) {
         value -= step;
     }

     if (e->key() == Qt::Key_Shift) {
         shiftPressed = true;
     }

     if (e->key() == Qt::Key_Control) {
         controlPressed = true;
     }

     this->setText(QString::number(value));
}


void KeyLineEdit::keyReleaseEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Shift) {
        shiftPressed = false;
    }

    if (e->key() == Qt::Key_Control) {
        controlPressed = false;
    }
}
