#include "button.h"

Button::Button( QRect & geo, Verso verso, QWidget * parent ) :
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
}
