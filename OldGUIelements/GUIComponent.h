#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H
#pragma once
#include "UIEnumOpt.h"
#include <SFML/Graphics.hpp>

class GUIComponent
{
    protected:
        sf::Color fillColor;
        sf::Color outlineColor;
        sf::Color hoverColor;
        sf::Color pressedColor;
        bool callUpdate = false;
    public:
        unsigned short ID = -1;
    public:
        virtual void Update(sf::Vector2f mousePos) = 0;
        virtual void Render(sf::RenderTarget& renderWindow) = 0;
};

class Label : public GUIComponent {
    private:
        sf::Text text;
    public:
        Label(const char* text, sf::Vector2f pos, short charsize, sf::Font& font, sf::Color fillColor, sf::Color outlineColor);

        Label(const char* text, sf::Vector2f pos, short charSize, sf::font& font, sf::Color fillColor)
            : Label(text,pos,charSize,font,fillColor,sf::Color::White) {}

        Label(const char* text, short charSize, sf::Font& font, sf::Color fillColor) 
            : Label(text,sf::Vector2f(0,0), charSize, font, fillColor) {}
        
        Label (){}
        void set_Color(sf::Color newColor, ColourType name);
        void setOrigin(Origin origin);
        void setOutlineThickness(float amount) {this->text.setOutlineThickness(amount)};

        void Update(sf::Vector2f mousePos);
        void Render(sf::RenderTarget& renderWindow);

};


#endif