/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionPause;
    QAction *actionQuit;
    QWidget *centralWidget;
    QWidget *gameWidget;
    QLabel *levelLabel;
    QLabel *Obiettivi;
    QWidget *layoutWidget;
    QHBoxLayout *StatusMainLabel;
    QVBoxLayout *GeneralLabel;
    QLabel *playerName_L;
    QLabel *HP_L;
    QLabel *STR_L;
    QLabel *DEF_L;
    QLabel *LUCK_L;
    QLabel *VEL_L;
    QLabel *AP_L;
    QVBoxLayout *StatsLabel;
    QLabel *PlayerName;
    QLabel *HP;
    QLabel *STR;
    QLabel *DEF;
    QLabel *LUCK;
    QLabel *VEL;
    QLabel *AP;
    QLabel *MessageBox;
    QWidget *layoutWidget1;
    QVBoxLayout *DropUseLayout;
    QWidget *layoutWidget2;
    QGridLayout *inventory;
    QLabel *PlayerImage;
    QWidget *layoutWidget3;
    QVBoxLayout *ItemDressed;
    QGraphicsView *view;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *battleButton;
    QLabel *turnLabel;
    QWidget *battleSplash;
    QWidget *enemyHitSplash;
    QWidget *playerHitSplash;
    QLabel *enemyHPLabel;
    QWidget *messageSplash;
    QWidget *splashScreen;
    QWidget *startScreen;
    QWidget *widget;
    QPushButton *inizia;
    QLabel *label;
    QTextEdit *playerStartName;
    QWidget *backgroundWidget;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        MainWindow->setMouseTracking(false);
        MainWindow->setDocumentMode(false);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QFont font;
        actionQuit->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setFocusPolicy(Qt::NoFocus);
        gameWidget = new QWidget(centralWidget);
        gameWidget->setObjectName(QStringLiteral("gameWidget"));
        gameWidget->setEnabled(true);
        gameWidget->setGeometry(QRect(0, 0, 800, 567));
        levelLabel = new QLabel(gameWidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(630, 10, 161, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        levelLabel->setFont(font1);
        levelLabel->setAutoFillBackground(false);
        levelLabel->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        levelLabel->setFrameShape(QFrame::Box);
        levelLabel->setLineWidth(4);
        levelLabel->setTextFormat(Qt::PlainText);
        levelLabel->setAlignment(Qt::AlignCenter);
        levelLabel->setWordWrap(false);
        Obiettivi = new QLabel(gameWidget);
        Obiettivi->setObjectName(QStringLiteral("Obiettivi"));
        Obiettivi->setGeometry(QRect(630, 50, 161, 81));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        Obiettivi->setFont(font2);
        Obiettivi->setAutoFillBackground(false);
        Obiettivi->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        Obiettivi->setFrameShape(QFrame::Box);
        Obiettivi->setLineWidth(4);
        Obiettivi->setTextFormat(Qt::PlainText);
        Obiettivi->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Obiettivi->setWordWrap(false);
        Obiettivi->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        layoutWidget = new QWidget(gameWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(630, 140, 161, 271));
        layoutWidget->setStyleSheet(QStringLiteral(""));
        StatusMainLabel = new QHBoxLayout(layoutWidget);
        StatusMainLabel->setSpacing(6);
        StatusMainLabel->setContentsMargins(11, 11, 11, 11);
        StatusMainLabel->setObjectName(QStringLiteral("StatusMainLabel"));
        StatusMainLabel->setContentsMargins(0, 0, 0, 0);
        GeneralLabel = new QVBoxLayout();
        GeneralLabel->setSpacing(6);
        GeneralLabel->setObjectName(QStringLiteral("GeneralLabel"));
        playerName_L = new QLabel(layoutWidget);
        playerName_L->setObjectName(QStringLiteral("playerName_L"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(97, 170, 152, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(41, 255, 238, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(26, 85, 212, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(85, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(113, 33, 106, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        QBrush brush7(QColor(241, 68, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush8(QColor(212, 127, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush10(QColor(170, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        playerName_L->setPalette(palette);
        QFont font3;
        font3.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        playerName_L->setFont(font3);
        playerName_L->setAutoFillBackground(true);
        playerName_L->setStyleSheet(QStringLiteral(""));
        playerName_L->setFrameShape(QFrame::Box);
        playerName_L->setLineWidth(3);
        playerName_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(playerName_L);

        HP_L = new QLabel(layoutWidget);
        HP_L->setObjectName(QStringLiteral("HP_L"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        HP_L->setPalette(palette1);
        HP_L->setFont(font3);
        HP_L->setAutoFillBackground(true);
        HP_L->setStyleSheet(QStringLiteral(""));
        HP_L->setFrameShape(QFrame::Box);
        HP_L->setLineWidth(3);
        HP_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(HP_L);

        STR_L = new QLabel(layoutWidget);
        STR_L->setObjectName(QStringLiteral("STR_L"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        STR_L->setPalette(palette2);
        STR_L->setFont(font3);
        STR_L->setAutoFillBackground(true);
        STR_L->setStyleSheet(QStringLiteral(""));
        STR_L->setFrameShape(QFrame::Box);
        STR_L->setLineWidth(3);
        STR_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(STR_L);

        DEF_L = new QLabel(layoutWidget);
        DEF_L->setObjectName(QStringLiteral("DEF_L"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        DEF_L->setPalette(palette3);
        DEF_L->setFont(font3);
        DEF_L->setAutoFillBackground(true);
        DEF_L->setStyleSheet(QStringLiteral(""));
        DEF_L->setFrameShape(QFrame::Box);
        DEF_L->setLineWidth(3);
        DEF_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(DEF_L);

        LUCK_L = new QLabel(layoutWidget);
        LUCK_L->setObjectName(QStringLiteral("LUCK_L"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        LUCK_L->setPalette(palette4);
        LUCK_L->setFont(font3);
        LUCK_L->setAutoFillBackground(true);
        LUCK_L->setStyleSheet(QStringLiteral(""));
        LUCK_L->setFrameShape(QFrame::Box);
        LUCK_L->setLineWidth(3);
        LUCK_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(LUCK_L);

        VEL_L = new QLabel(layoutWidget);
        VEL_L->setObjectName(QStringLiteral("VEL_L"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        VEL_L->setPalette(palette5);
        VEL_L->setFont(font3);
        VEL_L->setAutoFillBackground(true);
        VEL_L->setStyleSheet(QStringLiteral(""));
        VEL_L->setFrameShape(QFrame::Box);
        VEL_L->setLineWidth(3);
        VEL_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(VEL_L);

        AP_L = new QLabel(layoutWidget);
        AP_L->setObjectName(QStringLiteral("AP_L"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        AP_L->setPalette(palette6);
        AP_L->setFont(font3);
        AP_L->setAutoFillBackground(true);
        AP_L->setStyleSheet(QStringLiteral(""));
        AP_L->setFrameShape(QFrame::Box);
        AP_L->setLineWidth(3);
        AP_L->setAlignment(Qt::AlignCenter);

        GeneralLabel->addWidget(AP_L);


        StatusMainLabel->addLayout(GeneralLabel);

        StatsLabel = new QVBoxLayout();
        StatsLabel->setSpacing(6);
        StatsLabel->setObjectName(QStringLiteral("StatsLabel"));
        PlayerName = new QLabel(layoutWidget);
        PlayerName->setObjectName(QStringLiteral("PlayerName"));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setWeight(50);
        PlayerName->setFont(font4);
        PlayerName->setAutoFillBackground(false);
        PlayerName->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        PlayerName->setFrameShape(QFrame::Box);
        PlayerName->setTextFormat(Qt::AutoText);
        PlayerName->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(PlayerName);

        HP = new QLabel(layoutWidget);
        HP->setObjectName(QStringLiteral("HP"));
        HP->setFont(font1);
        HP->setAutoFillBackground(false);
        HP->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        HP->setFrameShape(QFrame::Box);
        HP->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(HP);

        STR = new QLabel(layoutWidget);
        STR->setObjectName(QStringLiteral("STR"));
        STR->setFont(font1);
        STR->setAutoFillBackground(false);
        STR->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        STR->setFrameShape(QFrame::Box);
        STR->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(STR);

        DEF = new QLabel(layoutWidget);
        DEF->setObjectName(QStringLiteral("DEF"));
        DEF->setFont(font1);
        DEF->setAutoFillBackground(false);
        DEF->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        DEF->setFrameShape(QFrame::Box);
        DEF->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(DEF);

        LUCK = new QLabel(layoutWidget);
        LUCK->setObjectName(QStringLiteral("LUCK"));
        LUCK->setFont(font1);
        LUCK->setAutoFillBackground(false);
        LUCK->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        LUCK->setFrameShape(QFrame::Box);
        LUCK->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(LUCK);

        VEL = new QLabel(layoutWidget);
        VEL->setObjectName(QStringLiteral("VEL"));
        VEL->setFont(font1);
        VEL->setAutoFillBackground(false);
        VEL->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        VEL->setFrameShape(QFrame::Box);
        VEL->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(VEL);

        AP = new QLabel(layoutWidget);
        AP->setObjectName(QStringLiteral("AP"));
        AP->setFont(font1);
        AP->setAutoFillBackground(false);
        AP->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        AP->setFrameShape(QFrame::Box);
        AP->setAlignment(Qt::AlignCenter);

        StatsLabel->addWidget(AP);


        StatusMainLabel->addLayout(StatsLabel);

        MessageBox = new QLabel(gameWidget);
        MessageBox->setObjectName(QStringLiteral("MessageBox"));
        MessageBox->setGeometry(QRect(170, 520, 451, 31));
        MessageBox->setFont(font1);
        MessageBox->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        MessageBox->setFrameShape(QFrame::Box);
        MessageBox->setAlignment(Qt::AlignCenter);
        MessageBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable);
        layoutWidget1 = new QWidget(gameWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(530, 430, 91, 81));
        DropUseLayout = new QVBoxLayout(layoutWidget1);
        DropUseLayout->setSpacing(6);
        DropUseLayout->setContentsMargins(11, 11, 11, 11);
        DropUseLayout->setObjectName(QStringLiteral("DropUseLayout"));
        DropUseLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(gameWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(170, 430, 351, 81));
        layoutWidget2->setStyleSheet(QStringLiteral(""));
        inventory = new QGridLayout(layoutWidget2);
        inventory->setSpacing(6);
        inventory->setContentsMargins(11, 11, 11, 11);
        inventory->setObjectName(QStringLiteral("inventory"));
        inventory->setContentsMargins(0, 0, 0, 0);
        PlayerImage = new QLabel(gameWidget);
        PlayerImage->setObjectName(QStringLiteral("PlayerImage"));
        PlayerImage->setGeometry(QRect(60, 430, 91, 121));
        PlayerImage->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        PlayerImage->setFrameShape(QFrame::Box);
        PlayerImage->setLineWidth(4);
        PlayerImage->setAlignment(Qt::AlignCenter);
        layoutWidget3 = new QWidget(gameWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 430, 45, 121));
        layoutWidget3->setStyleSheet(QStringLiteral(""));
        ItemDressed = new QVBoxLayout(layoutWidget3);
        ItemDressed->setSpacing(6);
        ItemDressed->setContentsMargins(11, 11, 11, 11);
        ItemDressed->setObjectName(QStringLiteral("ItemDressed"));
        ItemDressed->setContentsMargins(0, 0, 0, 0);
        view = new QGraphicsView(gameWidget);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(10, 10, 600, 400));
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        verticalLayoutWidget = new QWidget(gameWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(630, 480, 160, 71));
        verticalLayoutWidget->setStyleSheet(QStringLiteral(""));
        battleButton = new QVBoxLayout(verticalLayoutWidget);
        battleButton->setSpacing(6);
        battleButton->setContentsMargins(11, 11, 11, 11);
        battleButton->setObjectName(QStringLiteral("battleButton"));
        battleButton->setContentsMargins(0, 0, 0, 0);
        turnLabel = new QLabel(gameWidget);
        turnLabel->setObjectName(QStringLiteral("turnLabel"));
        turnLabel->setGeometry(QRect(630, 430, 161, 41));
        turnLabel->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255)"));
        turnLabel->setFrameShape(QFrame::Box);
        turnLabel->setAlignment(Qt::AlignCenter);
        battleSplash = new QWidget(gameWidget);
        battleSplash->setObjectName(QStringLiteral("battleSplash"));
        battleSplash->setGeometry(QRect(227, 140, 171, 141));
        enemyHitSplash = new QWidget(gameWidget);
        enemyHitSplash->setObjectName(QStringLiteral("enemyHitSplash"));
        enemyHitSplash->setGeometry(QRect(255, 295, 101, 80));
        playerHitSplash = new QWidget(gameWidget);
        playerHitSplash->setObjectName(QStringLiteral("playerHitSplash"));
        playerHitSplash->setGeometry(QRect(260, 20, 101, 80));
        enemyHPLabel = new QLabel(gameWidget);
        enemyHPLabel->setObjectName(QStringLiteral("enemyHPLabel"));
        enemyHPLabel->setGeometry(QRect(265, 100, 101, 25));
        enemyHPLabel->setTextFormat(Qt::RichText);
        enemyHPLabel->setAlignment(Qt::AlignCenter);
        enemyHPLabel->setMargin(1);
        messageSplash = new QWidget(gameWidget);
        messageSplash->setObjectName(QStringLiteral("messageSplash"));
        messageSplash->setGeometry(QRect(177, 140, 271, 141));
        splashScreen = new QWidget(centralWidget);
        splashScreen->setObjectName(QStringLiteral("splashScreen"));
        splashScreen->setEnabled(true);
        splashScreen->setGeometry(QRect(0, 0, 800, 567));
        startScreen = new QWidget(centralWidget);
        startScreen->setObjectName(QStringLiteral("startScreen"));
        startScreen->setGeometry(QRect(0, 0, 800, 567));
        startScreen->setAutoFillBackground(false);
        startScreen->setStyleSheet(QStringLiteral("background: url(:/Resources/Resources/startScreen.png)"));
        widget = new QWidget(startScreen);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 800, 600));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        widget->setFont(font5);
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QStringLiteral("background: url(:/Resources/Resources/startScreen.png)"));
        inizia = new QPushButton(widget);
        inizia->setObjectName(QStringLiteral("inizia"));
        inizia->setGeometry(QRect(350, 150, 100, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Segoe UI Semibold"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setWeight(75);
        inizia->setFont(font6);
        label = new QLabel(startScreen);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 50, 211, 41));
        QFont font7;
        font7.setPointSize(24);
        label->setFont(font7);
        label->setStyleSheet(QStringLiteral(""));
        label->setTextFormat(Qt::RichText);
        playerStartName = new QTextEdit(startScreen);
        playerStartName->setObjectName(QStringLiteral("playerStartName"));
        playerStartName->setGeometry(QRect(300, 100, 200, 30));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush11(QColor(255, 255, 255, 0));
        brush11.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush12(QColor(0, 0, 0, 255));
        brush12.setStyle(Qt::NoBrush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QBrush brush13(QColor(0, 0, 0, 255));
        brush13.setStyle(Qt::NoBrush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        playerStartName->setPalette(palette7);
        QFont font8;
        font8.setPointSize(12);
        playerStartName->setFont(font8);
        playerStartName->setAutoFillBackground(false);
        playerStartName->setStyleSheet(QStringLiteral("background: rgba(255, 255, 255, 0);color : white;"));
        playerStartName->setInputMethodHints(Qt::ImhLatinOnly);
        playerStartName->setLineWidth(70);
        playerStartName->setOverwriteMode(true);
        playerStartName->setAcceptRichText(false);
        playerStartName->setCursorWidth(0);
        backgroundWidget = new QWidget(centralWidget);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        backgroundWidget->setGeometry(QRect(0, 0, 800, 567));
        backgroundWidget->setStyleSheet(QStringLiteral("background:rgb(236, 240, 241)"));
        MainWindow->setCentralWidget(centralWidget);
        backgroundWidget->raise();
        gameWidget->raise();
        splashScreen->raise();
        startScreen->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 20));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuGame->setSeparatorsCollapsible(false);
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionStart);
        menuGame->addAction(actionPause);
        menuGame->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GameWindow", Q_NULLPTR));
        actionStart->setText(QApplication::translate("MainWindow", "Start New Game", Q_NULLPTR));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Exit Game", Q_NULLPTR));
        levelLabel->setText(QApplication::translate("MainWindow", "Level: 1", Q_NULLPTR));
        Obiettivi->setText(QApplication::translate("MainWindow", "Obiettivi:", Q_NULLPTR));
        playerName_L->setText(QApplication::translate("MainWindow", "Player Name", Q_NULLPTR));
        HP_L->setText(QApplication::translate("MainWindow", "HP:", Q_NULLPTR));
        STR_L->setText(QApplication::translate("MainWindow", "STR:", Q_NULLPTR));
        DEF_L->setText(QApplication::translate("MainWindow", "DEF:", Q_NULLPTR));
        LUCK_L->setText(QApplication::translate("MainWindow", "LUCK:", Q_NULLPTR));
        VEL_L->setText(QApplication::translate("MainWindow", "VEL:", Q_NULLPTR));
        AP_L->setText(QApplication::translate("MainWindow", "AP:", Q_NULLPTR));
        PlayerName->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        HP->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        STR->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        DEF->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        LUCK->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        VEL->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        AP->setText(QApplication::translate("MainWindow", "SETTABLE", Q_NULLPTR));
        MessageBox->setText(QApplication::translate("MainWindow", "MessageBox per le descrizioni", Q_NULLPTR));
        layoutWidget1->setStyleSheet(QString());
        PlayerImage->setText(QApplication::translate("MainWindow", "Player Image", Q_NULLPTR));
        turnLabel->setText(QString());
        enemyHPLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        inizia->setText(QApplication::translate("MainWindow", "INIZIA", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">INSERT NAME</span></p></body></html>", Q_NULLPTR));
        playerStartName->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\" bgcolor=\"#26211d\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Hero</p></body></html>", Q_NULLPTR));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
