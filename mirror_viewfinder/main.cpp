#include "mainwindow.h"
#include <QApplication>

#include "sharedviewfinder.h"

#include <QCameraInfo>
#include <QCameraViewfinderSettings>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SharedViewFinder viewfinder;

	MainWindow w;

	w.show();

	QObject::connect(&viewfinder, &SharedViewFinder::signalFrameReady, &w, &MainWindow::slotFrameReady);

	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	foreach(QCameraInfo info, cameras)
	{
		qDebug("%s", qPrintable(info.deviceName()));
	}

	QCamera camera(cameras[0]);
	camera.setViewfinder(&viewfinder);

#ifdef __RK3399__
	QCameraViewfinderSettings viewfinderSettings = camera.viewfinderSettings();

	qDebug("DBG default viewfinderSettings : %f~%f, %d:%d, %d*%d, %d",
		   viewfinderSettings.minimumFrameRate(),
		   viewfinderSettings.maximumFrameRate(),
		   viewfinderSettings.pixelAspectRatio().width(),
		   viewfinderSettings.pixelAspectRatio().height(),
		   viewfinderSettings.resolution().width(),
		   viewfinderSettings.resolution().height(),
		   viewfinderSettings.pixelFormat() );

#define RESOLUTION_X 1280
#define RESOLUTION_Y 800
	qDebug("DBG set viewfinderSettings 1~30, 16:9, %dx%d, NV12", RESOLUTION_X, RESOLUTION_Y);
	viewfinderSettings.setResolution(RESOLUTION_X, RESOLUTION_Y);
	viewfinderSettings.setPixelAspectRatio(16, 9);
	viewfinderSettings.setMinimumFrameRate(1.0);
	viewfinderSettings.setMaximumFrameRate(30.0);
	viewfinderSettings.setPixelFormat(QVideoFrame::Format_NV12);

	camera.setViewfinderSettings(viewfinderSettings);
#endif

	camera.start();

	return a.exec();
}
