#include "mainwindow.h"
#include "src/ag_program.c"


unsigned int keys=0;
unsigned int lkeys=0;
FlyData FlyPack;

uint16 memory[640*480];
unsigned short *renderbuffer=(unsigned short *)memory;
QString debug;

void PLOT(unsigned int addr, unsigned short c)
{
    renderbuffer[addr]=c;
}

void PLOT2(unsigned int addr,unsigned short c)
{
  ((unsigned int*)renderbuffer)[addr]=c|c<<16;
}

void PLOT2C(unsigned int addr,unsigned int c)
{
  if(c)((unsigned int*)renderbuffer)[addr]|=c;
}

void PLOT2T(unsigned int addr,unsigned int c)
{
    if(c+1)((unsigned int*)renderbuffer)[addr]&=c;
}

void SendCorrections (uint8 isAngles){
}

void SendCommand(uint8 command) {
    if (!debug.isEmpty())
        debug += QString("\n");
    debug += "Comans received: 0x" + QString::number(command, 16).toUpper();
}

void UpdateTime (void) {

}

void SaveParam(void) {

}

unsigned short GETP (unsigned int addr)
{
  return renderbuffer[addr];
}

void FILL(unsigned short c)
{
  unsigned int num = 640*480/2;
  unsigned int *pDestination = (unsigned int*)renderbuffer;
  while(num--)
     *pDestination++ = c|c<<16;
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Setup Window Params
    this->setFixedSize(640, 480);


    // Create And Setup Main Timer
    paintTimer = new QTimer;
    paintTimer->setInterval(100);
    this->connect(paintTimer, SIGNAL(timeout()), SLOT(repaint()));
    paintTimer->start();

    mainImage = new QImage(640, 480, QImage::Format_RGB16);
    mainImage->fill(0xFFFF);

}

void MainWindow::paintEvent(QPaintEvent *)
{
    //Запускаем программу
    ag_program();

    //Рисуем буфер
    uint16 *line;
    for(int y=0;y<480;y++)
    {
        line=(uint16*)mainImage->scanLine(y);
        for(int x=0; x<640; x++)
        {
            line[x]=memory[x+y*640];
        }
    }

    // Выводим нашу картинку
    QPainter painter(this);
    painter.drawImage(0,0,*mainImage);

    if (!debug.isEmpty())
        emit sendDebugText(debug);
    debug.clear();

}

MainWindow::~MainWindow()
{
    
}

void MainWindow::parameterChanged(QString name, QString text) {

    //TODO: Какая то херовая реализация. Надо переписать по уму

    if (!name.compare(QString("Pitch"))) {
        FlyPack.Pitch = text.toFloat();
    } else if (!name.compare(QString("Roll"))) {
        FlyPack.Roll = text.toFloat();
    } else if (!name.compare(QString("Yaw"))) {
        FlyPack.Yaw = text.toFloat();
    } else if (!name.compare(QString("BarSpeed"))) {
        FlyPack.Barspeed = text.toFloat();
    } else if (!name.compare(QString("Altitude"))) {
        FlyPack.Altitude = text.toFloat();
    } else if (!name.compare(QString("Ball"))) {
        FlyPack.Ball = text.toFloat();
    } else if (!name.compare(QString("RotorRPM"))) {
        FlyPack.rotorRpm = text.toInt();
    } else if (!name.compare(QString("EngineRPM"))) {
        FlyPack.engineRpm = text.toInt();
    } else if (!name.compare(QString("EngineTemp1"))) {
        FlyPack.engineTemp1 = text.toInt();
    } else if (!name.compare(QString("ExhaustTemp1"))) {
        FlyPack.exhaustTemp1 = text.toInt();
    } else if (!name.compare(QString("EngineTemp2"))) {
        FlyPack.engineTemp2 = text.toInt();
    } else if (!name.compare(QString("ExhaustTemp2"))) {
        FlyPack.exhaustTemp2 = text.toInt();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Up) {
        FlyPack.Pitch -= 5;
    } else if (e->key() == Qt::Key_Down) {
        FlyPack.Pitch += 5;
    } else if (e->key() == Qt::Key_Left) {
        FlyPack.Roll -= 5;
    } else if (e->key() == Qt::Key_Right) {
        FlyPack.Roll += 5;
    }

    if (e->key() == Qt::Key_1) {
        keys |= KEY1;
    }

    if (e->key() == Qt::Key_2) {
        keys |= KEY2;
    }

    if (e->key() == Qt::Key_3) {
        keys |= KEY3;
    }

    if (e->key() == Qt::Key_4) {
        keys |= KEY4;
    }

    if (e->key() == Qt::Key_5) {
        keys |= KEY5;
    }

    if (e->key() == Qt::Key_6) {
        keys |= KEY6;
    }

    emit updateToolbox(FlyPack);
}
