#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>

#include "qaesencryption.h"

class threadmanager : public QObject
{
    Q_OBJECT
public:
    explicit threadmanager(QObject *parent = nullptr);

signals:
    void update(QString s);

public slots:
    QString encrypt(QString in, QString key);
    QString decrypt(QString in, QString key);

    void run(QString in, QString key, bool mode);
};

#endif // THREADMANAGER_H
