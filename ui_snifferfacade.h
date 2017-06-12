/********************************************************************************
** Form generated from reading UI file 'snifferfacade.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNIFFERFACADE_H
#define UI_SNIFFERFACADE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SnifferFacade
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QTableWidget *packetlist;
    QLineEdit *filtersedit;
    QPushButton *applyfiltersbutton;
    QPushButton *startbutton;
    QPushButton *searchbutton;
    QPushButton *stopbutton;
    QPushButton *logbutton;
    QPushButton *prevpacketbutton;
    QPushButton *nextpacketbutton;
    QPushButton *helpbutton;
    QPushButton *zoomoutbutton;
    QPushButton *zoominbutton;
    QTextEdit *detailsview;
    QPushButton *firstpacketbutton;
    QPushButton *lastpacketbutton;
    QPushButton *statsbutton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuStatistics;
    QMenu *menuHelp;

    void setupUi(QMainWindow *SnifferFacade)
    {
        if (SnifferFacade->objectName().isEmpty())
            SnifferFacade->setObjectName(QStringLiteral("SnifferFacade"));
        SnifferFacade->resize(630, 581);
        SnifferFacade->setMinimumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QStringLiteral(":/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SnifferFacade->setWindowIcon(icon);
        actionQuit = new QAction(SnifferFacade);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(SnifferFacade);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        packetlist = new QTableWidget(centralWidget);
        if (packetlist->columnCount() < 6)
            packetlist->setColumnCount(6);
        packetlist->setObjectName(QStringLiteral("packetlist"));
        packetlist->setGeometry(QRect(10, 60, 610, 331));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(packetlist->sizePolicy().hasHeightForWidth());
        packetlist->setSizePolicy(sizePolicy);
        packetlist->setSortingEnabled(false);
        packetlist->setColumnCount(6);
        packetlist->horizontalHeader()->setDefaultSectionSize(90);
        packetlist->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        packetlist->verticalHeader()->setVisible(false);
        packetlist->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        filtersedit = new QLineEdit(centralWidget);
        filtersedit->setObjectName(QStringLiteral("filtersedit"));
        filtersedit->setGeometry(QRect(10, 35, 521, 20));
        applyfiltersbutton = new QPushButton(centralWidget);
        applyfiltersbutton->setObjectName(QStringLiteral("applyfiltersbutton"));
        applyfiltersbutton->setGeometry(QRect(540, 35, 80, 21));
        startbutton = new QPushButton(centralWidget);
        startbutton->setObjectName(QStringLiteral("startbutton"));
        startbutton->setGeometry(QRect(10, 0, 32, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/start.ico"), QSize(), QIcon::Normal, QIcon::Off);
        startbutton->setIcon(icon1);
        startbutton->setIconSize(QSize(32, 32));
        startbutton->setFlat(true);
        searchbutton = new QPushButton(centralWidget);
        searchbutton->setObjectName(QStringLiteral("searchbutton"));
        searchbutton->setGeometry(QRect(80, 0, 32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        searchbutton->setIcon(icon2);
        searchbutton->setIconSize(QSize(32, 32));
        searchbutton->setFlat(true);
        stopbutton = new QPushButton(centralWidget);
        stopbutton->setObjectName(QStringLiteral("stopbutton"));
        stopbutton->setGeometry(QRect(45, 0, 32, 32));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        stopbutton->setIcon(icon3);
        stopbutton->setIconSize(QSize(32, 32));
        stopbutton->setFlat(true);
        logbutton = new QPushButton(centralWidget);
        logbutton->setObjectName(QStringLiteral("logbutton"));
        logbutton->setGeometry(QRect(115, 0, 32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/openlog.ico"), QSize(), QIcon::Normal, QIcon::Off);
        logbutton->setIcon(icon4);
        logbutton->setIconSize(QSize(32, 32));
        logbutton->setFlat(true);
        prevpacketbutton = new QPushButton(centralWidget);
        prevpacketbutton->setObjectName(QStringLiteral("prevpacketbutton"));
        prevpacketbutton->setGeometry(QRect(170, 0, 32, 32));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/previouspacket.ico"), QSize(), QIcon::Normal, QIcon::Off);
        prevpacketbutton->setIcon(icon5);
        prevpacketbutton->setIconSize(QSize(32, 32));
        prevpacketbutton->setFlat(true);
        nextpacketbutton = new QPushButton(centralWidget);
        nextpacketbutton->setObjectName(QStringLiteral("nextpacketbutton"));
        nextpacketbutton->setGeometry(QRect(205, 0, 32, 32));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/nextpacket.ico"), QSize(), QIcon::Normal, QIcon::Off);
        nextpacketbutton->setIcon(icon6);
        nextpacketbutton->setIconSize(QSize(32, 32));
        nextpacketbutton->setFlat(true);
        helpbutton = new QPushButton(centralWidget);
        helpbutton->setObjectName(QStringLiteral("helpbutton"));
        helpbutton->setGeometry(QRect(455, 0, 32, 32));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        helpbutton->setIcon(icon7);
        helpbutton->setIconSize(QSize(32, 32));
        helpbutton->setFlat(true);
        zoomoutbutton = new QPushButton(centralWidget);
        zoomoutbutton->setObjectName(QStringLiteral("zoomoutbutton"));
        zoomoutbutton->setGeometry(QRect(365, 0, 32, 32));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/zoomout.ico"), QSize(), QIcon::Normal, QIcon::Off);
        zoomoutbutton->setIcon(icon8);
        zoomoutbutton->setIconSize(QSize(32, 32));
        zoomoutbutton->setFlat(true);
        zoominbutton = new QPushButton(centralWidget);
        zoominbutton->setObjectName(QStringLiteral("zoominbutton"));
        zoominbutton->setGeometry(QRect(330, 0, 32, 32));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/zoomin.ico"), QSize(), QIcon::Normal, QIcon::Off);
        zoominbutton->setIcon(icon9);
        zoominbutton->setIconSize(QSize(32, 32));
        zoominbutton->setFlat(true);
        detailsview = new QTextEdit(centralWidget);
        detailsview->setObjectName(QStringLiteral("detailsview"));
        detailsview->setGeometry(QRect(10, 400, 611, 141));
        detailsview->setReadOnly(true);
        firstpacketbutton = new QPushButton(centralWidget);
        firstpacketbutton->setObjectName(QStringLiteral("firstpacketbutton"));
        firstpacketbutton->setGeometry(QRect(240, 0, 32, 32));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/firstpacket.ico"), QSize(), QIcon::Normal, QIcon::Off);
        firstpacketbutton->setIcon(icon10);
        firstpacketbutton->setIconSize(QSize(32, 32));
        firstpacketbutton->setFlat(true);
        lastpacketbutton = new QPushButton(centralWidget);
        lastpacketbutton->setObjectName(QStringLiteral("lastpacketbutton"));
        lastpacketbutton->setGeometry(QRect(275, 0, 32, 32));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/lastpacket.ico"), QSize(), QIcon::Normal, QIcon::Off);
        lastpacketbutton->setIcon(icon11);
        lastpacketbutton->setIconSize(QSize(32, 32));
        lastpacketbutton->setFlat(true);
        statsbutton = new QPushButton(centralWidget);
        statsbutton->setObjectName(QStringLiteral("statsbutton"));
        statsbutton->setGeometry(QRect(420, 0, 32, 32));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/statistics.ico"), QSize(), QIcon::Normal, QIcon::Off);
        statsbutton->setIcon(icon12);
        statsbutton->setIconSize(QSize(32, 32));
        statsbutton->setFlat(true);
        SnifferFacade->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SnifferFacade);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 630, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuStatistics = new QMenu(menuBar);
        menuStatistics->setObjectName(QStringLiteral("menuStatistics"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SnifferFacade->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuStatistics->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(SnifferFacade);

        QMetaObject::connectSlotsByName(SnifferFacade);
    } // setupUi

    void retranslateUi(QMainWindow *SnifferFacade)
    {
        SnifferFacade->setWindowTitle(QApplication::translate("SnifferFacade", "Sniffer", 0));
        actionQuit->setText(QApplication::translate("SnifferFacade", "Quit", 0));
#ifndef QT_NO_STATUSTIP
        filtersedit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        filtersedit->setInputMask(QString());
        filtersedit->setText(QString());
        filtersedit->setPlaceholderText(QApplication::translate("SnifferFacade", "Enter the filters...", 0));
#ifndef QT_NO_TOOLTIP
        applyfiltersbutton->setToolTip(QApplication::translate("SnifferFacade", "Apply filters", 0));
#endif // QT_NO_TOOLTIP
        applyfiltersbutton->setText(QApplication::translate("SnifferFacade", "Apply", 0));
#ifndef QT_NO_TOOLTIP
        startbutton->setToolTip(QApplication::translate("SnifferFacade", "Start sniffing", 0));
#endif // QT_NO_TOOLTIP
        startbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        searchbutton->setToolTip(QApplication::translate("SnifferFacade", "Find packet", 0));
#endif // QT_NO_TOOLTIP
        searchbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        stopbutton->setToolTip(QApplication::translate("SnifferFacade", "Pause sniffing", 0));
#endif // QT_NO_TOOLTIP
        stopbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        logbutton->setToolTip(QApplication::translate("SnifferFacade", "View log file", 0));
#endif // QT_NO_TOOLTIP
        logbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        prevpacketbutton->setToolTip(QApplication::translate("SnifferFacade", "Previous packet", 0));
#endif // QT_NO_TOOLTIP
        prevpacketbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        nextpacketbutton->setToolTip(QApplication::translate("SnifferFacade", "Next packet", 0));
#endif // QT_NO_TOOLTIP
        nextpacketbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        helpbutton->setToolTip(QApplication::translate("SnifferFacade", "Help", 0));
#endif // QT_NO_TOOLTIP
        helpbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        zoomoutbutton->setToolTip(QApplication::translate("SnifferFacade", "Zoom Out", 0));
#endif // QT_NO_TOOLTIP
        zoomoutbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        zoominbutton->setToolTip(QApplication::translate("SnifferFacade", "Zoom In", 0));
#endif // QT_NO_TOOLTIP
        zoominbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        firstpacketbutton->setToolTip(QApplication::translate("SnifferFacade", "Scroll to start", 0));
#endif // QT_NO_TOOLTIP
        firstpacketbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        lastpacketbutton->setToolTip(QApplication::translate("SnifferFacade", "Scroll to end", 0));
#endif // QT_NO_TOOLTIP
        lastpacketbutton->setText(QString());
#ifndef QT_NO_TOOLTIP
        statsbutton->setToolTip(QApplication::translate("SnifferFacade", "View statistics", 0));
#endif // QT_NO_TOOLTIP
        statsbutton->setText(QString());
        menuFile->setTitle(QApplication::translate("SnifferFacade", "File", 0));
        menuSettings->setTitle(QApplication::translate("SnifferFacade", "View", 0));
        menuStatistics->setTitle(QApplication::translate("SnifferFacade", "Statistics", 0));
        menuHelp->setTitle(QApplication::translate("SnifferFacade", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SnifferFacade: public Ui_SnifferFacade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNIFFERFACADE_H
