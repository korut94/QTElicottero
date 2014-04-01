#include "screencamera.h"

ScreenCamera::ScreenCamera( QSize & dim, QWidget * parent ) :
    QWidget(parent)
{
    screen = new QLabel( parent );
    screen->setGeometry( 0, 0, dim.width(), dim.height() );

    QImage background( "GUIObject/gatti_69.jpg", "JPG" );

    if( background.isNull() ) qDebug() << "Errore immagine" << endl;
    else
    {
        QFile file( "Gattino" );
        if( file.open( QIODevice::WriteOnly ) )
        {
            uchar * pixelCat = background.bits();

            //Tento di creare un'immagine da un array di byte
            QByteArray arrayByteCat;
            QBuffer buffer( &arrayByteCat );
            buffer.open( QIODevice::ReadWrite );

            QDataStream out( &buffer );

            out << pixelCat;

            QPixmap imgBackground;

            if( imgBackground.loadFromData( arrayByteCat, "JPG" ) )
                screen->setPixmap( imgBackground );

            else qDebug() << "Errore realizzazione sfondo" << endl;
        }
    }
}
