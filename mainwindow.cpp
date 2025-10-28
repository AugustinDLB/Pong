#include <QPushButton>
#include <QLabel>

#include "mainframe.h"
#include "mainwindow.h"
#include "firstmenu.h"
#include "game.h"
#include "./ui_mainwindow.h"
#include "./ui_firstmenu.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Creates widgets
    first_menu  = new FirstMenu(this);
    game        = new Game(this);

    /* Add pages to the stack */
    stackedWidget = new QStackedWidget;

    stackedWidget->addWidget(first_menu);
    stackedWidget->addWidget(game);

    /* Create layout */
    layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);

    centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);

    connect(first_menu->ui->button_start,   &QPushButton::clicked,  game, &Game::Start);
    connect(first_menu->ui->button_start,   &QPushButton::clicked,  this, [this]() {stackedWidget->setCurrentIndex(1);});
    connect(game,                           &Game::game_is_finished,this, [this]() {stackedWidget->setCurrentIndex(0);});

}

void MainWindow::on_button_params_clicked()
{

}


