#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QLabel>

class Button : public QWidget
{
    Q_OBJECT

    public:
        explicit Button( QRect & pos, QWidget *parent = 0 );

    signals:

    public slots:

    private:
        QLabel * button;
};

#endif // BUTTON_H
