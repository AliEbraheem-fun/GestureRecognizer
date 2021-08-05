#ifndef GRUPDATEMANAGER_H
#define GRUPDATEMANAGER_H
#include "grdownloadmanager.h"
#include "grfilelist.h"

/*!
 * \brief The GRUpdateManager class updates files of a program and installs new files.
 *
 * The GRUpdateManager class performs the following operations:
 * - Connects to a url.
 * - Downloads a specific update file from the url which contains a list of files that can be downloaded from the same url.
 * - Compares the downloded update file with a file containing a list of currently existent files and their version.
 * - Downloads the files that need to updated and replaces them with the existing ones in addition to new files that did not exist before.
 */
class GRUpdateManager: public GRDownloadManager
{
    Q_OBJECT
public:
    GRUpdateManager();
    
    /*!
     * Constructs An GRUpdateManager object.
     * \param oldFileListPath The xml file containing current files and their versions.
     * \param downloadURL The url from which new files are downloaded.
     * \param updateFileName The file in the url containing a list of files to be downloaded from the url.
     */
    GRUpdateManager(QString oldFileListPath, QString downloadURL,QString updateFileName);
    
    void setOldFileListPath(QString oldFileListPath);
    
    void setDownloadURL(QString downloadURL);
    
    void setUpdateFileName(QString updateFileName);
    
    /*!
     * Starts the update process.
     */
    void startUpdate();

    /*!
     * Perform update.
     */
    void updateFilesDownloaded();


private:
    QString oldFileListPath; /*!< The xml file containing current files and their versions. */
    QString downloadURL; /*!< The url from which new files are downloaded. */
    GRFileList oldFileList;  /*!< The xml file containing current files and their versions. */
    GRFileList newFileList;/*!< List of files to be downloaded from the url. */
    QString updateFileName; /*!< The file containing the new files and their version. */
signals:

    /*!
     * A signal occurs when an error occurs.
     * \param error A string describing the error.
     */
    void updateError(QString error);
private slots:
    /*!
     * A slot executed in response to downloading the update file from the url.
     */
    void newFileListDownloaded();
};

#endif // GRUPDATEMANAGER_H
