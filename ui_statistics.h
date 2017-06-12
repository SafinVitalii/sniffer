/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Statistics
{
public:
    QLabel *title;

    void setupUi(QDialog *Statistics)
    {
        if (Statistics->objectName().isEmpty())
            Statistics->setObjectName(QStringLiteral("Statistics"));
        Statistics->resize(400, 300);
        title = new QLabel(Statistics);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(150, 10, 111, 16));
        QFont font;
        font.setPointSize(11);
        title->setFont(font);

        retranslateUi(Statistics);

        QMetaObject::connectSlotsByName(Statistics);
    } // setupUi

    void retranslateUi(QDialog *Statistics)
    {
        Statistics->setWindowTitle(QApplication::translate("Statistics", "Statistics", 0));
        title->setText(QApplication::translate("Statistics", "Overall statistics", 0));
    } // retranslateUi

};

namespace Ui {
    class Statistics: public Ui_Statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
