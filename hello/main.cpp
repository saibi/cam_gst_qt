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

	const char * desc;
#ifdef __RK3399_MALI__
	desc = "rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! myfilter int=128 silent=true ! kmssink render-rectangle=\"<400,100,320,240>\"";
#elif defined (__RK3399_X11__)
	desc = "rkisp device=/dev/video0 io-mode=1 analyzer=1 enable-3a=1 ! video/x-raw,format=NV12,width=320,height=240,framerate=30/1 ! videoconvert ! xvimagesink";
#else
	desc = "videotestsrc ! video/x-raw,format=NV12,width=640,height=480,framerate=30/1 ! videoconvert ! autovideosink";
#endif

	pipeline = gst_parse_launch(desc, NULL);

	if ( pipeline )
		w.setPipeline(pipeline);

	int ret = a.exec();

	if ( pipeline )
	{
		gst_element_set_state(pipeline, GST_STATE_NULL);
		gst_object_unref(pipeline);
	}

	return ret;

}
