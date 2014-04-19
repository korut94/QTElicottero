#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include "stick.h"
#include "button.h"
#include "screencamera.h"
#include "crediti.h"
#include "seriale.h"

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

   public:
        explicit ControlWindow(QWidget *parent = 0);
        ~ControlWindow();

   protected:
        void mousePressEvent( QMouseEvent * event );
        void mouseReleaseEvent( QMouseEvent * event );
        void mouseMoveEvent( QMouseEvent * event );

   signals:
        void controlHeli( QPoint & newPos );
        void leaveButton();
        void pressButton( QPoint & posMouse );
        void stop();

   private:
    Ui::ControlWindow * ui;

    Button * btnLeft;
    Button * btnRight;
    Button * btnTop;
    Button * btnDown;

    ScreenCamera * camera;

    Seriale * seriale;

    Stick * joyStick;

    bool mousePress;
};

#endif // CONTROLWINDOW_H
