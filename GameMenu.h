
#ifndef GAMEMENU_H
#define GAMEMENU_H

#include ".\Node.h"
#include ".\NodeManager.h"
#include "component\Frame.h"

#include ".\GameGui.h"
#include ".\InputListener.h"
#include ".\FreeTypeFontFactory.h"
#include ".\TextureFrame.h"

#include "component\MenuItem.h"
#include "component\Menu.h"
#include "component\MenuBar.h"

#include ".\BitmapFontFactory.h"

#include "Gui.h"

namespace uitest
{
	namespace nodes
	{
		class GameMenu : public Node, public InputListener
		{
		public:
			void start();
			void stop();
			void update();
			void render();

			/**
			* Mouse
			*/
			void mouseMotion(int x, int y);
			void mousePressed(int button);
			void mouseReleased(int button);

			/**
			* Keyboard
			*/
			void keyPressed(int charCode, int modifier);
			void keyReleased(int charCode, int modifier);

			void exit();

			GLuint getTextureId() const;
		private:
			void createMenu();
			void destroyMenu();
			int x,y,width,height;
			//ui::Frame *frame;
			ui::Gui *gui;
			nodes::gui::GameGui *frame;
			TextureFrame *textureFrame;
			FreeTypeFontFactory *factory;
			BitmapFontFactory *bFactory;

			ui::MenuBar *menuBar;
			ui::Menu *help;
			ui::MenuItem *about;
		};
	}
}

#endif