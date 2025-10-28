#include <QMainWindow>

#include "firstmenu.h"
#include "ui_firstmenu.h"

FirstMenu::FirstMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstMenu)
{

    ui->setupUi(this);

    connect(ui->button_quit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}

FirstMenu::~FirstMenu()
{
    delete ui;
}


