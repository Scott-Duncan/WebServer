#include <iostream>

// ASIO Libraries
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

int main() {
  std::cout << "Started web server example..." << std::endl;
  asio::error_code ec;
  std::string endpoint_addr = "51.38.81.49";

  // Create a context for asio to run
  asio::io_context context;

  std::cout << "Making endpoint at address [" << endpoint_addr << "]"
            << std::endl;
  // Make a tcp endpoint
  asio::ip::tcp::endpoint endpoint(asio::ip::make_address(endpoint_addr, ec),
                                   80);

  // create a socket for asio to connect to
  std::cout << "Creating socket" << std::endl;
  asio::ip::tcp::socket socket(context);

  // Tell socket to try and connect to endpoint we defined earlier
  std::cout << "Attempting to connect socket" << std::endl;
  socket.connect(endpoint, ec);

  if (!ec) {
    std::cout << "Socket connected to endpoint!" << std::endl;
  } else {
    std::cerr << "Uh oh! Unable to connect to socket because [" << ec.message()
              << "]" << std::endl;
  }

  if (socket.is_open()) {
    std::cout << "Socket is open " << std::endl;
  }

  return 0;
}
