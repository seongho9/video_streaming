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
			SDP(SDP& rhs);
			~SDP();

			std::string to_string();
			void set_version(const short& version);

			void set_origin(Origin* origin);

			void set_session_name(const std::string& session_name);

			void set_information(const std::string& info);

			void set_uri(const std::string& uri);

			void set_phone(const std::string& phone);

			void add_media(const Media& media);
			void set_media(const std::vector<Media>& param);

			void add_attribute(const Attribute& attribute);
			void set_attribute(const std::vector<Attribute>& param);

			short get_version() const;
			Origin get_origin() const;
			std::string get_session_name() const;
			std::string get_infomation() const;
			std::string get_uri() const;
			std::string get_phone() const;
			std::vector<Media> get_media() const;
			std::vector<Attribute> get_attribute() const;

		private:
			short _version;
			Origin *_origin;
			std::string _session_name;
			std::string _information;
			std::string _uri;
			std::string _phone;
			std::vector<Media> _media;
			std::vector<Attribute> _attri;

		};

		enum Address_Type
		{
			NONE,
			IPV4,
			IPV6
		};

		enum Network_Type
		{
			NONE,
			INTERNET
		};

		class Origin
		{
		public:
			Origin();
			Origin(Origin& rhs);

			std::string to_string();

			void set_username(const std::string& param);
			void set_session_ver(const std::string& param);
			void set_session_id(const std::string& param);
			void set_network_type(const Network_Type& param);
			void set_address_type(const Address_Type& param);
			void set_address(const std::string& param);
			
			std::string& get_username();
			std::string& get_session_ver();
			std::string& get_session_id();
			Network_Type& get_network_type();
			Address_Type& get_address_type();
			std::string& get_address();

		private:
			std::string _username;
			std::string _session_id;
			std::string _session_ver;

			Network_Type _network_type;
			Address_Type _address_type;
			std::string _address;
		};

		enum Protocol
		{
			NONE,
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

			std::string to_string();

			void set_key(std::string key);
			void set_value(std::string value);

		private:
			std::string _key;
			std::string _value;
		};

		class Media
		{
		public:
			Media();
			Media(Media& rhs);

			std::string to_string();

			void set_media(const std::string& media);

			void add_port(const int& param);
			void set_port(const std::vector<int>& ports);

			void set_protocol(const Protocol& proto);

			void add_format(const int& param);
			void set_format(const std::vector<int>& param);

			void add_attribute(const Attribute& attri);
			void set_attribute(const std::vector<Attribute>& attri);

			std::string get_media() const;
			std::vector<int> get_port() const;
			Protocol get_protocol()	const;
			std::vector<int> get_format() const;
			std::vector<Attribute> get_attribute() const;

		private:
			//	type of media( audio, video, etc )
			std::string _media;
			//	port number send or receive ( get at least one port)
			std::vector<int> _port;
			//	transport protocol
			Protocol _protocol;
			//	media format( protocol number is predefined )
			std::vector<int> _format;
			//	mapping attribute
			std::vector<Attribute> _attribute;
		};
	}
}

#endif