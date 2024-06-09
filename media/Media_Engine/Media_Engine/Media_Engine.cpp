// Media_Engine.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "Media_Engine.hpp"

int main(int argc, char* argv[])
{

	try {
		if (argc != 3) {
			log::error("Address infomatin not enough");
			return -1;
		}

		auto const addr = boost::asio::ip::make_address(argv[1]);
		auto const port = static_cast<unsigned short>(std::stoi(argv[2]));

		boost::asio::io_context ioc{ 1 };

		std::make_shared<websocket::WebSocketListener>(ioc, boost::asio::ip::tcp::endpoint{ addr, port })->run();

		ioc.run();

	}
	catch (const std::exception& e) {
		//	print error log
		return -1;
	}
	return 0;
}
