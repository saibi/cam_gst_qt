#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gst/gst.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void setPipeline(GstElement *pipeline) { m_pipeline = pipeline; }

private slots:
	void on_pushButton_play_clicked();

	void on_pushButton_stop_clicked();

private:
	Ui::MainWindow *ui;

	GstElement *m_pipeline;
};

#endif // MAINWINDOW_H
