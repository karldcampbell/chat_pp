#pragma once

#include <boost/network/protocol/http/server.hpp>
#include <sstream>
#include <string>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


struct duffel_handler;
typedef boost::network::http::server<duffel_handler> duffel_server;

struct url_entry {
	std::string url;
	long date_added;
};

std::string to_json(const url_entry &e){
	rapidjson::StringBuffer s;
	rapidjson::Writer<rapidjson::StringBuffer> writer(s);

	writer.StartObject();
	writer.String("url"); writer.String(e.url.c_str());
	writer.String("date"); writer.Uint(e.date_added);
	writer.EndObject();

	return s.GetString();
}

class duffel_handler {
	public:

	void operator() (duffel_server::request & req, duffel_server::response & resp);
	void log(duffel_server::string_type const & info);

	private:
	void handle_get(duffel_server::request & req, duffel_server::response & resp);
};


void duffel_handler::operator() (duffel_server::request & req, duffel_server::response & resp)
{
	std::cout<< "got a " << req.method << " on " << req.destination << std::endl;
	if(req.method == "GET"){
		handle_get(req, resp);
	}
	else {
		resp = duffel_server::response::stock_reply(duffel_server::response::not_supported);
	}
}


void duffel_handler::log(duffel_server::string_type const & info)
{
	std::cout << "ERROR : " << info << std::endl;	
}
	
void duffel_handler::handle_get(duffel_server::request & req, duffel_server::response & resp)
{
	url_entry e = {"Hello!", 1234};
	//std::cout << to_json(e) << std::endl;
	resp = duffel_server::response::stock_reply(
		duffel_server::response::ok, to_json(e));

}
