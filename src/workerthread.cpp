#include "workerthread.h"

WorkerThread::WorkerThread(QVector<QString> list, int width, int height, QString startDir, QObject *parent, bool b) :
    QThread(parent), stop(b)
{
    this->list = list;
    this->width = width;
    this->height = height;
    this->startDir = startDir;
}

void WorkerThread::run()
{
    for (int i = 0; i < list.count(); i++)
    {
        QMutex mutex;
        // PREVIENE CHE ALTRI THREAD IMPOSTINO LO STOP
        mutex.lock();
        if(this->stop) break;
        mutex.unlock();
        // EMETTE IL SEGNALE PER IMPOSTARE IL TESTO SULLA GUI
        ImageResize::resize(list.value(i), startDir + QDir::separator(), width, height);
        emit valueChanged(list.value(i));
        this->msleep(500);
    }
    emit finished();
}

WorkerThread::~WorkerThread()
{
}
