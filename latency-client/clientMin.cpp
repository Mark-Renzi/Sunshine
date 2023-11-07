#include <boost/asio.hpp>

using boost::asio::ip::udp;

int main() {
    try {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 44444));
        socket.set_option(boost::asio::socket_base::broadcast(true));

        while (true) {
            unsigned int data;
            udp::endpoint sender_endpoint;

            size_t len = socket.receive_from(boost::asio::buffer(&data, sizeof(data)), sender_endpoint);
		}
    }
    catch (std::exception& e) {
    }

    return 0;
}
