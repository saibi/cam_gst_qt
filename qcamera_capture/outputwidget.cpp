#include "outputwidget.h"
#include <QPainter>

OutputWidget::OutputWidget(QWidget *parent) : QWidget(parent)
{
}

void OutputWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);

	p.drawImage( (rect().bottomRight() - m_image.rect().bottomRight())/2, m_image); // draw center

	QWidget::paintEvent(event);
}

void OutputWidget::setImage(const QImage &img)
{
	m_image = img;
	update();
}
