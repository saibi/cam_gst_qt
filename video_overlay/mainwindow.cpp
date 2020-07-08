#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <gst/video/videooverlay.h>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_pipeline = 0;
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
	setupGStreamer();
	QMainWindow::showEvent(e);
}

void MainWindow::setupGStreamer()
{
	if ( m_pipeline )
	{
		qDebug("DBG m_pipeline already set. reset pipeline.");

		gst_element_set_state(m_pipeline, GST_STATE_NULL);
		gst_object_unref(m_pipeline);

		m_pipeline = 0;
	}

	// gstreamer
	const char * desc;
#ifdef __RK3399__
	desc = "rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! kmssink render-rectangle=\"<400,100,320,240>\"";
#else
	desc = "videotestsrc ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! videoconvert ! ximagesink";
#endif

	m_pipeline = gst_parse_launch(desc, NULL);

	if ( m_pipeline )
	{
		qDebug("gstreamer pipeline ready");

		GstElement *video_sink;

		const char * sink_name;

#ifdef __RK3399__
		sink_name = "kmssink0";
#else
		sink_name = "ximagesink0";
#endif

		video_sink = gst_bin_get_by_name(GST_BIN(m_pipeline), sink_name);

		gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(video_sink), ui->widget_gst_video->winId());

		gst_object_unref(video_sink);
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
