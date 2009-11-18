#ifndef SCROLLPANETEST_H
#define SCROLLPANETEST_H

#include "component\Dialog.h"
#include "component\Panel.h"
#include "component\ScrollPane.h"

namespace uitest
{
	namespace nodes
	{
		class ScrollPaneTest : public ui::Dialog
		{
		public:
			ScrollPaneTest(Window *owner);
			~ScrollPaneTest();
		private:
			ui::Panel *contentPane;
			ui::ScrollPane *scrollPane;
			ui::layout::FlowLayout layout;

			ui::Button *button1;
			ui::Button *button2;
			ui::Button *button3;
			ui::Button *button4;
			ui::Button *button5;
		};
	}
}
#endif