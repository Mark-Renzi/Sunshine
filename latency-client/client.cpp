#include <boost/asio.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

using boost::asio::ip::udp;

const int BROADCAST_PORT = 44444;

int main() {
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), BROADCAST_PORT));
        socket.set_option(boost::asio::socket_base::broadcast(true));

        while (true) {
            unsigned int data;
            udp::endpoint sender_endpoint;

            size_t len = socket.receive_from(boost::asio::buffer(&data, sizeof(data)), sender_endpoint);
            
            std::cout << "Received Round Trip Time: " << data << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
