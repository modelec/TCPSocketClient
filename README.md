# TCP Socket Client Lib for Modelec Robot !


### How to install
```bash
git clone https://github.com/modelec/TCPSocketClient.git
cd TCPSocketClient
mkdir build && cd build
cmake ..
sudo make install
```

### How to use
Create a class that inherit from TCPClient and implement the method handleMessage
```c++
#include <TCPSocket/TCPClient.hpp>

class MyClient : public TCPClient {
public:

    explicit MyClient(const char* ip = "127.0.0.1", int port = 8080) : TCPClient(ip, port) {}

    void handleMessage(const std::string& message) override {
        std::cout << "Message received : " << message << std::endl;
    }
}

int main() {
    MyClient client("127.0.0.1", 8080);

    client.start();

    while (true) {
        std::string message;
        std::cout << "Enter message ('quit' to exit): ";
        std::getline(std::cin, message);

        if (message == "quit") {
            client.stop();
            break;
        }

        client.sendMessage(message.c_str());
    }

    return 0;
}
```

CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.20)
project(MyClient)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(TCPSocket REQUIRED TCPSocket)

add_executable(MyClient MyClient.cpp)

target_link_libraries(MyClient TCPSocket)
```

### What that do
The client start a thread that listen to the server and call the method handleMessage when a message is received.


### Trubleshooting
If you have an error when you start the program and it tell you that the Lib.so is not find you need to export :
```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/lib
```
the path to lib is the folder that the sudo make install command give you.