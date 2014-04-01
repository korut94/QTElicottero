#ifndef SCREENCAMERA_H
#define SCREENCAMERA_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QBuffer>

class ScreenCamera : public QWidget
{
        Q_OBJECT
    public:
        explicit ScreenCamera( QSize & dim, QWidget * parent = 0 );

    private:
        QLabel * screen;

};

#endif // SCREENCAMERA_H
