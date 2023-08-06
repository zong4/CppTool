#pragma once

#include <QGraphicsPathItem>
#include <QPainter>
#include <QPointF>

class ZGraphicsPathItem : public QGraphicsPathItem
{
private:
    QPainterPath _path;

protected:
    void paint(QPainter *painter, QStyleOptionGraphicsItem const *option, QWidget *widget = nullptr) override;

public:
    ZGraphicsPathItem(QGraphicsItem *parent = nullptr) : QGraphicsPathItem(parent) {}

    void clear();

    void addStartPoint(QPointF point);
    void addStartPoint(double pointX, double pointY);
    void addLineSegment(QPointF point);
    void addLineSegment(double pointX, double pointY);
    void addQuadCurve(QPointF controlPoint, QPointF endPoint);
    void addQuadCurve(double controlPointX, double controlPointY, double endPointX, double endPointY);
    void addCubicCurve(QPointF controlPoint1, QPointF controlPoint2, QPointF endPoint);
    void addCubicCurve(double controlPoint1X, double controlPoint1Y, double controlPoint2X, double controlPoint2Y, double endPointX,
                       double endPointY);
    void addEllipse(QPointF point, double width, double height);
    void addEllipse(double pointX, double pointY, double width, double height);
};
