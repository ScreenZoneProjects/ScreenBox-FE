/*
*      Copyright (C) 2015 Team ScreenZone
*      http://screenzone.fr
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#pragma once

#include "CPlatform.hpp"
#include "CFranchise.hpp"
#include "CDeveloper.hpp"
#include "CGenre.hpp"
#include "CManufacturer.hpp"
#include "CRom.hpp"
#include "CGame.hpp"

class CFrontend
{

public:
	CFrontend();

	bool initialize();

	bool reload();

private:
	QMap<qint64, CPlatform*> m_mpPlateforms;
	QMap<qint64, CFranchise*> m_mpFranchise;
	QMap<qint64, CDeveloper*> m_mpDevelopers;
	QMap<qint64, CGenre*> m_mpGenres;
	QMap<qint64, CManufacturer*> m_mpManufacturers;
	QMap<qint64, CRom*> m_mpRoms;
	QMap<qint64, CGame*> m_mpGames;
};
