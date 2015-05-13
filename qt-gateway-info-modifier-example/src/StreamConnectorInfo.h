#ifndef PANAMA_STREAM_CONNECTOR_INFO_H
#define PANAMA_STREAM_CONNECTOR_INFO_H

#include <QtCore>

class StreamConnectorInfo {

public:

    QString name;

    QString description;

    StreamConnectorInfo() {
    }

    StreamConnectorInfo(QVariantMap map) :
        name(map["name"].toString()),
        description(map["description"].toString()) {
    }

    const QVariantMap toMap() {
        QVariantMap map;
        map["name"] = name;
        map["description"] = description;
        return map;
    }

private:


};

#endif