#include ".\gui.h"
#include ".\GameMenu.h"
#include "event\KeyEvent.h"


namespace uitest
{
	namespace nodes
	{
		using namespace ui;

		namespace gui
		{
			SliderTest::SliderTest(Window *owner)
				:	Dialog(owner,"Slider test")
			{
				contentPane = new Panel();
				hSlider = new Slider(0,100);
				vSlider = new Slider(Component::VERTICAL);

				contentPane->add(hSlider);
				contentPane->add(vSlider);

				setContentPane(contentPane);
				pack();
			}

			SliderTest::~SliderTest()
			{
				delete vSlider;
				delete hSlider;
				delete contentPane;
			}
// ---------------------------------------------------------------------

			TextTest::TextTest(Window *owner)
				:	Dialog(owner,"Text test"),
					layout(5,1)
			{
				contentPane = new Panel(&layout);
				username = new TextField("");
				password = new TextField("");
				usernameLabel = new Label("Enter username:");
				passwordLabel = new Label("Enter password:");

				password->setEchoCharacter(event::KeyEvent::VKUI_ASTERISK);

				contentPane->add(usernameLabel);
				contentPane->add(username);
				contentPane->add(passwordLabel);
				contentPane->add(password);

				setContentPane(contentPane);
				pack();
			}

			TextTest::~TextTest()
			{
				delete contentPane;
				delete username;
				delete usernameLabel;
				delete password;
				delete passwordLabel;
			}

// ---------------------------------------------------------------------

			ButtonTest::ButtonTest(Window *owner)
				:	Dialog(owner,"Button Test")	
			{
				contentPane = new Panel(&layout);

				north = new Button("North button");
				west = new Button("West button");
				east = new Button("East button");
				south = new Button("South button");
				center = new ToggleButton("Enable/Disable");

				center->addMouseListener(this);
				contentPane->add(north,layout::BorderLayout::NORTH);
				contentPane->add(west,layout::BorderLayout::WEST);
				contentPane->add(east,layout::BorderLayout::EAST);
				contentPane->add(south,layout::BorderLayout::SOUTH);
				contentPane->add(center,layout::BorderLayout::CENTER);

				setContentPane(contentPane);
				//setRotation(33.0f);
				pack();
			}

			void ButtonTest::mouseClicked(const event::MouseEvent &e)
			{
				north->setEnabled(!north->isEnabled());
				west->setEnabled(!west->isEnabled());
				east->setEnabled(!east->isEnabled());
				south->setEnabled(!south->isEnabled());
			}

			ButtonTest::~ButtonTest()
			{
				center->removeMouseListener(this);
				delete north;
				delete south;
				delete west;
				delete east;
				delete center;
				delete contentPane;
			}
// ---------------------------------------------------------------------

			OptionTest::OptionTest(Window *owner)
				:	Dialog(owner,"Option Dialog")
			{
				contentPane = new Panel(&layout);

				checkbox = new CheckBox("Test",true);
				checkbox1 = new CheckBox("Toggle me",false);
				option1 = new RadioButton("Option 1");
				option2 = new RadioButton("Option 2");
				option3 = new RadioButton("Option 3");


				group.add(option1);
				group.add(option2);
				group.add(option3);

				contentPane->add(checkbox,layout::BorderLayout::CENTER);
				contentPane->add(checkbox1,layout::BorderLayout::NORTH);
				contentPane->add(option1,layout::BorderLayout::EAST);
				contentPane->add(option2,layout::BorderLayout::WEST);
				contentPane->add(option3,layout::BorderLayout::SOUTH);
				setContentPane(contentPane);
				pack();
			}

			OptionTest::~OptionTest()
			{
				delete contentPane;
				delete checkbox;
				delete checkbox1;
				delete option1;
				delete option2;
				delete option3;
			}
// ---------------------------------------------------------------------

			AboutDialog::AboutDialog(Window *owner)
				:	Dialog(owner,"About UITest")
			{
				contentPane = new Panel(&layout);
				controlPane = new Panel();

				ok = new Button("Ok");
				//text = new Label("UITest v0.04 - http://www.bramstein.nl/gui/\nCopyright 2003-2006, Bram Stein");
				text = new Label("UITest v0.05 - Bram Stein");
				counter = new Label("");

				controlPane->add(ok);

				contentPane->add(controlPane,layout::BorderLayout::SOUTH);
				contentPane->add(text,layout::BorderLayout::CENTER);
				//contentPane->add(counter,layout::BorderLayout::NORTH);

				ok->addMouseListener(this);

				setContentPane(contentPane);
				pack();
			}

			AboutDialog::~AboutDialog()
			{
				delete contentPane;
				delete controlPane;
				delete ok;
				delete text;
				delete counter;
			}

			void AboutDialog::updateComponent(float deltaTime)
			{
				char s[8];
				sprintf(s,"%3.0ffps", 1/deltaTime);
				counter->setText(s);
			}

			void AboutDialog::mouseClicked(const event::MouseEvent &e)
			{
				hide();
			}
// ---------------------------------------------------------------------

			ProgressTest::ProgressTest(Window *owner)
				:	Dialog(owner,"ProgressBar test")
			{
				contentPane = new Panel(&layout);

				progressPanel = new Panel();
				progressBar = new ProgressBar(0,100);
				vProgressBar = new ProgressBar(0,100,ProgressBar::VERTICAL);
				start = new Button("Start");
				reset = new Button("Reset");

				controlPane = new Panel();
				controlPane->add(start);
				controlPane->add(reset);
				start->addMouseListener(this);
				reset->addMouseListener(this);

				progressPanel->add(progressBar);
				progressPanel->add(vProgressBar);

				contentPane->add(progressPanel,layout::BorderLayout::CENTER);
				contentPane->add(controlPane,layout::BorderLayout::SOUTH);

				setContentPane(contentPane);


				interpolator = new util::LinearTimeInterpolator(60.0f,0.0f,100.0f);
				interpolator->addInterpolatee(this);
				addInterpolator(interpolator);

				pack();
			}

			ProgressTest::~ProgressTest()
			{
				delete contentPane;
				delete controlPane;
				delete progressBar;
				delete vProgressBar;
				delete start;
				delete reset;
				delete progressPanel;
				delete interpolator;
			}

			void ProgressTest::update(float value)
			{
				progressBar->setValue(static_cast<int>(value));
				vProgressBar->setValue(static_cast<int>(value));
			}

			void ProgressTest::mouseClicked(const event::MouseEvent &e)
			{
				if(e.getSource() == start)
				{
					interpolator->start();
				}
				else if(e.getSource() == reset)
				{
					interpolator->reset();
					progressBar->setValue(0);
					vProgressBar->setValue(0);
				}
			}

// ---------------------------------------------------------------------

// ---------------------------------------------------------------------

			GameGui::GameGui(GameMenu *p)
				:	Frame(0,0,800,600),
					owner(p)
			{
				createMenuBar();

				buttonDialog = new ButtonTest(this);
				optionDialog = new OptionTest(this);
				progressDialog = new ProgressTest(this);
				textDialog = new TextTest(this);
				sliderDialog = new SliderTest(this);
				scrollPaneDialog = new ScrollPaneTest(this);

				aboutDialog = new AboutDialog(this);

				openglDemo = new OpenGLDemo(this);
				renderToTextureDemo = new RenderToTextureDemo(this,p);
				settingsDialog = new Settings(this);

				contentPane = new Panel(&layout);
				north = new Button("North");
				south = new Button("South");
				west = new Button("West");
				east = new Button("East");
				center = new Button("Center Button with\nmultiple lines");

				contentPane->add(north, layout::BorderLayout::NORTH);
				contentPane->add(south, layout::BorderLayout::SOUTH);
				contentPane->add(west, layout::BorderLayout::WEST);
				contentPane->add(east, layout::BorderLayout::EAST);
				contentPane->add(center, layout::BorderLayout::CENTER);

			//	setContentPane(contentPane);

			}

			GameGui::~GameGui()
			{
				destroyMenuBar();
				delete buttonDialog;
				delete optionDialog;
				delete progressDialog;
				delete aboutDialog;
				delete textDialog;
				delete sliderDialog;
				delete scrollPaneDialog;

				delete openglDemo;
				delete renderToTextureDemo;
				delete settingsDialog;

				delete contentPane;
				delete north;
				delete south;
				delete west;
				delete east;
				delete center;
			}

			void GameGui::mouseClicked(const event::MouseEvent &e)
			{
				if(e.getSource() == exit)
				{
					owner->exit();
				}
				else if(e.getSource() == buttonTest)
				{
					buttonDialog->setLocation(200,200);
					buttonDialog->show();
				}
				else if(e.getSource() == optionTest)
				{
					optionDialog->setLocation(300,300);
					optionDialog->show();
				}
				else if(e.getSource() == about)
				{
					aboutDialog->setLocation(400,100);
					aboutDialog->show();
				}
				else if(e.getSource() == progressTest)
				{
					progressDialog->setLocation(100,400);
					progressDialog->show();
				}
				else if(e.getSource() == textTest)
				{
					textDialog->setLocation(100,100);
					textDialog->show();
				}
				else if(e.getSource() == sliderTest)
				{
					sliderDialog->setLocation(600,300);
					sliderDialog->show();
				}
				else if(e.getSource() == glDemo)
				{
					openglDemo->setLocation(100,100);
					openglDemo->show();
				}
				else if(e.getSource() == scrollPaneTest)
				{
					scrollPaneDialog->setLocation(100,100);
					scrollPaneDialog->setSize(150,100);
					scrollPaneDialog->show();
				}
				else if(e.getSource() == textureDemo)
				{
					renderToTextureDemo->setLocation(110,110);
					renderToTextureDemo->show();
				}
				else if(e.getSource() == settings)
				{
					settingsDialog->setLocation(120,120);
					settingsDialog->show();
				}
			}

			void GameGui::createMenuBar()
			{
				menubar = new MenuBar();
 
				fileMenu = new Menu("File");
				helpMenu = new Menu("Help");
				demoMenu = new Menu("Demo's");
				testMenu = new Menu("Tests");

				exit = new MenuItem("Exit");
				about= new MenuItem("About UITest...");

				buttonTest = new MenuItem("Button Test");
				optionTest = new MenuItem("Options Test");
				sliderTest = new MenuItem("Slider Test");
				progressTest = new MenuItem("Progress Test");
				textTest = new MenuItem("Text entry Test");
				scrollPaneTest = new MenuItem("ScrollPane test");

				glDemo = new MenuItem("OpenGL Demo");
				textureDemo = new MenuItem("Render to texture demo");
				settings = new MenuItem("Settings");

				buttonTest->addMouseListener(this);
				optionTest->addMouseListener(this);
				sliderTest->addMouseListener(this);
				progressTest->addMouseListener(this);
				textTest->addMouseListener(this);
				exit->addMouseListener(this);
				about->addMouseListener(this);
				scrollPaneTest->addMouseListener(this);
				glDemo->addMouseListener(this);
				textureDemo->addMouseListener(this);
				settings->addMouseListener(this);

				fileMenu->add(settings);
				fileMenu->add(exit);


				helpMenu->add(about);

				testMenu->add(buttonTest);
				testMenu->add(optionTest);
				testMenu->add(progressTest);
				testMenu->add(sliderTest);
				testMenu->add(textTest);
				testMenu->add(scrollPaneTest);

				demoMenu->add(glDemo);
				//demoMenu->add(textureDemo);

				menubar->add(fileMenu);
				menubar->add(testMenu);
				menubar->add(demoMenu);
				menubar->add(helpMenu);

				setMenuBar(menubar);
			}

			void GameGui::destroyMenuBar()
			{
				delete menubar;
				delete fileMenu;
				delete helpMenu;
				delete demoMenu;
				delete exit;
				delete about;
				delete buttonTest;
				delete optionTest;
				delete sliderTest;
				delete progressTest;
				delete textTest;
				delete scrollPaneTest;
				delete testMenu;
				delete glDemo;
				delete textureDemo;
				delete settings;
			}
		}
	}
}