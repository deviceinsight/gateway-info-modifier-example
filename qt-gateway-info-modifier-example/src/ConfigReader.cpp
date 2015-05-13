#include <QtCore>
#include <qxtjson.h>
#include "ConfigReader.h"


static const int MAX_LINE_LEN = 8192;


ConfigReader::ConfigReader(QSharedPointer<QTextStream> _stream, QObject* _parent)
    : QThread(_parent), stream(_stream) {
}


GatewayInfoMessage ConfigReader::readConfig() {
    if(!stream->atEnd()) {
        QString str = stream->readLine(MAX_LINE_LEN);

        if(stream->status() != QTextStream::Ok) {
            QCoreApplication::exit(0);
            return GatewayInfoMessage();
        } else {
            QVariantMap cfgMap = QxtJSON::parse(str).toMap();
            //qDebug() << "CONFIG:" << cfgMap;
            GatewayInfoMessage gwInfo(cfgMap);
            return gwInfo;
        }
    } else {
        QCoreApplication::exit(0);
        return GatewayInfoMessage();
    }
}

