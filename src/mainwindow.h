#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include "resizewindow.h"

#define PATH "path"
#define SIZE_W "w"
#define SIZE_H "h"
#define POS "posizione"
#define PROP "proporzioni"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void on_btnStart_clicked();
    void on_btnClear_clicked();
    void on_actionAbout_triggered();
    void on_actionIstruzioni_triggered();
    void on_btnChoose_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QVector<QString> list;
    ResizeWindow *rw;
    QSettings settings;
    QString dir;
};

#endif // MAINWINDOW_H
