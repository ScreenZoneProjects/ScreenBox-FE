#ifndef QUICKFRONTEND_H
#define QUICKFRONTEND_H

#include <QQuickItem>
#include <QStack>

class QuickScene;

class QuickFrontend : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QuickScene *currentScene READ currentScene WRITE setCurrentScene NOTIFY currentSceneChanged)

public:
    explicit QuickFrontend(QQuickItem *parent = 0);
    QuickScene *currentScene() const;
    void setCurrentScene(QuickScene *currentScene);
    void enableScene(QuickScene * scene);
    void disableScene(QuickScene * scene);
signals:
    void currentSceneChanged();
private:
    QuickScene *m_enterScene;
    QuickScene *m_exitScene;
    QStack<QuickScene*> m_sceneStack;
};

#endif // QUICKFRONTEND_H
