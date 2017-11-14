#ifndef DEBUGWINDOW
#define DEBUGWINDOW

#include <QDialog>
#include <QLabel>

class DebugWindow : public QDialog
{
    Q_OBJECT
public:
    explicit DebugWindow(QWidget *parent = 0);

private:
    QLabel *textOutput;

public slots:
    void outputText(QString text);
};

#endif // DEBUGWINDOW

