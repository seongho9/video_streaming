#include "ICE/SDP.hpp"

using namespace media_engine::ICE;

//constructor
Attribute::Attribute() 
{
	_type = nullptr;
	_value = nullptr;
}
Attribute::Attribute(std::string param)
{
	size_t idx = param.find(':');

	set_type(param.substr(0, idx));
	set_value(param.substr(idx + 1));
}
Attribute::Attribute(Attribute& rhs)
{
	set_type(rhs.get_type());
	set_value(rhs.get_value());
}
Attribute::Attribute(Attribute&& rhs)
{
	_type = rhs._type;
	rhs._type = nullptr;

	_value = rhs._value;
	rhs._value = nullptr;
}

//destructor
Attribute::~Attribute()
{
	if (_type != nullptr) {
		delete _type;
	}
	if (_value != nullptr) {
		delete _value;
	}
}
//setter
void Attribute::set_type(const std::string& type)
{
	if (_type != nullptr) {
		delete _type;

		_type = nullptr;
	}

	_type = &std::string(type);
}

void Attribute::set_value(const std::string& value)
{
	if (_value != nullptr) {
		delete _value;

		_value = nullptr;
	}

	_value = &std::string(value);
}

//getter
std::string& Attribute::get_type()
{
	if (_type == nullptr) {
		return std::string("");
	}

	return *_type;
}
std::string& Attribute::get_value()
{
	if (_value == nullptr) {
		return std::string("");
	}

	return *_value;
}