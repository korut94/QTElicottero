#include "button.h"

Button::Button( QRect & geo, QWidget * parent ) :
    QWidget(parent)
{
    button = new QLabel();
    button->setGeometry( geo );

    button->setStyleSheet( "QLabel{ background-color : red;}" );
    button->setParent( parent );
}
