#ifndef SOCKET_H
#define SOCKET_H
#include <QObject>
#include <QTcpSocket>
#include <QDebug>;

class Socket : public QObject
{
    Q_OBJECT
public:
    explicit Socket(QObject *parent = 0);

    void connect();
    void write();
    void send();

signals:

public slots:

private:
    QTcpSocket *socket;

};
#endif
