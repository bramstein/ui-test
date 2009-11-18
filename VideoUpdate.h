
#ifndef VIDEOUPDATE_H
#define VIDEOUPDATE_H

#include ".\Node.h"

namespace uitest
{
	namespace nodes
	{
		class VideoUpdate : public Node
		{
		public:
			void start();
			void stop();
			void update();
			void render();
		};
	}
}

#endif