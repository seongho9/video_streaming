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

<<<<<<< HEAD
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
=======
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
>>>>>>> 72c6f86936713c3ea993536c55720164bf052747
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
<<<<<<< HEAD
=======
			Attribute(std::string param);
>>>>>>> 72c6f86936713c3ea993536c55720164bf052747
			Attribute(Attribute& rhs);

			std::string to_string();

<<<<<<< HEAD
			void set_type(const std::string& param);
			void set_value(const std::string& param);

			std::string& get_type();
			std::string& get_value();

		private:
			std::string _type;
=======
			void set_key(std::string key);
			void set_value(std::string value);

		private:
			std::string _key;
>>>>>>> 72c6f86936713c3ea993536c55720164bf052747
			std::string _value;
		};

		class Media
		{
		public:
			Media();
<<<<<<< HEAD
			Media(Media& rhs);

			std::string to_string();

			void set_media(const std::string& param);

			void add_port(const int& param);
			void set_port(const std::vector<int>& param);

			void set_protocol(const Protocol& param);

			void add_format(const int& param);
			void set_format(const std::vector<int>& param);

			void add_attribute(const Attribute& param);
			void set_attribute(const std::vector<Attribute>& param);

			const std::string& get_media() const;
			const std::vector<int>& get_port() const;
			const Protocol& get_protocol()	const;
			const std::vector<int>& get_format() const;
			const std::vector<Attribute>& get_attribute() const;

		private:
			//	type of media( audio, video, etc )
			std::string _media;
			//	port number send or receive ( get at least one port)
			std::vector<int> _port;
			//	transport protocol
			Protocol _protocol;
			//	media format( mapped to attribute )
			std::vector<int> _format;
			//	mapping attribute
			std::vector<Attribute> _attribute;
=======
			Media(std::string param);
			Media(Media& rhs);
			Media(Media&& rhs);

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

			std::string get_media() const;
			std::vector<int> get_port() const;
			Protocol get_protocol()	const;
			std::vector<int> get_format() const;
			std::vector<Attribute> get_attribute() const;

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
>>>>>>> 72c6f86936713c3ea993536c55720164bf052747

		};
	}
}

#endif