#ifndef CUSTOMVIEWFINDERWIDGET_H
#define CUSTOMVIEWFINDERWIDGET_H

#include <QWidget>
#include <QPixmap>

#include "customviewfinder.h"

class CustomViewFinderWidget : public QWidget
{
	Q_OBJECT
public:
	CustomViewFinderWidget(QWidget *parent = nullptr);

	CustomViewFinder * viewfinder() { return &m_viewfinder; }

	unsigned int counter() { return m_counter; }

protected:
	void paintEvent(QPaintEvent *event);

protected slots:
	void slotFrameReady(const QPixmap & pixmap);

private:
	unsigned int m_counter;
	QPixmap m_pixmap;
	CustomViewFinder m_viewfinder;
};

#endif // CUSTOMVIEWFINDERWIDGET_H
