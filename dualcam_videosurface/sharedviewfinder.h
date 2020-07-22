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

	void setInvert(bool invert = true) { m_invert = invert; }

signals:
	void signalFrameReady(QPixmap);

private:
	bool m_invert;
};

#endif // SHAREDVIEWFINDER_H
