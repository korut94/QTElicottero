#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "seriale.h"

enum Verso{ frecciaLX, frecciaRX, frecciaTX, frecciaDX  };

class Button : public QWidget
{
    Q_OBJECT

    public:
        explicit Button( QRect & pos, Verso verso, Seriale * accessPort, QWidget *parent = 0 );

    public slots:
        void press( QPoint & posMouse );
        //void leave();

    private:
        bool mouseIsEnter( QPoint & posMouse );

        QLabel * button;

        Seriale * serial;

        Verso direction;
};

#endif // BUTTON_H
