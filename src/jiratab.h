#ifndef lildevil_JIRATAB_H
#define lildevil_JIRATAB_H

#include "mainwindow.h"
#include "jiraissue.h"

#include <QSpacerItem>
#include <QLabel>
#include <QJsonArray>
#include <QUrlQuery>
#include <QSettings>

class JiraTab : public QWidget
{
    Q_OBJECT

public:
    explicit JiraTab(QWidget *parent = nullptr);
    ~JiraTab();

    JiraIssue *issue = nullptr;
    QComboBox *selectEpic;
    QComboBox *selectWeight;

    QLineEdit *issueTitle;
    QPlainTextEdit *issueDescription;

    QJsonObject epics;

    QPushButton *issueSubmit;
    QPushButton *issueCancel;

public slots:
    void onTextChanged(const QString& qString);
    void resetIssue();
    void submitIssue();

private:
    QSettings settings;
    void getWeights();
    void getEpics();
};


#endif //lildevil_JIRATAB_H
