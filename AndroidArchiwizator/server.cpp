#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{
    socket = new QTcpSocket();
}

void Server::run()
{
<<<<<<< HEAD
    if(!this->listen(QHostAddress::Any, 1234)){
=======
    if(!this->listen(QHostAddress::LocalHost, 9000)){
>>>>>>> eksperymentInnyPort
        qDebug() << "Nie mozna wystartowac serwera !";  // qmessage::error wyswietl ... ... lub jakies sprawdzanie czy juz wystartowal

    }
    else{
        qDebug() << "Server nasluchuje...";    // statusBar wyswietl ... ...
    }
}

void Server::receiveData(QByteArray data)
{
    emit sendingToGUI(data);
}

void Server::incomingConnection(int descriptor)
{
    qDebug() << descriptor << "Polaczony...";
    SrvThread* thread = new SrvThread(descriptor,this);

    connect( thread, SIGNAL( finished() ), thread, SLOT( deleteLater() ) );
    connect( thread, SIGNAL( readData(QByteArray) ), this, SLOT( receiveData(QByteArray) ) );

    thread->start();
 }

