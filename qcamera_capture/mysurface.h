#ifndef MYSURFACE_H
#define MYSURFACE_H

#include <QAbstractVideoSurface>

#include "outputwidget.h"

class MySurface : public QAbstractVideoSurface
{
	Q_OBJECT

public:
	MySurface();

	QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type) const;
	bool present(const QVideoFrame &frame);

	void setOutputWidget(OutputWidget *p) { m_widget = p; }
private:

	OutputWidget * m_widget;
};

#endif // MYSURFACE_H
