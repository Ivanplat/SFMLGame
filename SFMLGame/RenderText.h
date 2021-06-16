#pragma once
#include "SFML/Graphics.hpp"
#include "BaseGameObject.h"
class RenderText : BaseGameObject
{
public:
	RenderText(sf::String fn, sf::String text) : FileName(fn)
	{
		TextFont.loadFromFile("./fonts/" + FileName);
		Text = sf::Text(text, TextFont, 20);
		Text.setFillColor(sf::Color::White);
	}
	RenderText(sf::String fn, sf::String text, sf::Color textcolor) : FileName(fn)
	{
		TextFont.loadFromFile("./fonts/" + FileName);
		Text = sf::Text(text, TextFont, 20);
		Text.setFillColor(textcolor);
	}
	RenderText(sf::String fn, sf::String text, sf::Color textcolor, unsigned int textsize) : FileName(fn)
	{
		TextFont.loadFromFile("./fonts/" + FileName);
		Text = sf::Text(text, TextFont, textsize);
		Text.setFillColor(textcolor);
	}
	RenderText()
	{
		TextFont.loadFromFile("./fonts/CyrilicOld.TTF");
		Text = sf::Text("Sample text", TextFont, 20);
		Text.setFillColor(sf::Color::White);
	}
	~RenderText() = default;
public:
	void SetFont(sf::Font textfont);
	void SetText(sf::String text);
	void SetSize(unsigned int textsize);
	void SetColor(sf::Color textcolor);
	void SetPosition(int x, int y);
	sf::Text& GetTextObject();
private:
	sf::Font TextFont;
	sf::Text Text;
	sf::String FileName;
};

