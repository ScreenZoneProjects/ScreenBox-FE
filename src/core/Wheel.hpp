#ifndef WHEEL_H
#define WHEEL_H

#include <QFileInfoList>
#include "Settings.hpp"
#include <QGraphicsItemGroup>

class Wheel : public QGraphicsItemGroup
{
public:
    Wheel(QFileInfoList list, Settings settings, QGraphicsItem * parent = 0);
private:
    Settings m_settings;
};

#endif // WHEEL_H
