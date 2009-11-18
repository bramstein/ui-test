#include ".\freetypefont.h"

#include <list>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>
// the only C header :O
#include <cassert>

namespace uitest
{
	FreeTypeFont::FreeTypeFont(const std::string &font, std::size_t size)
		:	fontName(font),
			pointSize(size)
	{
		ftfont = new OGLFT::TranslucentTexture(font.c_str(),static_cast<float>(size),96);

		// build cache (i really, really need to write my own font engine)
		for(int i = 0; i < 255; ++i)
		{
		
			OGLFT::BBox bbox = ftfont->measure(static_cast<unsigned char>(i));
			width[i] = static_cast<int>(bbox.advance_.dx_);
			height[i] = static_cast<int>(bbox.advance_.dy_ + bbox.y_max_);
			fontCache.push_back(ui::util::Dimension(static_cast<int>(bbox.advance_.dx_),static_cast<int>(bbox.y_max_ + bbox.advance_.dy_)));
		}

	}

	FreeTypeFont::~FreeTypeFont()
	{
		delete ftfont;
	}

	void FreeTypeFont::drawString(int x, int y, const std::string &text)
	{
		glEnable(GL_TEXTURE_2D);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glPushMatrix();
		
		//glTranslatef(x,y + ftfont->measure(text.c_str()).y_max_ ,0);
		glTranslatef(static_cast<GLfloat>(x),static_cast<GLfloat>(y + getStringBoundingBox(text).height) ,0);
		glScalef(1,-1,1);
		ftfont->draw(text.c_str());
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	}

	const std::string FreeTypeFont::getFontName() const
	{
		return fontName;
	}

	std::size_t FreeTypeFont::getSize() const
	{
		return pointSize;
	}

	ui::util::Dimension FreeTypeFont::getStringBoundingBox(const std::string &text) const
	{
		
		ui::util::Dimension ret;

		for(std::size_t i = 0; i < text.length(); ++i)
		{
			char c = text[i];
		//	ret.width += fontCache.at(static_cast<int>(c)).width;
		//	ret.height = max(ret.height,fontCache.at(static_cast<int>(c)).height);
		//	ret.width += fontCache[static_cast<int>(c)].width;
		//	ret.height = max(ret.height,fontCache[static_cast<int>(c)].height);

			ret.width += width[static_cast<int>(c)];
			ret.height = max(ret.height,height[static_cast<int>(c)]);
		}
		return ret;
		
		/*
		OGLFT::BBox bbox = ftfont->measure(text.c_str());
		return ui::util::Dimension((bbox.x_max_),(bbox.y_max_));
		*/
	}
}