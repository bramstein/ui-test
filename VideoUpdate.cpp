#include ".\VideoUpdate.h"
#include ".\includes.h"

namespace uitest
{
	namespace nodes
	{
		void VideoUpdate::start()
		{
			int width	= 800;
			int height	= 600;
			bool fullscreen = false;
			int bpp = 32;
			int flags = 0;

			if(SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				fprintf(stderr, "Video initialization failed: %s\n", SDL_GetError( ));
			}

			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			//SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 5);
			//SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,5);
			//SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,5);
			//SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,5);

			if(!fullscreen)
				flags = SDL_OPENGL;
			else
				flags = SDL_OPENGL | SDL_FULLSCREEN;
			
			if(SDL_SetVideoMode(width, height, bpp, flags) == 0)
			{
				fprintf( stderr, "Video mode set failed: %s\n", SDL_GetError());
			}

			//SDL_EnableUNICODE(1);

			SDL_WM_SetCaption("UITest v0.05 - by Bram Stein",0);

		//	fprintf(stderr,"Video started\n");
		}

		void VideoUpdate::render()
		{
			SDL_GL_SwapBuffers();
		}

		void VideoUpdate::stop()
		{
			SDL_QuitSubSystem(SDL_INIT_VIDEO);
		}

		void VideoUpdate::update()
		{
		//	SDL_Delay(0);
		}
	}
}