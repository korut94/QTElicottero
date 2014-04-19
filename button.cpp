#include "button.h"

Button::Button( QRect & geo, Verso verso, Seriale * accessPort, QWidget * parent ) :
    QWidget(parent)
{
    button = new QLabel( parent );
    button->setGeometry( geo );

    direction = verso;

    QString dirPic = "GUIObject/";

    switch( direction )
    {
        case frecciaLX: dirPic += "frecciaLX";
                        break;
        case frecciaRX: dirPic += "frecciaRX";
                        break;
        case frecciaTX: dirPic += "frecciaTX";
                        break;
        case frecciaDX: dirPic += "frecciaDX";
                        break;
    }

    QImage imgBtnSX( dirPic );

    if( imgBtnSX.isNull() ) qDebug() << "Errore caricamento immagine" << endl;
    else button->setPixmap( QPixmap::fromImage( imgBtnSX ) );

    //La seriale che uso sarà quella dichiarata nel controlwindow
    serial = accessPort;
}

/*===============================================================================*/

bool Button::mouseIsEnter( QPoint & posMouse )
{
    QRect misura = button->geometry();

    bool limiteX = ( posMouse.x() >= misura.x() && posMouse.x() <= misura.x() + misura.width() );
    bool limiteY = ( posMouse.y() >= misura.y() && posMouse.y() <= misura.y() + misura.height() );

    return ( limiteX && limiteY );
}

/*===============================================================================*/

void Button::press( QPoint & posMouse )
{
    if( mouseIsEnter( posMouse ) )
    {
        serial->write( "1" );
    }
}
