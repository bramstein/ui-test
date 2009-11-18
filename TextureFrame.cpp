#include ".\TextureFrame.h"
//#include ".\imdebug.h"
#include "SelectionManager.h"

namespace uitest
{
	namespace nodes
	{
		TextureFrame::TextureFrame(int x, int y, int width, int height)
			: ui::Frame(x,y,width,height)
		{
			glGenTextures(1,&textureId);
			glBindTexture(GL_TEXTURE_2D,textureId);
			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
			
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		}

		TextureFrame::~TextureFrame()
		{
		}

		GLuint TextureFrame::getTextureId() const
		{
			return textureId;
		}

		void TextureFrame::paint(ui::Graphics &g)
		{
			int x = getLocationOnScreen().x;
			int y = getLocationOnScreen().y;
			int width = getBounds().width;
			int height = getBounds().height;

			int viewport[4];
			glGetIntegerv(GL_VIEWPORT,viewport);
			y = viewport[1];
		
			glPushAttrib(GL_ALL_ATTRIB_BITS);
			glViewport(x,y,width,height);

			glLoadIdentity();

			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
				glLoadIdentity();
				gluOrtho2D(x,width,height,y);

				ui::Frame::paint(g);

			glPopMatrix();
			
			glBindTexture(GL_TEXTURE_2D,textureId);
			glCopyTexSubImage2D(GL_TEXTURE_2D,0,0,0,x,y,width,height);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
			glPopAttrib();

		}
	}
}