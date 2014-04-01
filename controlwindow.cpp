#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow( QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow)
{
    qDebug() << "Finestra creata" << endl;
    ui->setupUi(this);

    QSize dimScreen( this->geometry().width(), this->geometry().height() );
    camera = new ScreenCamera( dimScreen, ui->centralWidget );

    //Posizione del joystick analogico
    QRect posStick( 20, 120, 60, 60 );
    //Aggiungo lo stick
    joyStick = new Stick( posStick, ui->centralWidget );

    QRect posBtnLeft( 255, 130, 25, 25 );
    QRect posBtnRight( 325, 130, 25, 25 );
    QRect posBtnTop( 290, 95, 25, 25 );
    QRect posBtnDown( 290, 165, 25, 25 );
    //Aggiungo i 4 bottoni per stabilire la quota e la rotazione dell'elicottero
    btnLeft = new Button( posBtnLeft, frecciaLX, ui->centralWidget );
    btnRight = new Button( posBtnRight, frecciaRX, ui->centralWidget );
    btnTop = new Button( posBtnTop, frecciaTX, ui->centralWidget );
    btnDown = new Button( posBtnDown, frecciaDX, ui->centralWidget );;

    //Connettiamo il controllo dello stick analogico alla finestra di comando
    connect( this, SIGNAL( controlHeli( QPoint& ) ), joyStick, SLOT( moveStick( QPoint& ) ) );
    connect( this, SIGNAL( stop() ), joyStick, SLOT( resetPosStick() ) );

    mouseDrag = false;
}

/*===============================================================================*/

ControlWindow::~ControlWindow()
{
    delete ui;
}

/*===============================================================================*/

void ControlWindow::mousePressEvent( QMouseEvent * event )
{
    mouseDrag = true;
}

/*===============================================================================*/

void ControlWindow::mouseReleaseEvent( QMouseEvent * event )
{
    mouseDrag = false;
    emit stop();
}

/*===============================================================================*/

void ControlWindow::mouseMoveEvent( QMouseEvent * event )
{
    //Lancio il segnale non appena il mouse è trascinato
    QPoint posMouse = event->pos();
    if( mouseDrag ) emit controlHeli( posMouse );
}
