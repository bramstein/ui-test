
#ifndef FREETYPEFONT_H
#define FREETYPEFONT_H

#include "Font.h"
#include ".\OGLFT.h"

namespace uitest
{
	class FreeTypeFont : public ui::Font
	{
	public:
		FreeTypeFont(const std::string &font, std::size_t size);
		const std::string getFontName() const;
		std::size_t getSize() const;
		ui::util::Dimension getStringBoundingBox(const std::string &text) const;
		void drawString(int x, int y, const std::string &text);
		~FreeTypeFont();
	private:
		std::size_t pointSize;
		std::string fontName;
		OGLFT::TranslucentTexture *ftfont;
		std::vector<ui::util::Dimension> fontCache;
		int width[256];
		int height[256];
	};
}

#endif