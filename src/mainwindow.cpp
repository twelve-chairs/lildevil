#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    mainLayout = new QGridLayout();

    auto *tabs = new QTabWidget();
    tabs->addTab(new JiraTab(), tr("Backlog"));
    tabs->addTab(new JenkinsTab(), tr("CI/CD"));
    tabs->addTab(new GithubTab(), tr("Version Control"));
    tabs->addTab(new ConfigTab(), tr("Settings"));
    mainLayout->addWidget(tabs);

    auto *window = new QWidget();
    window->setLayout(mainLayout);
    setCentralWidget(window);
    setWindowTitle(tr("lilDevil"));
    statusBar()->showMessage(tr("Credentials not set!"));

    logindialog();
}

MainWindow::~MainWindow(){}

void MainWindow::logindialog() {
    mainLayout = new QGridLayout();

    auto *collection = new QWidget;
    auto *layout = new QVBoxLayout();

    auto *scrollArea = new QScrollArea;
    auto *imageLabel = new QLabel;
    QImage image(":/res/AppIcon.ico");
    imageLabel->setPixmap(QPixmap::fromImage(image).scaled(100,
                                                           100,
                                                           Qt::KeepAspectRatio,
                                                           Qt::SmoothTransformation));
    scrollArea->setAlignment(Qt::AlignHCenter);
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setWidget(imageLabel);

    layout->addWidget(scrollArea);

    auto *usernameBox = new QWidget;
    auto *usernameLayout = new QHBoxLayout();
    username = new QLineEdit();
    username->setMinimumWidth(200);
    username->setPlaceholderText("Username");
    usernameLayout->addWidget(username, 1);
    usernameBox->setLayout(usernameLayout);
    layout->addWidget(usernameBox);

    auto *passwordBox = new QWidget;
    auto *passwordLayout = new QHBoxLayout();
    password = new QLineEdit();
    password->setMinimumWidth(200);
    password->setPlaceholderText("Password");
    password->setEchoMode(QLineEdit::Password);
    passwordLayout->addWidget(password, 1);
    passwordBox->setLayout(passwordLayout);
    layout->addWidget(passwordBox);

    auto *collection2 = new QWidget;
    auto *buttonGroup = new QHBoxLayout();

    auto submitButton = new QPushButton("Login");
    connect(submitButton, SIGNAL (released()),this, SLOT (login()));
    buttonGroup->addWidget(submitButton);

    auto cancelButton = new QPushButton("Cancel");
    connect(cancelButton, SIGNAL (released()),this, SLOT (cancelLogin()));
    buttonGroup->addWidget(cancelButton);

    collection2->setLayout(buttonGroup);
    layout->addWidget(collection2);

    collection->setLayout(layout);

    mainLayout->addWidget(collection);

    loginDialog.setLayout(mainLayout);
    loginDialog.setModal(true);
    loginDialog.show();
}

void MainWindow::login() {
    if (username->text().size() != 0 && password->text().size() != 0) {
        this->usr = username->text().toLower();
        this->pwd = password->text();
        this->statusBar()->showMessage("User: " + usr);
        loginDialog.hide();
    }
}

void MainWindow::cancelLogin(){
    QCoreApplication::quit();
}

const QString &MainWindow::getEid() const {
    return usr;
}

const QString &MainWindow::getPwd() const {
    return pwd;
}