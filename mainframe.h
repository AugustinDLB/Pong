#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QWidget>

class MainFrame : public QWidget
{
    Q_OBJECT
public:
    explicit MainFrame(QWidget *parent = nullptr);

signals:

private:
    QPoint ball_pos;
    QPoint ball_speed;
};

#endif // MAINFRAME_H
