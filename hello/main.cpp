#include "mainwindow.h"
#include <QApplication>

#include <gst/gst.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();


	// gstreamer

	GstElement *pipeline;

	gst_init(&argc, &argv);

	char * desc;
#ifdef __RK3399__
	desc = "rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=640,height=480,framerate=30/1 ! kmssink render-rectangle='<10, 10, 320, 240>'";
#else
	desc = "videotestsrc ! video/x-raw,format=NV12,width=640,height=480,framerate=30/1 ! videoconvert ! autovideosink";
#endif

	pipeline = gst_parse_launch(desc, NULL);

	gst_element_set_state(pipeline, GST_STATE_PLAYING);

	a.exec();

	gst_element_set_state(pipeline, GST_STATE_NULL);
	gst_object_unref(pipeline);

	return 0;
}
