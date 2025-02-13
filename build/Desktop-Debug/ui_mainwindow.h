/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newGame;
    QAction *saveGame;
    QAction *loadGame;
    QAction *exitGame;
    QAction *help;
    QAction *about;
    QAction *showScores;
    QAction *action3x3;
    QAction *action4x4;
    QAction *action5x5;
    QAction *action6x6;
    QAction *action7x7;
    QAction *action8x8;
    QWidget *centralwidget;
    QPushButton *moveUpButton;
    QPushButton *moveDownButton;
    QPushButton *moveLeftButton;
    QPushButton *moveRightButton;
    QLabel *label;
    QLabel *maxNumberLabel;
    QPushButton *undoButton;
    QWidget *widget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(460, 595);
        MainWindow->setMinimumSize(QSize(460, 595));
        MainWindow->setMaximumSize(QSize(460, 595));
        newGame = new QAction(MainWindow);
        newGame->setObjectName("newGame");
        saveGame = new QAction(MainWindow);
        saveGame->setObjectName("saveGame");
        loadGame = new QAction(MainWindow);
        loadGame->setObjectName("loadGame");
        exitGame = new QAction(MainWindow);
        exitGame->setObjectName("exitGame");
        help = new QAction(MainWindow);
        help->setObjectName("help");
        about = new QAction(MainWindow);
        about->setObjectName("about");
        showScores = new QAction(MainWindow);
        showScores->setObjectName("showScores");
        action3x3 = new QAction(MainWindow);
        action3x3->setObjectName("action3x3");
        action4x4 = new QAction(MainWindow);
        action4x4->setObjectName("action4x4");
        action5x5 = new QAction(MainWindow);
        action5x5->setObjectName("action5x5");
        action6x6 = new QAction(MainWindow);
        action6x6->setObjectName("action6x6");
        action7x7 = new QAction(MainWindow);
        action7x7->setObjectName("action7x7");
        action8x8 = new QAction(MainWindow);
        action8x8->setObjectName("action8x8");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        moveUpButton = new QPushButton(centralwidget);
        moveUpButton->setObjectName("moveUpButton");
        moveUpButton->setGeometry(QRect(63, 450, 41, 41));
        QFont font;
        font.setPointSize(20);
        moveUpButton->setFont(font);
        moveDownButton = new QPushButton(centralwidget);
        moveDownButton->setObjectName("moveDownButton");
        moveDownButton->setGeometry(QRect(63, 500, 41, 41));
        moveDownButton->setFont(font);
        moveLeftButton = new QPushButton(centralwidget);
        moveLeftButton->setObjectName("moveLeftButton");
        moveLeftButton->setGeometry(QRect(13, 500, 41, 41));
        moveLeftButton->setFont(font);
        moveRightButton = new QPushButton(centralwidget);
        moveRightButton->setObjectName("moveRightButton");
        moveRightButton->setGeometry(QRect(113, 500, 41, 41));
        moveRightButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 455, 180, 40));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        maxNumberLabel = new QLabel(centralwidget);
        maxNumberLabel->setObjectName("maxNumberLabel");
        maxNumberLabel->setGeometry(QRect(220, 495, 180, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Ubuntu")});
        font2.setPointSize(24);
        font2.setItalic(false);
        maxNumberLabel->setFont(font2);
        maxNumberLabel->setStyleSheet(QString::fromUtf8(""));
        maxNumberLabel->setAlignment(Qt::AlignCenter);
        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");
        undoButton->setGeometry(QRect(13, 450, 41, 41));
        undoButton->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 436, 436));
        widget->setMinimumSize(QSize(436, 436));
        widget->setMaximumSize(QSize(436, 436));
        widget->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        moveDownButton->raise();
        moveLeftButton->raise();
        moveRightButton->raise();
        moveUpButton->raise();
        label->raise();
        maxNumberLabel->raise();
        undoButton->raise();
        widget->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 460, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_3 = new QMenu(menu);
        menu_3->setObjectName("menu_3");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(newGame);
        menu->addAction(saveGame);
        menu->addAction(loadGame);
        menu->addAction(menu_3->menuAction());
        menu->addAction(showScores);
        menu->addSeparator();
        menu->addAction(exitGame);
        menu_3->addAction(action3x3);
        menu_3->addAction(action4x4);
        menu_3->addAction(action5x5);
        menu_3->addAction(action6x6);
        menu_3->addAction(action7x7);
        menu_3->addAction(action8x8);
        menu_2->addAction(help);
        menu_2->addAction(about);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newGame->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", nullptr));
#if QT_CONFIG(shortcut)
        newGame->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        saveGame->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
#if QT_CONFIG(shortcut)
        saveGame->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        loadGame->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\263\321\200\321\203", nullptr));
#if QT_CONFIG(shortcut)
        loadGame->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        exitGame->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(shortcut)
        exitGame->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        help->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
#if QT_CONFIG(shortcut)
        help->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        about->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261 \320\270\320\263\321\200\320\265", nullptr));
#if QT_CONFIG(shortcut)
        about->setShortcut(QCoreApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        showScores->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\272\320\276\321\200\320\264\321\213", nullptr));
        action3x3->setText(QCoreApplication::translate("MainWindow", "3x3", nullptr));
        action4x4->setText(QCoreApplication::translate("MainWindow", "4x4", nullptr));
        action5x5->setText(QCoreApplication::translate("MainWindow", "5x5", nullptr));
        action6x6->setText(QCoreApplication::translate("MainWindow", "6x6", nullptr));
        action7x7->setText(QCoreApplication::translate("MainWindow", "7x7", nullptr));
        action8x8->setText(QCoreApplication::translate("MainWindow", "8x8", nullptr));
#if QT_CONFIG(tooltip)
        moveUpButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
#endif // QT_CONFIG(tooltip)
        moveUpButton->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
#if QT_CONFIG(tooltip)
        moveDownButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
#endif // QT_CONFIG(tooltip)
        moveDownButton->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
#if QT_CONFIG(tooltip)
        moveLeftButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        moveLeftButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
#if QT_CONFIG(tooltip)
        moveRightButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        moveRightButton->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\200\320\265\320\272\320\276\321\200\320\264:", nullptr));
        maxNumberLabel->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
#if QT_CONFIG(tooltip)
        undoButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260 \321\205\320\276\320\264\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        undoButton->setText(QCoreApplication::translate("MainWindow", "\342\206\266", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\263\321\200\320\260", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\273\321\217", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
