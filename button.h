#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QLabel>
#include <QDebug>

enum Verso{ frecciaLX, frecciaRX, frecciaTX, frecciaDX  };

class Button : public QWidget
{
    Q_OBJECT

    public:
        explicit Button( QRect & pos, Verso verso, QWidget *parent = 0 );

    private:
        QLabel * button;

        Verso direction;
};

#endif // BUTTON_H
