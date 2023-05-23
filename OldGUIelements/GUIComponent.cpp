#include "GUIComponent.h"


Label::Label(const char* text, sf::Vector2f pos, short charsize, sf::Font& font, sf::Color fillColor, sf::Color outlineColor){
    this->text.setString(text);
    this->text.setCharacterSize(charsize);
    this->text.setFont(font);
    this->text.setPosition(pos);
    this->text.setFillColor(fillColor);
    this->text.setOutlineColor(outlineColor);
    this->text.setOutlineThickness(1);
    setOrigin(CENTER);
    this->fillColor = fillColor;
    this->outlineColor = outlineColor;
}

void Label::set_Color(sf::Color newColor, ColorType name){
    switch(name){
        case FILL:
            fillColor = newColor;
            this->text.setFillColor(fillColor);
            break;
        case HOVER:
            hoverColor = newColor;
            callUpdate = true;
            break;
        case OUTLINE:
            outlineColor = newColor;
            this->text.setOutlineColor(outlineColor);
            break;
        default:
            std::cout << "Label class has no PRESSED option" << std::endl;
            break;
    
    }

}


    void Label::setOrigin(Origin origin) {
        sf::Vector2f newOrigin;
        switch (origin){
            case TOPLEFT:
                newOrigin = sf::Vector2f(0,0);
                break;
            case TOPRIGHT:
                newOrigin = sf::Vector2f(this->text.getGlobalBounds().width,0);
                break;
            case BOTTOMLEFT:
                newOrigin = sf::Vector2f(this->text.getGlobalBounds().height,0);
                break;           
            case BOTTOMRIGHT:
                newOrigin = sf::Vector2f(this->text.getGlobalBounds().width,this->text.getGlobalBounds().height);
                break;
            case CENTER:
                newOrigin = sf::Vector2f(this->text.getGlobalBounds().width/2,this->text.getGlobalBounds().height/2);
                break;
        }
        this->text.setOrigin(newOrigin);
    }

void Label::Update(sf::Vector2f mousePos){
    if (!this->callUpdate) return;
    if (this->text.getGlobalBounds().contains(mousePos)) {
        this->text.setFillColor(hoverColor);
    }
    else {
        this->text.setFillColor(fillColor);
    }
}

void Label::Render(sf::RenderTarget& renderWindow){
    renderWindow.draw(this->text);
}