/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlWindow
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *ControlWindow)
    {
        if (ControlWindow->objectName().isEmpty())
            ControlWindow->setObjectName(QStringLiteral("ControlWindow"));
        ControlWindow->resize(370, 200);
        ControlWindow->setMinimumSize(QSize(370, 200));
        ControlWindow->setMaximumSize(QSize(370, 200));
        centralWidget = new QWidget(ControlWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ControlWindow->setCentralWidget(centralWidget);

        retranslateUi(ControlWindow);

        QMetaObject::connectSlotsByName(ControlWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ControlWindow)
    {
        ControlWindow->setWindowTitle(QApplication::translate("ControlWindow", "Telecamera", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlWindow: public Ui_ControlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
