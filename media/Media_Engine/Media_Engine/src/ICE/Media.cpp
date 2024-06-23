#include "ICE/SDP.hpp"
using namespace media_engine::ICE;

//constructor
Media::Media()
{
	_media = "";
	_port = {};
	_protocol = Protocol::NONE;
	_format = {};
	_attribute = {};
}
Media::Media(Media& rhs)
{
	set_media(rhs.get_media());
	set_port(rhs.get_port());
	set_protocol(rhs.get_protocol());
	set_format(rhs.get_format());
	set_attribute(rhs.get_attribute());
}
//getter
std::string Media::get_media() const
{
	return _media;
}
std::vector<int> Media::get_port() const
{
	return _port;
}
Protocol Media::get_protocol() const
{
	return _protocol;
}
std::vector<int> Media::get_format() const
{
	return _format;
}
std::vector<Attribute> Media::get_attribute() const
{
	return _attribute;
}

//setter
void Media::set_media(const std::string& param)
{
	_media = param;
}

void Media::add_port(const int& param)
{
	_port.push_back(param);
}
void Media::set_port(const std::vector<int>& param)
{
	_port = param;
}

void Media::set_protocol(const Protocol& param)
{
	_protocol = param;
}

void Media::add_format(const int& param)
{
	_format.push_back(param);
}
void Media::set_format(const std::vector<int>& param)
{
	_format = param;
}

void Media::add_attribute(const Attribute& param)
{
	_attribute.push_back(param);
}
void Media::set_attribute(const std::vector<Attribute>& param)
{
	_attribute = param;
}

//to_string
std::string Media::to_string()
{
	std::stringstream stream;

	stream << _media;
	if (_port.size() > 1) {
		stream << " " << _port.at(0) << "/" << _port.size();
	}
	else {
		stream << " " << _port.at(0);
	}

	if (_protocol == Protocol::RTP_AVP) {
		stream << " RTP/AVP";
	}
	else if (_protocol == Protocol::RTP_SAVP) {
		stream << " RTP/SAVP";
	}
	else if (_protocol == Protocol::UDP) {
		stream << " UDP";
	}
	else {
		stream << "";
	}

	for (int fmt : _format) {
		stream << " " << fmt;
	}

	return stream.str();
}