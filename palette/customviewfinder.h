#ifndef CUSTOMVIEWFINDER_H
#define CUSTOMVIEWFINDER_H

#include <QAbstractVideoSurface>
#include <QPixmap>

class CustomViewFinder : public QAbstractVideoSurface
{
	Q_OBJECT
public:
	CustomViewFinder();

	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const;
	bool present(const QVideoFrame &frame);

signals:
	void signalFrameReady(QPixmap);

};

#endif // CUSTOMVIEWFINDER_H
