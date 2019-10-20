//
// Created by VokamisAir on 9/29/19.
//

#include "jiratab.h"
#include "configdialog.h"

ConfigTab::ConfigTab(QWidget *parent) : QWidget(parent) {
    auto mainlayout = new QVBoxLayout();

    auto *group = new QGroupBox("Settings and Configuration");
    auto hlayout = new QGridLayout();
    hlayout->setRowStretch(0,0);
    hlayout->setRowStretch(1,0);
    hlayout->setRowStretch(2,0);
    hlayout->setRowStretch(3,1);

    auto box1 = new QWidget();
    auto vlayout1 = new QHBoxLayout();
    auto *comingSoon = new QLabel("Test URL");
    comingSoon->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vlayout1->addWidget(comingSoon, 1);
    testUrl = new QLineEdit();
    testUrl->setMinimumWidth(400);
    vlayout1->addWidget(testUrl, 1);
    box1->setLayout(vlayout1);
    hlayout->addWidget(box1, 0, 0);


    auto box2 = new QWidget();
    auto vlayout2 = new QHBoxLayout();
    auto *comingSoon2 = new QLabel("GitHub API:");
    comingSoon2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vlayout2->addWidget(comingSoon2, 1);
    gitApiUrl = new QLineEdit();
    gitApiUrl->setMinimumWidth(400);
    vlayout2->addWidget(gitApiUrl, 1);
    box2->setLayout(vlayout2);
    hlayout->addWidget(box2, 0, 1);

    auto box3 = new QWidget();
    auto vlayout3 = new QHBoxLayout();
    auto *comingSoon3 = new QLabel("Jira API:");
    comingSoon3->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vlayout3->addWidget(comingSoon3, 1);
    jiraApiUrl = new QLineEdit();
    jiraApiUrl->setFixedWidth(400);
    vlayout3->addWidget(jiraApiUrl, 1);
    box3->setLayout(vlayout3);
    hlayout->addWidget(box3, 1, 0);

    auto box4 = new QWidget();
    auto vlayout4 = new QHBoxLayout();
    auto *comingSoon4 = new QLabel("Jenkins API:");
    comingSoon4->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vlayout4->addWidget(comingSoon4, 1);
    jenkinsApiUrl = new QLineEdit();
    jenkinsApiUrl->setMinimumWidth(400);
    vlayout4->addWidget(jenkinsApiUrl, 1);
    box4->setLayout(vlayout4);
    hlayout->addWidget(box4, 1, 1);

    auto box8 = new QWidget();
    auto vlayout8 = new QHBoxLayout();
    auto *comingSoon8 = new QLabel("Issue Weights:");
    comingSoon8->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vlayout8->addWidget(comingSoon8, 1);
    defaultIssueWeight = new QLineEdit();
    defaultIssueWeight->setMinimumWidth(400);
    vlayout8->addWidget(defaultIssueWeight, 1);
    box8->setLayout(vlayout8);
    hlayout->addWidget(box8, 2, 0);

    auto box5 = new QWidget();
    auto vlayout5 = new QHBoxLayout();
    auto *comingSoon5 = new QLabel("Issue Summary:");
    comingSoon5->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    vlayout5->addWidget(comingSoon5, 1);
    defaultSummary = new QLineEdit();
    defaultSummary->setMinimumWidth(400);
    vlayout5->addWidget(defaultSummary, 1);
    box5->setLayout(vlayout5);
    hlayout->addWidget(box5, 2, 1);

    auto box6 = new QWidget();
    auto vlayout6 = new QVBoxLayout();
    auto *comingSoon6 = new QLabel("Issue Description:");
    vlayout6->addWidget(comingSoon6);
    defaultDescription = new QTextEdit();
    vlayout6->addWidget(defaultDescription, 1);
    box6->setLayout(vlayout6);
    hlayout->addWidget(box6, 3, 0);

    auto box7 = new QWidget();
    auto vlayout7 = new QVBoxLayout();
    auto *comingSoon7 = new QLabel("Issue Object:");
    vlayout7->addWidget(comingSoon7);
    baseIssueObject = new QTextEdit();
    vlayout7->addWidget(baseIssueObject, 1);
    box7->setLayout(vlayout7);
    hlayout->addWidget(box7, 3, 1);

    group->setLayout(hlayout);

    auto buttonGroup = new QWidget();
    auto buttonLayout = new QHBoxLayout();
    auto *button = new QPushButton("Cancel");
    connect(button, SIGNAL (released()), this, SLOT (cancelSettings()));
    buttonLayout->addWidget(button);
    auto *button2 = new QPushButton("Update");
    connect(button2, SIGNAL (released()), this, SLOT (updateSettings()));
    buttonLayout->addWidget(button2);
    buttonGroup->setLayout(buttonLayout);

    mainlayout->addWidget(group);
    mainlayout->addWidget(buttonGroup);
    mainlayout->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(mainlayout);

    cancelSettings();
}

void ConfigTab::updateSettings(){
    settings.setValue("testUrl", testUrl->text());
    settings.setValue("gitApiUrl", gitApiUrl->text());
    settings.setValue("jiraApiUrl", jiraApiUrl->text());
    settings.setValue("jenkinsApiUrl", jenkinsApiUrl->text());
    settings.setValue("defaultSummary", defaultSummary->text());
    settings.setValue("defaultDescription", defaultDescription->toPlainText());
    settings.setValue("baseIssueObject", baseIssueObject->toPlainText());
    settings.setValue("defaultIssueWeight", defaultIssueWeight->text());
    // TODO: reset values in Jira tab
};

void ConfigTab::cancelSettings(){
    testUrl->clear();
    testUrl->insert(settings.value("testUrl").toString());

    gitApiUrl->clear();
    gitApiUrl->insert(settings.value("gitApiUrl").toString());

    jiraApiUrl->clear();
    jiraApiUrl->insert(settings.value("jiraApiUrl").toString());

    jenkinsApiUrl->clear();
    jenkinsApiUrl->insert(settings.value("jenkinsApiUrl").toString());

    defaultSummary->clear();
    defaultSummary->insert(settings.value("defaultSummary").toString());

    defaultDescription->clear();
    defaultDescription->setPlainText(settings.value("defaultDescription").toString());

    baseIssueObject->clear();
    baseIssueObject->setPlainText(settings.value("baseIssueObject").toString());

    defaultIssueWeight->clear();
    defaultIssueWeight->insert(settings.value("defaultIssueWeight").toString());
}

ConfigTab::~ConfigTab() {}