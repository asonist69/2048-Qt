/********************************************************************************
** Form generated from reading UI file 'field4.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELD4_H
#define UI_FIELD4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_field4
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *field4)
    {
        if (field4->objectName().isEmpty())
            field4->setObjectName("field4");
        field4->resize(436, 436);
        field4->setMinimumSize(QSize(400, 400));
        field4->setMaximumSize(QSize(436, 436));
        gridLayout = new QGridLayout(field4);
        gridLayout->setObjectName("gridLayout");

        retranslateUi(field4);

        QMetaObject::connectSlotsByName(field4);
    } // setupUi

    void retranslateUi(QWidget *field4)
    {
        field4->setWindowTitle(QCoreApplication::translate("field4", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class field4: public Ui_field4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELD4_H
