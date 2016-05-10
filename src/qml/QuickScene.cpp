#include "QuickScene.h"

#include "QuickFrontend.h"

QuickScene::QuickScene(QuickFrontend * parent)
    : QQuickItem(parent)
    , m_running(false)
    , m_enterAnimation(0)
    , m_exitAnimation(0)
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

QObject * QuickScene::enterAnimation() const
{
    return m_enterAnimation;
}

void QuickScene::setEnterAnimation(QObject *animation)
{
    const QMetaObject *meta = animation->metaObject();
    do{
        if(QString("QQuickAbstractAnimation") == QString::fromLocal8Bit(meta->className())){
            m_enterAnimation = animation;
            break;
        }
    }
    while( (meta = meta->superClass()) != 0);
}

QObject * QuickScene::exitAnimation() const
{
    return m_exitAnimation;
}

void QuickScene::setExitAnimation(QObject *animation)
{
    const QMetaObject *meta = animation->metaObject();
    do{
        if(QString("QQuickAbstractAnimation") == QString::fromLocal8Bit(meta->className())){
            m_enterAnimation = animation;
            break;
        }
    }
    while( (meta = meta->superClass()) != 0);
}
