#include <QApplication>
#include <QSettings>
#include <QFileInfo>
#include <QDir>
#include<qpdfjswindow.h>
#include<QDebug>
#include<iostream>
#include "mylist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTextCodec::setCodecForCStrings ( tc )  ;

    MyList w;
    w.show();

//    QApplication a(argc, argv);



//    QString app_path = qApp->applicationDirPath();


//    QSettings s;
//    QVector<QWidget *> windows;

//    bool no_one = true;
//   // for(auto pdf_path : a.arguments()) {
//      QString pdf_path = "/home/doka/C_plus/ppp.pdf";
//        QFileInfo pdf_fi(pdf_path);

//       if (pdf_fi.exists())
//          std::cout<<"file  exists\n";

//        if (!pdf_path.endsWith(".pdf", Qt::CaseInsensitive))
//             std::cout<<"file end .PDF\n";

//       pdf_path = pdf_fi.absoluteFilePath();

//        no_one = false;
//        QPdfJsWindow * window = new QPdfJsWindow(pdf_path);
//        int w = s.value("geomw", 1000).toInt();
//        int h = s.value("geomh", 800).toInt();
//        window->resize(w,h);
//        window->show();
//        windows.push_back(window);
//   // }

//    if (no_one) {
//        QString pdf_path = app_path+"/empty.pdf";
//        QPdfJsWindow * window = new QPdfJsWindow(pdf_path);
//        int w = s.value("geomw", 1000).toInt();
//        int h = s.value("geomh", 800).toInt();
//        window->resize(w,h);
//        window->show();
//        windows.push_back(window);
//    }

//    int code = a.exec();

//    for (auto window : windows) {
//        if (window) {
//            s.setValue("geomw", window->width());
//            s.setValue("geomh", window->height());
//        }
//        delete window;
//    }

   return a.exec();
}









//#include <QApplication>
//#include <QWebEngineView>

//QUrl commandLineUrlArgument()
//{
//    const QStringList args = QCoreApplication::arguments();
//    for (const QString &arg : args.mid(1)) {
//        if (!arg.startsWith(QLatin1Char('-')))
//            return QUrl::fromUserInput(arg);
//    }
//    return QUrl(QStringLiteral("https://www.qt.io"));
//}

//int main(int argc, char *argv[])
//{
//    QCoreApplication::setOrganizationName("QtExamples");
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QApplication app(argc, argv);

//    QWebEngineView view;
//    view.setUrl(commandLineUrlArgument());
//    view.resize(1024, 750);
//    view.show();

//    return app.exec();
//}
