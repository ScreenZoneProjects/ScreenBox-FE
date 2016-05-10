#include "QuickFrontend.h"

#include "QuickScene.h"

#include <QXmlSchema>
#include <QFile>
#include <QApplication>
#include <QXmlSchemaValidator>
#include <QUrl>

#include <QDebug>

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
