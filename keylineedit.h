#ifndef KEYLINEEDIT_H
#define KEYLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

class KeyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit KeyLineEdit(QWidget *parent = 0);

private:
    bool shiftPressed;
    bool controlPressed;
    bool altPressed;

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

signals:
    
public slots:
    
};

#endif // KEYLINEEDIT_H
