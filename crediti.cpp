#include "crediti.h"
#include "ui_crediti.h"

Crediti::Crediti(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Crediti)
{
    ui->setupUi(this);
}

Crediti::~Crediti()
{
    delete ui;
}
