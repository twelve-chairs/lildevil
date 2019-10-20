#ifndef lildevil_JIRAISSUE_H
#define lildevil_JIRAISSUE_H

#include <QString>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QListWidget>
#include <QAbstractSlider>
#include <QSettings>

class JiraIssue {
private:
    QSettings settings;

public:
    explicit JiraIssue();
    ~JiraIssue();

    QString getJsonString();
    void setTitle(QString&);
    void setDescription(QString&);
    void setEpic(QString&);

    const QString gitApiUrl = settings.value("gitApiUrl").toString();
    const QString jiraApiUrl = settings.value("jiraApiUrl").toString();

    QStringList weight = {"", "Small", "Medium", "Large", "XXL"};

    QString defaultSummary = settings.value("defaultSummary").toString();
    QString defaultDescription = settings.value("defaultDescription").toString();

    QJsonDocument doc;

    const QByteArray baseJson = settings.value("baseIssueObject").toByteArray();
};


#endif //lildevil_JIRAISSUE_H
