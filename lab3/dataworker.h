#ifndef DATAWORKER_H
#define DATAWORKER_H

#include <QObject>
#include <QDateTime>
#include <QMetaType>
#include <QList>
//必须包含QMetaType，否则会出现下面错误：
//error: expected constructor, destructor, or type conversion before ‘;’ token
#include <QString>

class QNetworkAccessManager;
class QNetworkReply;
class QSslError;

class Message{
private:

public:
    Message();
    Message(const Message &other);
    ~Message();

    QString l1;
    QString l2;

};

Q_DECLARE_METATYPE(Message)


class dataWorker : public QObject
{
    Q_OBJECT
public:
    explicit dataWorker(QObject *parent = 0);
    explicit dataWorker(QString date, QObject *parent = 0);

    void setRequestCity(QString newCity);
    void setRequestDate(QString newDate);

    void setSwitchNum(int num);
    int switch_Num;

    QString requestCity();
    QString requestDate();

    void doRequest();

protected:
    QString requestUrl();
    void httpGet(QString url);
    void initNetwork();
    void parseHTML(const QString sourceText);
    void parseData(const QString sourceText);
    void exportDataToFile(const QString dataText);

protected slots:
    void httpsFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString _requestCity;
    QString _requestDate;

    QList<QDateTime> dataDate;              // 日期
    QList<qreal> dataHigh;                  // 最高温度
    QList<qreal> dataLow;                   // 最低温度
    QList<qreal> dataAQI;
    QList<qreal> dataPM25;

    const QString splitter;
    const QString dataPath;

signals:
    void dataParseFinished(QList<QDateTime> date,QList<qreal> high, QList<qreal> low);

};


#endif // DATAWORKER_H
