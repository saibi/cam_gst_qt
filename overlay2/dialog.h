#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <gst/gst.h>

#include "transparentwidget.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit Dialog(QWidget *parent = 0);
	~Dialog();

	virtual void showEvent(QShowEvent *e);

protected:
	void setupGStreamer();

private slots:
	void on_pushButton_play_clicked();

	void on_pushButton_stop_clicked();

	void on_pushButton_video_clicked();

private:
	Ui::Dialog *ui;

	GstElement *m_pipeline;

	TransparentWidget *m_transparentWidget;

};

#endif // DIALOG_H
