#pragma once

#ifndef SDP_PACKET_HPP
#define SDP_PACKET_HPP

#include <string>
#include <vector>

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

			std::string to_string();

			void set_version(short version);
			void set_
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
			std::stringn _address;
		};

		enum Protocol
		{
			UDP,
			RTP_AVP,
			RTP_SAVP
		};

		class Media
		{
		public:
			Media();
			Media(std::string param);
			Media(Media& rhs);

			std::string to_string();

			void set_media(std::string media);
			void set_port(int port);
			void set_protocol(Protocol proto);
			int set_format(int format);
			int set_attribute(Attribute attri);

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
	}
}

#endif