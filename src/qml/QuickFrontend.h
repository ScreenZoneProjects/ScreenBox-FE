#ifndef QUICKFRONTEND_H
#define QUICKFRONTEND_H

#include <QQuickItem>
#include <QMetaMethod>
#include <QStack>

class QuickScene;
class QXmlSchema;

class QuickFrontend : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QuickScene *currentScene READ currentScene WRITE setCurrentScene NOTIFY currentSceneChanged)
    Q_PROPERTY(QString currentDataName READ currentDataName WRITE setCurrentDataName NOTIFY currentDataNameChanged)
    Q_PROPERTY(DataType currentDataType READ currentDataType WRITE setCurrentDataType NOTIFY currentDataTypeChanged)
    Q_PROPERTY(QString nextDataName READ nextDataName WRITE setNextDataName NOTIFY nextDataNameChanged)
    Q_PROPERTY(DataType nextDataType READ nextDataType WRITE setNextDataType NOTIFY nextDataTypeChanged)
    Q_PROPERTY(QList<QString> dataPath READ dataPath WRITE setDataPath NOTIFY dataPathChanged)


public:
    explicit QuickFrontend(QQuickItem *parent = 0);

    enum DataType {
        InvalidType,
        MenuType,
        SystemType
    };
    Q_ENUMS(DataType)

    QuickScene *currentScene() const;
    void setCurrentScene(QuickScene *currentScene);

    QString currentDataName() const;
    void setCurrentDataName(QString currentDataName);

    DataType currentDataType() const;
    void setCurrentDataType(DataType currentDataType);

    QString nextDataName() const;
    void setNextDataName(QString nextDataName);

    DataType nextDataType() const;
    void setNextDataType(DataType nextDataType);

    QList<QString> dataPath() const;
    void setDataPath(QList<QString> dataPath);

    void enableScene(QuickScene * scene);
    void disableScene(QuickScene * scene);
    void attachScene(QuickScene * scene);
    QMetaMethod getMetaMethod(QObject * object, QString methodSignature) const;
    Q_INVOKABLE DataType isValidDatabase(QString database);
public slots:
    void handleEnterAnimationRunningChanged(bool running);
    void handleExitAnimationRunningChanged(bool running);
signals:
    void currentSceneChanged();
    void currentDataNameChanged();
    void currentDataTypeChanged();
    void nextDataNameChanged();
    void nextDataTypeChanged();
    void dataPathChanged();
private:
    QuickScene *m_enterScene;
    QuickScene *m_exitScene;
    QStack<QuickScene*> m_sceneStack;

    QString m_currentDataName;
    DataType m_currentDataType;
    QString m_nextDataName;
    DataType m_nextDataType;
    QList<QString> m_dataPath;

    QList<QString> m_validMenus;
    QList<QString> m_validSystems;
    QXmlSchema * m_menuSchema;
    QXmlSchema * m_systemSchema;

    bool triggerExitAnimation(QuickScene *scene);
    bool triggerEnterAnimation(QuickScene *scene);
};

#endif // QUICKFRONTEND_H
