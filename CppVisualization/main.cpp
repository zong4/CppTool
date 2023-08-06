#include <qelapsedtimer.h>

#include <QApplication>
#include <QTime>

#include "./ZWidget/ZGraphicsPathItem.h"
#include "./ZWidget/ZMainWindow.h"
#include "ZUserConfigJson.h"

int main(int argc, char* argv[])
{
    const QApplication app(argc, argv);
    ZMainWindow        mainWindow;

    // 从 JSON 文件中恢复布局信息
    ZUserConfigJson userConfig("UserConfig.json");

    // 第一次打开用
    if (!userConfig.isFileExist())
        mainWindow.initialize();
    else
        userConfig.load(mainWindow);

    // 获取场景
    QGraphicsScene* scene = (mainWindow.views()[mainWindow.currentViewindex()])->scene();

    // 注册窗口关闭事件处理函数，用于保存布局信息到 JSON 文件
    QObject::connect(&app, &QApplication::aboutToQuit, [&]() { userConfig.save(mainWindow); });

    if (mainWindow.isMaxShow())
        mainWindow.showMaximized();
    else
        mainWindow.show();

    // 添加图形
    {
        ZGraphicsPathItem* item = new ZGraphicsPathItem();
        item->setPen(*mainWindow.pen());

        // TODO: 需要注意坐标轴方向不一致，可能需要调整数据
        item->clear();
        item->addStartPoint(0, 0);
        item->addLineSegment(100, 100);
        item->addCubicCurve(125, 125, 175, 125, 200, 100);
        item->addEllipse(0, -100, 50, 50);

        scene->addItem(item);
    }

    // QElapsedTimer t;
    // t.start();
    // while (t.elapsed() < 10000)
    //{
    // }

    // scene->deleteLater();

    return app.exec();
}
