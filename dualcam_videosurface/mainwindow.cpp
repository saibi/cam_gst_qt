#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_counter = 0;
	m_time.start();
	startTimer(1000);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
	int elapsed = m_time.elapsed();

	if ( elapsed > 1000 )
	{
		QString msg = QString("elapsed %1, #1 m_counter %2, %3fps, #2 m_counter2 %4, %5fps").arg(elapsed).arg(m_counter).arg(float(m_counter) / float(elapsed/1000)).arg(m_counter2).arg(float(m_counter2) / float(elapsed/1000));
		ui->statusBar->showMessage(msg);
		qDebug("DBG %s", qPrintable(msg));
	}
}

void MainWindow::slotFrameReady(QPixmap pixmap)
{
	++m_counter;

	ui->label1->setPixmap(pixmap);
	ui->label1->update();
}

void MainWindow::slotFrame2Ready(QPixmap pixmap)
{
	++m_counter2;

	ui->label2->setPixmap(pixmap);
	ui->label2->update();
}
