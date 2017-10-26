#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QMutex>
#include <QThread>
#include <QVector>
#include "imageresize.h"

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QVector<QString> list, int width, int height, QString startDir, QObject *parent = 0, bool b = false);
    virtual ~WorkerThread();
    void run();
    bool stop;

private:
    QVector<QString> list;
    int width;
    int height;
    QString startDir;

signals:
    void valueChanged(QString text);
    void finished();
};

#endif // WORKTHREAD_H
// http://www.bogotobogo.com/Qt/Qt5_QThreads_GuiThread.php
