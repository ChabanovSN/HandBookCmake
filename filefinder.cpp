#include<filefinder.h>
#include <QtGui>
#include<QFileDialog>

FileFinder::FileFinder(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(QString::fromUtf8("Поиск файлов"));
    m_ptxtDir    = new QLineEdit();
    m_ptxtDir->setText(settings.value(SETTINGS_DIR, QDir::current().absolutePath()).toString());
    m_ptxtMask   = new QLineEdit("*.pdf");  //("*.cpp *.h");
    m_ptxtResult = new QTextEdit;

    plblDir  = new QLabel("Папка");
    plblMask = new QLabel("Маска");
    pcmdDir  = new QPushButton(QString::fromUtf8("Открыть папку"));
    pcmdFind = new QPushButton(QString::fromUtf8("Поиск"));

    connect(pcmdDir, SIGNAL(clicked()), SLOT(slotBrowse()));
    connect(pcmdFind, SIGNAL(clicked()), SLOT(slotFind()));

    plblDir->setBuddy(m_ptxtDir);
    plblMask->setBuddy(m_ptxtMask);

    //Layout setup
    pgrdLayout = new QGridLayout;
    pgrdLayout->setMargin(5);
    pgrdLayout->setSpacing(15);
    pgrdLayout->addWidget(plblDir, 0, 0);
    pgrdLayout->addWidget(plblMask, 1, 0);
    pgrdLayout->addWidget(m_ptxtDir, 0, 1);
    pgrdLayout->addWidget(m_ptxtMask, 1, 1);
    pgrdLayout->addWidget(pcmdDir, 0, 2);
    pgrdLayout->addWidget(pcmdFind, 1, 2);
    pgrdLayout->addWidget(m_ptxtResult, 2, 0, 1, 3);
    setLayout(pgrdLayout);

    slotFind();
}



void FileFinder::slotBrowse()
{
    QString str = QFileDialog::getExistingDirectory
            (0,
             QString::fromUtf8("Выбрать папку"),
             m_ptxtDir->text());

    if (!str.isEmpty()) {
        m_ptxtDir->setText(str);
    }
}
void FileFinder::slotFind()
{
    settings.setValue(SETTINGS_DIR,m_ptxtDir->text());
    settings.sync();
    start(QDir(m_ptxtDir->text()));
}

void FileFinder::start(const QDir& dir)
{
    QApplication::processEvents();
    m_ptxtResult->clear();
    listFiles =
            dir.entryList(m_ptxtMask->text().split(" "), QDir::Files);

    foreach (QString file, listFiles) {
        m_ptxtResult->append(file);
        //  m_ptxtResult->append(dir.absoluteFilePath(file));
    }

    for(int i = 0;i<listFiles.size();i++)
        listFiles[i]=dir.absoluteFilePath(listFiles[i]);
    //  рекурсивный поиск  обнуляте в конце  listFiles
    //    QStringList listDir = dir.entryList(QDir::Dirs);
    //    foreach (QString subdir, listDir) {
    //        if (subdir == "." || subdir == "..") {
    //            continue;
    //        }
    //        start(QDir(dir.absoluteFilePath(subdir)));
    //    }

}
QStringList FileFinder::getListFiles(){
    //    qDebug()<<"getListFiles()"<<listFiles.size();

    //    foreach (QString str, listFiles) {
    //       qDebug()<<str;
    //    }
    return listFiles;
}
