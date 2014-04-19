#ifndef STICK_H
#define STICK_H

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include "seriale.h"

class Stick : public QWidget
{
    Q_OBJECT

    public:
        explicit Stick( QRect & geo, QWidget * parent = 0 );

    public slots:
        void moveStick( QPoint & pos );
        void resetPosStick();

    private:
        QLabel * baseStick;
        QLabel * joyStick;
        QPoint * origPosStick;
        QSize * sizeStick;
};

#endif // STICK_H
