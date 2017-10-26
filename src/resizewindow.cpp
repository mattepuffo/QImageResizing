#include "resizewindow.h"
#include "ui_resizewindow.h"

ResizeWindow::ResizeWindow(QVector<QString> list, int width, int height, QString startDir, QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::ResizeWindow)
{
    ui->setupUi(this);
    wt = new WorkerThread(list, width, height, startDir, this);
    connect(wt, SIGNAL(valueChanged(QString)), this, SLOT(onValueChanged(QString)));
    connect(wt, SIGNAL(finished()), this, SLOT(onFinished()));
    wt->start();
}

void ResizeWindow::on_btnClose_clicked()
{
    wt->stop = true;
    this->close();
}

void ResizeWindow::onValueChanged(QString text)
{
    ui->txtArea->appendPlainText(text);
}

void ResizeWindow::onFinished()
{
   ui->txtArea->appendPlainText("OPERAZONI TERMINATE");
}

ResizeWindow::~ResizeWindow()
{
    delete ui;
}
