#pragma once

#include <QtGlobal>

class CIndexable
{
public:
	CIndexable();

	qint64 getId() const;
	void setId(const qint64& i64Id);

private:
	qint64 m_i64Id;
};

