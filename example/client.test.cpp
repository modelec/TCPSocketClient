#include <TCPSocket/TCPClient.hpp>

int main(int argc, char* argv[]) {

    int port = 8080;
    if (argc >= 2) {
        port = std::stoi(argv[1]);
    }

    TCPClient client("127.0.0.1", port); // Replace "127.0.0.1" with the IP address of your server and 8080 with the port number

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
