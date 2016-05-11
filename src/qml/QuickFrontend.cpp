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
    , m_menuSchema(0)
    , m_systemSchema(0)
{
    m_sceneStack.clear();

    m_menuSchema = new QXmlSchema();
    m_systemSchema = new QXmlSchema();

    m_menuSchema->load(QUrl(QStringLiteral("qrc:/xsd/xsd/mainMenu.xsd")));
    m_systemSchema->load(QUrl(QStringLiteral("qrc:/xsd/xsd/systemMenu.xsd")));
}

QString QuickFrontend::currentDataName() const
{
    return m_currentDataName;
}

QuickFrontend::DataType QuickFrontend::currentDataType() const
{
    return m_currentDataType;
}

QString QuickFrontend::nextDataName() const
{
    return m_nextDataName;
}

QuickFrontend::DataType QuickFrontend::nextDataType() const
{
    return m_nextDataType;
}

void QuickFrontend::setCurrentDataName(QString currentDataName)
{
    m_currentDataName = currentDataName;
}

void QuickFrontend::setCurrentDataType(DataType currentDataType)
{
    m_currentDataType = currentDataType;
}

void QuickFrontend::setNextDataName(QString nextDataName)
{
    m_nextDataName = nextDataName;
}

void QuickFrontend::setNextDataType(DataType nextDataType)
{
    m_nextDataType = nextDataType;
}

QList<QString> QuickFrontend::dataPath() const
{
    return m_dataPath;
}

void QuickFrontend::setDataPath(QList<QString> dataPath)
{
    m_dataPath = dataPath;
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

QuickFrontend::DataType QuickFrontend::isValidDatabase(QString systemName)
{
    if (m_validMenus.contains(systemName))
        return DataType::MenuType;

    if (m_validSystems.contains(systemName))
        return DataType::SystemType;

    QFile xmlFile(QApplication::applicationDirPath().remove(OSX_DIR_SUFFIX)+
                  "/Databases/"+systemName+"/"+systemName+".xml");

    if (!xmlFile.exists())
        return DataType::InvalidType;

    xmlFile.open(QIODevice::ReadOnly);

    QXmlSchemaValidator systemValidator(*m_systemSchema);
    QXmlSchemaValidator menuValidator(*m_menuSchema);

    bool isMenu = menuValidator.validate(&xmlFile, QUrl::fromLocalFile(xmlFile.fileName()));
    bool isSystem = systemValidator.validate(&xmlFile, QUrl::fromLocalFile(xmlFile.fileName()));

    if (isMenu)
    {
        m_validMenus.append(systemName);
        return DataType::MenuType;
    }
    else if (isSystem)
    {
        m_validSystems.append(systemName);
        return DataType::SystemType;
    }
    else
        return DataType::InvalidType;
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
