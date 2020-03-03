#include "jiratab.h"
#include <QMessageLogger>


JiraTab::JiraTab(QWidget *parent) : QWidget(parent) {
    auto gridlayout = new QGridLayout();

    auto *pr1 = new QGroupBox("My Issues");
    auto layout = new QVBoxLayout();
    auto topBox = new QTreeWidget();
    layout->addWidget(topBox);
    auto bottomBox = new QPlainTextEdit();
    bottomBox->setReadOnly(true);
    layout->addWidget(bottomBox, 1);
    pr1->setLayout(layout);
    gridlayout->addWidget(pr1, 0, 0);


    auto *pr2 = new QGroupBox("New Issue");

    auto *mainLayout = new QGridLayout();
    mainLayout->setRowStretch(0,0);
    mainLayout->setRowStretch(1,0);
    mainLayout->setRowStretch(2,1);
    mainLayout->setRowStretch(3,0);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,1);

    auto *topLeftCollection = new QWidget();
    auto topLeftVlayout = new QHBoxLayout();
    auto *epicLabel = new QLabel("Epic");
    epicLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    topLeftVlayout->addWidget(epicLabel);
    selectEpic = new QComboBox;
    topLeftVlayout->addWidget(selectEpic, 1);
    topLeftCollection->setLayout(topLeftVlayout);
    mainLayout->addWidget(topLeftCollection, 0, 0);

    auto *bottomRightCollection = new QWidget;
    auto bottomRightVlayout = new QHBoxLayout();
    auto *weightLabel = new QLabel("Weight");
    weightLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    bottomRightVlayout->addWidget(weightLabel);
    selectWeight = new QComboBox;
    bottomRightVlayout->addWidget(selectWeight, 1);
    bottomRightCollection->setLayout(bottomRightVlayout);
    mainLayout->addWidget(bottomRightCollection, 0, 1);

    auto *bottomLeftCollection = new QWidget;
    auto bottomLeftVlayout = new QHBoxLayout();
    auto *summaryLabel = new QLabel("* Summary");
    summaryLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    bottomLeftVlayout->addWidget(summaryLabel);
    issueTitle = new QLineEdit();
    issueTitle->setPlaceholderText("required");
    connect(issueTitle,
            SIGNAL(textChanged(QString)),
            this,
            SLOT(onTextChanged(QString)));

    bottomLeftVlayout->addWidget(issueTitle, 1);
    bottomLeftCollection->setLayout(bottomLeftVlayout);
    mainLayout->addWidget(bottomLeftCollection, 1, 0, 1, 2);

    auto *middleLeftCollection = new QWidget;
    auto middleLeftVlayout = new QVBoxLayout();
    auto *issueDescriptionLabel = new QLabel(tr("* Description"));
    middleLeftVlayout->addWidget(issueDescriptionLabel);
    issueDescription = new QPlainTextEdit();
    middleLeftVlayout->addWidget(issueDescription, 1);
    middleLeftCollection->setLayout(middleLeftVlayout);
    mainLayout->addWidget(middleLeftCollection, 2, 0, 1, 2);



    auto *bottomRightButtonCollection = new QWidget;
    auto hlayout = new QHBoxLayout();

    issueCancel = new QPushButton("Reset");
    mainLayout->addWidget(issueCancel);
    connect(issueCancel, SIGNAL (released()),this, SLOT (resetIssue()));

    issueSubmit = new QPushButton("Create");
    mainLayout->addWidget(issueSubmit);
    issueSubmit->setDisabled(true);
    connect(issueSubmit, SIGNAL (released()),this, SLOT (submitIssue()));
    bottomRightButtonCollection->setLayout(hlayout);

    pr2->setLayout(mainLayout);
    gridlayout->addWidget(pr2, 0, 1);
    gridlayout->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(gridlayout);

    resetIssue();
}

JiraTab::~JiraTab() {}

void JiraTab::resetIssue(){
    try {
        delete issue;
    }
    catch(const std::system_error &e) {
        QMessageBox::warning(this, "Error", tr(e.what()),
                              QMessageBox::Ok);
    }

    issue = new JiraIssue();

    selectWeight->clear();
    try {
        getWeights();
    }
    catch(const std::system_error &e) {
        QMessageBox::warning(this, "Error", tr(e.what()),
                              QMessageBox::Ok);
    }

    issueTitle->clear();
    issueTitle->insert(issue->defaultSummary);

    issueDescription->clear();
    issueDescription->setPlainText(issue->defaultDescription);

    selectEpic->clear();
    getEpics();
}

void JiraTab::submitIssue(){
    int ret = QMessageBox::warning(this, tr("Confirm new issue"),
                                   "Title: " + issueTitle->text() + "\n\n" +
                                   "Are you sure you are ready to submit it?",
                                   QMessageBox::Ok | QMessageBox::Cancel,
                                   QMessageBox::Ok);
    switch (ret){
        case QMessageBox::Ok:
            try {
                QNetworkRequest request;
                request.setUrl(QUrl(settings.value("jiraApiUrl").toString()));
                request.setRawHeader("Content-type", "application/json");

                auto *networkManager = new QNetworkAccessManager(this);

                QNetworkReply *reply = networkManager->post(request, issue->getJsonString().toUtf8());

                QEventLoop loop;
                connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
                loop.exec();

                auto replyJsonDoc = QJsonDocument::fromJson(reply->readAll());
//                repos = replyJsonDoc.object();
                QString replyJsonString(replyJsonDoc.toJson(QJsonDocument::Compact));

                QMessageBox::information(this, tr("New issue"),
                                         replyJsonString,
                                         QMessageBox::Ok,
                                         QMessageBox::Ok);
            }
            catch(const std::system_error &e){
                QMessageBox::critical(this, "Error", tr(e.what()),
                                      QMessageBox::Ok,
                                      QMessageBox::Ok);

            }
            resetIssue();
            break;
        case QMessageBox::Cancel:
            break;
        default:
            break;
    }
}

void JiraTab::getWeights(){
    selectWeight->addItems(issue->weight);
}

void JiraTab::getEpics(){
    QNetworkRequest request;
    request.setUrl(QUrl(settings.value("jiraApiUrl").toString()));
    request.setRawHeader("Content-type", "application/json");

    auto *networkManager = new QNetworkAccessManager(this);
    QNetworkReply *reply = networkManager->get(request);

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    auto replyJsonDoc = QJsonDocument::fromJson(reply->readAll());
    epics = replyJsonDoc.object();
    QString replyJsonString(replyJsonDoc.toJson(QJsonDocument::Compact));

    QJsonArray dataObject = epics.value("data").toArray();
    QStringList list("");
    for (auto v : dataObject) {
        QJsonObject element = v.toObject();
        list.append(element["avatar"].toString());
    }
    selectEpic->addItems(list);
}

void JiraTab::onTextChanged(const QString &qString) {
    this->issueSubmit->setDisabled(qString.isEmpty());
}
