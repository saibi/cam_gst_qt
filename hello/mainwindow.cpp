#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_pipeline = 0;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_play_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_pipeline )
		gst_element_set_state(m_pipeline, GST_STATE_PLAYING);
}

void MainWindow::on_pushButton_stop_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_pipeline )
		gst_element_set_state(m_pipeline, GST_STATE_PAUSED);

}
