#pragma once

#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include "CPlatform.hpp"
#include "CGame.hpp"
#include "CRom.hpp"
#include "CManufacturer.hpp"
#include "CPlatform.hpp"

class CLocalDatabase
{
public:
	CLocalDatabase();

	// Structure representing descriptions tables
	struct SDescription
	{
		qint64 i64Id;
		QString sDescription;
		QLocale::Language eLanguage;
	};

	struct SObjectDescription
	{
		qint64 i64Id;
		qint64 i64ObjecId;
		qint64 i64DescriptionId;
	};

	// SQLite
	bool open();
	bool close();
	bool checkDatabaseIntegrity();

	bool addPlatformInformation(CPlatform &oPlatform);
	bool addGameInformation(CGame &game);
	bool addRomInformation(CRom &rom);

	bool loadLocalDatabase();

	bool getManufacturersList(QMap<qint64, CManufacturer*>& mpManufacturers);
	bool getPlatformsList(QMap<qint64, CPlatform*>& mpPlatforms, qint64 i64ManufacturerId = -1);
	bool getDevelopersList(QMap<qint64, CDeveloper*>& mpDevelopers);
	bool getGenresList(QMap<qint64, CGenre*>& mpGenres);
	bool getGamesList(QMap<qint64, CGame*>& mpGames);
	bool getRomsList(QMap<qint64, CRom*>& mpRoms);

	bool getLanguagesList(QMap<qint64, QLocale::Language>& moLanguagesTable);

	QLocale::Language databaseLanguageCodeToQLocale(QString sLanguageCode);

	bool getDescription(qint64 i64DescriptionId, CDescription& oDescription);
	bool getDescriptionsTable(QMap<qint64, SDescription> moDescriptions, const QMap<qint64, QLocale::Language>& moLanguagesTable);

	bool getObjectsDescriptions(QMap<qint64, SObjectDescription>& mObjectsDescriptions, const QString& sObjectTableName, const QString& sForeignKeyObjectName, qint64 i64ObjectId = -1);


	bool setDescriptions();
	bool setManufacturersDescriptions(QMap<qint64, CManufacturer*>& mpManufacturers,
									  const QMap<qint64, SObjectDescription>& moManufacturersDescriptions,
									  const QMap<qint64, SDescription>& moDescriptions);

	bool setPlatformsDescriptions(QMap<qint64, CPlatform*>& mpPlatforms,
								  const QMap<qint64, SObjectDescription>& moPlatformsDescriptions,
								  const QMap<qint64, SDescription>& moDescriptions);

	bool setDevelopersDescriptions(QMap<qint64, CDeveloper*>& mpDevelopers,
								   const QMap<qint64, SObjectDescription>& moDeveloperDescriptions,
								   const QMap<qint64, SDescription>& moDescriptions);

	bool setGamesDescriptions(QMap<qint64, CGame*>& mpGames,
							  const QMap<qint64, SObjectDescription>& moGamesDescriptions,
							  const QMap<qint64, SDescription>& moDescriptions);

	bool getObjectsDescriptions(QMap<qint64,SObjectDescription>& moObjectDescriptions, const QString& sObjectTableName, qint64 i64ObjectId = -1);

private:
	QString m_sLocalDatabaseFilePath;
	QSqlDatabase m_oSQLiteDatabase;

	// SQLite tables name
	static const QString s_sDescriptionsTable;
	static const QString s_sDevelopersTable;
	static const QString s_sDevelopersDescriptionsTable;
	static const QString s_sFranchisesTable;
	static const QString s_sRomsTable;
	static const QString s_sGamesTable;
	static const QString s_sGamesDescriptionsTable;
	static const QString s_sGamesGenresTable;
	static const QString s_sGamesLanguagesTable;
	static const QString s_sGenresTable;
	static const QString s_sGenresDescriptionsTable;
	static const QString s_sLanguagesTable;
	static const QString s_sManufacturersTable;
	static const QString s_sManufacturersDescriptionsTable;
	static const QString s_sPlatformsTable;
	static const QString s_sPlatformsDescriptionsTable;
	static const QString s_sRegionsTable;
};
