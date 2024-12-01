#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
class DialogueBox
{
public:
    DialogueBox(sf::Font fontFile, std::vector<std::string> text, const sf::Vector2f& size, const sf::Vector2f& position);
    void init(sf::Font fontFile, std::vector<std::string> text, const sf::Vector2f& size, const sf::Vector2f& position);
    bool iterThruText();
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getSize() const;
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape box;
    sf::Text dialogueText;
    sf::Font font; // Store the font as a member

    //samples lines
    std::vector<std::string> lines;
    std::vector<std::string>::iterator lineIter;
};