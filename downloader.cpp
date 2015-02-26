#include "downloader.h"
#include <QDir>
#include <QStringList>
#include <QDesktopServices>
#include <windows.h>

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(QUrl("https://yandex.ru/images/today?size=1920x1080")));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloaderSlot(QNetworkReply*)));
}

Downloader::~Downloader()
{

}

void Downloader::openImage()
{
    QString fileForExec = filePath;
    QDesktopServices::openUrl(QUrl("file:///" + fileForExec));
}

void Downloader::setWallpape()
{
    if(!SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (LPWSTR)filePath.toStdWString().c_str(), SPIF_UPDATEINIFILE))
        qDebug() << "Не установилось!";
}

void Downloader::downloaderSlot(QNetworkReply *reply)
{
    filePath = QDir::toNativeSeparators(QDir::currentPath()) + "\\" + "yandex_tooday_image_" +QDate::currentDate().toString("dd_MM_yy") + ".jpg";
    QStringList dirList = QDir::current().entryList(QDir::Files, QDir::Name);

    qDebug() << "filePath: " << filePath;
    qDebug() << dirList;

    if(reply->error() == 0 && dirList.indexOf("yandex_tooday_image_" +QDate::currentDate().toString("dd_MM_yy") + ".jpg") == -1){
        QByteArray array = reply->readAll();
        QImage image;
        if(image.loadFromData(array))
            qDebug() << "download complite";
        if(image.save(filePath))
            qDebug() << "save прошел";
    }
}

