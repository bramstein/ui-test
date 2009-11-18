#include ".\ScrollPaneTest.h"

namespace uitest
{
	namespace nodes
	{
		using namespace ui;

		ScrollPaneTest::ScrollPaneTest(Window *owner)
			:	Dialog(owner,"ScrollPane test")
		{
			button1 = new Button("Button 1");
			button2 = new Button("Button 2");
			button3 = new Button("Button 3");
			button4 = new Button("Button 4");
			button5 = new Button("Button 5");

			contentPane = new Panel(&layout);
			contentPane->add(button1);
			contentPane->add(button2);
			contentPane->add(button3);
			contentPane->add(button4);
			contentPane->add(button5);

			scrollPane = new ScrollPane(contentPane);
			setContentPane(scrollPane);
			pack();
		}

		ScrollPaneTest::~ScrollPaneTest()
		{
			delete button1;
			delete button2;
			delete button3;
			delete button4;
			delete button5;

			delete contentPane;
			delete scrollPane;
		}
	}
}