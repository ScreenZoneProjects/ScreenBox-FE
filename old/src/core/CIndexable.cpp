#include "CIndexable.hpp"

CIndexable::CIndexable():
	m_i64Id(-1)
{

}

qint64 CIndexable::getId() const
{
	return m_i64Id;
}

void CIndexable::setId(const qint64 &i64Id)
{
	m_i64Id = i64Id;
}
