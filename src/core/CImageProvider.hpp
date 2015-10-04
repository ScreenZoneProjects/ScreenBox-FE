#pragma once

#include <QQuickImageProvider>
#include <QImage>

class CImageProvider : public QQuickImageProvider
{
public:
	CImageProvider(): QQuickImageProvider(QQuickImageProvider::Pixmap)
	{

	}

	QImage requestImage(const QString& sId, QSize* pSize, const QSize& requestedSize, bool bRequestedAutoTransform);

	QPixmap requestPixmap(const QString& sId, QSize* pSize, const QSize& requestedSize, bool bRequestedAutoTransform);

	QQuickTextureFactory * requestTexture(const QString& sId, QSize* pSize, const QSize & requestedSize, bool bRequestedAutoTransform);

signals:

public slots:
};
