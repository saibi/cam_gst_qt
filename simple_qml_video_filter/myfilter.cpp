#include "myfilter.h"

QVideoFrame MyFilterRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags)
{
	if ( !input->isValid())
		return *input;

	qDebug("DBG surfaceFormat %d %dx%d, runflags %d", surfaceFormat.pixelFormat(), surfaceFormat.frameWidth(), surfaceFormat.frameHeight(), flags);

	// no convert function from NV12 to QImage
	// copy NV12 raw data as gray scale img
	input->map(QAbstractVideoBuffer::ReadOnly);
	QImage img(input->bits(), input->width(), input->height(), input->bytesPerLine(), QImage::Format_Grayscale8);
	input->unmap();

	img = img.convertToFormat(QImage::Format_RGB16);
	img = img.mirrored(false, true);
	img = img.scaled(64, 48);

	return QVideoFrame(img);
}
