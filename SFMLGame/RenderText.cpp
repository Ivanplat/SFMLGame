#include "RenderText.h"

void RenderText::SetFont(sf::Font textfont)
{
	Text.setFont(textfont);
}

void RenderText::SetText(sf::String text)
{
	Text.setString(text);
}

void RenderText::SetSize(unsigned int textsize)
{
	Text.setCharacterSize(textsize);
}

void RenderText::SetColor(sf::Color textcolor)
{
	Text.setFillColor(textcolor);
}

void RenderText::SetPosition(int x, int y)
{
	Text.setPosition(x, y);
}

sf::Text& RenderText::GetTextObject()
{
	return Text;
}
