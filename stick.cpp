#include "stick.h"

Stick::Stick( QRect & geo, QWidget *parent ) :
    QWidget(parent)
{
    //Creo il widget di controllo dell'elicottero
    //Base dello stick
    baseStick = new QLabel();
    //Stick analogico
    joyStick = new QLabel();

    baseStick->setGeometry( geo );
    joyStick->setGeometry( geo );

    //Memorizziamo la posizione originale e la dimensione dello stick analogico.
    //Serve per quando bisogna far tornare lo stick analogico nella posizione originale
    origPosStick = new QPoint( geo.x(), geo.y() );
    sizeStick = new QSize( geo.width(), geo.height() );

    QImage imageBase( "GUIObject/BaseJoy.png" );
    QImage imageJoy( "GUIObject/JoyStick.png" );

    if( imageBase.isNull() && imageJoy.isNull() )
        qDebug() << "Nessuna immagine caricata" << endl;
    else
    {
        baseStick->setPixmap( QPixmap::fromImage( imageBase ) );
        joyStick->setPixmap( QPixmap::fromImage( imageJoy ) );
        qDebug() << "Caricato joystich" << endl;
    }

    //Inserisco il joystick nell'interfaccia
    baseStick->setParent( parent );
    joyStick->setParent( parent );
}

/*===============================================================================*/

void Stick::resetPosStick()
{
    QRect rPos( *origPosStick, *sizeStick );
    joyStick->setGeometry( rPos );
}


/*===============================================================================*/

void Stick::moveStick( QPoint & pos )
{
   //Differenza tra la dimensione della base dello stick e lo stick stesso
    int delta = 30;

    int x = pos.x() - delta;
    int y = pos.y() - delta;
    int width = sizeStick->width();
    int height = sizeStick->height();

    bool limiteX = ( x >= origPosStick->x() - delta && x <= origPosStick->x() + delta );
    bool limiteY = ( y >= origPosStick->y() - delta && y <= origPosStick->y() + delta );

    if( limiteX && limiteY ) joyStick->setGeometry( x, y, width, height );
}
