#include "mainwindow.h"
#include <QApplication>

#include <QCameraInfo>
#include <QCameraViewfinderSettings>

#include "customviewfinder.h"
#include "customcamerawidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	foreach(const QCameraInfo & info, cameras)
	{
		qDebug("%s", qPrintable(info.deviceName()));
	}

	CustomViewFinder viewfinder;
	CustomViewFinder viewfinder2;

	QObject::connect(&viewfinder, &CustomViewFinder::signalFrameReady, w.cameraWidget(0), &CustomCameraWidget::slotFrameReady);
	QObject::connect(&viewfinder2, &CustomViewFinder::signalFrameReady, w.cameraWidget(1), &CustomCameraWidget::slotFrameReady);

	QCamera camera(cameras[0]);
	camera.setViewfinder(&viewfinder);

#ifdef __RK3399__
	QCameraViewfinderSettings viewfinderSettings = camera.viewfinderSettings();

#define RESOLUTION_X 640
#define RESOLUTION_Y 480

	qDebug("DBG set viewfinderSettings 1~30, 4:3, %dx%d, NV12", RESOLUTION_X, RESOLUTION_Y);
	viewfinderSettings.setResolution(RESOLUTION_X, RESOLUTION_Y);
	viewfinderSettings.setPixelAspectRatio(4, 3);
	viewfinderSettings.setMinimumFrameRate(1.0);
	viewfinderSettings.setMaximumFrameRate(30.0);
	viewfinderSettings.setPixelFormat(QVideoFrame::Format_NV12);

	camera.setViewfinderSettings(viewfinderSettings);
#endif
	camera.start();

#ifdef __RK3399__
	QCamera camera2(cameras[2]);
	camera2.setViewfinder(&viewfinder2);
	camera2.setViewfinderSettings(viewfinderSettings);
	camera2.start();
#endif

	w.show();

	return a.exec();
}
