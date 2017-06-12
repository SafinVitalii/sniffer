/********************************************************************************
** Form generated from reading UI file 'trafficinterceptor.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAFFICINTERCEPTOR_H
#define UI_TRAFFICINTERCEPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_TrafficInterceptor
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QListWidget *listWidget;

    void setupUi(QDialog *TrafficInterceptor)
    {
        if (TrafficInterceptor->objectName().isEmpty())
            TrafficInterceptor->setObjectName(QStringLiteral("TrafficInterceptor"));
        TrafficInterceptor->resize(400, 365);
        TrafficInterceptor->setMinimumSize(QSize(400, 365));
        QIcon icon;
        icon.addFile(QStringLiteral("favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        TrafficInterceptor->setWindowIcon(icon);
        textEdit = new QTextEdit(TrafficInterceptor);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 381, 221));
        textEdit->setReadOnly(true);
        pushButton = new QPushButton(TrafficInterceptor);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 320, 100, 30));
        listWidget = new QListWidget(TrafficInterceptor);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(80, 230, 241, 81));

        retranslateUi(TrafficInterceptor);

        QMetaObject::connectSlotsByName(TrafficInterceptor);
    } // setupUi

    void retranslateUi(QDialog *TrafficInterceptor)
    {
        TrafficInterceptor->setWindowTitle(QApplication::translate("TrafficInterceptor", "Welcome!", 0));
        pushButton->setText(QApplication::translate("TrafficInterceptor", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class TrafficInterceptor: public Ui_TrafficInterceptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAFFICINTERCEPTOR_H
