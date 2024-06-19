#pragma once

#ifndef SDP_PACKET_HPP
#define SDP_PACKET_HPP

#include <string>
#include <sstream>
#include <vector>
#include <spdlog/spdlog.h>

namespace media_engine 
{
	namespace ICE
	{
		class SDP
		{
		public:

			SDP();
			SDP(std::string);
			SDP(SDP& rhs);

			~SDP();

			std::string to_string();

			void set_version(short version);
			void set_origin(Origin origin);
			void set_session_name(std::string session_name);
			void set_information(std::string info);
			void set_uri(std::string uri);
			void set_phone(std::string phone);
			int set_media(Media media);
			int set_attribute(Attribute attribute);

		private:
			short _version;
			Origin _origin;
			std::string _session_name;
			std::string _information;
			std::string _uri;
			std::string _phone;
			std::vector<Media> _media;
			std::vector<Attribute> _attri;

		};

		enum Address_Type
		{
			IPV4,
			IPV6
		};

		enum Network_Type
		{
			IN
		};

		class Origin
		{
		public:
			Origin();
			Origin(std::string param);
			Origin(Origin& rhs);

			std::string to_string();

			void set_username(std::string username);
			void set_session_id(std::string session_id);
			void set_network_type(Network_Type network_type);
			void set_address_type(Address_Type Address_type);
			void set_address(std::string address);

		private:
			std::string _username;
			std::string _session_id;
			Network_Type _network_type;
			Address_Type _address_type;
			std::string _address;
		};

		enum Protocol
		{
			UDP,
			RTP_AVP,
			RTP_SAVP
		};

		class Attribute
		{
		public:
			Attribute();
			Attribute(std::string param);
			Attribute(Attribute& rhs);
			Attribute(Attribute&& rhs);

			~Attribute();

			std::string to_string();

			void set_type(const std::string& type);
			void set_value(const std::string& value);

			std::string& get_type();
			std::string& get_value();

		private:
			std::string *_type;
			std::string *_value;
		};

		class Media
		{
		public:
			Media();
			Media(std::string param);
			Media(Media& rhs);
			Media(Media&& rhs);
			~Media();

			std::string to_string();

			void set_media(const std::string& media);

			void set_port(const int& port);
			void set_port(const std::string& port);
			void set_port(const std::vector<int>& ports);

			void set_protocol(const Protocol& proto);
			void set_protocol(const std::string& proto);

			void set_format(const int& format);
			void set_format(const std::string& format);
			void set_format(const std::vector<int>& formats);

			void set_attribute(const Attribute& attri);
			void set_attribute(const std::vector<Attribute>& attri);

			std::string& get_media() const;
			std::vector<int>& get_port() const;
			Protocol& get_protocol()	const;
			std::vector<int>& get_format() const;
			std::vector<Attribute>& get_attribute() const;

		private:
			//	type of media( audio, video, etc )
			std::string *_media;
			//	port number send or receive ( get at least one port)
			std::vector<int> *_port;
			//	transport protocol
			Protocol *_protocol;
			//	media format( protocol number is predefined )
			std::vector<int> *_format;
			//	mapping attribute
			std::vector<Attribute> *_attribute;

		};
	}
}

#endif