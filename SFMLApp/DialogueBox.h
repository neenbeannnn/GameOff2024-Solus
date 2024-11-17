#pragma once
#include <SFML/Graphics.hpp>

class DialogueBox
{
public:
    DialogueBox(const sf::Font& font, const std::string& text, const sf::Vector2f& size, const sf::Vector2f& position);
    void setText(const std::string& text);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getSize() const;
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape box;
    sf::Text dialogueText;
};




