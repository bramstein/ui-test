#ifndef SETTINGS_H
#define SETTINGS_H

#include "component\Dialog.h"
#include "component\Panel.h"
#include "event\ItemListener.h"
#include "event\ItemEvent.h"
#include "event\WindowListener.h"
#include "event\WindowEvent.h"
#include "event\MouseListener.h"
#include "event\MouseEvent.h"
#include "component\RadioButton.h"
#include "util\ButtonGroup.h"
#include "layout\GridLayout.h"
#include "component\Button.h"
#include "component\Label.h"

#include "theme\Default\Scheme.h"
#include "theme\Default\DefaultScheme.h"
#include "theme\Default\MetalScheme.h"

namespace uitest
{
	namespace nodes
	{
		class Settings : public ui::Dialog, public ui::event::ItemListener, public ui::event::WindowListener, public ui::event::MouseAdapter
		{
		public:
			Settings(ui::Window *owner);
			~Settings();
		private:
			ui::Panel *contentPane;
			ui::layout::BorderLayout layout;
			void itemStateChanged(const ui::event::ItemEvent &e);
			ui::RadioButton *defaultScheme;
			ui::RadioButton *metalScheme;
			ui::util::ButtonGroup group;
			ui::layout::GridLayout gridLayout;
			ui::Panel *radioGroup;
			ui::Panel *controlGroup;
			ui::Button *ok;
			ui::Button *cancel;
			ui::Label *label;

			void windowOpened(const ui::event::WindowEvent &e);
			void windowClosed(const ui::event::WindowEvent &e) {};
			void windowActivated(const ui::event::WindowEvent &e) {};
			void windowDeactivated(const ui::event::WindowEvent &e) {};

			void mouseReleased(const ui::event::MouseEvent &e);

			ui::theme::defaulttheme::DefaultScheme *dScheme;
			ui::theme::defaulttheme::MetalScheme *mScheme;

			ui::theme::defaulttheme::Scheme *currentScheme;
		};
	}
}

#endif