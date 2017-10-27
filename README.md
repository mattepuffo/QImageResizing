QImageResizing
=======

Qt program to resize images
-----------

Program written in Qt 5 and multi platform.

It is used to resize many images automatically; you can choose how many images, dragging the files into the appropriate area.

Images will not be edited, but copies will be created in the directory you chose.

Resizing works like this:
* if you choose both height and width, the  image will be forced to that size; in this case tha image could be grainy
* if you choose the width by zeroing the height, this will be set proportionally to the width
* if you choose the height, leaving the width wide, this will be set proportionally to the height

The program was tested on 64-bit Windows 7, Windows 10 64bit, and various 64-bit Linunx distributions.

On Linux, the only faced problem is when a GLIBC versione older than the one used for compiling is installed.
