#ifndef TRANSPARENTWIDGET_H
#define TRANSPARENTWIDGET_H

#include <QWidget>

namespace Ui {
class TransparentWidget;
}

class TransparentWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TransparentWidget(QWidget *parent = 0);
	~TransparentWidget();

protected:
	virtual void showEvent(QShowEvent *e);

private slots:
	void on_pushButton_clicked();

private:
	Ui::TransparentWidget *ui;
};

#endif // TRANSPARENTWIDGET_H
