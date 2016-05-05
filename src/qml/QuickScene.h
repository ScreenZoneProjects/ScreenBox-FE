#ifndef QUICKSCENE_H
#define QUICKSCENE_H

#include <QQuickItem>

class QuickScene : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)
public:
    explicit QuickScene(QQuickItem * parent = 0);
    bool running() const;
    void setRunning(const bool &running);
signals:
    void runningChanged();
private:
    bool m_running;
};

#endif // QUICKSCENE_H
