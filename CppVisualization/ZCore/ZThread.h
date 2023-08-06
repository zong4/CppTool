#pragma once

#include <QtCore>

class ZThread : public QThread
{
    Q_OBJECT

protected:
    void run() override;

public:
    ZThread(QObject *parent);
    ~ZThread();
};
