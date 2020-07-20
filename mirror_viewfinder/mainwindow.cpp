#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::slotFrameReady(QPixmap pixmap)
{
	ui->label1->setPixmap(pixmap);
	ui->label1->update();

	ui->label2->setPixmap(pixmap);
	ui->label2->update();
}
