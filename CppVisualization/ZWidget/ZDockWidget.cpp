#include "ZDockWidget.h"

ZDockWidget::ZDockWidget(QWidget* parent) : QDockWidget(parent)
{
    // 去除 DockWidget 的标题栏
    QWidget* oldTitalbar = this->titleBarWidget();
    QWidget* newTitalbar = new QWidget();

    this->setTitleBarWidget(newTitalbar);

    delete oldTitalbar;
}

ZDockWidget::~ZDockWidget()
{
}
