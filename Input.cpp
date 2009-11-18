#include ".\input.h"
#include ".\InputListener.h"

namespace uitest
{
	namespace nodes
	{
		void Input::start()
		{
			//fprintf(stderr,"Input started\n");
			// enable keyrepeat
			SDL_EnableUNICODE(1);
			SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
			SDL_PumpEvents();
			SDL_PumpEvents();
		}

		void Input::stop()
		{
			inputList.clear();
		}

		void Input::render()
		{
		}

		void Input::addInputListener(InputListener* l)
		{
			inputList.push_back(l);
		}

		void Input::removeInputListener(InputListener* l)
		{
			InputListenerList::iterator iter = std::find(inputList.begin(),inputList.end(),l);

			if(iter != inputList.end())
			{
				inputList.erase(iter);
			}
		}

		void Input::update()
		{
			
			SDL_Event event;

			int mx, my;
			SDL_GetMouseState(&mx,&my);

			for(int i = 0; i < static_cast<int>(inputList.size()); ++i)
			{
				inputList[i]->mouseMotion(mx,my);
			}

			while(SDL_PollEvent(&event))
			{
				switch(event.type)
				{
					case SDL_QUIT:
					{
						for(int i = 0; i < static_cast<int>(inputList.size()); ++i)
						{
							inputList[i]->windowClosed();
						}
						break;
					}
					case SDL_MOUSEBUTTONUP:
					{
						for(int i = 0; i < static_cast<int>(inputList.size()); ++i)
						{
							inputList[i]->mouseReleased(1);
						}
						break;
					}
					case SDL_MOUSEBUTTONDOWN:
					{
						for(int i = 0; i < static_cast<int>(inputList.size()); ++i)
						{
							inputList[i]->mousePressed(1);
						}
						break;
					}
					case SDL_KEYDOWN:
					{
						for(int i = 0; i < static_cast<int>(inputList.size()); ++i)
						{
							inputList[i]->keyPressed(event.key.keysym.unicode,event.key.keysym.mod);
						}
						//fprintf(stderr, "pressed: %c\n", event.key.keysym.sym);
						break;
					}
					case SDL_KEYUP:
					{
						for(int i = 0; i < static_cast<int>(inputList.size()); ++i)
						{
							inputList[i]->keyReleased(event.key.keysym.sym,event.key.keysym.mod);
						}
						//fprintf(stderr, "released: %c\n", event.key.keysym.sym);
						break;
					}
				}
			}
		}
	}
}