#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);


//	setWindowFlags(Qt::FramelessWindowHint);
//	setAttribute(Qt::WA_NoSystemBackground);
	setAttribute(Qt::WA_TranslucentBackground);
//	setAttribute(Qt::WA_PaintOnScreen);
//	setAttribute(Qt::WA_TransparentForMouseEvents);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);
}
