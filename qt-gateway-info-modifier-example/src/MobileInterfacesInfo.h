#ifndef PANAMA_MOBILE_INTERFACES_INFO_MESSAGE_H
#define PANAMA_MOBILE_INTERFACES_INFO_MESSAGE_H

#include <QtCore>

class MobileInterfacesInfo {

public:
    QString imsi;
    QString imei;
    QString icc;

    MobileInterfacesInfo() {}
    MobileInterfacesInfo(QVariantMap map) {
        imsi = map["imsi"].toString();
        imei = map["imei"].toString();
        icc = map["icc"].toString();

    }

    QVariantMap toMap() {

        QVariantMap map;
        map["imsi"] = imsi;
        map["imei"] = imei;
        map["icc"] = icc;

        return map;
    }

};


#endif