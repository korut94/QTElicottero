#ifndef STICK_H
#define STICK_H

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>

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
<<<<<<< HEAD
=======
        
>>>>>>> 271419a5fb0f03af065de45aa1e9084866b3cd26
        QPoint * origPosStick;
        QSize * sizeStick;
};

#endif // STICK_H
