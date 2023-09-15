//WILL BE THREADED LATER

#include "threadmanager.h"
#include "qaesencryption.h"

#include <QCryptographicHash>
#include <QDebug>

//Main variable for the encryption functions.
QAESEncryption *enc;

//Encrypt function, largely credited to https://github.com/bricke/Qt-AES
QString threadmanager::encrypt(QString in, QString key)
{
    //Convert key string to hash, create base IV.
    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    QByteArray hashIV = QCryptographicHash::hash(QString("Default").toLocal8Bit(), QCryptographicHash::Md5);

    //Encrypt input text to byte array
    QByteArray encodeText = enc->encode(in.toLocal8Bit(), hashKey, hashIV);

    //Convert byte array to string and return
    return QString::fromUtf8(encodeText.toBase64());;
}

//Decrypt function, largely credited to https://github.com/bricke/Qt-AES
QString threadmanager::decrypt(QString in, QString key)
{
    //Convert key string to hash, create base IV.
    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    QByteArray hashIV = QCryptographicHash::hash(QString("Default").toLocal8Bit(), QCryptographicHash::Md5);

    //Encode to string
    QByteArray encodeText = QByteArray::fromBase64(in.toUtf8());

    //Decrypt that string
    QByteArray decodeText = enc->decode(encodeText, hashKey, hashIV);

    //Return
    return QString(enc->removePadding(decodeText));
}


void threadmanager::run(QString in, QString key, bool mode)
{
    //Decide what method to use based on the 'mode' switch variable passed on from the UI.

    QString out;
    if(mode) out = encrypt(in, key);
    else out = decrypt(in, key);

    //Post signal, used to update interface (unlock the UI after it's been locked) and update the text box.
    emit update(out);

    //Redundant return cause why not.
    return;
}


threadmanager::threadmanager(QObject *parent)
    : QObject{parent}
{
    //Create main variable for encryption.
    enc = new QAESEncryption(QAESEncryption::AES_256, QAESEncryption::CBC);
}
