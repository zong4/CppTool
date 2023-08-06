#include "ZGraphicsView.h"

void ZGraphicsView::wheelEvent(QWheelEvent* event)
{
    // 获取鼠标滚轮滚动的角度
    QPoint angleDelta = event->angleDelta();
    if (!angleDelta.isNull())
    {
        // 根据垂直滚动角度来缩放
        int verticalAngle = angleDelta.y();

        if (verticalAngle > 0)
        {
            // 向上滚动，放大画布
            _scaleFactor *= 1.2;
        }
        else
        {
            // 向下滚动，缩小画布
            _scaleFactor /= 1.2;
        }
        this->setTransform(QTransform::fromScale(_scaleFactor, _scaleFactor));

        // 忽略事件，避免进一步处理滚轮事件
        event->accept();
    }
}

ZGraphicsView::ZGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
    // 启用抗锯齿
    this->setRenderHint(QPainter::Antialiasing);
}
