#include "ZGraphicsPathItem.h"

void ZGraphicsPathItem::paint(QPainter* painter, QStyleOptionGraphicsItem const* option, QWidget* widget)
{
    painter->setPen(this->pen());
    painter->drawPath(_path);
}

void ZGraphicsPathItem::clear()
{
    _path.clear();
}

void ZGraphicsPathItem::addStartPoint(QPointF point)
{
    _path.moveTo(point);
}

void ZGraphicsPathItem::addStartPoint(double pointX, double pointY)
{
    _path.moveTo(pointX, pointY);
}

void ZGraphicsPathItem::addLineSegment(QPointF point)
{
    _path.lineTo(point);
}

void ZGraphicsPathItem::addLineSegment(double pointX, double pointY)
{
    _path.lineTo(pointX, pointY);
}

void ZGraphicsPathItem::addQuadCurve(QPointF controlPoint, QPointF endPoint)
{
    _path.quadTo(controlPoint, endPoint);
}

void ZGraphicsPathItem::addQuadCurve(double controlPointX, double controlPointY, double endPointX, double endPointY)
{
    _path.quadTo(controlPointX, controlPointY, endPointX, endPointY);
}

void ZGraphicsPathItem::addCubicCurve(QPointF controlPoint1, QPointF controlPoint2, QPointF endPoint)
{
    _path.cubicTo(controlPoint1, controlPoint2, endPoint);
}

void ZGraphicsPathItem::addCubicCurve(double controlPoint1X, double controlPoint1Y, double controlPoint2X, double controlPoint2Y,
                                      double endPointX, double endPointY)
{
    _path.cubicTo(controlPoint1X, controlPoint1Y, controlPoint2X, controlPoint2Y, endPointX, endPointY);
}

void ZGraphicsPathItem::addEllipse(QPointF point, double width, double height)
{
    _path.addEllipse(point, width, height);
}

void ZGraphicsPathItem::addEllipse(double pointX, double pointY, double width, double height)
{
    _path.addEllipse(pointX, pointY, width, height);
}
