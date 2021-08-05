#include "grfilelist.h"

GRFileList::GRFileList()
{
    fileList.clear();
}

bool GRFileList::parse(QString xmlFile)
{
    QFile file(xmlFile);
    fileList.clear();

    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument domDocument;
    GRFileInfo *fileinfo;
    if (!domDocument.setContent(&file, true, &errorStr, &errorLine,&errorColumn))
    {
        fileList.clear();
        return false;
    }
    QDomElement root = domDocument.documentElement();
    if(root.nodeName()=="filelist")
    {
        QDomElement child = root.firstChildElement();
        while (!child.isNull())
        {
            if(child.nodeName()=="file")
            {
                fileinfo = new GRFileInfo;
                if(fileinfo->updateFromXMLElement(child))
                {
                    fileList.append(*fileinfo);
                }
                else
                {
                    fileList.clear();
                    return false;
                }
            }
            else
            {
                fileList.clear();
                return false;
            }
            child=child.nextSiblingElement();
        }
    }
    return true;
}

bool GRFileList::save(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
        return false;
    QXmlStreamWriter iStream(&file);
    iStream.setAutoFormatting(true);
    iStream.writeStartDocument();
    iStream.writeStartElement("filelist");
    for(int i=0;i<fileList.length();i++)
    {
        iStream.writeStartElement("file");
        iStream.writeTextElement("fileName", fileList[i].fileName);
        iStream.writeTextElement("version",QString::number(fileList[i].version));
        iStream.writeTextElement("destination",fileList[i].destination);
        iStream.writeEndElement();
    }
    iStream.writeEndElement();
    iStream.writeEndDocument();
    file.close();
    return true;
}

QList<GRFileInfo> GRFileList::getFilesToBeUpdated(QList<GRFileInfo> otherFileList)
{
    QList<GRFileInfo> list;
    QString filename;
    for (int i=0;i<fileList.length();i++)
    {
       filename=fileList[i].fileName;
       for(int j=0;j<otherFileList.length();j++)
       {
           if(fileList[i].compare(otherFileList[j])==GRFileInfo::Older)
           {
                list.append(otherFileList[j]);
                break;
           }
       }
    }
    bool found=false;
    for(int i=0;i<otherFileList.length();i++)
    {
        filename=otherFileList[i].fileName;
        found=false;
        for(int j=0;j<fileList.length();j++)
        {
            if(filename==fileList[j].fileName)
            {
                found=true;
            }
        }
        if(!found)
        {
            list.append(otherFileList[i]);
        }
    }
    return list;
}

QString GRFileList::getString()
{
    QString str="";
    for(int i=0;i<fileList.length();i++)
    {
        str+=QObject::tr("File name: %1 \nVersion: %2 \nDestination: %3 \n").arg(fileList[i].fileName).arg(QString::number(fileList[i].version)).arg(fileList[i].destination);
    }
    return str;
}

