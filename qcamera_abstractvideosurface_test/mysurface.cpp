#include "mysurface.h"

#include <QAbstractVideoSurface>

#include <QVideoSurfaceFormat>

MySurface::MySurface() : QAbstractVideoSurface(nullptr)
{
	m_videoWidget = 0;
}

QList<QVideoFrame::PixelFormat> MySurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const
{
	QList<QVideoFrame::PixelFormat> list;

	qDebug("[%s] type %d", Q_FUNC_INFO, type);
	if ( type == QAbstractVideoBuffer::NoHandle )
	{
		list.append(QVideoFrame::Format_RGB32);
		//list.append(QVideoFrame::Format_NV12);
	}
	return list;
}

bool MySurface::present(const QVideoFrame &frame)
{
	static bool first = true;

	qDebug("[%s] format %d, size (%d, %d)", Q_FUNC_INFO, frame.pixelFormat(), frame.size().width(), frame.size().height());

	if ( m_videoWidget )
	{
		// m_videoWidget->videoSurface() : only for 5.15.x

		if ( first )
		{
			QVideoSurfaceFormat format(frame.size(), QVideoFrame::Format_RGB32); //frame.pixelFormat());
			m_videoWidget->videoSurface()->start(format);
			first = false;
		}

		QVideoFrame f(frame);
		f.map(QAbstractVideoBuffer::ReadOnly);

		QImage img = f.image(); // only for 5.15.x, old : QImage img(f.bits(), f.width(), f.height(), f.bytesPerLine(), QImage::Format_RGB32);
		img = img.mirrored(false, true);

		m_videoWidget->videoSurface()->present(QVideoFrame(img));
	}
	return true;
}
