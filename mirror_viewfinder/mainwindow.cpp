#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_counter = 0;

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
		QString msg = QString("elapsed %1, m_counter %2, %3 fps").arg(elapsed).arg(m_counter).arg(float(m_counter) / float(elapsed/1000));
		ui->statusBar->showMessage(msg);
		qDebug("DBG %s", qPrintable(msg));
	}
}

void MainWindow::slotFrameReady(QPixmap pixmap)
{
	if ( m_counter == 0 )
		m_time.start();

	++m_counter;

	ui->label1->setPixmap(pixmap);
	ui->label1->update();

	ui->label2->setPixmap(pixmap);
	ui->label2->update();
}
