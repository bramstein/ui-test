
#ifndef INPUTLISTENER_H
#define INPUTLISTENER_H

namespace uitest
{
	namespace nodes
	{
		class InputListener
		{
		public:
			/**
			* Mouse
			*/
			virtual void mouseMotion(int x, int y) {};
			virtual void mousePressed(int button) {};
			virtual void mouseReleased(int button) {};

			/**
			* Keyboard
			*/
			virtual void keyPressed(int charCode, int modifier) {};
			virtual void keyReleased(int charCode, int modifier) {};


			/**
			 * Window messages
			*/
			virtual void windowClosed() {};
		};
	}
}
#endif