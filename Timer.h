#ifndef TIMER_H
#define TIMER_H

#include ".\Node.h"

namespace uitest
{
	namespace nodes
	{
		class Timer : public Node
		{
		public:
			void start();
			void stop();
			void update();
			void render();

			static float deltaTime;
			static unsigned int lastFrameIndex;
			static unsigned int thisFrameIndex;
		};
	}
}

#endif

