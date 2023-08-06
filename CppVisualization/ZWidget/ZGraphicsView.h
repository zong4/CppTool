#pragma once

#include <QGraphicsView>
#include <QWheelEvent>
#include <iostream>

class ZGraphicsView : public QGraphicsView
{
    Q_OBJECT

private:
    qreal  _scaleFactor   = 1.0;
    qreal  _moveSensitive = 100;
    QPoint _lastPos;

protected:
    void wheelEvent(QWheelEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override
    {
        if (event->button() == Qt::MiddleButton) // Shift + leftClick
        {
            setDragMode(QGraphicsView::ScrollHandDrag);
            setInteractive(false);

            _lastPos = event->pos();
        }

        QGraphicsView::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent* event) override
    {
        setStyleSheet("QGraphicsView::rubberBand {background-color::transparent;}");

        if (event->button() == Qt::MiddleButton) // Shift + leftClick
        {
            QPointF delta = mapToScene(event->pos()) - mapToScene(_lastPos);
            delta *= 100;
            QGraphicsView::translate(delta.x(), delta.y());

            //_lastPos = event->pos();
        }

        QGraphicsView::mouseMoveEvent(event);
    }

public:
    ZGraphicsView(QWidget* parent = nullptr);
};
