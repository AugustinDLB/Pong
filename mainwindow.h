#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "mainframe.h"
#include "game.h"
#include "firstmenu.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow() {}

    private:
        Game            *game;
        FirstMenu       *first_menu;

        QComboBox       *pageComboBox;
        QStackedWidget  *stackedWidget;
        QVBoxLayout     *layout;
        QWidget         *centralWidget;

    private slots:
        void on_button_params_clicked();
};

#endif
