#include "mainwindow.h"
#include <QApplication>

#include "sharedviewfinder.h"

#include <QCameraInfo>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SharedViewFinder viewfinder;

	MainWindow w;

	w.show();

	QObject::connect(&viewfinder, &SharedViewFinder::signalFrameReady, &w, &MainWindow::slotFrameReady);

	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	QCamera camera(cameras[0]);
	camera.setViewfinder(&viewfinder);

	camera.start();

	return a.exec();
}
