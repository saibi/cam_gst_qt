#include "myfilter.h"
#include <private/qvideoframe_p.h>

QVideoFrame MyFilterRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags)
{
	if ( !input->isValid())
		return *input;

	qDebug("DBG surfaceFormat %d %dx%d, runflags %d", surfaceFormat.pixelFormat(), surfaceFormat.frameWidth(), surfaceFormat.frameHeight(), int(flags) );

	QImage img = qt_imageFromVideoFrame(*input);

	qDebug("DBG img format %d", img.format());

	img = img.scaled(64, 48);
	img = img.mirrored(false, true);

	return QVideoFrame(img);
}
