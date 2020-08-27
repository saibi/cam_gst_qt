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

	setupCamera();
}

MainWindow::~MainWindow()
{
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

	m_camera = new QCamera(cameras[0]);
	Q_CHECK_PTR(m_camera);

	m_camera->setViewfinder(ui->widget_viewfinder);


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

void MainWindow::on_pushButton_test_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( ! m_camera )
		return;

	QCameraImageProcessing * imageProcessing = m_camera->imageProcessing();

	if ( imageProcessing->isAvailable() )
	{
		qDebug("imageProcessing available");

		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterGrayscale) )
			qDebug("ColorFilterGrayscale available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterNegative) )
			qDebug("ColorFilterNegative available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterSolarize) )
			qDebug("ColorFilterSolarize available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterSepia) )
			qDebug("ColorFilterSepia available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterPosterize) )
			qDebug("ColorFilterPosterize available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterWhiteboard) )
			qDebug("ColorFilterWhiteboard available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterBlackboard) )
			qDebug("ColorFilterBlackboard available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterAqua) )
			qDebug("ColorFilterAqua available");
		if ( imageProcessing->isColorFilterSupported(QCameraImageProcessing::ColorFilterVendor) )
			qDebug("ColorFilterVendor available");

		if ( imageProcessing->isWhiteBalanceModeSupported(QCameraImageProcessing::WhiteBalanceAuto))
			qDebug("WhiteBalanceAuto available");

		imageProcessing->setWhiteBalanceMode(QCameraImageProcessing::WhiteBalanceFluorescent);
		imageProcessing->setDenoisingLevel(-0.3);


	}

}
