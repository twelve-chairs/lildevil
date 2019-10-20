//
// Created by VokamisAir on 9/29/19.
//

#include "jiraissue.h"
#include <iostream>

JiraIssue::JiraIssue(){
    doc = QJsonDocument::fromJson(baseJson);
};

JiraIssue::~JiraIssue()= default;

void JiraIssue::setTitle(QString &title){
    QJsonObject jsonRoot = doc.object();
    QJsonObject keys = jsonRoot["fields"].toObject();
    keys["summary"] = title;
    doc.setObject(keys);
}

void JiraIssue::setDescription(QString &description){
    QJsonObject jsonRoot = doc.object();
    QJsonObject keys = jsonRoot["fields"].toObject();
    keys["description"] = description;
    doc.setObject(keys);
}

void JiraIssue::setEpic(QString &epic){
    QJsonObject jsonRoot = doc.object();
    QJsonObject keys = jsonRoot["fields"].toObject();
    keys["epic"] = epic;
    doc.setObject(keys);
}

QString JiraIssue::getJsonString(){
    QString replyJsonString(doc.toJson(QJsonDocument::Compact));
    std::cout << replyJsonString.toStdString() << std::endl;
    return replyJsonString;
}