#pragma once

#include "CSystem.hpp"
#include "CPlatform.hpp"
#include "CGenre.hpp"
#include "CDeveloper.hpp"
#include "CManufacturer.hpp"
#include "CRegion.hpp"
#include "CFranchise.hpp"

#include <QLocale>
#include <QFileInfo>
#include <QVector>
#include <QDate>

class CGame
{

public:
	CGame();

private:
	quint64 m_ui64Id;
	QString m_sName;
	QString m_sSynopsis;

	CPlatform* m_pPlatform;

	CSystem m_oSystem;
	QVector<CGenre*> m_vpGenres;
	QVector<CGame*> m_vpCloneOf;

	CDeveloper* m_pDeveloper;
	CManufacturer* m_pManufacturer;

	CFranchise* m_pFranchise;
	QDate m_oDate;

	QVector<QLocale::Language> m_veLanguages;

	quint8 m_ui8Players;
};
