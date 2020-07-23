#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include "customcamerawidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	CustomCameraWidget * cameraWidget(int no);

protected:
	void timerEvent(QTimerEvent *e);

private:
	Ui::MainWindow *ui;

	QTime m_timer;

	int prevCounter;
	int prevCounter2;
};

#endif // MAINWINDOW_H
