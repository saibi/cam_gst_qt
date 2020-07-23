#ifndef CUSTOMCAMERAWIDGET_H
#define CUSTOMCAMERAWIDGET_H

#include <QWidget>

class CustomCameraWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CustomCameraWidget(QWidget *parent = nullptr);

	int counter() { return m_counter; }

protected:
	void paintEvent(QPaintEvent *event);

signals:

public slots:
	void slotFrameReady(const QPixmap& pixmap);

private:
	QPixmap m_pixmap;
	int m_counter;



};

#endif // CUSTOMCAMERAWIDGET_H
