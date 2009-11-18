
#ifndef LGUI_H
#define LGUI_H

#include "component\Frame.h"
#include "event\MouseListener.h"
#include "component\MenuItem.h"
#include "component\Menu.h"
#include "component\MenuBar.h"
#include "component\Dialog.h"
#include "component\Panel.h"
#include "layout\BorderLayout.h"
#include "component\Button.h"
#include "component\ToggleButton.h"
#include "component\Checkbox.h"
#include "component\RadioButton.h"
#include "component\Label.h"
#include "component\ProgressBar.h"
#include "component\TextField.h"
#include "component\Slider.h"
#include "component\GLCanvas.h"
#include "event\ChangeListener.h"
#include "event\ChangeEvent.h"
#include "component\Scrollbar.h"
#include ".\OpenGLDemo.h"
#include ".\ScrollPaneTest.h"
#include ".\RenderToTexture.h" 
#include ".\Settings.h"

#include "util\LinearTimeInterpolator.h"
#include "util\ButtonGroup.h"


namespace uitest
{
	namespace nodes
	{
		class GameMenu;

		namespace gui
		{
			class SliderTest : public ui::Dialog
			{
			public:
				SliderTest(Window *owner);
				~SliderTest();
			private:
				ui::Panel *contentPane;
				ui::Slider *hSlider;
				ui::Slider *vSlider;
			};

			class TextTest : public ui::Dialog
			{
			public:
				TextTest(Window *owner);
				~TextTest();
			private:
				ui::Panel *contentPane;
				ui::layout::GridLayout layout;
				ui::Label *usernameLabel;
				ui::Label *passwordLabel;
				ui::TextField *username;
				ui::TextField *password;
			};

			class ButtonTest : public ui::Dialog, public ui::event::MouseAdapter
			{
			public:
				ButtonTest(Window *owner);
				~ButtonTest();
			private:
				ui::Panel *contentPane;
				ui::layout::BorderLayout layout;
				ui::Button *north;
				ui::Button *south;
				ui::Button *east;
				ui::Button *west;
				ui::ToggleButton *center;
				void mouseClicked(const ui::event::MouseEvent &e);
			};

			class OptionTest : public ui::Dialog
			{
			public:
				OptionTest(Window *owner);
				~OptionTest();
			private:
				ui::Panel *contentPane;
				ui::layout::BorderLayout layout;
				ui::CheckBox *checkbox;
				ui::CheckBox *checkbox1;


				ui::RadioButton *option1;
				ui::RadioButton *option2;
				ui::RadioButton *option3;
				ui::util::ButtonGroup group;
			//	ui::RadioButton *option4;
			//	ui::RadioButton *option5;
			};

			class AboutDialog : public ui::Dialog , public ui::event::MouseAdapter
			{
			public:
				AboutDialog(Window *owner);
				~AboutDialog();
			private:
				ui::Panel *contentPane;
				ui::Panel *controlPane;
				ui::layout::BorderLayout layout;
				ui::Label	*text;
				ui::Button *ok;
				void mouseClicked(const ui::event::MouseEvent &e);
				ui::Label *counter;
				void updateComponent(float deltaTime);
			};

			class ProgressTest : public ui::Dialog, public ui::event::MouseAdapter, public ui::util::Interpolatee
			{
			public:
				ProgressTest(Window *owner);
				~ProgressTest();
			private:
				void updateProgressBar(float value);
				ui::Panel *contentPane;
				ui::layout::BorderLayout layout;
				ui::Panel *controlPane;
				ui::Panel *progressPanel;
				ui::Button *start;
				ui::Button *reset;
				ui::ProgressBar *progressBar;
				ui::ProgressBar *vProgressBar;
				void mouseClicked(const ui::event::MouseEvent &e);
				void update(float value);

				ui::util::LinearTimeInterpolator *interpolator;
			};



			class GameGui : public ui::Frame, public ui::event::MouseAdapter
			{
			public:
				GameGui(GameMenu *p);
				~GameGui();
				void mouseClicked(const ui::event::MouseEvent &e);
			private:
				void createMenuBar();
				void destroyMenuBar();
				ui::MenuBar *menubar;
				ui::Menu *fileMenu;
				ui::Menu *helpMenu;
				ui::Menu *demoMenu;
				ui::Menu *testMenu;
				ui::MenuItem *exit;
				ui::MenuItem *about;
				ui::MenuItem *buttonTest;
				ui::MenuItem *optionTest;
				ui::MenuItem *sliderTest;
				ui::MenuItem *progressTest;
				ui::MenuItem *textTest;
				ui::MenuItem *scrollPaneTest;
				ui::MenuItem *settings;
				
				ui::MenuItem *glDemo;
				ui::MenuItem *textureDemo;
				GameMenu *owner;

				ButtonTest *buttonDialog;
				OptionTest *optionDialog;
				ProgressTest *progressDialog;
				TextTest *textDialog;
				SliderTest *sliderDialog;

				AboutDialog *aboutDialog;

				OpenGLDemo *openglDemo;
				ScrollPaneTest *scrollPaneDialog;
				RenderToTextureDemo *renderToTextureDemo;
				Settings *settingsDialog;

				ui::Panel *contentPane;
				ui::Button *north;
				ui::Button *south;
				ui::Button *west;
				ui::Button *east;
				ui::Button *center;
				ui::layout::BorderLayout layout;
				
			};
		}
	}
}

#endif
