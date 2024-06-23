#include "ICE/SDP.hpp"

using namespace media_engine::ICE;

//constructor
Attribute::Attribute() 
{
	_type = "";
	_value = "";
}
Attribute::Attribute(Attribute& rhs)
{
	set_type(rhs.get_type());
	set_value(rhs.get_value());
}

//setter
void Attribute::set_type(const std::string& param)
{
	_type = param;
}

void Attribute::set_value(const std::string& param)
{
	_value = param;
}

//getter
std::string Attribute::get_type() const
{
	return _type;
}
std::string Attribute::get_value() const
{
	return _value;
}

std::string Attribute::to_string()
{
	std::stringstream stream;

	stream << _type << ":" << _value;

	return stream.str();
}