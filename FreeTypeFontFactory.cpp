#include ".\FreeTypeFontFactory.h"
#include ".\FreeTypeFont.h"

namespace uitest
{
	ui::Font * FreeTypeFontFactory::createFont(const std::string &font, std::size_t size)
	{
		// we keep a list of all our allocated memory here, as the GUI does not.
		FreeTypeFont * f = new FreeTypeFont(font,size);
		fontList.push_back(f);

		return f;
	}

	FreeTypeFontFactory::~FreeTypeFontFactory()
	{
		std::vector<ui::Font*>::iterator iter;
		for(iter = fontList.begin(); iter != fontList.end(); ++iter)
		{
			delete (*iter);
		}
		fontList.clear();
	}
}
