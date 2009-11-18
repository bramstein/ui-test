#include ".\Timer.h"
#include "SDL.h"

namespace uitest
{
	namespace nodes
	{
		void Timer::start()
		{
			thisFrameIndex = SDL_GetTicks();
			lastFrameIndex = thisFrameIndex = 0;

			deltaTime = 0;
			//fprintf(stderr,"Timer started\n");
		}

		float Timer::deltaTime = 0;
		unsigned int Timer::lastFrameIndex = 0;
		unsigned int Timer::thisFrameIndex = 0;

		void Timer::render()
		{
		}

		void Timer::stop()
		{
		}

		void Timer::update()
		{
			lastFrameIndex = thisFrameIndex;
			thisFrameIndex = SDL_GetTicks();
			deltaTime = ((float)(thisFrameIndex-lastFrameIndex))/1000.0f;

			
			char s[8];
			sprintf(s,"%3.0ffps", 1/deltaTime);

			//SDL_WM_SetCaption(s,0);
			
			//fprintf(stderr,"Updating timer\n");
		}
	}
}