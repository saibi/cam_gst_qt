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

void MainWindow::timerEvent(QTimerEvent *e)
{
	int elapsed = m_timer.elapsed();

	int counter = ui->widget_camera->counter();
	int counter2 = ui->widget_camera2->counter();

	QString msg_elapsed = QString("elapsed %1").arg(elapsed);
	QString msg_camera = QString("#1 counter %2(%3, %4fps)").arg(counter - prevCounter).arg(counter).arg(float(counter) / float(elapsed/1000));
	QString msg_camera2 = QString("#2 counter %2(%3, %4fps)").arg(counter2 - prevCounter2).arg(counter2).arg(float(counter2) / float(elapsed/1000));

	ui->statusBar->showMessage(msg_elapsed + "\t" + msg_camera + "\t" + msg_camera2);
	qDebug("DBG %s\t%s\t%s", qPrintable(msg_elapsed), qPrintable(msg_camera), qPrintable(msg_camera2));

	prevCounter = counter;
	prevCounter2 = counter2;

	QMainWindow::timerEvent(e);
}

CustomCameraWidget * MainWindow::cameraWidget(int no)
{
	if ( no == 0 )
		return ui->widget_camera;
	else
		return ui->widget_camera2;
}
