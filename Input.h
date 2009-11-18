
#ifndef INPUT_H
#define INPUT_H

#include ".\includes.h"
#include ".\Node.h"

namespace uitest
{
	namespace nodes
	{
		class InputListener;

		class Input : public Node
		{
		public:
		void addInputListener(InputListener* l);
		void start();
		void stop();
		void update();
		void render();

		void removeInputListener(InputListener* l);

	private:
		int x, y;
		typedef std::vector<InputListener*> InputListenerList;
		InputListenerList inputList;
		};
	}
}
#endif