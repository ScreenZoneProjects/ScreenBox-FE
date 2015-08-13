#pragma once

#include "CSystem.hpp"
#include "CPlatform.hpp"
#include "CGenre.hpp"
#include "CDeveloper.hpp"
#include "CManufacturer.hpp"
#include "CRegion.hpp"
#include "CFranchise.hpp"
#include "CHyperSpinTheme.hpp"

#include <QLocale>
#include <QFileInfo>
#include <QVector>
#include <QDate>
#include <QMap>

/**
 * @brief The CGame class
 */
class CGame
{

public:
	CGame();

	quint64 getId() const;
	void setId(const quint64& ui64Id);

	QMap<QLocale::Language, QString> getNames() const;
	void setNames(const QMap<QLocale::Language, QString>& vsNames);

	QMap<QLocale::Language, QString> getSynopsis() const;
	void setSynopsis(const QMap<QLocale::Language, QString>& vsSynopsis);

	quint8 getPlayerCount() const;
	void setPlayerCount(const quint8& ui8PlayerCount);

private:
	quint64 m_ui64Id; //< Unique ID
	QMap<QLocale::Language, QString> m_vsNames; //< Name of the game

	QMap<QLocale::Language, QString> m_vsSynopsis; //< A short synopsis/brief of the game

	CPlatform* m_pPlatform;

	CSystem m_oSystem;
	QVector<CGenre*> m_vpGenres;
	QVector<CGame*> m_vpCloneOf;

	CDeveloper* m_pDeveloper;
	CManufacturer* m_pManufacturer;

	CFranchise* m_pFranchise;
	QDate m_oDate;

	QVector<QLocale::Language> m_veLanguages;

	quint8 m_ui8PlayerCount;

	CHyperSpinTheme m_oHyperSpinTheme;
};
