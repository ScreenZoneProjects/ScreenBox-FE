#include "CRom.hpp"

CRom::CRom()
{

}
bool CRom::isTrained() const
{
	return m_bIsTrained;
}

void CRom::setIsTrained(bool bIsTrained)
{
	m_bIsTrained = bIsTrained;
}

bool CRom::isPrelease() const
{
	return m_bIsPrelease;
}

void CRom::setIsPrelease(bool bIsPrelease)
{
	m_bIsPrelease = bIsPrelease;
}

bool CRom::isDemo() const
{
	return m_bIsDemo;
}

void CRom::setIsDemo(bool bIsDemo)
{
	m_bIsDemo = bIsDemo;
}

bool CRom::isTranslated() const
{
	return m_bIsTranslated;
}

void CRom::setIsTranslated(bool bIsTranslated)
{
	m_bIsTranslated = bIsTranslated;
}

bool CRom::isPirate() const
{
	return m_bIsPirate;
}

void CRom::setIsPirate(bool bIsPirate)
{
	m_bIsPirate = bIsPirate;
}

bool CRom::isPrototype() const
{
	return m_bIsPrototype;
}

void CRom::setIsPrototype(bool bIsPrototype)
{
	m_bIsPrototype = bIsPrototype;
}

quint64 CRom::getSize() const
{
	return m_ui64Size;
}

void CRom::setSize(const quint64& ui64Size)
{
	m_ui64Size = ui64Size;
}

QByteArray CRom::getSHA1() const
{
	return m_vbSHA1;
}

void CRom::setSHA1(const QByteArray& vbSHA1)
{
	m_vbSHA1 = vbSHA1;
}

QByteArray CRom::getMD5() const
{
	return m_vbMD5;
}

void CRom::setMD5(const QByteArray& vbMD5)
{
	m_vbMD5 = vbMD5;
}

quint64 CRom::getCRC() const
{
	return m_ui64CRC;
}

void CRom::setCRC(const quint64& ui64CRC)
{
	m_ui64CRC = ui64CRC;
}

quint64 CRom::getId() const
{
	return m_ui64Id;
}

void CRom::setId(const quint64& ui64Id)
{
	m_ui64Id = ui64Id;
}

