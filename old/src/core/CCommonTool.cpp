#include "CCommonTool.hpp"

#include <QMapIterator>

const QMap<QString, QString> CCommonTool::m_mVideoFormat{
	{"webm", "WebM"},
	{"mkv", "Matroska"},
	{"flv", "Flash Video"},
	{"avi", "Audio Video Interleave"},
	{"mov", "QuickTime File Format"},
	{"wmv", "Windows Media Video"},
	{"mp4", "MPEG-4 Part 14"}
};

bool CCommonTool::checkVideoCompatibility(const QFileInfo& oFileInfo)
{
	QString m_oFileInfoSuffix = oFileInfo.completeSuffix();

	QMapIterator<QString, QString> l_iMapIterator(m_mVideoFormat);

	while (l_iMapIterator.hasNext())
	{
		l_iMapIterator.next();

		if(l_iMapIterator.key() == m_oFileInfoSuffix)
		{
			return true;
		}
	}

	return false;
}

const QMap<QString, QString> CCommonTool::m_mImageFormat{
	{"png", "Portable Network Graphics"},
	{"jpeg", "Joint Photographic Experts Group"},
	{"jpg", "Joint Photographic Experts Group"},
	{"bmp", "Windows Bitmap"},
	{"gif", "Graphic Interchange Format"},
	{"svg", "Scalable Vector Graphics"}
};

bool CCommonTool::checkImageCompatibility(const QFileInfo& oFileInfo)
{
	QString m_oFileInfoSuffix = oFileInfo.completeSuffix();

	QMapIterator<QString, QString> l_iMapIterator(m_mImageFormat);

	while (l_iMapIterator.hasNext())
	{
		l_iMapIterator.next();

		if(l_iMapIterator.key() == m_oFileInfoSuffix)
		{
			return true;
		}
	}

	return false;
}
