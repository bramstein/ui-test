#include ".\gamemenu.h"
#include ".\includes.h"
#include ".\Timer.h"
#include "component\Button.h"
#include "component\ToggleButton.h"
#include "component\Panel.h"
#include "component\MenuBar.h"
#include "component\Menu.h"
#include "util\Paint.h"
#include "GlyphContext.h"
#include "layout\GridLayout.h"
#include "layout\BorderLayout.h"

#ifdef WIN32
#include <windows.h>
#else
#include <stdio.h>
#endif

#include <gl/gl.h>
#include <gl/glu.h>

namespace uitest
{
	namespace nodes
	{
		void GameMenu::start()
		{
			glShadeModel(GL_SMOOTH);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClearDepth(1.0f);
			glDepthFunc(GL_LEQUAL);
			glEnable(GL_DEPTH_TEST);
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
			//glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
			//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

			//glEnable(GL_LINE_SMOOTH);
			//glEnable(GL_POLYGON_SMOOTH);
		//	glEnable(GL_MULTISAMPLE);

			x = 0;
			y = 0;
			width = 800;
			height = 600;

			glViewport(0,0,800,600);

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glMatrixMode(GL_MODELVIEW);

		
			createMenu();
		}

		GLuint GameMenu::getTextureId() const
		{
			return textureFrame->getTextureId();
		}

		void GameMenu::createMenu()
		{
			factory = new FreeTypeFontFactory();
			bFactory = new BitmapFontFactory();

			gui = new ui::Gui();
			gui->setFontFactory(factory);

			
			frame = new nodes::gui::GameGui(this);
			textureFrame = new TextureFrame(0,0,320,200);

			//gui->addFrame(textureFrame);
			gui->addFrame(frame);

			menuBar = new ui::MenuBar();
			help = new ui::Menu("Help");
			about = new ui::MenuItem("About");

			help->add(about);
			menuBar->add(help);
			//textureFrame->setMenuBar(menuBar);

			//textureFrame->show();
			frame->show();
		}

	//	ui::Gui * GameMenu::getGui()
	//	{
	//		return gui;
	//	}

		void GameMenu::destroyMenu()
		{
			frame->hide();
			//textureFrame->hide();
			delete frame;
			delete textureFrame;
			delete factory;
			delete bFactory;
			delete gui;

			delete menuBar;
			delete help;
			delete about;
		}

		void GameMenu::stop()
		{
			destroyMenu();
		}

		void GameMenu::render()
		{
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glLoadIdentity();

				

				glMatrixMode(GL_PROJECTION);
				glPushMatrix();
				glLoadIdentity();
				gluOrtho2D(0,800,600,0);
				glMatrixMode(GL_MODELVIEW);

				// render ui
				gui->paint();
				//frame->paint();

				glMatrixMode(GL_PROJECTION);
				glPopMatrix();
				glMatrixMode(GL_MODELVIEW);
		}

		void GameMenu::exit()
		{
			getManager()->stop();
		}

		void GameMenu::update()
		{
			gui->importUpdate(nodes::Timer::deltaTime);
		}

		void GameMenu::keyPressed(int charCode, int modifier)
		{
			gui->importKeyPressed(charCode,modifier);
		}

		void GameMenu::keyReleased(int charCode,int modifier)
		{
			gui->importKeyReleased(charCode,modifier);
		}

		void GameMenu::mouseMotion(int x, int y)
		{
			gui->importMouseMotion(x,y);
		}

		void GameMenu::mousePressed(int button)
		{
			gui->importMousePressed(button);
		}

		void GameMenu::mouseReleased(int button)
		{
			gui->importMouseReleased(button);
		}
	}
}