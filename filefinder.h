#ifndef FILEFINDER_H
#define FILEFINDER_H

#include<QApplication>
#include <QWidget>
#include<QDir>
#include<QtGui>
#include<QLineEdit>
#include<QTextEdit>
#include<QLabel>
#include<QPushButton>
#include<QGridLayout>


#define SETTINGS_DIR "settings/dir"
class FileFinder: public QWidget
{
    Q_OBJECT
public:
    FileFinder(QWidget *parent = 0);

public slots:

 void slotBrowse();
 void slotFind();
 void start(const QDir& dir);
 QStringList getListFiles();
private:
 QSettings settings;
 QLineEdit *  m_ptxtDir    ;
 QLineEdit *  m_ptxtMask   ;
 QTextEdit * m_ptxtResult;
 QStringList listFiles;
 QLabel*      plblDir;
 QLabel*      plblMask;
 QPushButton* pcmdDir;
 QPushButton* pcmdFind;
 QGridLayout* pgrdLayout;

};

#endif // FILEFINDER_H
