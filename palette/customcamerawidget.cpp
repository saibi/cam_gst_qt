#include "customcamerawidget.h"

#include <QPainter>

CustomCameraWidget::CustomCameraWidget(QWidget *parent) : QWidget(parent)
{
	m_counter = 0;
}

void CustomCameraWidget::slotFrameReady(const QPixmap &pixmap)
{
	m_pixmap = pixmap;
	++m_counter;
	update();
}

void CustomCameraWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.drawPixmap( (rect().bottomRight() - m_pixmap.rect().bottomRight()) / 2, m_pixmap); // draw center
	QWidget::paintEvent(event);
}
