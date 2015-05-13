#include <QtCore>

#include <QDebug>
#include <QtCore/QList>
#include <qxtjson.h>

#include "ConfigReader.h"
#include "GatewayInfoMessage.h"

static bool showPorts = false;

void modifyGatewayInfoMessage(GatewayInfoMessage* msg);
QString getPropertyFromRdb(QString property);


int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);


    QTextStream streamStdout(stdout);
    QSharedPointer<QTextStream> streamStdinPtr = QSharedPointer<QTextStream>(new QTextStream(stdin));

    ConfigReader *cfgr = new ConfigReader(streamStdinPtr, &a);
    GatewayInfoMessage cfgMap = cfgr->readConfig();

    modifyGatewayInfoMessage(&cfgMap);

    QString json = QxtJSON::stringify(cfgMap.toMap());

    streamStdout << json << "\n";
    streamStdout.flush();

}


void modifyGatewayInfoMessage(GatewayInfoMessage* msg) {

    QString imei = getPropertyFromRdb("wwan.0.imei");
    QString imsi = getPropertyFromRdb("wwan.0.imsi.msin");

    MobileInterfacesInfo tmp;
    tmp.imei = imei;
    tmp.imsi = imsi;
    tmp.icc = "";

    msg->mobileInterfaces.append(tmp);

}


QString getPropertyFromRdb(QString property) {
    int retryCounter = 5;

    QString prop;

    while(prop.isEmpty() && retryCounter > 0) {

        retryCounter--;
        QProcess proc;
        proc.start("/usr/bin/rdb get " + property);

        if(proc.waitForStarted()) {
            if(proc.waitForFinished()) {
                QByteArray result = proc.readAll().trimmed();

                if(!result.isEmpty()) {
                    prop = QString(result);
                    return prop;
                }
            }

        }
    }

    return QString();
}



