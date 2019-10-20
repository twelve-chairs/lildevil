#ifndef lildevil_CONFIGDIALOG_H
#define lildevil_CONFIGDIALOG_H

#import <QSettings>
#import <QButtonGroup>
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
    QTextEdit *defaultDescription;
    QTextEdit *baseIssueObject;
    QLineEdit *defaultIssueWeight;

    QSettings settings;

private slots:
    void cancelSettings();
    void updateSettings();

public:
    explicit ConfigTab(QWidget *parent = nullptr);
    ~ConfigTab();
};


#endif //lildevil_CONFIGDIALOG_H
