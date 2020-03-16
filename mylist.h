#ifndef MYLIST_H
#define MYLIST_H
#include "filefinder.h"
#include <QWidget>
#include<QListWidget>
#include<QtGui>
#include<QToolBar>
class MyList : public QWidget
{
    Q_OBJECT
public:
    explicit MyList(QWidget *parent = nullptr);


signals:


public slots:
    void makeItem(QString item, QListWidget* lstWgt );
    void onBtnClicked();
    void getNewList();
    void showPDF(QString path);
private:
    FileFinder * fileFinder;
    QToolBar *tb ;
    QStringList listFiles;
    QListWidget* lstWgt;
};

#endif // MYLIST_H
