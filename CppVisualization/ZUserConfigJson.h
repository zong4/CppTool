#pragma once

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "./ZWidget/ZMainWindow.h"

class ZUserConfigJson
{
private:
    QFile _file;

public:
    ZUserConfigJson(QString const& filePath) : _file(QFile(filePath)) {}

    inline bool isFileExist() const { return _file.exists(); }

    void save(ZMainWindow const& mainWindow);
    void load(ZMainWindow& mainWindow);
};
