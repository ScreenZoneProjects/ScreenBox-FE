#pragma once

#include <QObject>
#include <QLocale>
#include <QFileInfo>
#include <QVector>
#include <QDate>

#include "CIndexable.hpp"

class CRom : public QObject, public CIndexable
{
	Q_OBJECT

	Q_PROPERTY(QString id READ getId)
	Q_PROPERTY(QString CRC READ getCRC)
	Q_PROPERTY(QString MD5 READ getMD5)
	Q_PROPERTY(QString SHA1 READ getSHA1)
	Q_PROPERTY(QString fileSize READ getFileSize)
	Q_PROPERTY(QString isPrototype READ isPrototype)
	Q_PROPERTY(QString isPirate READ isPirate)
	Q_PROPERTY(QString isTranslated READ isTranslated)
	Q_PROPERTY(QString isDemo READ isDemo)
	Q_PROPERTY(QString isPrelease READ isPrelease)
	Q_PROPERTY(QString isTrained READ isTrained)

public:
	explicit CRom(QObject *parent = 0);

	quint64 getCRC() const;
	void setCRC(const quint64& ui64CRC);

	QByteArray getMD5() const;
	void setMD5(const QByteArray& vbMD5);

	QByteArray getSHA1() const;
	void setSHA1(const QByteArray& vbSHA1);

	quint64 getFileSize() const;
	void setFileSize(const quint64& ui64Size);

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

	QFileInfo getFileInfo() const;

private:
	QFileInfo m_oFileInfo;

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

signals:

public slots:
};
