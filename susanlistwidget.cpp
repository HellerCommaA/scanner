#include "susanlistwidget.h"
#include <iostream>

SusanListWidget::SusanListWidget(QWidget *xParent)
    : QListWidget(xParent)
{

}


void SusanListWidget::addListItem(QString xString)
{
    this->addItem(xString);
}
