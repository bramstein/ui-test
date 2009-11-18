#include ".\Settings.h"

namespace uitest
{
	namespace nodes
	{
		Settings::Settings(ui::Window *owner)
			:	ui::Dialog(owner,"Settings"),
				gridLayout(2,1)
		{
			mScheme = new ui::theme::defaulttheme::MetalScheme();
			dScheme = new ui::theme::defaulttheme::DefaultScheme();

			contentPane = new ui::Panel(&layout);
			radioGroup = new ui::Panel(&gridLayout);
			controlGroup = new ui::Panel();

			ok = new ui::Button("Ok");
			cancel = new ui::Button("Cancel");

			defaultScheme = new ui::RadioButton("Default scheme");
			metalScheme = new ui::RadioButton("Java Metal Scheme");

			label = new ui::Label("Select a color scheme: ");

			defaultScheme->addItemListener(this);
			metalScheme->addItemListener(this);

			cancel->addMouseListener(this);
			ok->addMouseListener(this);

			controlGroup->add(cancel);
			controlGroup->add(ok);

			radioGroup->add(defaultScheme);
			radioGroup->add(metalScheme);

			group.add(defaultScheme);
			group.add(metalScheme);

			contentPane->add(label,ui::layout::BorderLayout::NORTH);
			contentPane->add(radioGroup,ui::layout::BorderLayout::CENTER);
			contentPane->add(controlGroup,ui::layout::BorderLayout::SOUTH);

			defaultScheme->setSelected(true);

			addWindowListener(this);

			setContentPane(contentPane);
			pack();
		}

		Settings::~Settings()
		{
			delete contentPane;
			delete radioGroup;
			delete defaultScheme;
			delete metalScheme;
			delete label;
			delete ok;
			delete cancel;
			delete controlGroup;

			delete mScheme;
			delete dScheme;
		}

		void Settings::mouseReleased(const ui::event::MouseEvent &e)
		{
			if(e.getSource() == cancel)
			{
				ui::theme::defaulttheme::SchemeManager::getInstance().setScheme(currentScheme);
				getParent()->resetTheme();
			}
			hide();
		}

		void Settings::itemStateChanged(const ui::event::ItemEvent &e)
		{
			if(e.getSource() == defaultScheme)
			{
				ui::theme::defaulttheme::SchemeManager::getInstance().setScheme(dScheme);
				getParent()->resetTheme();
			}
			else if(e.getSource() == metalScheme)
			{
				ui::theme::defaulttheme::SchemeManager::getInstance().setScheme(mScheme);
				getParent()->resetTheme();
			}
		}

		void Settings::windowOpened(const ui::event::WindowEvent &e)
		{
			currentScheme = ui::theme::defaulttheme::SchemeManager::getInstance().getScheme();

			if(currentScheme == mScheme)
			{
				metalScheme->setSelected(true);
				defaultScheme->setSelected(false);
			}
			else
			{
				defaultScheme->setSelected(true);
				metalScheme->setSelected(false);
			}
		}

	}
}