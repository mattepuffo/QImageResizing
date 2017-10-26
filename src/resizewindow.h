#ifndef RESIZEWINDOW_H
#define RESIZEWINDOW_H

#include <QScrollArea>
#include "workerthread.h"

namespace Ui {
class ResizeWindow;
}

class ResizeWindow : public QScrollArea
{
    Q_OBJECT

public:
    explicit ResizeWindow(QVector<QString> list, int width, int height, QString startDir, QWidget *parent = 0);
    virtual ~ResizeWindow();
    WorkerThread *wt;

private slots:
    void on_btnClose_clicked();

public slots:
    void onValueChanged(QString text);
    void onFinished();

private:
    Ui::ResizeWindow *ui;
};

#endif // RESIZEWINDOW_H
