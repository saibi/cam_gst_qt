#ifndef MYSURFACE_H
#define MYSURFACE_H

#include <QAbstractVideoSurface>
#include <QVideoWidget>

class MySurface : public QAbstractVideoSurface
{
	Q_OBJECT

public:
	MySurface();

	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const;
	bool present(const QVideoFrame &frame);

	void setVideoWidget(QVideoWidget *p) { m_videoWidget = p; }
private:

	QVideoWidget * m_videoWidget;
};

#endif // MYSURFACE_H
