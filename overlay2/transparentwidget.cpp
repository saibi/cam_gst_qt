#include "transparentwidget.h"
#include "ui_transparentwidget.h"

TransparentWidget::TransparentWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TransparentWidget)
{
	ui->setupUi(this);

	// transparent widget test

	setAttribute(Qt::WA_TranslucentBackground);

//	ui->widget_over->setWindowFlags(Qt::FramelessWindowHint);
//	ui->widget_over->setAttribute(Qt::WA_NoSystemBackground);
//	ui->widget_over->setAttribute(Qt::WA_TranslucentBackground);
//	ui->widget_over->setAttribute(Qt::WA_PaintOnScreen);
//	ui->widget_over->setAttribute(Qt::WA_TransparentForMouseEvents);

//	ui->widget_over->setStyleSheet("background-color: rgba(0,0,0,0)");
//	ui->label_hello->setStyleSheet("background-color: rgba(0,0,0,0)");


//	ui->widget_over->setAttribute(Qt::WA_TranslucentBackground, true);
//	ui->widget_over->setAttribute( Qt::WA_NoSystemBackground, true );
//	ui->widget_over->setAttribute( Qt::WA_OpaquePaintEvent, false );

//	ui->widget_over->setGeometry( ui->widget_gst_video->geometry() );

}

TransparentWidget::~TransparentWidget()
{
	delete ui;
}

void TransparentWidget::on_pushButton_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);
}

void TransparentWidget::showEvent(QShowEvent *e)
{
	qDebug("[%s]", Q_FUNC_INFO);

	QWidget::showEvent(e);
}
