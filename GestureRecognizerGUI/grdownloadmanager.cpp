#include "grdownloadmanager.h"
#include <QFileInfo>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QStringList>
#include <QTimer>

GRDownloadManager::GRDownloadManager(QObject *parent)
    : QObject(parent), downloadedCount(0), totalCount(0), destination("")
{
}

void GRDownloadManager::append(const QStringList &urlList)
{
    foreach (QString url, urlList)
        append(QUrl::fromEncoded(url.toLocal8Bit()));

    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SIGNAL(finished()));
}

void GRDownloadManager::append(const QUrl &url)
{
    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SLOT(startNextDownload()));

    downloadQueue.enqueue(url);
    ++totalCount;
}

QString GRDownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";
    QString tmp;
    if(destination!="")
    {
     tmp=destination+"/"+basename;
    }
    else
    {
        tmp=basename;
    }
    /*if (QFile::exists(tmp)) {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }
*/
    return basename;
}

void GRDownloadManager::setDestination(QString destination)
{
    this->destination=destination;
}

void GRDownloadManager::startNextDownload()
{
    if (downloadQueue.isEmpty())
    {
        emit downloadDone();
        return;
    }

    QUrl url = downloadQueue.dequeue();

    QString filename = saveFileName(url);
    if(destination!="")
    {
        output.setFileName(destination+QObject::tr("/")+filename);
    }
    else
    {
        output.setFileName(filename);

    }
    if (!output.open(QIODevice::WriteOnly))
    {
        emit log(
                  tr("Problem opening save file '%1' for download '%2': %3\n")
                 .arg(filename)
                 .arg(url.toString())
                 .arg(output.errorString())
                 );
        startNextDownload();
        return;                 // skip this download
    }

    QNetworkRequest request(url);
    currentDownload = manager.get(request);
    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),
            SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()),
            SLOT(downloadFinished()));
    connect(currentDownload, SIGNAL(readyRead()),
            SLOT(downloadReadyRead()));

    // prepare the output
    emit log(tr("Downloading %1...").arg(url.toString()));
    downloadTime.start();
}

void GRDownloadManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    // calculate the download speed
    double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
    QString unit;
    if (speed < 1024) {
        unit = "bytes/sec";
    } else if (speed < 1024*1024) {
        speed /= 1024;
        unit = "kB/s";
    } else {
        speed /= 1024*1024;
        unit = "MB/s";
    }
    emit progressStatus(bytesReceived,bytesTotal,speed,unit);
}

void GRDownloadManager::downloadFinished()
{
    output.close();
    emit progressCompleted();
    if (currentDownload->error())
    {
        // download failed
        emit log(
                  tr("Failed: %1")
                  .arg(currentDownload->errorString())
                 );
    }
    else
    {
        emit log(tr("Succeeded."));
        ++downloadedCount;
    }

    currentDownload->deleteLater();
    startNextDownload();
}

void GRDownloadManager::downloadReadyRead()
{
    output.write(currentDownload->readAll());
}
