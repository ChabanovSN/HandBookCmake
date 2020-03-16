#include "mylist.h"
#include<QDebug>
#include<iostream>
#include "qpdfjswindow.h"
MyList::MyList(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(QString::fromUtf8("Справочник"));
    fileFinder = new FileFinder();
    listFiles = fileFinder->getListFiles();
    tb = new QToolBar();
    tb->addAction(QString::fromUtf8("Настройки"),fileFinder,SLOT(show()));
    tb->addAction(QString::fromUtf8("Обновить"),this,SLOT(getNewList()));
    tb->addAction(QString::fromUtf8("Выход"),this,SLOT(close()));

    lstWgt = new QListWidget;
    QLayout* l = new QVBoxLayout;
    l->setMenuBar(tb);
    l->addWidget( lstWgt );
    setLayout( l );


    foreach( const QString& str, listFiles) {
        makeItem( str,lstWgt );
    }

    resize( 500, 500 );
}

void MyList::getNewList(){
    qDebug()<<"refresh";
    listFiles.clear();
    listFiles = fileFinder->getListFiles();
    lstWgt->clear();
    foreach( const QString& str, listFiles) {
        //    qDebug()<<str;
        makeItem( str,lstWgt );
    }


}

void MyList::makeItem( QString str,  QListWidget* lstWgt ) {
    QWidget* wgt = new QWidget;
    QLayout* l = new QHBoxLayout;
    // QLineEdit path = new QLineEdit(str);
    //  m_ptxtResult->append(dir.absoluteFilePath(file));
    QLineEdit *absPath = new QLineEdit(str);
    QPushButton* btn = new QPushButton();
    absPath->hide();
    l->addWidget( absPath);
    QString name = str.mid(str.lastIndexOf("/"));
    if(!str.endsWith("empty.pdf")){
        QString name1 = name.mid(name.indexOf("_")+1,name.size()-7);
        name1 =  name1.replace("_"," ");
        btn->setText(name1);
    }
    else btn->setText(str);

    connect( btn, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    l->addWidget( btn );
    wgt->setLayout( l );
    QListWidgetItem* item = new QListWidgetItem( lstWgt );
    item->setSizeHint( wgt->sizeHint() );
    lstWgt->setItemWidget( item, wgt );
}
void MyList::showPDF(QString path){

    QString app_path = qApp->applicationDirPath();

    QSettings s;
    QVector<QWidget *> windows;

    bool no_one = true;
    // for(auto pdf_path : a.arguments()) {
    QString pdf_path =  path;  // "/home/doka/C_plus/ppp.pdf";
    QFileInfo pdf_fi(pdf_path);
    if (!pdf_path.endsWith(".pdf", Qt::CaseInsensitive))
        std::cout<<"file end .PDF\n";

 qDebug()<<"showPDF(pdf_fi.exists()) path = "<<pdf_fi.exists();
    if (pdf_fi.exists()){
        no_one = false;
        std::cout<<"file  no exists\n";
    }




  //  pdf_path = pdf_fi.absoluteFilePath();


    QPdfJsWindow * window = new QPdfJsWindow(path,this);
    int w = s.value("geomw", 1000).toInt();
    int h = s.value("geomh", 800).toInt();
    window->resize(w,h);
    window->show();
    windows.push_back(window);




    if (no_one) {
        QString pdf_path = app_path+"/empty.pdf";
        QPdfJsWindow * window = new QPdfJsWindow(pdf_path);
        int w = s.value("geomw", 1000).toInt();
        int h = s.value("geomh", 800).toInt();
        window->resize(w,h);
        window->show();
        windows.push_back(window);
    }



    //    for (auto window : windows) {
    //        if (window) {
    //            s.setValue("geomw", window->width());
    //            s.setValue("geomh", window->height());
    //        }
    //        delete window;
    //    }


}
void MyList::onBtnClicked() {
    if( QPushButton* btn = qobject_cast< QPushButton* >( sender() ) ) {

        if( QLineEdit* e = btn->parent()->findChild< QLineEdit* >() ) {
            if(QFile::exists(e->text())){
              //  qDebug()<<"file !!! exist";
                showPDF(e->text());
  qDebug()<<"onBtnClicked() "<<e->text();
                //   QDesktopServices::openUrl(QUrl::fromLocalFile( e->text()));
            }
            else
                qDebug()<<"file  NOt exist";
            // QDesktopServices::openUrl(QUrl::fromLocalFile(destinationTemp + fileName   + ".pdf"));
            // QMessageBox::information( this, "Button was clicked!", e->text() );
            return;
        }
    }
}
