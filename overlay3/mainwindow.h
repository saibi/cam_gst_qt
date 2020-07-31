#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <gst/gst.h>
#include "transparentwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	virtual void showEvent(QShowEvent *e);

protected:
	void setupGStreamer();

private slots:
	void on_pushButton_play_clicked();

	void on_pushButton_stop_clicked();

	void on_pushButton_init_clicked();

	void on_pushButton_overlay_clicked();

private:
	Ui::MainWindow *ui;

	GstElement *m_pipeline;

	TransparentWidget *m_transparentWidget;
};

#endif // MAINWINDOW_H
