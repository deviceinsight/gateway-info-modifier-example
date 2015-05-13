#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <QtCore>
#include "GatewayInfoMessage.h"

class ConfigReader :  public QThread {

    Q_OBJECT

private:
    QSharedPointer<QTextStream> stream;

public:
    explicit ConfigReader(QSharedPointer<QTextStream> _stream, QObject* _parent = 0);

    GatewayInfoMessage readConfig();


};

#endif
