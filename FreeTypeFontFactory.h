
#ifndef FREETYPEFONTFACTORY_H
#define FREETYPEFONTFACTORY_H

#include "Font.h"

namespace uitest
{
	class FreeTypeFontFactory : public ui::AbstractFontFactory
	{
	public:
		ui::Font * createFont(const std::string &font, std::size_t size);
		~FreeTypeFontFactory();
	private:
		std::vector<ui::Font*> fontList;
	};
}

#endif
