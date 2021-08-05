#include "grfileinfo.h"
#include <iostream>
using namespace std;

/*!
 * \brief Constructs a GRFileInfo object with empty fields;
 */
GRFileInfo::GRFileInfo()
{
    fileName="";
    destination="*";
    version=0;
}

/*!
 * \brief GRFileInfo::GRFileInfo
 * \param fileName
 * \param destination
 * \param version
 */
GRFileInfo::GRFileInfo(QString fileName, QString destination, int version)
{
    this->fileName=fileName;
    this->destination=destination;
    this->version=version;
}

GRFileInfo::CompareResults GRFileInfo::compare(GRFileInfo &file)
{
    if(fileName != file.fileName)
    {
        return DifferentFileNames;
    }
    if(destination != file.destination)
    {
        return DifferentDestination;
    }
    if(version==file.version)
    {
        return Same;
    }
    else if(version>file.version)
    {
        return Newer;
    }
    else
    {
        return Older;
    }
}

bool GRFileInfo::updateFromXMLElement(QDomElement element)
{
    QString name,destination;
    int version;
    if(element.nodeName()=="file")
    {
        QDomNodeList children,x,y;
        children=element.childNodes();
        if(children.length()==3)
        {
            x=element.elementsByTagName("fileName");
            if(x.length()!=1)
            {
                return false;
            }
            y=x.at(0).childNodes();
            if(y.length()!=1)
            {
                return false;
            }
            name=y.at(0).toText().nodeValue();
            x=element.elementsByTagName("destination");
            if(x.length()!=1)
            {
                return false;
            }
            y=x.at(0).childNodes();
            if(y.length()!=1)
            {
                return false;
            }
            destination=y.at(0).toText().nodeValue();
            x=element.elementsByTagName("version");
            if(x.length()!=1)
            {
                return false;
            }
            y=x.at(0).childNodes();
            if(y.length()!=1)
            {
                return false;
            }
            bool ok=true;
            version=y.at(0).toText().nodeValue().toInt(&ok);
            if(!ok)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    this->fileName=name;
    this->destination=destination;
    this->version=version;
    return true;

}

QDomNode GRFileInfo::exportToXMLNode()
{
    QDomNode root;
    QDomNode *elementNode;
    QDomText *textNode;
    elementNode=new QDomElement;
    ((QDomElement *)elementNode)->setTagName("file");
    root=*elementNode;
    elementNode=new QDomElement;
    ((QDomElement *)elementNode)->setTagName("fileName");
    textNode=new QDomText;
    textNode->setNodeValue(fileName);
    elementNode->appendChild(*textNode);
    root.appendChild(*elementNode);
    elementNode=new QDomElement;
    ((QDomElement *)elementNode)->setTagName("version");
    textNode=new QDomText;
    textNode->setNodeValue(QString::number(version));
    elementNode->appendChild(*textNode);
    root.appendChild(*elementNode);
    elementNode=new QDomElement;
    ((QDomElement *)elementNode)->setTagName("destination");
    textNode=new QDomText;
    textNode->setNodeValue(destination);
    elementNode->appendChild(*textNode);
    root.appendChild(*elementNode);
    return root;
}
