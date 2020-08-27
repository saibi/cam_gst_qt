#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QCameraViewfinderSettings>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_camera = 0;
	m_surface = 0;

	setupCamera();
}

MainWindow::~MainWindow()
{
	delete m_camera;
	delete m_surface;

	delete ui;
}


void MainWindow::setupCamera()
{
	if ( m_camera )
		return;

	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

	if ( cameras.size() < 1 )
	{
		qDebug("[%s] no camera", Q_FUNC_INFO);
		return;
	}

	m_surface = new MySurface();
	Q_CHECK_PTR(m_surface);

	m_surface->setVideoWidget(ui->widget_viewfinder);

	m_camera = new QCamera(cameras[0]);
	Q_CHECK_PTR(m_camera);

	m_camera->setViewfinder(m_surface);


#ifdef __RK3399__
	QCameraViewfinderSettings viewfinderSettings = m_camera->viewfinderSettings();

#define RESOLUTION_X 640
#define RESOLUTION_Y 480
	viewfinderSettings.setResolution(RESOLUTION_X, RESOLUTION_Y);
	viewfinderSettings.setPixelAspectRatio(4, 3);
	viewfinderSettings.setMinimumFrameRate(1.0);
	viewfinderSettings.setMaximumFrameRate(30.0);
	viewfinderSettings.setPixelFormat(QVideoFrame::Format_NV12);

	m_camera->setViewfinderSettings(viewfinderSettings);
#endif


	m_camera->start();
}
