#include "SideMenuButton.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
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

    // create sub menu widget
    ptr_submenu_ = new SideSubMenu();
    ptr_vlayout_->addWidget(ptr_submenu_);

    // add action to this button
    connect(ptr_button_, &QPushButton::toggled, ptr_submenu_, &QWidget::setVisible);
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
    //setSubMenuIcon();
    ptr_button_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // create horizontal layout for icon and button
    QHBoxLayout *ptr_hlayout = new QHBoxLayout();
    ptr_hlayout->setContentsMargins(0, 0, 0, 0);
    ptr_hlayout->setSpacing(0);

    ptr_hlayout->addWidget(ptr_icon_);
    ptr_hlayout->addWidget(ptr_button_);

    // create central vertical layout for menu button an sub menu
    ptr_vlayout_ = new QVBoxLayout(this);
    ptr_vlayout_->addLayout(ptr_hlayout);
}

void SideMenuButton::setSubMenuIcon()
{
    // create empty QIcon or override
    submenu_icon_ = QIcon();

    // if the button has a sub menu, create the QICon with arrows
    if (button_with_submenu_)
    {
        submenu_icon_.addPixmap(QPixmap(":/icons/arrow-right.ico"), QIcon::Normal, QIcon::Off);
        submenu_icon_.addPixmap(QPixmap(":/icons/arrow-down.ico"), QIcon::Normal, QIcon::On);
    }

    // checkable is necessary to change between the arrows
    ptr_button_->setIcon(submenu_icon_);
    ptr_button_->setLayoutDirection(Qt::RightToLeft);
    ptr_button_->setCheckable(button_with_submenu_);
}

void SideMenuButton::addSubMenuButton(QWidget *ptr_button)
{
    // a button activates the sub menu
    if (!button_with_submenu_)
    {
        setSubMenu(true);
    }

    // add button to layout
    ptr_submenu_->addButton(ptr_button);
}

void SideMenuButton::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
