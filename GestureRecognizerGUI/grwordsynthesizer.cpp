#include "grwordsynthesizer.h"
GRWordSynthesizer::GRWordSynthesizer()
{
    clear();
}

void GRWordSynthesizer::clear()
{
    str="";
    text="";
    emit textChanged(text);
}

void GRWordSynthesizer::del()
{
    int idx=-1;
    if(text != "")
    {
         text.remove(text.length()-1,1);
         idx=text.lastIndexOf(" ");
         if(idx!=-1)
         {
            str=text.left(text.length() -idx+1);
         }
         else
         {
             str=text;
         }
         emit textChanged(text);
    }
}

void GRWordSynthesizer::setText(QString txt)
{
    int idx;
    text=txt;
    idx=text.lastIndexOf(" ");
    if(idx!=-1)
    {
       str=text.left(text.length() -idx+1);
    }
    else
    {
        str=text;
    }
    emit textChanged(text);
}
QString GRWordSynthesizer::getText()
{
    return text;
}

QString GRWordSynthesizer::whatToSay(int gest)
{
    char c=char(gest);
    QChar qc(c);
    QString s="";
    if(qc.isLetter())
    {
        s=QString(qc);
        text+=s;
        str+=s;
        emit textChanged(text);
    }
    else if(qc.isSpace())
    {
        s=str;
        text+=" ";
        str="";
        emit textChanged(text);
    }
    else
    {
        s="";
    }
    return s;
}


