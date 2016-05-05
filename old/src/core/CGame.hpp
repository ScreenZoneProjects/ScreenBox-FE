#pragma once

#include "CGenre.hpp"
#include "CDeveloper.hpp"
#include "CRegion.hpp"
#include "CFranchise.hpp"
#include "CDescription.hpp"

#include "CHyperSpinTheme.hpp"
#include "CIndexable.hpp"

#include <QObject>
#include <QLocale>
#include <QFileInfo>
#include <QVector>
#include <QDate>
#include <QMap>
#include <QPixmap>
#include <QPointer>

class CGame : public QObject, public CIndexable
{
	Q_OBJECT

	Q_PROPERTY(QString id READ getId)
	Q_PROPERTY(QString playersCount READ getPlayerCount)
	//Q_PROPERTY(QString name READ getName)

public:
	explicit CGame(QObject *parent = 0);

	QMap<QLocale::Language, QString> getNames() const;
	void setNames(const QMap<QLocale::Language, QString>& vsNames);

	quint8 getPlayerCount() const;
	void setPlayerCount(const quint8& ui8PlayerCount);

private:
	QMap<QLocale::Language, QString> m_vsNames; //< Name of the game

	CDescription m_vsSynopsis; //< A short synopsis/brief of the game

	QList<QPointer<CGenre>> m_vpGenres;
	QList<QPointer<CDeveloper>> m_vpDevelopers;
	QList<QPointer<CFranchise>> m_vpFranchises;

	QDate m_oDate;

	QList<QLocale::Language> m_veLanguages;

	quint8 m_ui8PlayerCount;

	CHyperSpinTheme m_oHyperSpinTheme;

	QPixmap m_o2DCover;
	QPixmap m_o3DCover;

signals:

public slots:

};
