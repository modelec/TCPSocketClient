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
    sockaddr_in serverAddress;
    bool running;
    //void (*callback)(const std::string& message);

public:
    TCPClient(const char* serverIP = "127.0.0.1", int port = 8080/*, void (*callback)(const std::string& message) = [](const std::string& message) { std::cout << message << std::endl; }*/);

    void sendMessage(const char* message);

    void receiveMessages();

    void start();

    void stop();

    virtual ~TCPClient();

    virtual void handleMessage(const std::string& message);

    //void setCallback(void (*callback)(const std::string& message));
};