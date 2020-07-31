#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <gst/video/videooverlay.h>


#ifdef __RK3399_MALI__
#define PIPELINE_DESC "rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! kmssink render-rectangle=\"<400,100,320,240>\""
#define SINK_NAME "kmssink0"

#elif defined(__RK3399_X11__)
#define PIPELINE_DESC "rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! videoconvert ! ximagesink"
#define SINK_NAME "ximagesink0"

#elif defined(__1810TZ__)
#define PIPELINE_DESC "v4l2src device=/dev/video0 ! video/x-raw,format=YUY2,width=320,height=240,framerate=30/1 ! videoconvert ! ximagesink"
#define SINK_NAME "ximagesink0"

#else
#define PIPELINE_DESC "videotestsrc ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! videoconvert ! ximagesink"
#define SINK_NAME "ximagesink0"
#endif


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_pipeline = 0;
	m_transparentWidget = 0;
}

MainWindow::~MainWindow()
{
	if ( m_pipeline )
	{
		gst_element_set_state(m_pipeline, GST_STATE_NULL);
		gst_object_unref(m_pipeline);
	}
	delete ui;
}

void MainWindow::showEvent(QShowEvent *e)
{
	qDebug("[%s]", Q_FUNC_INFO);

	QMainWindow::showEvent(e);
}

void MainWindow::setupGStreamer()
{
	if ( ! m_pipeline )
	{
		// gstreamer
		m_pipeline = gst_parse_launch(PIPELINE_DESC, NULL);

		if ( m_pipeline )
		{
			qDebug("gstreamer pipeline ready");

			GstElement *video_sink;

			video_sink = gst_bin_get_by_name(GST_BIN(m_pipeline), SINK_NAME);
			if ( video_sink )
			{
				gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(video_sink), ui->widget_gst_video->winId());
				gst_object_unref(video_sink);
			}
		}
	}
}

void MainWindow::on_pushButton_play_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_pipeline )
		gst_element_set_state(m_pipeline, GST_STATE_PLAYING);
}

void MainWindow::on_pushButton_stop_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_pipeline )
		gst_element_set_state(m_pipeline, GST_STATE_PAUSED);
}

void MainWindow::on_pushButton_init_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);
	setupGStreamer();
}

void MainWindow::on_pushButton_overlay_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( ! m_transparentWidget )
	{
		qDebug("DBG new");
		m_transparentWidget = new TransparentWidget();
		Q_CHECK_PTR(m_transparentWidget);

	}

	if ( m_transparentWidget )
	{
		if ( m_transparentWidget->isVisible() )
		{
			qDebug("DBG Hide");
			m_transparentWidget->hide();
		}
		else
		{
			qDebug("DBG Show");
			m_transparentWidget->show();
		}
	}
}
