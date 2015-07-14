#include <QtDebug>

#include "CHyperSpinTheme.hpp"

CHyperSpinTheme::CHyperSpinTheme()
{

}

bool CHyperSpinTheme::parseATheme(QString sFilePath)
{
	QFile l_oFile(sFilePath);

	if(!l_oFile.open(QFile::ReadOnly| QFile::Text))
	{
		qWarning() << "Cannot open the HyperSpin theme file:" << sFilePath << ":" << l_oFile.errorString();
		return false;
	}

	QXmlStreamReader l_oXMLStreamReader;
	l_oXMLStreamReader.setDevice(&l_oFile);

	l_oXMLStreamReader.readNext();

	while (!l_oXMLStreamReader.atEnd())
	{
		if(l_oXMLStreamReader.isStartElement())
		{
			if(l_oXMLStreamReader.name() == "Theme")
			{
				l_oXMLStreamReader.readNext();

				while(l_oXMLStreamReader.isStartElement() ==false)
				{
					l_oXMLStreamReader.readNext();
				}

				if(l_oXMLStreamReader.name() == "video")
				{
					if(l_oXMLStreamReader.attributes().hasAttribute("w"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("h"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("x"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("y"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("r"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("rx"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("ry"))
					{
					}

					if(l_oXMLStreamReader.attributes().hasAttribute("below"))
					{
					}
				}

				if(l_oXMLStreamReader.name() == "artwork1")
				{
				}

				if(l_oXMLStreamReader.name() == "artwork2")
				{
				}

				if(l_oXMLStreamReader.name() == "artwork3")
				{
				}

				if(l_oXMLStreamReader.name() == "artwork4")
				{
				}

				if(l_oXMLStreamReader.name() == "particle")
				{
				}
			}
		}
		// do processing
	}

	l_oFile.close();


	if (l_oXMLStreamReader.hasError())
	{
		qWarning() << "Failed to parse the HyperSpin theme file:" << sFilePath << ":" << l_oXMLStreamReader.errorString();
		return false;
	}

	return true;
}
