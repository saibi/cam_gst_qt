#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include <QWidget>
#include <QImage>

class OutputWidget : public QWidget
{
	Q_OBJECT
public:
	explicit OutputWidget(QWidget *parent = nullptr);

	void setImage(const QImage & img);

protected:
	void paintEvent(QPaintEvent *event);

signals:

public slots:

private:
	QImage m_image;
};

#endif // OUTPUTWIDGET_H
