#include "mainwindow.h"
#include <QApplication>

#include <gst/gst.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	gst_init(&argc, &argv);

	MainWindow w;

#ifdef __RK3399__
	w.showFullScreen();
#else
	w.show();
#endif

	return a.exec();
}
