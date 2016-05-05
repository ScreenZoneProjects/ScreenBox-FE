#pragma once

#include <QFileInfo>

class CCommonTool
{
public:
	static bool checkVideoCompatibility(const QFileInfo& oFileInfo);
	static bool checkImageCompatibility(const QFileInfo& oFileInfo);

private:

	static const QMap<QString, QString> m_mVideoFormat;
	static const QMap<QString, QString> m_mImageFormat;
};
