#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>

class TCPClient {
    int clientSocket;
    sockaddr_in serverAddress{};
    bool running;

public:
    explicit TCPClient(const char* serverIP = "127.0.0.1", int port = 8080);

    void sendMessage(const char* message) const;

    void sendMessage(const std::string& message) const;

    void receiveMessages();

    void start();

    void stop();

    virtual ~TCPClient();

    virtual void handleMessage(const std::string& message);

};