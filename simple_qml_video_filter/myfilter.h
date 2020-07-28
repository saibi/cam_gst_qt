#ifndef MYFILTER_H
#define MYFILTER_H

#include <QVideoFilterRunnable>
#include <QAbstractVideoFilter>

class MyFilter;

class MyFilterRunnable : public QVideoFilterRunnable
{
public:
	MyFilterRunnable(MyFilter *filter) : m_filter(filter) {}

	QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);

private:
	MyFilter *m_filter;
};

class MyFilter : public QAbstractVideoFilter
{
public:
	QVideoFilterRunnable * createFilterRunnable() { return new MyFilterRunnable(this); }

signals:
	void finished(QObject *result);
};

#endif // MYFILTER_H
