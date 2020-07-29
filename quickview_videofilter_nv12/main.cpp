#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>

#ifdef __RK3399__
#include <QCamera>
#endif

#include "myfilter.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	qmlRegisterType<MyFilter>("test.saibi.qt", 1, 0, "MyFilter");

	QQuickView view;
	view.setResizeMode(QQuickView::SizeRootObjectToView);
	QObject::connect(view.engine(), &QQmlEngine::quit, qApp, &QGuiApplication::quit);
	view.setSource(QUrl("qrc:///main.qml"));
	view.show();

#ifdef __RK3399__
	QQuickItem * rootItem = qobject_cast<QQuickItem*>(view.rootObject());
	if ( rootItem )
	{
		qDebug("DBG rootItem");
		QObject * obj = rootItem->findChild<QObject *>("qml-Camera");
		if ( obj )
		{
			qDebug("DBG qml-Camera found.");
			QCamera * camera = qvariant_cast<QCamera *>(obj->property("mediaObject"));
			if ( camera )
			{
				qDebug("DBG mediaObject QCamera");
				QCameraViewfinderSettings settings = camera->viewfinderSettings();
				settings.setResolution(640, 480);
				settings.setPixelFormat(QVideoFrame::Format_NV12);
				settings.setPixelAspectRatio(16, 9);
				settings.setMinimumFrameRate(10.0);
				settings.setMaximumFrameRate(30.0);
				camera->setViewfinderSettings(settings);
				qDebug("DBG set viewfindersettings");
			}
		}
	}
#endif

	qDebug("DBG exec");
	return app.exec();
}
