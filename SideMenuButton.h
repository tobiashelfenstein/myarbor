#ifndef SIDEMENUBUTTON_H
#define SIDEMENUBUTTON_H

#include <QWidget>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QPaintEvent>

class SideMenuButton : public QWidget
{
    Q_OBJECT

public:
    explicit SideMenuButton(QWidget *parent = nullptr);
    explicit SideMenuButton(const QString &caption, QWidget *parent = nullptr);
    SideMenuButton(const QPixmap &icon, const QString &caption, QWidget *parent = nullptr);
    ~SideMenuButton();

    void setSubMenu(bool submenu);

private:
    void setupUi();
    void setSubMenuIcon();
    void paintEvent(QPaintEvent *);

    bool button_with_submenu_ = false;

    QLabel *ptr_icon_ = new QLabel();
    QPushButton *ptr_button_ = new QPushButton();
    QIcon sub_menu_icon_;
};

#endif // SIDEMENUBUTTON_H
