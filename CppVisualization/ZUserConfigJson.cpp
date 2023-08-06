#include "ZUserConfigJson.h"

void ZUserConfigJson::save(ZMainWindow const& mainWindow)
{
    // 不存在文件会自动创建
    if (_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QJsonObject jsonObj;

        QJsonObject mainWindowObj;
        {
            QJsonObject mainWindowPositionObj;
            mainWindowPositionObj["x"] = mainWindow.pos().x();
            mainWindowPositionObj["y"] = mainWindow.pos().y();

            QJsonObject mainWindowSizeObj;
            mainWindowSizeObj["width"]  = mainWindow.size().width();
            mainWindowSizeObj["height"] = mainWindow.size().height();

            mainWindowObj.insert("position", mainWindowPositionObj);
            mainWindowObj.insert("size", mainWindowSizeObj);
            mainWindowObj.insert("isMaxShow", mainWindow.isMaximized());
        }

        jsonObj["MainWindow"] = mainWindowObj;

        const QJsonDocument doc(jsonObj);
        _file.write(doc.toJson());

        _file.flush();
        _file.close();
    }
}

void ZUserConfigJson::load(ZMainWindow& mainWindow)
{
    if (_file.open(QIODevice::ReadOnly))
    {
        const QJsonDocument doc     = QJsonDocument::fromJson(_file.readAll());
        QJsonObject         jsonObj = doc.object();

        {
            QJsonObject mainWindowObj         = jsonObj["MainWindow"].toObject();
            QJsonObject mainWindowPositionObj = mainWindowObj["position"].toObject();
            QJsonObject mainWindowSizeObj     = mainWindowObj["size"].toObject();

            mainWindow.move(mainWindowPositionObj["x"].toInt(), mainWindowPositionObj["y"].toInt());
            mainWindow.resize(mainWindowSizeObj["width"].toInt(), mainWindowSizeObj["height"].toInt());
            mainWindow.setIsMaxShow(mainWindowObj["isMaxShow"].toBool());
        }

        _file.close();
    }
}
