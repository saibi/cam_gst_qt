#include "customviewfinderwidget.h"
#include <QPainter>

CustomViewFinderWidget::CustomViewFinderWidget(QWidget *parent) : QWidget(parent)
{
	m_counter = 0;
	connect(&m_viewfinder, &CustomViewFinder::signalFrameReady, this, &CustomViewFinderWidget::slotFrameReady);
}

void CustomViewFinderWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.drawPixmap( (rect().bottomRight() - m_pixmap.rect().bottomRight()) / 2, m_pixmap); // draw center
	QWidget::paintEvent(event);
}

void CustomViewFinderWidget::slotFrameReady(const QPixmap& pixmap)
{
	m_pixmap = pixmap;
	++m_counter;
	update();
}
