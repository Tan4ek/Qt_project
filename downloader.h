#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QImage>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);
    ~Downloader();
    Q_INVOKABLE void openImage();
    Q_INVOKABLE void setWallpape();

signals:

private:
    QString filePath;

public slots:

private slots:
    void downloaderSlot(QNetworkReply*);
};

#endif // DOWNLOADER_H
