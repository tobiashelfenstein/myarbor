#ifndef SIDESUBMENU_H
#define SIDESUBMENU_H

#include <QWidget>
#include <QVBoxLayout>

class SideSubMenu : public QWidget
{
    Q_OBJECT

public:
    SideSubMenu(QWidget *parent = nullptr);
    ~SideSubMenu();

    void addButton(QWidget *ptr_button);

private:
    void setupUi();
    //void paintEvent(QPaintEvent *);

    QVBoxLayout *ptr_layout_;
};

#endif // SIDESUBMENU_H
