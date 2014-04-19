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
        uchar * pCharByteImg = background.bits();

        QFile out( "ImgByte" );
        QFile in( "ImgByte" );

        if( out.open( QIODevice::WriteOnly ) && in.open( QIODevice::ReadOnly ) )
        {
            QDataStream outFile( &out );

            //Carico i byte dell'immagine nel file ImgByte per simulare la seriale
            for( int i = 0; i < background.bytesPerLine(); i++ )
                outFile << *( pCharByteImg + i );

            QDataStream inFile( &in );

            QByteArray  bufferImg;

            inFile >> bufferImg;

            qDebug() << bufferImg[0] << endl;
        }
    }
}
