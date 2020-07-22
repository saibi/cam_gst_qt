#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void slotFrameReady(QPixmap pixmap);
	void slotFrame2Ready(QPixmap pixmap);

protected:
	void timerEvent(QTimerEvent *event);

private:
	Ui::MainWindow *ui;

	int m_counter;
	int m_counter2;

	QTime m_time;
};

#endif // MAINWINDOW_H
