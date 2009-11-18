#ifndef OPENGLDEMO_H
#define OPENGLDEMO_H

#include "component\Dialog.h"
#include "component\Panel.h"
#include "component\Slider.h"
#include "component\GLCanvas.h"
#include "event\ChangeListener.h"
#include "event\ChangeEvent.h"
#include "component\Scrollbar.h"

namespace uitest
{
	namespace nodes
	{
			class RotatingCube : public ui::GLCanvas
			{
			public:
				RotatingCube();
				void render() const;
				void setHSpeed(int speed);
				void setVSpeed(int speed);

				void updateComponent(float deltaTime);
			private:
				void drawCube() const;
				float vRotation;
				float hRotation;
				float vSpeed;
				float hSpeed;
			};

			class OpenGLDemo : public ui::Dialog, public ui::event::ChangeListener
			{
			public:
				OpenGLDemo(Window *owner);
				~OpenGLDemo();
			private:
				void stateChanged(const ui::event::ChangeEvent &e);
				ui::Panel *contentPane;
				ui::layout::BorderLayout layout;
				RotatingCube *rotatingCube;
				ui::Scrollbar *vSlider;
				ui::Scrollbar *hSlider;
			};
	}
}

#endif