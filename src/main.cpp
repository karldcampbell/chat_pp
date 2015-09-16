#include <iostream>
#include <thread>
#include "duffel_server_handler.hpp"

using namespace boost::network::http;

int main()
{
	std::cout << "hello" << std::endl;

	duffel_handler handler;
	duffel_server::options options(handler);
	options.address("0.0.0.0").port("8080");
	
	duffel_server duffel(options);
	
	std::thread a(&duffel_server::run, &duffel);
	std::thread b(&duffel_server::run, &duffel);
	std::thread c(&duffel_server::run, &duffel);
	std::thread d(&duffel_server::run, &duffel);
	std::thread e(&duffel_server::run, &duffel);
	
	a.join();
	b.join();
	c.join();
	d.join();
	e.join();
	
	
	return 0;
}
