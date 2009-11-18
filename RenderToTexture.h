#ifndef RENDERTOTEXTURE_H
#define RENDERTOTEXTURE_H

#include "component\Dialog.h"
#include "component\Panel.h"
#include "component\Slider.h"
#include "component\GLCanvas.h"
#include "event\ChangeListener.h"
#include "event\ChangeEvent.h"
#include "component\Slider.h"
//#include ".\GameMenu.h"
#include "config.h"

namespace uitest
{
	namespace nodes
	{
			class GameMenu;

			class RenderWindow : public ui::GLCanvas, public ui::event::MouseAdapter
			{
			public:
				RenderWindow(GameMenu *m);
				void render() const;
				void updateComponent(float deltaTime);
				void renderSelection() const;
				void setPanelRotation(float f);
			//protected:
			//	void paintSelectionComponent(ui::Graphics &g);
			private:
				ui::util::Color background;
				static const int textureWidth = 512;
				static const int textureHeight = 512;
				GLubyte texture[textureWidth][textureHeight][4];
				GLuint textureId;
				GameMenu *menu;
				float rotation;
			};

			class RenderToTextureDemo : public ui::Dialog, public ui::event::ChangeListener
			{
			public:
				RenderToTextureDemo(Window *owner, GameMenu *menu);
				~RenderToTextureDemo();
			private:
				void stateChanged(const ui::event::ChangeEvent &e);
				ui::Panel *contentPane;
				ui::Slider *slider;
				ui::layout::BorderLayout layout;
				RenderWindow *renderWindow;
			};
	}
}

#endif