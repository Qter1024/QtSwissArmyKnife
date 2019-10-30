﻿/*
 * The file is encoding with utf-8 (with BOM)
 *
 * I write the comment with English, it's not because that I'm good at English,
 * but for "installing B".
 *
 * Copyright (C) 2018-2018 wuhai persionnal. All rights reserved.
 */
#include "SAKGlobal.hh"

#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include <QDebug>

SAKGlobal::SAKGlobal(QObject* parent)
    :QObject (parent)
{

}

QString SAKGlobal::logFile()
{
    QString fileName = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);

    QDir dir;
    if (!dir.exists(fileName)){
        SAKGlobal::mkMutiDir(fileName);
    }    

    fileName.append("/");
    fileName.append("QtSwissArmyKnife.txt");

    return fileName;
}

QString SAKGlobal::dataPath()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);

    QDir dir;
    if (!dir.exists(path)){
        mkMutiDir(path);
    }

    return path;
}

QString SAKGlobal::mkMutiDir(const QString path){

    QDir dir(path);
    if (dir.exists(path)){
        return path;
    }

    QString parentDir = mkMutiDir(path.mid(0,path.lastIndexOf('/')));
    QString dirname = path.mid(path.lastIndexOf('/') + 1);
    QDir parentPath(parentDir);

    if ( !dirname.isEmpty() ){
        parentPath.mkpath(dirname);
    }

    return parentDir + "/" + dirname;
}

QString SAKGlobal::getIODeviceTypeName(int type)
{
    QString name;
    switch (type) {
    case SAKEnumDebugPageTypeUDP:
        name = tr("UDP调试");
        break;
    case SAKEnumDebugPageTypeTCPClient:
        name = tr("TCP客户端");
        break;
    case SAKEnumDebugPageTypeTCPServer:
        name = tr("TCP服务器");
        break;
#ifdef SAK_IMPORT_COM_MODULE
    case SAKEnumDebugPageTypeCOM:
        name = tr("串口调试");
        break;
#endif
    default:
        Q_ASSERT_X(false, __FUNCTION__, "Unknow debug page type");
        break;
    }

    return name;
}
