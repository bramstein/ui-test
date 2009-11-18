#include ".\includes.h"
#include ".\UITest.h"
#include ".\NodeManager.h"
#include ".\VideoUpdate.h"
#include ".\Input.h"
#include ".\GameMenu.h"
#include ".\Timer.h"
//#include ".\mmgr.h"

namespace uitest
{
	UITest::UITest()
		: manager(new NodeManager())
	{
	}

	void UITest::run()
	{
		nodes::VideoUpdate *videoUpdate(new nodes::VideoUpdate());
		nodes::Input *input(new nodes::Input());
		nodes::GameMenu *menu(new nodes::GameMenu());
		nodes::Timer *timer(new nodes::Timer());

		input->addInputListener(this);
		input->addInputListener(menu);
		manager->addNode(videoUpdate);
		manager->addNode(timer);
		manager->addNode(input);
		manager->addNode(menu);


		manager->update();
	}

	void UITest::windowClosed()
	{
		manager->stop();
	}
	
	void UITest::keyPressed(int charCode, int modifier)
	{
		if(charCode == SDLK_ESCAPE)
			manager->stop();
	}

	UITest::~UITest()
	{
	}
}

int main(int argc, char* argv [])
{
	using namespace uitest;

	std::auto_ptr<UITest> uiTest(new UITest());

	uiTest->run();

//	m_dumpMemoryReport();

	return 0;
}