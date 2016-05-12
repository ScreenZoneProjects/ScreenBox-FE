#pragma once

#include <QObject>
#include <QtGlobal>
#include <QString>
#include <QList>
#include <QPointer>

#include "CPlatform.hpp"
#include "CIndexable.hpp"

class CManufacturer : public QObject, public CIndexable
{
	Q_OBJECT

public:
	explicit CManufacturer(QObject *parent = 0);

	QString getName() const;
	void setName(const QString& sName);

	CDescription& getDescriptionReference();

private:
	QString m_sName;
	CDescription m_oDescription;

	QMap<qint64, CPlatform*> m_mpPlatforms;

	// Logos
	QFileInfo m_oLogoColorImageFilePath;
	QFileInfo m_oLogoMonochromeImageFilePath;

signals:

public slots:
};
