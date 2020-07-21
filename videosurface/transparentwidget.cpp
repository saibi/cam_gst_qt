#include "transparentwidget.h"
#include "ui_transparentwidget.h"

TransparentWidget::TransparentWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TransparentWidget)
{
	ui->setupUi(this);
	//setAttribute(Qt::WA_TranslucentBackground);
}

TransparentWidget::~TransparentWidget()
{
	delete ui;
}

void TransparentWidget::on_pushButton_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);
}

void TransparentWidget::frameReady(QPixmap pixmap)
{
	ui->label->setPixmap(pixmap);
	ui->label->update();
}
