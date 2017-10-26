#ifndef IMAGERESIZI_H
#define IMAGERESIZI_H

#include <QImage>
#include <QPixmap>
#include <QDir>
#include <QBuffer>

class ImageResize
{
public:
    virtual ~ImageResize();
    static void resize(QString inputImage, QString dir, int width, int height);
};

#endif // IMAGERESIZI_H
