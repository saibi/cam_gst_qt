#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Form)
{
	ui->setupUi(this);

	m_camera = 0;
}

Form::~Form()
{
	delete ui;
}

void Form::on_pushButton_clicked()
{
	qDebug("[%s]", Q_FUNC_INFO);

	if ( m_camera )
	{
		if ( m_camera->status() == QCamera::ActiveStatus )
		{
			qDebug("DBG stop camera");
			m_camera->stop();
			m_camera->unload();
		}
		else
		{
			qDebug("DBG start camera");
			m_camera->start();
		}
	}
}
