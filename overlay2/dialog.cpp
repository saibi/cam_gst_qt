#include "dialog.h"
#include "ui_dialog.h"

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

Dialog::Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Dialog)
{
	ui->setupUi(this);

	m_pipeline = 0;
}


Dialog::~Dialog()
{
	if ( m_pipeline )
	{
		gst_element_set_state(m_pipeline, GST_STATE_NULL);
		gst_object_unref(m_pipeline);
	}

	delete ui;
}

void Dialog::showEvent(QShowEvent *e)
{
	setupGStreamer();
	QDialog::showEvent(e);
}

void Dialog::setupGStreamer()
{
	if ( m_pipeline )
	{
		qDebug("DBG m_pipeline already set. reset pipeline.");

		gst_element_set_state(m_pipeline, GST_STATE_NULL);
		gst_object_unref(m_pipeline);

		m_pipeline = 0;
	}

	// gstreamer
    m_pipeline = gst_parse_launch(PIPELINE_DESC, NULL);

	if ( m_pipeline )
	{
		qDebug("gstreamer pipeline ready");

		GstElement *video_sink;

        video_sink = gst_bin_get_by_name(GST_BIN(m_pipeline), SINK_NAME);

		gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(video_sink), ui->widget_gst_video->winId());

		gst_object_unref(video_sink);
	}

}

void Dialog::on_pushButton_play_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_pipeline )
		gst_element_set_state(m_pipeline, GST_STATE_PLAYING);
}

void Dialog::on_pushButton_stop_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_pipeline )
		gst_element_set_state(m_pipeline, GST_STATE_PAUSED);
}

void Dialog::on_pushButton_video_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);
}
