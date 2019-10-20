#include "jenkinstab.h"

JenkinsTab::JenkinsTab(QWidget *parent) : QWidget(parent){
    auto gridlayout = new QHBoxLayout();

    auto *pr1 = new QGroupBox("Modules");
    auto layout = new QVBoxLayout();
    auto *tree = new QTreeWidget();
    tree->setColumnCount(4);
    QStringList headers;
    headers << "" << "Module" << "Branch" << "Action";
    tree->setHeaderLabels(headers);
    auto *item = new QTreeWidgetItem;
    item->setCheckState(0, Qt::Unchecked);
    item->setText(1, "vulnnext-enrichment-dynamo-test");
    item->setText(2, "dev");
    item->setText(3, "");
    tree->addTopLevelItem(item);
    layout->addWidget(tree);
    pr1->setLayout(layout);
    gridlayout->addWidget(pr1);

    auto *pr2 = new QGroupBox("Activity");
    auto layout2 = new QVBoxLayout();
    QListWidget *listWidget = new QListWidget(this);
    QListWidgetItem *listItem = new QListWidgetItem("THIS",listWidget);
    listItem->setCheckState(Qt::Unchecked);
    listWidget->addItem(listItem);
    layout2->addWidget(listWidget);


    pr2->setLayout(layout2);
    gridlayout->addWidget(pr2);
    setLayout(gridlayout);
    gridlayout->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(gridlayout);
}

JenkinsTab::~JenkinsTab(){}