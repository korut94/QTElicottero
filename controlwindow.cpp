#include "controlwindow.h"
#include "ui_controlwindow.h"

ControlWindow::ControlWindow( QWidget *parent ) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow)
{
    qDebug() << "Finestra creata" << endl;
    ui->setupUi(this);

    seriale = new Seriale();

    /*
    QSize dimScreen( this->geometry().width(), this->geometry().height() );
    camera = new ScreenCamera( dimScreen, ui->centralWidget );
    */
    //Posizione del joystick analogico
    QRect posStick( 20, 120, 60, 60 );
    //Aggiungo lo stick
    joyStick = new Stick( posStick, ui->centralWidget );

    QRect posBtnLeft( 255, 130, 25, 25 );
    QRect posBtnRight( 325, 130, 25, 25 );
    QRect posBtnTop( 290, 95, 25, 25 );
    QRect posBtnDown( 290, 165, 25, 25 );
    //Aggiungo i 4 bottoni per stabilire la quota e la rotazione dell'elicottero
    btnLeft = new Button( posBtnLeft, frecciaLX, seriale, ui->centralWidget );
    btnRight = new Button( posBtnRight, frecciaRX, seriale, ui->centralWidget );
    btnTop = new Button( posBtnTop, frecciaTX, seriale, ui->centralWidget );
    btnDown = new Button( posBtnDown, frecciaDX, seriale, ui->centralWidget );;

    QSerialPort::SerialPortError error = seriale->openSerial( "ttyACM0", 9600 );

    //Connessione con la porta seriale riuscita
    if( /*error == QSerialPort::NoError*/ true )
    {
        //Connettiamo il controllo dello stick analogico alla finestra di comando
        connect( this, SIGNAL( controlHeli( QPoint& ) ), joyStick, SLOT( moveStick( QPoint& ) ) );
        connect( this, SIGNAL( stop() ), joyStick, SLOT( resetPosStick() ) );
        //Connettiamo il controllo dei bottoni alla finestra di comando
        connect( this, SIGNAL( pressButton( QPoint&  ) ), btnLeft, SLOT( press( QPoint& ) ) );
    }

    else qDebug() << error << endl;

    mousePress = false;
}

/*===============================================================================*/

ControlWindow::~ControlWindow()
{
    delete seriale;
    delete ui;
}

/*===============================================================================*/

void ControlWindow::mousePressEvent( QMouseEvent * event )
{
    mousePress = true;

    QPoint posMouse = event->pos();

    emit pressButton( posMouse );
}

/*===============================================================================*/

void ControlWindow::mouseReleaseEvent( QMouseEvent * event )
{
    Q_UNUSED( event );

    mousePress = false;
    emit stop();
}

/*===============================================================================*/

void ControlWindow::mouseMoveEvent( QMouseEvent * event )
{
    //Lancio il segnale non appena il mouse è trascinato
    QPoint posMouse = event->pos();
    if( mousePress ) emit controlHeli( posMouse );
}
