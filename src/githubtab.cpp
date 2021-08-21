#include "githubtab.h"

GithubTab::GithubTab(QWidget *parent) : QWidget(parent){
    qRegisterMetaType<QTextCursor>("QTextCursor");
    qRegisterMetaType<QTextCharFormat>("QTextCharFormat");

    auto gridlayout = new QGridLayout();

    auto *pr1 = new QGroupBox("PRs awaiting approval");
    auto layout = new QVBoxLayout();
    table = new QTreeWidget();
    QStringList horzHeaders;
    horzHeaders << "Repository" << "Title" << "Status";
    table->setColumnCount(horzHeaders.count());
    table->setHeaderLabels(horzHeaders);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    layout->addWidget(table);
    pr1->setLayout(layout);
    gridlayout->addWidget(pr1, 0, 0);

    auto *pr2 = new QGroupBox("My PRs");
    auto layout2 = new QVBoxLayout();
    table2 = new QTreeWidget();
    layout2->addWidget(table2);
    pr2->setLayout(layout2);
    gridlayout->addWidget(pr2, 0, 1);

    auto *pr3 = new QGroupBox("Admin Actions");
    auto layout3 = new QGridLayout();

    auto *button1 = new QPushButton();
    button1->setText("Lock master");
    connect(button1, SIGNAL (released()),this, SLOT (lockMaster()));

    layout3->addWidget(button1, 0, 0);

    auto *button2 = new QPushButton();
    button2->setText("New");
    connect(button2, SIGNAL (released()),this, SLOT (newRepo()));
    layout3->addWidget(button2, 0, 1);

    auto *button3 = new QPushButton();
    button3->setText("Rebase");
    connect(button3, SIGNAL (released()),this, SLOT (rebase()));
    layout3->addWidget(button3, 0, 2);

    auto *button4 = new QPushButton();
    button4->setText("Lock QA");
    connect(button4, SIGNAL (released()),this, SLOT (lockQa()));
    layout3->addWidget(button4, 1, 0);

    auto *button5 = new QPushButton();
    button5->setText("List");
    connect(button5, SIGNAL (released()),this, SLOT (listRepos()));
    layout3->addWidget(button5, 1, 1);

    auto *button6 = new QPushButton();
    button6->setText("Something");
    connect(button6, SIGNAL (released()),this, SLOT (something()));
    layout3->addWidget(button6, 1, 2);

    auto *button7 = new QPushButton();
    button7->setText("Lock dev");
    connect(button7, SIGNAL (released()),this, SLOT (lockDev()));
    layout3->addWidget(button7, 2, 0);

    auto *button8 = new QPushButton();
    button8->setText("Unlock dev");
    connect(button8, SIGNAL (released()),this, SLOT (unlockDev()));
    layout3->addWidget(button8, 2, 1);

    auto *button9 = new QPushButton();
    button9->setText("Set dependencies");
    connect(button9, SIGNAL (released()),this, SLOT (tuneUp()));
    layout3->addWidget(button9, 2, 2);

    pr3->setLayout(layout3);
    gridlayout->addWidget(pr3, 1, 0);


    auto *pr = new QGroupBox("Repositories");
    auto layout6 = new QVBoxLayout();
    reposList = new QListWidget(this);
    layout6->addWidget(reposList);
    pr->setLayout(layout6);
    gridlayout->addWidget(pr, 1, 1);

    auto *pr4 = new QGroupBox("Activity");
    auto layout4 = new QVBoxLayout();
    table4 = new QTextEdit();
    layout4->addWidget(table4);
    pr4->setLayout(layout4);
    gridlayout->addWidget(pr4, 2, 0, 1, 2);


    setLayout(gridlayout);
    gridlayout->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(gridlayout);
    getRepos();
}

GithubTab::~GithubTab(){}

void GithubTab::getRepos(){
    this->repos << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "0" << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
    for (const auto& each: repos) {
        auto *listItem = new QListWidgetItem(each, reposList);
        listItem->setCheckState(Qt::Checked);
        reposList->addItem(listItem);
    }
};

void GithubTab::updateActivityMonitor(const QFuture<QString>& futureReference){
        table4->insertPlainText( futureReference.result()+ "\n\n");
        table4->moveCursor(QTextCursor::EndOfBlock);
        table4->ensureCursorVisible();
}

void GithubTab::updateActivityMonitor(const QString& string){
    table4->insertPlainText(string + "\n\n");
    table4->moveCursor(QTextCursor::EndOfBlock);
    table4->ensureCursorVisible();
}

QString GithubTab::postGitHub(const QString& url, const QList<QMap<QString, QString>>& headers, const QString& data){
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    for (auto& header : headers){
        request.setRawHeader(header.firstKey().toLocal8Bit(), header.value(header.firstKey()).toLocal8Bit());
    }

    auto *networkManager = new QNetworkAccessManager();
    QNetworkReply *reply = networkManager->post(request, data.toUtf8());

//    Doesn't work in QT6
//    QEventLoop loop;
//    connect(reply, SIGNAL (finished()), &loop, SLOT (quit()));
//    loop.exec();

    auto replyJsonDoc = QJsonDocument::fromJson(reply->readAll());
    QString replyJsonString(replyJsonDoc.toJson(QJsonDocument::Compact));
    return replyJsonString;
}

void GithubTab::lockMaster(){
    try {
        QString url = settings.value("gitApiUrl").toString();;

        QList<QMap<QString, QString>> headers;
        QMap<QString, QString> map;
        map.insert("Content-type", "application/json");
        headers.append(map);

        const QByteArray baseJson = settings.value("baseIssueObject").toByteArray();

        for (int i=0; i < reposList->count(); i++){
            if (reposList->item(i)->checkState() == Qt::Checked) {
                future = QtConcurrent::run([=]() {
                    QJsonDocument doc = QJsonDocument::fromJson(baseJson);
                    QJsonObject jsonRoot = doc.object();
                    QJsonObject keys = jsonRoot["fields"].toObject();
                    keys["epic"] = reposList->item(i)->text();
                    doc.setObject(keys);
                    const QString jsonString(doc.toJson(QJsonDocument::Compact));
                    const QString futureResponse = postGitHub(url, headers, jsonString);
                    return futureResponse;
                });
                futureWatcher.setFuture(future);
                future.waitForFinished();
                updateActivityMonitor(future.result());

//                connect(&futureWatcher, SIGNAL(finished()), this, [=](const QFuture<QString>& res){updateActivityMonitor(res)});
            }
        }
    }
    catch (std::exception &e){
        QString error = e.what();
        updateActivityMonitor(error);
    }
};

void GithubTab::lockQa(){
    QString str = "Lock QA";
    updateActivityMonitor(str);
};

void GithubTab::lockDev(){
    QString str = "Lock dev";
    updateActivityMonitor(str);
};

void GithubTab::unlockDev(){
    QString str = "Unlock dev";
    updateActivityMonitor(str);
};

void GithubTab::listRepos(){
    for (auto& repo : repos){
        updateActivityMonitor(repo);
    }
};

void GithubTab::newRepo(){
    QString str = "New repo";
    updateActivityMonitor(str);
};

void GithubTab::tuneUp(){
    QString str = "Tune up";
    updateActivityMonitor(str);
};

void GithubTab::something(){
    QString str = "Something";
    updateActivityMonitor(str);
};

void GithubTab::rebase(){
    QString str = "Rebase";
    updateActivityMonitor(str);
};