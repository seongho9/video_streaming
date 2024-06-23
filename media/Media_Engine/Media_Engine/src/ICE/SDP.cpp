#include "ICE/SDP.hpp"

using namespace media_engine::ICE;

SDP::SDP()
{
	_version = -1;
	_origin = nullptr;
	_session_name = "";
	_information = "";
	_uri = "";
	_phone = "";
	_media = {};
	_attri = {};
}
SDP::SDP(SDP& rhs)
{
	set_version(rhs.get_version());
	set_origin(&rhs.get_origin());
	set_session_name(rhs.get_session_name());
	set_information(rhs.get_infomation());
	set_uri(rhs.get_uri());
	set_phone(rhs.get_phone());
	set_media(rhs.get_media());
	set_attribute(rhs.get_attribute());
}

SDP::~SDP()
{
	if (_origin != nullptr) {
		delete _origin;
	}
}

std::string SDP::to_string()
{
	std::stringstream stream;
	
	stream << "v=" << _version << "\n";
	stream << "o=" << _origin->to_string() << "\n";
	stream << "s=" << _session_name << "\n";
	stream << "c=" << _origin->get_network_type() << " " << _origin->get_address_type() << " " << "\n";
	stream << "t=" << "0 0\n";

	for (Media media : _media) {
		stream << "m=" << media.to_string();
		for (Attribute attri : media.get_attribute()) {
			stream << "a=" << attri.to_string();
		}
	}
	
	return stream.str();
}

void SDP::set_version(const short& version)
{
	_version = version;
}
void SDP::set_origin(Origin* origin)
{
	if (_origin != nullptr) {
		delete _origin;
	}
	_origin = origin;
}
void SDP::set_session_name(const std::string& session_name)
{
	_session_name = session_name;
}
void SDP::set_information(const std::string& info)
{
	_information = info;
}
void SDP::set_uri(const std::string& uri)
{
	_uri = uri;
}
void SDP::set_phone(const std::string& phone)
{
	_phone = phone;
}
void SDP::set_media(const std::vector<Media>& param)
{
	
	_media = param;
}
void SDP::add_media(const Media& param)
{
	_media.push_back(param);
}
void SDP::set_attribute(const std::vector<Attribute>& param)
{
	_attri = param;
}
void SDP::add_attribute(const Attribute& param)
{
	_attri.push_back(param);
}

short SDP::get_version() const
{
	return _version;
}
Origin SDP::get_origin() const
{
	return *_origin;
}
std::string SDP::get_session_name() const
{
	return _session_name;
}
std::string SDP::get_infomation() const
{
	return _information;
}
std::string SDP::get_uri() const
{
	return _uri;
}
std::string SDP::get_phone() const
{
	return _phone;
}
std::vector<Media> SDP::get_media() const
{
	return _media;
}
std::vector<Attribute> SDP::get_attribute() const
{
	return _attri;
}