#pragma once
#ifndef ICE_PROCESSOR_HPP
#define ICE_PROCESSOR_HPP

#include "SDP.hpp"
#include "SDPParser.hpp"

namespace media_engine
{
	namespace ICE
	{
		class ICEProcessor
		{
		public:
			virtual ICEProcessor& get_instance() = 0;
			virtual offer() = 0;
			virtual answer(SDP packet) = 0;

		private:

			virtual static ICEProcessor() = 0;
			
			static ICEProcessor _obj;
		};
	}
}