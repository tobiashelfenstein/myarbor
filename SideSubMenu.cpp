#include "SideSubMenu.h"

#include <QVBoxLayout>

SideSubMenu::SideSubMenu(QWidget *parent) : QWidget(parent)
{
    setupUi();
}

SideSubMenu::~SideSubMenu()
{
    // nothing to do
}

void SideSubMenu::setupUi()
{
    // create vertical layout for buttons
    ptr_layout_ = new QVBoxLayout(this);
    ptr_layout_->setContentsMargins(0, 0, 0, 0);
    ptr_layout_->setSpacing(0);

    // always invisible
    setVisible(false);
}

void SideSubMenu::addButton(QWidget *ptr_button)
{
    ptr_layout_->addWidget(ptr_button);
}

/*void SideSubMenu::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}*/
