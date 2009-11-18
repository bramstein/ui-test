#ifndef TEXTUREFRAME_H
#define TEXTUREFRAME_H

#include "component\Frame.h"
#include "Graphics.h"
#include "config.h"

namespace uitest
{
	namespace nodes
	{
		class TextureFrame : public ui::Frame
		{
		public:
			TextureFrame(int x, int y, int width, int height);
			~TextureFrame();
			void paint(ui::Graphics &g);
			GLuint getTextureId() const;
		private:
			static const int textureWidth = 512;
			static const int textureHeight = 512;
			GLubyte texture[textureWidth][textureHeight][3];
			GLuint textureId;
		};
	};
}

#endif