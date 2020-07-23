#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_timer.start();
	startTimer(1000);

	prevCounter = 0;
	prevCounter2 = 0;
}

MainWindow::~MainWindow()
{
	delete ui;
}

#define FPS_QSTR(no, counter, prev, elapsed) QString::asprintf("#%d %d (%d, %.2ffps)", no, counter - prev, counter, (float(counter) / float(elapsed/1000)))

void MainWindow::timerEvent(QTimerEvent *e)
{
	int elapsed = m_timer.elapsed();

	if ( elapsed > 0 )
	{
		int counter = ui->widget_camera->counter();
		int counter2 = ui->widget_camera2->counter();

		QString msg = QString("elapsed %1").arg(elapsed) + "\t" + FPS_QSTR(1, counter, prevCounter, elapsed) + "\t" + FPS_QSTR(2, counter2, prevCounter2, elapsed);

		ui->statusBar->showMessage(msg);
		qDebug("DBG %s", qPrintable(msg));

		prevCounter = counter;
		prevCounter2 = counter2;
	}

	QMainWindow::timerEvent(e);
}

CustomViewFinder * MainWindow::cameraViewFinder(int no)
{
	if ( no == 0 )
		return ui->widget_camera->viewfinder();
	else
		return ui->widget_camera2->viewfinder();
}

void MainWindow::on_pushButton_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);
}
