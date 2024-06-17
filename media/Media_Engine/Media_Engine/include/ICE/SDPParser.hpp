#pragma once

#ifndef SDP_PARSER_HPP
#define SDP_PARSER_HPP

#include "SDP.hpp"

namespace media_engine
{
	namespace ICE
	{
		class SDPParser
		{
		public:
			virtual SDPParser get_instance() = 0;
			virtual SDP parse(std::string param) = 0;

		private:

			virtual static SDPParser() = 0;
			static SDPParser _obj;
		};
	}
}

#endif