#pragma once

#include <QLocale>
#include <QFileInfo>
#include <QVector>
#include <QDate>

class CRom
{
public:
	CRom();

	QFileInfo m_oFileInfo;

private:
	quint64 m_ui64Id;


	quint64 m_ui64CRC;
	QByteArray m_vbMD5;
	QByteArray m_vbSHA1;
	quint64 m_ui64Size;

	bool m_bIsPrototype;
	bool m_bIsPirate;
	bool m_bIsTranslated;
	bool m_bIsDemo;
	bool m_bIsPrelease;
	bool m_bIsTrained;
};
