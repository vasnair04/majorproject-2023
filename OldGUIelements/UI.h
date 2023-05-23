#ifndef UI_H
#define UI_H
#include "GUIComponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class UI {
    private:
        sf::RenderWindow* window;

        // ELEMENTS
        std::vector<std::unique_ptr<GUIComponent>> UIElements;
    public:
        void init (sf::RenderWindow& renderWindow, sf::Font& font);

        Label& createText(const char* text,sf::Vector2f pos,short charSize,sf::Color fillColor, sf::Font& font);

        void Update(sf::Event& evnt, sf::RenderWindow& window);
        void Render();

};





#endif