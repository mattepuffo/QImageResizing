#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setAcceptDrops(true);
    ui->txtWidth->setText(settings.value(SIZE_W, "0").toString());
    ui->txtHeight->setText(settings.value(SIZE_H, "0").toString());
    ui->txtPath->setText(settings.value(PATH, "").toString());
    if (settings.contains(POS)) {
        move(settings.value(POS).toPoint());
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasUrls()) {
        foreach (QUrl url, event->mimeData()->urls()) {
            QFileInfo f(url.toLocalFile());
            if(f.fileName().toLower().endsWith(".jpeg") ||
                    f.fileName().toLower().endsWith(".jpg") ||
                    f.fileName().toLower().endsWith(".png") ||
                    f.fileName().toLower().endsWith(".bmp") ||
                    f.fileName().toLower().endsWith(".gif")) {
                ui->txtList->appendPlainText(url.toLocalFile());
                list.append(f.filePath());
            }
        }
        ui->lblCount->setText("No. immagini: " + QString::number(list.count()));
    }
}

void MainWindow::on_btnStart_clicked() {
    QString strDir(ui->txtPath->text());
    QDir d(strDir);
    if (!d.exists()) {
        d.mkdir(strDir);
    }

    if (!strDir.isEmpty()) {
        if (list.count() > 0) {
            if (!ui->txtWidth->text().isEmpty() && !ui->txtHeight->text().isEmpty()) {
                int w = ui->txtWidth->text().toInt();
                int h = ui->txtHeight->text().toInt();
                if (w > 0 || h > 0) {
                    settings.setValue(SIZE_W, ui->txtWidth->text());
                    settings.setValue(SIZE_H, ui->txtHeight->text());
                    settings.setValue(PATH, ui->txtPath->text());
                    rw = new ResizeWindow(list, w, h, strDir);
                    rw->setVisible(true);
                } else {
                    QMessageBox msgBox;
                    msgBox.setText("Imposta almeno una dimensione diversa da zero!");
                    msgBox.exec();
                }
            } else {
                QMessageBox msgBox;
                msgBox.setText("Imposta le dimensioni (zero per non definirla)!");
                msgBox.exec();
            }
        } else {
            QMessageBox msgBox;
            msgBox.setText("Non hai selezionato nessuna immagine!");
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Seleziona una directory!");
        msgBox.exec();
    }
}


void MainWindow::on_btnChoose_clicked() {
    dir = QFileDialog::getExistingDirectory(this, tr("Scegli directory"), QDir::homePath(), QFileDialog::ShowDirsOnly);
    settings.setValue(PATH, dir);
    ui->txtPath->setText(settings.value(PATH, "").toString());
}

void MainWindow::on_btnClear_clicked() {
    list.clear();
    ui->txtList->clear();
    ui->lblCount->setText("");
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, "About", qApp->applicationName() +
                       ": Programma per il ridimensionamento delle immagini.<br><br>"
                       "Autore: " + QString(qApp->organizationName()).replace("_"," ") +
                       "<br><br>"
                       "Blog: <a href='" + qApp->organizationDomain() +
                       "'>Mattepuffo.com</a><br><br>"
                       "Licenza: <a href='http://www.mattepuffo.com/blog/copyright.html'>Creative Commons</a><br><br>"
                       "Linguaggio: C++/Qt<br><br>"
                       "Versione: " + qApp->applicationVersion() +
                       "<br><br>"
                       "Versione Qt: " + QT_VERSION_STR);
}

void MainWindow::on_actionIstruzioni_triggered() {
    QMessageBox::about(this, "Istruzioni",
                       "<ul>"
                       "<li>Selezionare gli articoli trascindandoli nella area bianca (jpeg, jpeg, png, gif, bmp)</li>"
                       "<li>Impostare larghezza e altezza:"
                       "<ul>"
                       "<li>Le caselle non devono essere vuote</li>"
                       "<li>Le caselle non devono essere entrambe a zero</li>"
                       "<li>Per impostare l'altezza in base alla larghezza, lasciare l'altezza a zero</li>"
                       "<li>Per impostare la larghezza in base all'altezza', lasciare la larghezza a zero</li>"
                       "</ul>"
                       "</li>"
                       "<li>Cliccare il tasto <strong>Start</strong></li>"
                       "<li>Scegliere la directory dove salvare i file ridimenensionati</li>"
                       "</ul>");
}

void MainWindow::closeEvent(QCloseEvent *event) {
    settings.setValue(POS, pos());
    event->accept();
}

MainWindow::~MainWindow() {
    delete ui;
}
