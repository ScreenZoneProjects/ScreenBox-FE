#ifndef QUICKSCENE_H
#define QUICKSCENE_H

#include <QQuickItem>

class QuickFrontend;

class QuickScene : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)
    Q_PROPERTY(QObject *enterAnimation READ enterAnimation WRITE setEnterAnimation NOTIFY enterAnimationChanged)
    Q_PROPERTY(QObject *exitAnimation READ exitAnimation WRITE setExitAnimation NOTIFY exitAnimationChanged)
public:
    explicit QuickScene(QuickFrontend * parent = 0);
    bool running() const;
    void setRunning(const bool &running);

    QObject *enterAnimation() const;
    void setEnterAnimation(QObject *animation);

    QObject *exitAnimation() const;
    void setExitAnimation(QObject *animation);
signals:
    void runningChanged();
    void enterAnimationChanged();
    void exitAnimationChanged();
private:
    bool m_running;
    QObject *m_enterAnimation;
    QObject *m_exitAnimation;
};

#endif // QUICKSCENE_H
