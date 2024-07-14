#include "mainwindow.h"
#include "SideMenuButton.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi();
    setupMenuBar();
}

MainWindow::~MainWindow()
{
    // nothing to do
}

void MainWindow::setupUi()
{
    setMinimumWidth(800);
    setMinimumHeight(600);

    QPixmap testIcon = QPixmap(":/icons/color-management.svg");

    SideMenuButton *pTestBtn = new SideMenuButton(testIcon, "Hello, World");
    pTestBtn->setSubMenu(true);

    QWidget *pSideMenuWidget = new QWidget();
    pSideMenuWidget->setMaximumWidth(300);
    pSideMenuWidget->setContentsMargins(0, 0, 0, 0);
    setCentralWidget(pSideMenuWidget);

    /*QPushButton *pHomeBtn = new QPushButton("Home");

    QWidget *pBestattungenSubMenu = new QWidget(pSideMenuWidget);
    QLabel *pBestattungenLbl = new QLabel("Bestattungen", pBestattungenSubMenu);
    QPushButton *pBestattungenBtn = new QPushButton("Bestattungen Btn", pBestattungenSubMenu);*/

    QVBoxLayout *pSideMenuLayout = new QVBoxLayout(pSideMenuWidget);
    pSideMenuLayout->setContentsMargins(0, 0, 0, 0);
    pSideMenuLayout->setSpacing(0);
    pSideMenuLayout->addWidget(pTestBtn);
    pSideMenuLayout->addStretch();
}

void MainWindow::setupMenuBar()
{
    QMenu *pFileMenu = menuBar()->addMenu("&Datei");
    pFileMenu->addAction("&Drucken");

    pFileMenu->addSeparator();
    pFileMenu->addAction("&Beenden", qApp, &QCoreApplication::quit); /* TODO: QCoreApplication */

    QMenu *pDatabaseMenu = menuBar()->addMenu("Datenbank");
    pDatabaseMenu->addAction("Datenbank sichern");

    pDatabaseMenu->addSeparator();
    pDatabaseMenu->addAction("Einstellungen");


    QMenu *pHelpMenu = menuBar()->addMenu("&Hilfe");
    pHelpMenu->addAction("&Über myArbor");
}

