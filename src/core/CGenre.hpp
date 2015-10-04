#pragma once

#include <QObject>
#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QLocale>

#include "CIndexable.hpp"

class CGame;

class CGenre : public QObject, public CIndexable
{
	Q_OBJECT

	Q_PROPERTY(QString id READ getId)

public:
	explicit CGenre(QObject *parent = 0);

	QString getName() const;
	void setName(const QString& sName);

	QString getDescription(QLocale::Language eLanguage) const;
	void setDescription(QLocale::Language eLanguage, QString sDescription);

private:
	QString m_sName;
	QMap<QLocale::Language, QString> m_vsDescriptions;

	QList<CGame*> m_vpGames;

signals:
	void playerCountChanged();

public slots:
};
