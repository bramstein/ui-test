
#ifndef UITEST_H
#define UITEST_H

#include ".\includes.h"
#include ".\InputListener.h"

namespace uitest
{
	class NodeManager;

	class UITest : public nodes::InputListener
	{
	public:
		void run();
		UITest();
		~UITest();
		void windowClosed();
		void keyPressed(int charCode, int modifier);
	private:
		std::auto_ptr<NodeManager> manager;
	};
}
#endif