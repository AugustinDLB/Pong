#ifndef FIRSTMENU_H
#define FIRSTMENU_H

#include <QWidget>

namespace Ui {
class FirstMenu;
}

class FirstMenu : public QWidget
{
    Q_OBJECT

public:
    explicit FirstMenu(QWidget *parent = nullptr);
    ~FirstMenu();
    Ui::FirstMenu *ui;
private slots:


private:

};

#endif // FIRSTMENU_H
