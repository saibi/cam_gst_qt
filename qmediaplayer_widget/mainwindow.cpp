#include "mainwindow.h"
#include "ui_mainwindow.h"

#if defined(__RK3399_X11__)
#define PIPELINE "gst-pipeline: rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=800,height=480,framerate=30/1 ! videoconvert ! ximagesink name=qtvideosink"
#elif defined(__RK3399_MALI__)
#define PIPELINE "gst-pipeline: rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=1280,height=800,framerate=30/1 ! videoconvert ! autovideosink name=qtvideosink"
#else
#define PIPELINE "gst-pipeline: videotestsrc ! autovideosink name=qtvideosink"
#endif



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_player = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
	Q_CHECK_PTR(m_player);

	m_player->setVideoOutput(ui->widget_output);
	m_player->setMedia(QUrl(PIPELINE));
	m_player->play();

}

MainWindow::~MainWindow()
{
	if ( m_player )
		m_player->stop();

	delete m_player;

	delete ui;
}
