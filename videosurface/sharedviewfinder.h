#ifndef SHAREDVIEWFINDER_H
#define SHAREDVIEWFINDER_H

#include <QAbstractVideoSurface>
#include <QPixmap>

class SharedViewFinder : public QAbstractVideoSurface
{
	Q_OBJECT
public:
	SharedViewFinder();

	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const;
	bool present(const QVideoFrame &frame);

signals:
	void signalFrameReady(QPixmap);
};

#endif // SHAREDVIEWFINDER_H
