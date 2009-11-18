#include ".\RenderToTexture.h"
#include ".\GameMenu.h"

namespace uitest
{
	namespace nodes
	{
		RenderToTextureDemo::RenderToTextureDemo(Window *owner, GameMenu *menu)
			:	Dialog(owner,"Render to texture demo")
		{
			contentPane = new ui::Panel(&layout);

			renderWindow = new RenderWindow(menu);
			slider = new ui::Slider(-50.0f,50.0f,0.0f,ui::Slider::HORIZONTAL);

			contentPane->add(renderWindow,ui::layout::BorderLayout::CENTER);
			contentPane->add(slider,ui::layout::BorderLayout::SOUTH);

			slider->addChangeListener(this);

			setContentPane(contentPane);

			pack();
		}

		RenderToTextureDemo::~RenderToTextureDemo()
		{
			delete contentPane;
			delete renderWindow;
			delete slider;

		}

		void RenderToTextureDemo::stateChanged(const ui::event::ChangeEvent &e)
		{
			renderWindow->setPanelRotation(slider->getValue());
		}

		RenderWindow::RenderWindow(GameMenu *m)
			: GLCanvas(320,200),
				background(0,0,0),
				menu(m),
				rotation(0.0f)
		{
			setBackground(&background);
			addMouseListener(this);
		}

		void RenderWindow::setPanelRotation(float f)
		{
			rotation = f;
		}

		void RenderWindow::renderSelection() const
		{
			glLoadIdentity();

			glColor3f(0.0f,0.0f,0.0f);


			glDisable(GL_LIGHTING);
			glDisable(GL_DITHER);
						glDisable(GL_BLEND);
			glEnable(GL_TEXTURE_2D);

			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

			glBindTexture(GL_TEXTURE_2D,menu->getTextureId());

			glTranslatef(0.0f,0.0f,-3.0f);

			glRotatef(rotation,0.0f,1.0f,0.0f);

			float depth = 0.0f;

			float xcoord = 320.0f / 512.0f;
			float ycoord = 200.0f / 512.0f;

			// flip around the texture
			glScalef(1.0f,-1.0f,1.0f);

			int x = 0;
			int y = 0;
			int width = 320;
			int height = 200;
			
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(-1.0f,1.0f,depth);
	
				glTexCoord2f(xcoord,0.0f);
				glVertex3f(1.0f,1.0f,depth);

				glTexCoord2f(xcoord,ycoord);
				glVertex3f(1.0f,-1.0f,depth);

				glTexCoord2f(0.0f,ycoord);
				glVertex3f(-1.0f,-1.0f,depth);

			glEnd();

			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
			glDisable(GL_TEXTURE_2D);
			glEnable(GL_DITHER);
			glEnable(GL_BLEND);
			glEnable(GL_LIGHTING);
		}

		void RenderWindow::render() const
		{
		//	glLoadIdentity();
			/*
			int x = getLocationOnScreen().x;
			int y = getLocationOnScreen().y;
			int width = getBounds().width;
			int height = getBounds().height;

		//	glLoadIdentity();
			int viewport[4];
			glGetIntegerv(GL_VIEWPORT,viewport);
			y = viewport[1];
		
			glPushAttrib(GL_ALL_ATTRIB_BITS);
			glViewport(x,y,width,height);

			glLoadIdentity();

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
				glLoadIdentity();
				//gluOrtho2D(0,width,height,0);
				gluOrtho2D(0,800,600,0);

				glColor3f(1.0f,1.0f,0.0f);

				int xx = 100;
				int yy = 100;
				int wwidth = 180;
				int hheight = 180;

				glBegin(GL_QUADS);
			
					glVertex3f(xx, yy, 0.0f);	// Top Left
			
					glVertex3f(xx + wwidth, yy, 0.0f);	// Top Right
			
					glVertex3f(xx + wwidth, yy + hheight, 0.0f);	// Bottom Right

					glVertex3f(xx, yy + hheight, 0.0f);	// Bottom Left
				glEnd();

			glPopMatrix();
			glPopAttrib();

			glBindTexture(GL_TEXTURE_2D,textureId);
			glCopyTexSubImage2D(GL_TEXTURE_2D,0,0,0,x,y,width,height);


			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
*/

			glLoadIdentity();

			glColor3f(1.0f,0.0f,0.0f);


			glEnable(GL_TEXTURE_2D);
		//	glDisable(GL_BLEND);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

			glBindTexture(GL_TEXTURE_2D,menu->getTextureId());

			glTranslatef(0.0f,0.0f,-3.0f);

			glRotatef(rotation,0.0f,1.0f,0.0f);

			float depth = 0.0f;
		
			// flip around the texture
			glScalef(1.0f,-1.0f,1.0f);

			/*
			glBegin(GL_QUADS);

				glTexCoord2f(0.0f,0.0f);
				glVertex3f(-1.0f,1.0f,depth);
	
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(1.0f,1.0f,depth);

				glTexCoord2f(1.0f,1.0f);
				glVertex3f(1.0f,-1.0f,depth);

				glTexCoord2f(0.0f,1.0f);
				glVertex3f(-1.0f,-1.0f,depth);

			glEnd();
			*/

						float xcoord = 320.0f / 512.0f;
			float ycoord = 200.0f / 512.0f;

			glBegin(GL_QUADS);
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(-1.0f,1.0f,depth);
			//	glVertex3f(xcoord,ycoord
	
				glTexCoord2f(xcoord,0.0f);
				glVertex3f(1.0f,1.0f,depth);

				glTexCoord2f(xcoord,ycoord);
				glVertex3f(1.0f,-1.0f,depth);

				glTexCoord2f(0.0f,ycoord);
				glVertex3f(-1.0f,-1.0f,depth);

			glEnd();

			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
			glDisable(GL_TEXTURE_2D);
			
		}

		void RenderWindow::updateComponent(float deltaTime)
		{
		}
	}
}