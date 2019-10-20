#ifndef LILDEVIL_JENKINSTAB_H
#define LILDEVIL_JENKINSTAB_H

#include "mainwindow.h"
#include <QTreeWidget>
#include <QHeaderView>
#include <QListWidget>
#include <QSettings>

class JenkinsTab : public QWidget
{
    Q_OBJECT

public:
    explicit JenkinsTab(QWidget *parent = nullptr);
    ~JenkinsTab();

public slots:


private:
    QSettings settings;

};


#endif //LILDEVIL_JENKINSTAB_H
