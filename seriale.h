#ifndef SERIALE_H
#define SERIALE_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Seriale
{
    public:
        Seriale();
        QSerialPort::SerialPortError openSerial( QString namePort, int baudRate );
        bool write( const char * str );

    private:
        bool foundPort( QString namePort );

        QSerialPort * serialPort;
        QSerialPortInfo * infoSerialPort;
};

#endif // SERIALE_H
