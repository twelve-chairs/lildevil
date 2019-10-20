//
// Created by VokamisAir on 9/29/19.
//

#ifndef lildevil_GITHUBTAB_H
#define lildevil_GITHUBTAB_H

#include "mainwindow.h"
#include <QLineEdit>
#include <QGroupBox>
#include <QTreeWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QListWidget>
#include <QtConcurrent>
#include <QSettings>
#include <QFuture>
#include <QThreadPool>

class GithubTab : public QWidget
{
    Q_OBJECT
public:
    explicit GithubTab(QWidget *parent = nullptr);
    ~GithubTab();
    QTreeWidget *table;
    QTreeWidget *table2;
    QTextEdit *table4;
    QListWidget *reposList;
    QFuture<QString> future;
    QFutureWatcher<QString> futureWatcher;
//    static QString futureResponse;

private:
    QSettings settings;
    QStringList repos;
    void getRepos();
    QString postGitHub(const QString&, const QList<QMap<QString, QString>>&, const QString&);

private slots:
    void updateActivityMonitor(const QFuture<QString>&);
    void updateActivityMonitor(const QString&);
    void lockMaster();
    void lockQa();
    void lockDev();
    void unlockDev();
    void listRepos();
    void newRepo();
    void tuneUp();
    void something();
    void rebase();
};


#endif //lildevil_GITHUBTAB_H
