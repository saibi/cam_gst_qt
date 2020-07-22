#include "mainwindow.h"
#include <QApplication>

#include "sharedviewfinder.h"

#include <QCameraInfo>
#include <QCameraViewfinderSettings>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SharedViewFinder viewfinder, viewfinder2;

	MainWindow w;
	w.show();

	QObject::connect(&viewfinder, &SharedViewFinder::signalFrameReady, &w, &MainWindow::slotFrameReady);
	QObject::connect(&viewfinder2, &SharedViewFinder::signalFrameReady, &w, &MainWindow::slotFrame2Ready);

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

#ifdef __RK3399__
	QCamera camera2(cameras[2]);
	camera2.setViewfinder(&viewfinder2);

	QCameraViewfinderSettings viewfinderSettings2 = camera2.viewfinderSettings();
	viewfinderSettings2.setResolution(RESOLUTION_X, RESOLUTION_Y);
	viewfinderSettings2.setPixelAspectRatio(16, 9);
	viewfinderSettings2.setMinimumFrameRate(1.0);
	viewfinderSettings2.setMaximumFrameRate(30.0);
	viewfinderSettings2.setPixelFormat(QVideoFrame::Format_NV12);
	camera2.setViewfinderSettings(viewfinderSettings2);

	camera2.start();
#endif

	return a.exec();
}
