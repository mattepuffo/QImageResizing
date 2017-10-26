#ifndef STARTRESIZING_H
#define STARTRESIZING_H

#include <QPlainTextEdit>
#include <QPushButton>
#include <QThread>
#include <QDebug>

class StartResizing : public QObject
{
public:
    explicit StartResizing(QVector<QString> list, int width, int height, QString dir);
    virtual ~StartResizing();
    void doWork();

signals:
    void resizing(QString text);

protected:
    QVector<QString> list;
    int width;
    int heigh;
    QString dir;
};

#endif // STARTRESIZING_H
