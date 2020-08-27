#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCamera>
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

private:
	Ui::MainWindow *ui;

	QCamera *m_camera;
	MySurface *m_surface;
};

#endif // MAINWINDOW_H
