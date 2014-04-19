#ifndef CREDITI_H
#define CREDITI_H

#include <QDialog>

namespace Ui {
    class Crediti;
}

class Crediti : public QDialog
{
        Q_OBJECT

    public:
        explicit Crediti(QWidget *parent = 0);
        ~Crediti();

    private:
        Ui::Crediti *ui;
};

#endif // CREDITI_H
