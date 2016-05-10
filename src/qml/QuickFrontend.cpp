#include "QuickFrontend.h"

#include "QuickScene.h"

#include <QXmlSchema>
#include <QFile>
#include <QApplication>
#include <QXmlSchemaValidator>
#include <QUrl>
#include <QObject>

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
    else if (stackSize > 0 && currentScene->objectName() == m_sceneStack.top()->objectName())
        return;
    else if (m_sceneStack.contains(currentScene)) {
        int index = m_sceneStack.indexOf(currentScene);
        m_sceneStack.removeAt(index);
        for (int i = index; i < stackSize - 1; i++) {
            m_sceneStack.at(i)->setZ(i);
        }
    }
    if (stackSize > 0)
        m_exitScene = m_sceneStack.top();
    m_sceneStack.push(currentScene);
    currentScene->setZ(m_sceneStack.size());

    disableScene(m_exitScene);

    attachScene(currentScene);
    triggerExitAnimation(m_exitScene);
    if (!triggerEnterAnimation(currentScene)) {
        enableScene(currentScene);
        if (m_exitScene)
            m_exitScene->setVisible(false);
        m_exitScene = NULL;
    }
}

bool QuickFrontend::triggerExitAnimation(QuickScene *scene)
{
    if (!scene)
        return false;

    QObject * exitAnimation = scene->exitAnimation();

    if (!exitAnimation)
        return false;

    m_exitScene = scene;
    const QMetaObject *meta = exitAnimation->metaObject();
    int propIndex = meta->indexOfProperty("running");
    QMetaMethod exitSignal = meta->property(propIndex).notifySignal();
    connect(exitAnimation, exitSignal, this, getMetaMethod(this, "handleExitAnimationRunningChanged(bool)"));
    getMetaMethod(exitAnimation, "start()").invoke(exitAnimation, Qt::AutoConnection);
    return true;
}

void QuickFrontend::attachScene(QuickScene * scene)
{
    if (!scene) return;

    scene->setParentItem(this);
    scene->setVisible(true);
    scene->setRunning(false);
    scene->setEnabled(false);
    scene->setFocus(false, Qt::OtherFocusReason);
}

void QuickFrontend::enableScene(QuickScene * scene)
{
    if (!scene) return;

    scene->setParentItem(this);
    scene->setVisible(true);
    scene->setRunning(true);
    scene->setEnabled(true);
    scene->setFocus(true, Qt::OtherFocusReason);
    emit currentSceneChanged();
}

void QuickFrontend::disableScene(QuickScene * scene)
{
    if(!scene) return;

    scene->setRunning(false);
    scene->setEnabled(false);
    scene->setFocus(false, Qt::OtherFocusReason);
}

bool QuickFrontend::isValidDatabase(QString systemName)
{
    QXmlSchema databaseSchema;
    if (systemName == "Main Menu")
        databaseSchema.load(QUrl(QStringLiteral("qrc:/xsd/xsd/mainMenu.xsd")));
    else
        databaseSchema.load(QUrl(QStringLiteral("qrc:/xsd/xsd/systemMenu.xsd")));
    if (databaseSchema.isValid()) {
        QFile file(QApplication::applicationDirPath().remove(OSX_DIR_SUFFIX)+
                   "/Databases/"+systemName+"/"+systemName+".xml");
        if (file.exists()) {
            file.open(QIODevice::ReadOnly);
            QXmlSchemaValidator validator(databaseSchema);
            if (validator.validate(&file, QUrl::fromLocalFile(file.fileName())))
                return true;
        }
    }
    return false;
}



void QuickFrontend::handleExitAnimationRunningChanged(bool running)
{
    if (running) return;
    disconnect(sender(), 0, this, SLOT(handleExitAnimationRunningChanged(bool)));

    if (m_exitScene)
        m_exitScene->setVisible(false);
    m_exitScene = NULL;

    if (!m_sceneStack.isEmpty()) {
        if (!m_sceneStack.top()->running())
            enableScene(m_sceneStack.top());
    } else {
        emit currentSceneChanged();
    }
}

bool QuickFrontend::triggerEnterAnimation(QuickScene *scene)
{
    QObject *enterAnimation = scene->enterAnimation();
    if (!enterAnimation)
        return false;

    m_enterScene = scene;
    const QMetaObject *meta = enterAnimation->metaObject();
    int propIndex = meta->indexOfProperty("running");
    QMetaMethod enterSignal = meta->property(propIndex).notifySignal();
    connect(enterAnimation, enterSignal, this, getMetaMethod(this, "handleEnterAnimationRunningChanged(bool)"));
    getMetaMethod(enterAnimation, "start()").invoke(enterAnimation, Qt::AutoConnection);
    return true;
}

void QuickFrontend::handleEnterAnimationRunningChanged(bool running)
{
    if (running) return;
    disconnect(sender(), 0, this, SLOT(handleEnterAnimationRunningChanged(bool)));

    enableScene(m_enterScene);
    m_enterScene = NULL;

    if (m_exitScene)
        m_exitScene->setVisible(false);
}

QMetaMethod QuickFrontend::getMetaMethod(QObject * object, QString methodSignature) const
{
    int methodIndex = object->metaObject()->indexOfMethod(QMetaObject::normalizedSignature(methodSignature.toLocal8Bit()));

    if(!object || methodIndex == -1)
        return QMetaMethod();

    return object->metaObject()->method(methodIndex);
}
