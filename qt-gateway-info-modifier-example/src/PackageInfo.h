#ifndef PANAMA_PACKAGE_INFO_H
#define PANAMA_PACKAGE_INFO_H

#include <QtCore>

class PackageInfo {

public:

    QString name;

    QString version;

    PackageInfo() {
    }

    PackageInfo(QVariantMap map) :
        name(map["name"].toString()),
        version(map["version"].toString()) {
    }

    const QVariantMap toMap() {
        QVariantMap map;
        map["name"] = name;
        map["version"] = version;
        return map;
    }

private:


};

#endif