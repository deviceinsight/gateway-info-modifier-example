#ifndef PANAMA_MSG_H
#define PANAMA_MSG_H

#include <QtCore>

#include "Header.h"

class PanamaMessage {

public:

    PanamaMessage() {
    }

    PanamaMessage(QVariantMap map) : header(Header(map["header"].toMap())) {
    }

    Header header;

    virtual QString messageType() = 0;

    virtual QVariantMap toMap() {
        QVariantMap map;
        map["header"] = header.toMap();
        map["messageType"] = messageType();
        return map;
    }

private:

};

#endif