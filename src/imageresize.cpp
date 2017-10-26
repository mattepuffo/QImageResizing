#include "imageresize.h"

void ImageResize::resize(QString inputImage, QString dir, int width, int height)
{
    QFileInfo f(inputImage);
    QImage pixmap(inputImage);
    QImage newPixmap;
    if (width == 0)
    {
        newPixmap = pixmap.scaledToHeight(height, Qt::SmoothTransformation);
    }
    else if (height == 0)
    {
        newPixmap = pixmap.scaledToWidth(width, Qt::SmoothTransformation);
    }
    else
    {
        newPixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    QFile file(dir + f.fileName());
    file.open(QIODevice::WriteOnly);
    newPixmap.save(&file, 0, 100);
    file.close();
}

/*void ImageResize::resize(QString inputImage, QString dir, int width, int height)
{
    QFileInfo f(inputImage);
    QPixmap pixmap(inputImage);
    QPixmap newPixmap;
    if (width == 0)
    {
        newPixmap = pixmap.scaledToHeight(height, Qt::SmoothTransformation);
    }
    else if (height == 0)
    {
        newPixmap = pixmap.scaledToWidth(width, Qt::SmoothTransformation);
    }
    else
    {
        newPixmap = pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
    QFile file(dir + f.fileName());
    file.open(QIODevice::WriteOnly);
    newPixmap.save(&file, 0, 100);
    file.close();
}*/

ImageResize::~ImageResize()
{
}
