#include "sharedviewfinder.h"

SharedViewFinder::SharedViewFinder() : QAbstractVideoSurface(nullptr)
{
	m_invert = false;
}

QList<QVideoFrame::PixelFormat> SharedViewFinder::supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const
{
	QList<QVideoFrame::PixelFormat> list;

	if ( type == QAbstractVideoBuffer::NoHandle )
	{
		list.append(QVideoFrame::Format_RGB32);
	}

	return list;
}

bool SharedViewFinder::present(const QVideoFrame &frame)
{
	QVideoFrame copy(frame);

	copy.map(QAbstractVideoBuffer::ReadOnly);
	QImage image(copy.bits(), copy.width(), copy.height(), copy.bytesPerLine(), QImage::Format_RGB32);
	copy.unmap();

	if ( m_invert )
	{
		QTransform transform;
		transform.rotate(90);
		image = image.transformed(transform);
	}

	emit signalFrameReady(QPixmap::fromImage(image));

	return true;
}
