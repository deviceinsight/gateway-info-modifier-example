#ifndef PANAMA_GATEWAY_INFO_MESSAGE_H
#define PANAMA_GATEWAY_INFO_MESSAGE_H

#include <QtCore>
#include "PanamaMessage.h"
#include "StreamConnectorInfo.h"
#include "PackageInfo.h"
#include "MobileInterfacesInfo.h"

class GatewayInfoMessage : public PanamaMessage {

public:

    QList<QString> networkInterfaces;
    QList<QString> gatewayCapabilities;
    QList<StreamConnectorInfo> streamConnectors;
    QList<PackageInfo> installedPackages;
    QList<MobileInterfacesInfo> mobileInterfaces;
    QVariantMap extraInfoMap;

    GatewayInfoMessage() : PanamaMessage() {
    }

    GatewayInfoMessage(QVariantMap& map) :
        PanamaMessage(map) {

        foreach(QVariant v, map["networkInterfaces"].toList()) {
            networkInterfaces << v.toString();
        }

        foreach(QVariant v, map["gatewayCapabilities"].toList()) {
            gatewayCapabilities << v.toString();
        }

        foreach(QVariant v, map["streamConnectors"].toList()) {
            StreamConnectorInfo streamConnector(v.toMap());
            streamConnectors << streamConnector;
        }

        foreach(QVariant v, map["packages"].toList()) {
            PackageInfo package(v.toMap());
            installedPackages << package;
        }

        foreach(QVariant v, map["mobileInterfaces"].toList()) {
            MobileInterfacesInfo mobileInterfacesInfo(v.toMap());
            mobileInterfaces << mobileInterfacesInfo;
        }

        extraInfoMap = map ["extraInfo"].toMap();
    }

    QVariantMap toMap() {

        QVariantMap map = PanamaMessage::toMap();

        QStringList networkInterfaceList;
        foreach(QString networkInterface, networkInterfaces) {
            networkInterfaceList << networkInterface;
        }

        map["networkInterfaces"] = networkInterfaceList;

        QStringList gatewayCapabilityList;
        foreach(QString gatewayCapability, gatewayCapabilities) {
            gatewayCapabilityList << gatewayCapability;
        }

        map["gatewayCapabilities"] = gatewayCapabilityList;

        QVariantList streamConnectorList;
        foreach(StreamConnectorInfo streamConnector, streamConnectors) {
            streamConnectorList << streamConnector.toMap();
        }

        map["streamConnectors"] = streamConnectorList;

        QVariantList packagesList;
        foreach(PackageInfo package, installedPackages) {
            packagesList << package.toMap();
        }

        map["packages"] = packagesList;

        QVariantList mobileIfList;
        foreach(MobileInterfacesInfo mobileInterfacesInfo, mobileInterfaces) {
            mobileIfList << mobileInterfacesInfo.toMap();
        }
        map ["mobileInterfaces"]  = mobileIfList;

        map ["extraInfo"] = extraInfoMap;

        return map;
    }

    QString messageType() {
        return "gatewayInfo";
    }

private:

};

#endif