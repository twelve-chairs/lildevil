#ifndef lildevil_CONFIGDIALOG_H
#define lildevil_CONFIGDIALOG_H

#include <QSettings>
#include <QButtonGroup>
#include "mainwindow.h"

class ConfigTab : public QWidget
{
Q_OBJECT

private:
    QLineEdit *testUrl;
    QLineEdit *gitApiUrl;
    QLineEdit *jiraApiUrl;
    QLineEdit *jenkinsApiUrl;
    QLineEdit *defaultSummary;
    QLineEdit *defaultIssueWeight;
    QTextEdit *defaultDescription;
    QTextEdit *baseIssueObject;
    QSettings settings;

private slots:
    void cancelSettings();
    void updateSettings();

public:
    explicit ConfigTab(QWidget *parent = nullptr);
    ~ConfigTab();
};


#endif //lildevil_CONFIGDIALOG_H
