#include "ICE/SDP.hpp"

using namespace media_engine::ICE;


Origin::Origin()
{
	_username = "";
	_session_id = "";
	_session_ver = "";
	_address = "";

	_network_type = Network_Type::INTERNET;
	_address_type = Address_Type::IPV4;

	_address = "";
}

Origin::Origin(Origin& rhs)
{
	set_username(rhs.get_username());
	set_session_id(rhs.get_session_id());
	set_network_type(rhs.get_network_type());
	set_address_type(rhs.get_address_type());
	set_address(rhs.get_address());
}

std::string& Origin::get_username()
{
	return _username;
}

std::string& Origin::get_session_ver()
{
	return _session_ver;
}

std::string& Origin::get_session_id()
{
	return _session_id;
}

Network_Type& Origin::get_network_type()
{
	return _network_type;
}

Address_Type& Origin::get_address_type()
{
	return _address_type;
}

std::string& Origin::get_address()
{
	return _address;
}

void Origin::set_username(const std::string& param)
{
	_username = param;
}

void Origin::set_session_ver(const std::string& param)
{
	_session_ver = param;
}

void Origin::set_session_id(const std::string& param)
{
	_session_id = param;
}

void Origin::set_network_type(const Network_Type& param)
{
	_network_type = param;
}

void Origin::set_address_type(const Address_Type& param)
{
	_address_type = param;
}

void Origin::set_address(const std::string& param)
{
	_address = param;
}

std::string Origin::to_string()
{
	std::stringstream stream;

	stream << _username << " " << _session_id << " " << _session_ver << " ";
	if (_network_type == Network_Type::INTERNET) {
		stream << "IN ";
	}

	if (_address_type == Address_Type::IPV4) {
		stream << "IP4 ";
	}
	else if (_address_type == Address_Type::IPV6) {
		stream << "IP6 ";
	}

	stream << _address;

	return stream.str();
}