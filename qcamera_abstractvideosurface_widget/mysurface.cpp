#include "mysurface.h"

#include <QAbstractVideoSurface>

#include <QVideoSurfaceFormat>

MySurface::MySurface() : QAbstractVideoSurface(nullptr)
{
	m_widget = 0;
}

QList<QVideoFrame::PixelFormat> MySurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const
{
	QList<QVideoFrame::PixelFormat> list;

	qDebug("[%s] type %d", Q_FUNC_INFO, type);
	if ( type == QAbstractVideoBuffer::NoHandle )
	{
		list.append(QVideoFrame::Format_RGB565);
	}
	return list;
}

bool MySurface::present(const QVideoFrame &frame)
{
	qDebug("[%s] format %d, size (%d, %d)", Q_FUNC_INFO, frame.pixelFormat(), frame.size().width(), frame.size().height());

	if ( m_widget )
	{
		QVideoFrame f(frame);
		f.map(QAbstractVideoBuffer::ReadOnly);

		QImage img(f.bits(), f.width(), f.height(), f.bytesPerLine(), QImage::Format_RGB16);
		img = img.mirrored(true, true);

		m_widget->setImage(img);
	}
	return true;
}
