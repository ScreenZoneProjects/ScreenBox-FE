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

	quint64 getId() const;
	void setId(const quint64& ui64Id);

	quint64 getCRC() const;
	void setCRC(const quint64& ui64CRC);

	QByteArray getMD5() const;
	void setMD5(const QByteArray& vbMD5);

	QByteArray getSHA1() const;
	void setSHA1(const QByteArray& vbSHA1);

	quint64 getSize() const;
	void setSize(const quint64& ui64Size);

	bool isPrototype() const;
	void setIsPrototype(bool bIsPrototype);

	bool isPirate() const;
	void setIsPirate(bool bIsPirate);

	bool isTranslated() const;
	void setIsTranslated(bool bIsTranslated);

	bool isDemo() const;
	void setIsDemo(bool bIsDemo);

	bool isPrelease() const;
	void setIsPrelease(bool bIsPrelease);

	bool isTrained() const;
	void setIsTrained(bool bIsTrained);

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
