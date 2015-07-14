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
	quint64 m_ui64Id; //< The unique ID of the rom file.

	quint64 m_ui64CRC; //< The CRC of the rom file.
	QByteArray m_vbMD5; //< The MD5 of the rom file
	QByteArray m_vbSHA1; //< The SHA1 of the rom file.
	quint64 m_ui64Size; //< The size of the rom file.

	bool m_bIsPrototype;
	bool m_bIsPirate;
	bool m_bIsTranslated;
	bool m_bIsDemo;
	bool m_bIsPrelease;
	bool m_bIsTrained;
};
