#ifndef FORM_H
#define FORM_H

#include <QWidget>

#include <QCamera>

namespace Ui {
class Form;
}

class Form : public QWidget
{
	Q_OBJECT

public:
	explicit Form(QWidget *parent = 0);
	~Form();

	void setCamera(QCamera *cam) { m_camera = cam; }

private slots:
	void on_pushButton_clicked();

private:
	Ui::Form *ui;

	QCamera * m_camera;
};

#endif // FORM_H
