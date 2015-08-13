#pragma once

#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QLocale>
#include <QFileInfo>
#include <QPixmap>
#include <QFont>

#include "CManufacturer.hpp"
#include "CHyperSpinTheme.hpp"

class CPlatform
{
public:
	CPlatform();

	quint32 getId() const;
	void setId(const quint32 &ui32Id);

	QString getName() const;
	void setName(const QString &sName);

	QString getDescription() const;
	void setDescription(const QString &sDescription);

private:
	quint32 m_ui32Id; //< Unique ID.
	QString m_sName; //
	QMap<QLocale::Language, QString> m_vsDescriptions; // Description of the platform.
	CManufacturer* m_pManufacturer;

	CHyperSpinTheme m_oHyperSpinTheme;

	QFileInfo m_oLogoImageFilePath;
	QPixmap m_oLogoImage;
	QVector<QPixmap> m_voArtworksImage;
	QVector<QPixmap> m_oBackgroundImages;

	QPixmap m_o2DCartbridge;


	QFont m_oFont;
};
