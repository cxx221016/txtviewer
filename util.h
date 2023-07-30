//
// Created by 86159 on 2023/7/27.
//

#ifndef TXTVIEWER_UTIL_H
#define TXTVIEWER_UTIL_H

#include<QString>
#include<QMap>

inline QString getbookname(const QString& path)
{
    int index=path.lastIndexOf('/');
    int pointindex=path.lastIndexOf('.');
    return path.mid(index+1,pointindex-index-1);
}

inline QString removespace(const QString& line)
{
    QString newline;
    for(int i=0;i<line.length();i++)
    {
        if(line[i]!=' ')
            newline+=line[i];
    }
    return newline;
}

inline bool ischaptername(const QString& line)
{
    if(line.contains("第")&&line.contains("章"))
        return true;
    else
        return false;
}

static QMap<QString,int> number_map
        {
            {"零",0},
            {"一",1},
            {"二",2},
            {"三",3},
            {"四",4},
            {"五",5},
            {"六",6},
            {"七",7},
            {"八",8},
            {"九",9},
        };

static QMap<QString,int> unit_map
        {
            {"十",10},
            {"百",100},
            {"千",1000},
            {"万",10000},
            {"亿",100000000},
        };

inline QString cn2an(const QString& cnnumber)
{
    int annumber=0;
    int num=1;
    int unit=1;
    QVector<QString> tex;
    for(auto&& ch: cnnumber)
    {
        tex.push_back(ch);
    }
    for(int i=0;i<tex.size();++i)
    {
        if(number_map.count(tex[i]))
        {
            num=number_map[tex[i]];
            if(i==tex.size()-1)
            {
                annumber+=num;
            }
        }
        else if(unit_map.count(tex[i]))
        {
            unit=unit_map[tex[i]];
            annumber+=num*unit;
            num=0;
        }
        else
        {
            return "-1";
        }
    }
    return QString::number(annumber);
}

inline QString getcontentnumber(const QString& line)
{
    QString cnnumber;
    int bid=line.indexOf("第");
    int eid=line.indexOf("章");
    cnnumber=line.mid(bid+1,eid-bid-1);
    /*
    QString pyexecpath="python";
    QString pyfile="D:\\MY_CODE\\Clion\\txtviewer\\translation.py";
    QString pyarg="\""+cnnumber+"\"";

    QString pycmd=pyexecpath+" "+pyfile+" "+pyarg;
    //const char* cmd=pycmd.toStdString().c_str();
    const char* cmd=pycmd.toUtf8().data();
    //qDebug()<<cmd;
    char buffer[1024];
    FILE* pipe=_popen(cmd,"r");
    if(!pipe)
    {
        qDebug()<<"popen failed";
        return "";
    }
    while(!feof(pipe))
    {
        if(fgets(buffer,1024,pipe))
        {
            cnnumber=buffer;
        }
    }
    _pclose(pipe);
     */

    return cn2an(cnnumber);
}
#endif //TXTVIEWER_UTIL_H
