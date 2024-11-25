#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
class DialogueBox
{
public:
    DialogueBox();
    void init(const std::string& fontFile, const std::string& text, const sf::Vector2f& size, const sf::Vector2f& position);
    bool iterThruText();
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getSize() const;
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape box;
    sf::Text dialogueText;
    sf::Font font; // Store the font as a member

    //samples lines
    std::vector<std::string> lines = { "Look mom, I'm a cat!", "I'm a cat, mom!", "Meow!", "Feed Me!" };
    std::vector<std::string>::iterator lineIter = lines.begin();
};