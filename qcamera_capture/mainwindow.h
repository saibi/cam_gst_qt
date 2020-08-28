#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCamera>
#include <QCameraImageCapture>

#include "mysurface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void setupCamera();

private slots:
	void on_pushButton_capture_clicked();

private:
	Ui::MainWindow *ui;

	QCamera *m_camera;
	MySurface *m_surface;

	QCameraImageCapture *m_capture;
};


#endif // MAINWINDOW_H
