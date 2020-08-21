#include "customviewfinder.h"

CustomViewFinder::CustomViewFinder() : QAbstractVideoSurface(nullptr)
{
}

QList<QVideoFrame::PixelFormat> CustomViewFinder::supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const
{
	QList<QVideoFrame::PixelFormat> list;

	qDebug("DBG [%s] type %d", Q_FUNC_INFO, type);
	if ( type == QAbstractVideoBuffer::NoHandle )
	{
		list.append(QVideoFrame::Format_RGB32);
	}

	return list;
}

bool CustomViewFinder::present(const QVideoFrame &frame)
{
	QVideoFrame copy(frame);

	copy.map(QAbstractVideoBuffer::ReadOnly);
	QImage image(copy.bits(), copy.width(), copy.height(), copy.bytesPerLine(), QImage::Format_RGB32);
	copy.unmap();

	emit signalFrameReady(QPixmap::fromImage(image));
	return true;
}
