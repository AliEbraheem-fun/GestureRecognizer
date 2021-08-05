/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef GRDOWNLOADMANAGER_H
#define GRDOWNLOADMANAGER_H

#include <QFile>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <QUrl>
#include <QNetworkAccessManager>

/*!
 * \brief The gRDownloadManager class downloads files from a network url.
 *
 * The GRDownloadManager class can download files from a network
 * url to hard drive. Files are downloaded one after the other
 * not in parallel.
 */
class GRDownloadManager: public QObject
{
    Q_OBJECT
public:
    /*!
     * Constructs a  GRDownloadManager object.
     */
    GRDownloadManager(QObject *parent = 0);

    /*!
     * Adds a new url to the download queue.
     * \param url The url of the file to be downloaded.
     */
    void append(const QUrl &url);

    /*!
     * Adds a group of urls to the download queue.
     * \param urlList The list containing urls to be added to the download queue.
     */
    void append(const QStringList &urlList);

    /*!
     * Extracts the file name part in the url and checks for its exitence
     * in the download directory. if the file already exists then a '.'
     * followed by an incrementing number is added.
     * \param url The url to the file to be downloaded.
     * \return The name to be used for the downloaded file.
     */
    QString saveFileName(const QUrl &url);

    /*!
     * Specifies the destination folder where the downloded file is to be saved.
     * \param destination The destination folder for the downloaded files.
     */
    void setDestination(QString destination);

signals:

    /*!
     * A signal which indicates that all downloads in the download queue are over.
     */
    void downloadDone();

    /*!
     * A signal containing a message to be passed to a logging mechanism such as
     * a file or a terminal.
     * \param msg The message to be passed to the logging mechanism.
     */
    void log(QString msg);

    /*!
     * A signal indicating  the status of the currently on going
     * download.
     * \param bytesReceived Number of bytes received so far.
     * \param bytesTotal The total number of bytes.
     * \param speed Download speed.
     * \param unit Download speed unit.
     */
    void progressStatus(qint64 bytesReceived, qint64 bytesTotal,double speed,QString unit);

    /*!
     * progressCompleted A signal indicating that current download is over.
     */
    void progressCompleted();

private slots:

    /*!
     * A slot that starts a download from the download queue.
     */
    void startNextDownload();

    /*!
     * A slot that takes the number of received and total bytes
     * and calculates the speed of the download. It emits the
     * progressStatus signal.
     * \param bytesReceived Number of bytes received so far.
     * \param bytesTotal The total number of bytes.
     */
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

    /*!
     * A slot that:
     * - saves the file of the download to the hard disk.
     * - emits the progressCompleted signal.
     * - starts next download.
     */
    void downloadFinished();

    /*!
     * A Slot that reads the contents of the current download and writes them to the corresponding file.
     */
    void downloadReadyRead();

private:
    QNetworkAccessManager manager;/*!< Used to send requests over the network. */
    QQueue<QUrl> downloadQueue;/*!< The download queue which saves the urls to be downloaded successfully. */
    QNetworkReply *currentDownload;/*!< Contains the data and headers sent with a QNetworkAccessManager object \ref manager. */
    QFile output;/*!< The file to which the downloaded data will be saved. */
    QTime downloadTime;/*!< Used to measure timespan between data blocks so that download speed can be calculated. */
    int downloadedCount;/*!< Number of downloaded files.  */
    int totalCount;/*!< Total number of files that are downloaded or to be downloaded */
    QString destination;/*!< The destination to which the downloaded files will be saved. */

};

#endif
