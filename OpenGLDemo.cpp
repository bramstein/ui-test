#include ".\OpenGLDemo.h"
#include "config.h"

namespace uitest
{
	namespace nodes
	{
		using namespace ui;

		OpenGLDemo::OpenGLDemo(Window *owner)
			:	Dialog(owner,"OpenGL Rotating Cube demo"),
				layout(false)
		{
			contentPane = new Panel(&layout);

			rotatingCube = new RotatingCube();

			hSlider = new Scrollbar(-100,100,0,Slider::HORIZONTAL);
			vSlider = new Scrollbar(-100,100,0,Slider::VERTICAL);

			contentPane->add(hSlider,layout::BorderLayout::SOUTH);
			contentPane->add(vSlider,layout::BorderLayout::EAST);
			contentPane->add(rotatingCube,layout::BorderLayout::CENTER);

			hSlider->addChangeListener(this);
			vSlider->addChangeListener(this);

			setContentPane(contentPane);

			pack();
		}

		void OpenGLDemo::stateChanged(const event::ChangeEvent &e)
		{
			if(e.getSource() == vSlider)
			{
				rotatingCube->setVSpeed(static_cast<int>(vSlider->getValue()));
			}
			else if(e.getSource() == hSlider)
			{
				rotatingCube->setHSpeed(static_cast<int>(hSlider->getValue()));
			}
		}

		OpenGLDemo::~OpenGLDemo()
		{
			delete contentPane;
			delete rotatingCube;
			delete hSlider;
			delete vSlider;
		}

// ---------------------------------------------------------------------

		RotatingCube::RotatingCube()
			:	vRotation(0.0f),
				hRotation(0.0f),
				hSpeed(0.0f),
				vSpeed(0.0f)
		{
			setViewportWidth(200);
			setViewportHeight(200);
		}

		void RotatingCube::updateComponent(float deltaTime)
		{
			vRotation += vSpeed * deltaTime;
			hRotation += hSpeed * deltaTime;
		}

		void RotatingCube::setVSpeed(int speed)
		{
			// assume we get values between -100 and 100
			vSpeed = static_cast<float>(speed/1.0f);
		}

		void RotatingCube::setHSpeed(int speed)
		{
			hSpeed = static_cast<float>(speed/1.0f);
		}

		void RotatingCube::render() const
		{
			drawCube();
		}

		void RotatingCube::drawCube() const
		{
			glRotatef(vRotation,1.0f,0.0f,0.0f);
			glRotatef(hRotation,0.0f,1.0f,0.0f);

			glBegin(GL_QUADS); 

			glColor4f(0.0f,1.0f,0.0f,1.8f);
			glVertex3f( 1.0f, 1.0f,-1.0f);
			glVertex3f(-1.0f, 1.0f,-1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
			glVertex3f( 1.0f, 1.0f, 1.0f);

			glColor4f(1.0f,0.5f,0.0f,1.8f); 
			glVertex3f( 1.0f,-1.0f, 1.0f);
			glVertex3f(-1.0f,-1.0f, 1.0f);
			glVertex3f(-1.0f,-1.0f,-1.0f);
			glVertex3f( 1.0f,-1.0f,-1.0f); 
			
			glColor4f(1.0f,0.0f,0.0f,1.8f);
			glVertex3f( 1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f,-1.0f, 1.0f);
			glVertex3f( 1.0f,-1.0f, 1.0f); 
			
			glColor4f(1.0f,1.0f,0.0f,1.8f);
			glVertex3f( 1.0f,-1.0f,-1.0f);
			glVertex3f(-1.0f,-1.0f,-1.0f);
			glVertex3f(-1.0f, 1.0f,-1.0f);
			glVertex3f( 1.0f, 1.0f,-1.0f); 

			glColor4f(0.0f,0.0f,1.0f,1.8f);
			glVertex3f(-1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0f, 1.0f,-1.0f);
			glVertex3f(-1.0f,-1.0f,-1.0f);
			glVertex3f(-1.0f,-1.0f, 1.0f);
			
			glColor4f(1.0f,0.0f,1.0f,1.8f);
			glVertex3f( 1.0f, 1.0f,-1.0f);
			glVertex3f( 1.0f, 1.0f, 1.0f);
			glVertex3f( 1.0f,-1.0f, 1.0f);
			glVertex3f( 1.0f,-1.0f,-1.0f);

			glEnd();
		}

	}
}