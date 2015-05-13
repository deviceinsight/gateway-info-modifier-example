#ifndef PANAMA_HEADER_H
#define PANAMA_HEADER_H

class Header {

public:

    QString gatewayUrn;

    QString gatewayTypeUrn;

    QString messageId;

    QString correlationId;

    int version;

    QString creator;

    QString creatorVersion;

    Header() {
        version = 0; //set to avoid big random int if not set
    }

    Header(QVariantMap map) :
        gatewayUrn(map["gatewayUrn"].toString()),
        gatewayTypeUrn(map["gatewayTypeUrn"].toString()),
        messageId(map["messageId"].toString()),
        correlationId(map["correlationId"].toString()),
        version(map["version"].toInt()),
        creator(map["creator"].toString()),
        creatorVersion(map["creatorVersion"].toString()) {
    }

    QVariantMap toMap() {
        QVariantMap map;
        map["gatewayUrn"] = gatewayUrn;
        map["gatewayTypeUrn"] = gatewayTypeUrn;
        map["messageId"] = messageId;
        map["correlationId"] = correlationId;
        map["version"] = version;
        map["creator"] = creator;
        map["creatorVersion"] = creatorVersion;
        return map;
    }

private:

};

#endif