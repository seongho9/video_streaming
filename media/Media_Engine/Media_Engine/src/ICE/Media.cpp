#include "ICE/SDP.hpp"
using namespace media_engine::ICE;

//constructor
Media::Media()
{
	this->_media = nullptr;
	this->_port = nullptr;
	this->_protocol = nullptr;
	this->_format = nullptr;
	this->_attribute = nullptr;
}
Media::Media(std::string param)
{
	std::vector<int> split;

	split.push_back(-1);

	for (int i = 0; i < param.length(); i++) {
		if (param[i] == ' ') {
			split.push_back(i);
		}
	}
	
	split.push_back(param.length());

	if (split.size() < 5) {
		spdlog::error("m= tag has not enough infomation");

		return;
	}
	else {
		this->set_media(param.substr(split[0] + 1, split[1] - split[0] + 1));
		this->set_port(param.substr(split[1] + 1, split[2] - split[1] + 1));
		this->set_protocol(param.substr(split[2] + 1, split[3] - split[2] + 1));
		this->set_format(param.substr(split[3] + 1, param.length() - split[3] + 1));
	}
}
Media::Media(Media& rhs)
{
	this->set_media(rhs.get_media());
	this->set_port(rhs.get_port());
	this->set_protocol(rhs.get_protocol());
	this->set_format(rhs.get_format());
	this->set_attribute(rhs.get_attribute());
}
Media::Media(Media&& rhs):_media(std::move(rhs._media)), _port(std::move(rhs._port)), 
	_protocol(std::move(rhs._protocol)), _format(std::move(rhs._format)), _attribute(rhs._attribute)
{
	rhs._media = nullptr;
	rhs._port = nullptr;
	rhs._protocol = nullptr;
	rhs._format = nullptr;
	rhs._attribute = nullptr;
}
Media::~Media()
{
	if (_media != nullptr) {
		delete _media;
	}
	if (_port != nullptr) {
		delete _port;
	}
	if (_protocol != nullptr) {
		delete _protocol;
	}
	if (_format != nullptr) {
		delete _format;
	}
	if (_attribute != nullptr) {
		delete _attribute;
	}
}
//getter
std::string Media::get_media() const
{
	if (this->_media == nullptr) {
		return "";
	}

	return *(this->_media);
}
std::vector<int> Media::get_port() const
{
	if (_port == nullptr) {
		return;
	}

	return *(this->_port);
}
Protocol Media::get_protocol() const
{
	if (_protocol == nullptr) {
		return;
	}

	return *(this->_protocol);
}
std::vector<int> Media::get_format() const
{
	if (_format == nullptr) {
		return;
	}

	return *(this->_format);
}
std::vector<Attribute> Media::get_attribute() const
{
	if (_attribute == nullptr) {
		return;
	}

	return *(this->_attribute);
}

//setter
void Media::set_media(const std::string& media)
{
	if (_media != nullptr) {
		delete _media;
	}
	this->_media = new std::string;
	*(this->_media) = media;
}

void Media::set_port(const int& port)
{
	if (_port == nullptr) {
		this->_port = new std::vector<int>;
	}
	_port->push_back(port);
}
void Media::set_port(const std::string& port)
{
	if (_port == nullptr) {
		this->_port = new std::vector<int>;
	}

	size_t idx = port.find('/');
	if (idx == std::string::npos) {
		_port->push_back(std::stoi(port));
	}
	else {
		size_t size = std::stoi(port.substr(idx, port.length())) - 1;
		int port_num = std::stoi(port.substr(0, idx));

		while (size > 0) {
			_port->push_back(port_num + (int)size);
			size--;
		}
	}
}
void Media::set_port(const std::vector<int>& ports)
{
	if (_port != nullptr) {
		delete _port;
		_port = new std::vector<int>;
	}
	*(this->_port) = ports;
}

void Media::set_protocol(const Protocol& proto)
{
	if (_protocol == nullptr) {

		_protocol = new Protocol;
	}
	*(_protocol) = proto;
}
void Media::set_protocol(const std::string& proto)
{
	if (_protocol == nullptr) {

		_protocol = new Protocol;
	}

	if (proto.compare("RTP/AVP") == 0) {
		*_protocol = Protocol::RTP_AVP;
	}
	else if (proto.compare("RTP/SAVP") == 0) {
		*_protocol = Protocol::RTP_SAVP;
	}
	else if (proto.compare("UDP") == 0) {
		*_protocol = Protocol::UDP;
	}
}

void Media::set_format(const int& format)
{
	if (_format == nullptr) {
		_format = new std::vector<int>;
	}

	_format->push_back(format);
}
void Media::set_format(const std::string& format)
{
	if (_format == nullptr) {
		_format = new std::vector<int>;
	}

	int prev = 0;
	for (int i = 0; i < format.length(); i++) {
		if (format[i] == ' ') {
			_format->push_back (std::stoi(format.substr(prev, i)) );
		}
	}
}
void Media::set_format(const std::vector<int>& formats)
{
	if (_format == nullptr) {
		_format = new std::vector<int>;
	}

	*_format = formats;
}

void Media::set_attribute(const Attribute& attri)
{
	if (_attribute == nullptr) {
		_attribute = new std::vector<Attribute>;
	}

	_attribute->push_back(attri);
}
void Media::set_attribute(const std::vector<Attribute>& attri)
{
	if (_attribute == nullptr) {
		_attribute = new std::vector<Attribute>;
	}

	*_attribute = attri;
}

//to_string
std::string Media::to_string()
{
	std::stringstream stream;
	//media
	stream << this->get_media() << " ";
	//port
	stream << this->get_port()[0];
	if (this->_port->size() > 1) {
		stream << "/" << this->get_port().size();
	}
	stream << " ";
	//proto
	Protocol proto = this->get_protocol();
	if (proto == Protocol::RTP_AVP) {
		stream << "RTP/AVP ";
	}
	else if (proto == Protocol::RTP_SAVP) {
		stream << "RTP/SAVP ";
	}
	else if (proto == Protocol::UDP) {
		stream << "UDP";
	}
	//fmt
	for (int number : this->get_format()) {
		stream << number << " ";
	}

	return stream.str();
}