#include "grupdatemanager.h"

GRUpdateManager::GRUpdateManager()
{
    
}

GRUpdateManager::GRUpdateManager(QString oldFileListPath, QString downloadURL, QString updateFileName)
{
    this->oldFileListPath=oldFileListPath;
    this->downloadURL=downloadURL;
    this->updateFileName=updateFileName;
}

void GRUpdateManager::setOldFileListPath(QString oldFileListPath)
{
    this->oldFileListPath=oldFileListPath;
}

void GRUpdateManager::setDownloadURL(QString downloadURL)
{
    this->downloadURL=downloadURL;
}

void GRUpdateManager::setUpdateFileName(QString updateFileName)
{
    this->updateFileName=updateFileName;
}

void GRUpdateManager::startUpdate()
{
    log("restart program after updates are downloaded...");

    if(!oldFileList.parse(oldFileListPath))
    {
        log(
            tr("cannot read current version control file: %1")
            .arg(oldFileListPath)
            );
        return;
    }

    QString downloadPath=QDir::current().absolutePath()+"/temp";
    QDir downloadDir(downloadPath);
    if(downloadDir.exists())
    {
        if(!downloadDir.removeRecursively())
        {
            log(
                tr("cannot empty download directory: %1\nPlease close any programs using it or deleted manually and try again.")
                .arg(downloadDir.absolutePath())
                );
            return;
        }
    }
    if(!QDir::current().mkdir("temp"))
    {
        log(
            tr("cannot make download path: %1")
            .arg(downloadPath)
            );
        return;
    }
    connect(this,SIGNAL(downloadDone()),this,SLOT(newFileListDownloaded()));
    QStringList lst;
    lst.append(downloadURL+tr("/")+updateFileName);
    setDestination(downloadPath);
    this->append(lst);

}

void GRUpdateManager::newFileListDownloaded()
{
    disconnect(this,SIGNAL(downloadDone()),this,SLOT(newFileListDownloaded()));
    QString downloadPath=QDir::current().absolutePath()+"/temp";
    QDir downloadDir(downloadPath);
    if(!downloadDir.exists())
    {
        log(
            tr("cannot find download directory: %1")
            .arg(downloadPath)
            );
        return;
    }
    QString downloadedFile=downloadPath+"/"+updateFileName;

    if(!QFileInfo::exists(downloadedFile))
    {
        log(tr("cannot open update file.") );
    }
    if(!newFileList.parse(downloadedFile))
    {
        log(
            tr("cannot read update file: %1")
            .arg(downloadedFile)
            );
        return;
    }
    QStringList downloadList;
    for(int i=0;i<newFileList.fileList.length();i++)
    {
        downloadList.append(downloadURL+tr("/")+newFileList.fileList[i].fileName);
    }
    //connect(this,SIGNAL(downloadDone()),this,SLOT(updateFilesDownloaded()));
    append(downloadList);
}

void GRUpdateManager::updateFilesDownloaded()
{
    //disconnect(this,SIGNAL(downloadDone()),this,SLOT(updateFilesDownloaded()));
    QString downloadPath=QDir::current().absolutePath()+"/temp";
    QString updateFilePath=downloadPath+"/"+updateFileName;
    QString tmp;
    QDir downloadDir(downloadPath);
    if(!downloadDir.exists() || ! QFile::exists(updateFilePath))
    {
        log("no updates available...");
        return;
    }
    if(!newFileList.parse(updateFilePath))
    {
        log("cannot perform updates...");
        return;
    }

    for(int i=0;i< newFileList.fileList.length();i++)
    {
        tmp=downloadPath+"/"+newFileList.fileList[i].fileName;
        if(QFileInfo::exists(tmp))
        {
            QFile file(tmp);
            QString destination=QDir::current().absolutePath();
            if(newFileList.fileList[i].destination=="*")
            {
                destination+="/"+newFileList.fileList[i].fileName;
            }
            else
            {
                destination+="/"+newFileList.fileList[i].destination+"/"+newFileList.fileList[i].fileName;
            }
            if(QFileInfo::exists(destination))
            {
                if(!QFile::remove(destination))
                {
                    log(
                        tr("cannot remove old file: %1")
                        .arg(destination)
                        );
                    continue;
                }
            }
           if(!file.copy(destination))
           {
               log(
                   tr("cannot copy downloaded file to destination: %1")
                   .arg(destination)
                   );
           }
        }
    }
    if(!QFile::remove(oldFileListPath))
    {
        log(
            tr("cannot remove old update file: %1")
            .arg(oldFileListPath)
            );
        return;
    }
    newFileList.save(oldFileListPath);
    if(!downloadDir.removeRecursively())
    {
        log(
            tr("cannot empty download directory: %1\nPlease close any programs using it or deleted manually and try again.")
            .arg(downloadDir.absolutePath())
            );
        return;
    }
    log("downloads applied successfully...");

}
