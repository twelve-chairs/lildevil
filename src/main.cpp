#include "main.h"

int main(int argc, char *argv[])
{
    enum window {
        windowWidth = 1200,
        windowHeight = 800
    };

    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Twelve Chairs Software, LLC");
    QCoreApplication::setOrganizationDomain("twelvechairs-software.com");
    QCoreApplication::setApplicationName("lilDevil");

    QSettings settings;
//    settings.setValue("testUrl", "https://reqres.in/api/users");
//    settings.setValue("gitApiUrl", "https://reqres.in/api/users");
//    settings.setValue("jiraApiUrl", "https://reqres.in/api/users");
//    settings.setValue("jenkinsApiUrl", "https://reqres.in/api/users");
//    settings.setValue("defaultSummary", "");
//    settings.setValue("defaultDescription", "As a \n\n\nAcceptance Criteria:\n\n- \n\n\nDeveloper Notes:\n\nCreated with \u2764\ufe0f by lilDevil\n");
//    settings.setValue("baseIssueObject", "{                                                      "
//                                                     "     \"fields\": {                                     "
//                                                     "        \"project\": {\"key\": \"CRIEVM\"},            "
//                                                     "        \"customfield_11248\": {\"value\": \"Forge\"}, "
//                                                     "        \"customfield_10811\": [                       "
//                                                     "             {                                         "
//                                                     "                 \"key\": \"khf768\"                   "
//                                                     "             },                                        "
//                                                     "             {                                         "
//                                                     "                 \"name\": \"KHF768\"                  "
//                                                     "             }                                         "
//                                                     "         ],                                            "
//                                                     "        \"issuetype\": {\"Forge\": \"Story\"},         "
//                                                     "        \"labels\": [\"Forge\"],                       "
//                                                     "        \"customfield_10400\": \"CRIEVM-17018\",       "
//                                                     "        \"summary\": \"\",                             "
//                                                     "        \"description\": \"\"                          "
//                                                     "     }                                                 "
//                                                     " }                                                     ");
//    settings.setValue("defaultIssueWeight", ", Small, Medium, Large, XXL");

    QDesktopWidget *desktop = QApplication::desktop();

    MainWindow w;
    w.resize(window::windowWidth, window::windowHeight);
    w.move((desktop->width() - window::windowWidth) / 2, (desktop->height() - window::windowHeight) / 2);
    w.show();

    return QApplication::exec();
}
