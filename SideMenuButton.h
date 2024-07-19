#ifndef SIDEMENUBUTTON_H
#define SIDEMENUBUTTON_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QPaintEvent>

#include "SideSubMenu.h"

class SideMenuButton : public QWidget
{
    Q_OBJECT

public:
    explicit SideMenuButton(QWidget *parent = nullptr);
    explicit SideMenuButton(const QString &caption, QWidget *parent = nullptr);
    SideMenuButton(const QPixmap &icon, const QString &caption, QWidget *parent = nullptr);
    ~SideMenuButton();

    void addSubMenuButton(QWidget *ptr_button);

private:
    void setupUi();
    void setSubMenu(bool submenu);
    void setSubMenuIcon();
    void paintEvent(QPaintEvent *);

    bool button_with_submenu_ = false;

    QVBoxLayout *ptr_vlayout_;

    QLabel *ptr_icon_ = new QLabel();
    QPushButton *ptr_button_ = new QPushButton();
    QIcon submenu_icon_;

    SideSubMenu *ptr_submenu_;
};

#endif // SIDEMENUBUTTON_H
