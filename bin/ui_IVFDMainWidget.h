/********************************************************************************
** Form generated from reading UI file 'IVFDMainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IVFDMAINWIDGET_H
#define UI_IVFDMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IVFDMainWidget
{
public:

    void setupUi(QWidget *IVFDMainWidget)
    {
        if (IVFDMainWidget->objectName().isEmpty())
            IVFDMainWidget->setObjectName(QStringLiteral("IVFDMainWidget"));
        IVFDMainWidget->resize(400, 300);

        retranslateUi(IVFDMainWidget);

        QMetaObject::connectSlotsByName(IVFDMainWidget);
    } // setupUi

    void retranslateUi(QWidget *IVFDMainWidget)
    {
        IVFDMainWidget->setWindowTitle(QApplication::translate("IVFDMainWidget", "IVFDMainWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class IVFDMainWidget: public Ui_IVFDMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IVFDMAINWIDGET_H
