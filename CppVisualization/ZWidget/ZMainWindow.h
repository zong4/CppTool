#pragma once

#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QScreen>

#include "ZDockWidget.h"
#include "ZGraphicsPathItem.h"
#include "ZGraphicsView.h"

class ZMainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool                    _isMaxShow;
    uint                    _currentViewindex;
    QPen*                   _pen;
    QVector<ZGraphicsView*> _views;

protected:
public:
    ZMainWindow(QWidget* parent = nullptr);

    inline bool                    isMaxShow() const { return _isMaxShow; }
    inline uint                    currentViewindex() const { return _currentViewindex; }
    inline QPen*                   pen() const { return _pen; }
    inline QVector<ZGraphicsView*> views() const { return _views; }

    inline void setIsMaxShow(bool isMaxShow) { _isMaxShow = isMaxShow; }

    void initialize();
};
