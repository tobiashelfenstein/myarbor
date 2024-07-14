#include "SideMenuButton.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

SideMenuButton::SideMenuButton(QWidget *parent) : QWidget(parent)
{
    setupUi();
}

SideMenuButton::SideMenuButton(const QString &caption, QWidget *parent) : QWidget(parent)
{
    setupUi();

    ptr_icon_->setVisible(false); // WORKAROUND
    ptr_button_->setText(caption);
}

SideMenuButton::SideMenuButton(const QPixmap &icon, const QString &caption, QWidget *parent) : QWidget(parent)
{
    setupUi();

    ptr_icon_->setPixmap(icon);
    ptr_button_->setText(caption);
}

SideMenuButton::~SideMenuButton()
{
    // nothing to do
}

void SideMenuButton::setSubMenu(bool submenu)
{
    button_with_submenu_ = submenu;
    setSubMenuIcon();
}

void SideMenuButton::setupUi()
{
    // define design of the icon
    ptr_icon_->setScaledContents(true);
    ptr_icon_->setMinimumHeight(32);
    ptr_icon_->setMaximumHeight(32);
    ptr_icon_->setMinimumWidth(32);
    ptr_icon_->setMaximumWidth(32);

    // define design of the button
    setSubMenuIcon();
    ptr_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    /*QIcon btnIcon;
    btnIcon.addPixmap(QPixmap(":/icons/home.svg"), QIcon::Normal, QIcon::Off);
    btnIcon.addPixmap(QPixmap(":/icons/rosegarden.svg"), QIcon::Normal, QIcon::On);
    pButton->setIcon(btnIcon);
    pButton->setCheckable(true);*/

    // create horizontal layout for icon and button
    QHBoxLayout *ptr_layout = new QHBoxLayout(this);
    ptr_layout->setContentsMargins(0, 0, 0, 0);
    ptr_layout->setSpacing(0);

    ptr_layout->addWidget(ptr_icon_);
    ptr_layout->addWidget(ptr_button_);

    //ptr_layout->addStretch();
}

void SideMenuButton::setSubMenuIcon()
{
    // create empty QIcon or override
    sub_menu_icon_ = QIcon();

    // if the button has a sub menu, create the QICon with arrows
    if (button_with_submenu_)
    {
        sub_menu_icon_.addPixmap(QPixmap(":/icons/arrow-right.ico"), QIcon::Normal, QIcon::Off);
        sub_menu_icon_.addPixmap(QPixmap(":/icons/arrow-down.ico"), QIcon::Normal, QIcon::On);
    }

    // checkable is necessary to change between the arrows
    ptr_button_->setIcon(sub_menu_icon_);
    ptr_button_->setLayoutDirection(Qt::RightToLeft);
    ptr_button_->setCheckable(button_with_submenu_);
}

void SideMenuButton::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
