#include "seriale.h"

Seriale::Seriale()
{
    serialPort = new QSerialPort();
    infoSerialPort = new QSerialPortInfo();
}

/*===============================================================================*/

bool Seriale::foundPort( QString namePort )
{
    QList<QSerialPortInfo> listPorts( QSerialPortInfo::availablePorts() );

    bool found = false;

    //Ricerca della porta seriale richiesta
    for( int i = 0; i < listPorts.count() && !found; i++ )
    {
        if( listPorts[i].portName() == namePort )
        {
            *infoSerialPort = listPorts[i];
            found = true;
        }
    }

    if( found )
    {
        serialPort->setPort( *infoSerialPort );
        return true;
    }

    else return false;
}

/*===============================================================================*/

QSerialPort::SerialPortError Seriale::openSerial( QString namePort, int baudRate )
{
    //Porta seriale trovata
    if( foundPort( namePort ) )
    {
        if( serialPort->open( QIODevice::ReadWrite ) )
        {
            //Setta la porta seriale
            if ( serialPort->setBaudRate( baudRate )
                  && serialPort->setDataBits( QSerialPort::Data8 )
                  && serialPort->setParity( QSerialPort::NoParity )
                  && serialPort->setStopBits( QSerialPort::OneStop )
                  && serialPort->setFlowControl( QSerialPort::HardwareControl ) )
             return QSerialPort::NoError;

            else return serialPort->error();
        }

        else
        {
            serialPort->close();
            return serialPort->error();
        }
    }

    else return serialPort->error();
}

/*===============================================================================*/

bool Seriale::write( const char * str )
{
    if( serialPort->write( str ) != -1 ) return true;
    else return false;
}
