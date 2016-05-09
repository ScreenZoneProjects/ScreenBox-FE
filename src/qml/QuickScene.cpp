#include "QuickScene.h"

QuickScene::QuickScene(QQuickItem * parent) : QQuickItem(parent), m_running(false)
{
    setVisible(false);
}

void QuickScene::setRunning(const bool &running)
{
    if (m_running == running)
        return;
    m_running = running;
    emit runningChanged();
}

bool QuickScene::running() const
{
    return m_running;
}
