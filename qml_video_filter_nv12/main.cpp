#include <QGuiApplication>
#include <QQmlApplicationEngine>

#ifdef __RK3399__
#include <QCamera>
#endif

#include "myfilter.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	qmlRegisterType<MyFilter>("test.saibi.qt", 1, 0, "MyFilter");

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;


#ifdef __RK3399__
	if ( ! engine.rootObjects().isEmpty() )
	{
		qDebug("DBG get rootObjects");
		QObject * obj = engine.rootObjects()[0]->findChild<QObject *>("qml-Camera");
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
