#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QComboBox>
#include <QTabBar>
#include <QPlainTextEdit>
#include <QStatusBar>
#include <QMenuBar>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QApplication>
#include <QScrollArea>

#include "githubtab.h"
#include "jiratab.h"
#include "jenkinstab.h"
#include "confluencetab.h"
#include "configdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QDialog loginDialog;
    QLineEdit *username;
    QLineEdit *password;
    QString usr;
    QString pwd;

    const QString &getEid() const;
    const QString &getPwd() const;

private slots:
    void login();
    static void cancelLogin();

private:
    void logindialog();
    QGridLayout *mainLayout;

};

#endif // MAINWINDOW_H
