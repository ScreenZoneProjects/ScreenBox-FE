#include "QuickFrontend.h"

#include "QuickScene.h"

QuickFrontend::QuickFrontend(QQuickItem *parent)
    : QQuickItem(parent)
    , m_enterScene(0)
    , m_exitScene(0)
{
    m_sceneStack.clear();
}

QuickScene * QuickFrontend::currentScene() const
{
    if(m_sceneStack.isEmpty())
        return NULL;
    return m_sceneStack.top();
}

void QuickFrontend::setCurrentScene(QuickScene *currentScene)
{
    int stackSize = m_sceneStack.size();
    if (!currentScene)
        return;
    else if (stackSize > 0 && currentScene == m_sceneStack.top())
        return;
    else if (m_sceneStack.contains(currentScene)) {
        int index = m_sceneStack.indexOf(currentScene);
        m_sceneStack.removeAt(index);
        for (int i = index; i < stackSize - 1; i++) {
            m_sceneStack.at(i)->setZ(i);
        }
    }
    if (stackSize > 0)
        m_exitScene = m_sceneStack.pop();
    m_sceneStack.push(currentScene);
    currentScene->setZ(m_sceneStack.size());
    disableScene(m_exitScene);
    enableScene(currentScene);
}

void QuickFrontend::enableScene(QuickScene * scene)
{
    if (!scene)
        return;

    scene->setParentItem(this);
    scene->setVisible(true);
    scene->setRunning(true);
    scene->setEnabled(true);
    scene->setFocus(true, Qt::OtherFocusReason);
    emit currentSceneChanged();
}

void QuickFrontend::disableScene(QuickScene * scene)
{
    if (!scene)
        return;

    scene->setEnabled(false);
    scene->setRunning(false);
    scene->setFocus(false, Qt::OtherFocusReason);
}
