
#include "DialogueBox.h"
#include <iostream>

DialogueBox::DialogueBox(sf::Font fontFile, std::vector<std::string> text, const sf::Vector2f& size, const sf::Vector2f& position)
{
    init(fontFile, text, size, position);
}

void DialogueBox::init(sf::Font fontFile, std::vector<std::string> text, const sf::Vector2f& size, const sf::Vector2f& position)
{

    box.setSize(size);
    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(3.0f);
    box.setOutlineColor(sf::Color::Black);
    box.setPosition(position);

    dialogueText.setFont(font);
    this->lines = text;
    dialogueText.setCharacterSize(20);
    dialogueText.setFillColor(sf::Color::Black);
    dialogueText.setPosition(position.x + 20, position.y + 20);
    this->lineIter = lines.begin();
}

//returns a bool to check if there are more lines to display
bool DialogueBox::iterThruText()
{
    if (lineIter != this->lines.end())
    {
        dialogueText.setString(*lineIter);
        lineIter++;
        return true;
    }
    else
    {
        return false;
    }
}

void DialogueBox::setPosition(const sf::Vector2f& position)
{
    box.setPosition(position);
    dialogueText.setPosition(position.x + 20, position.y + 20);
}

sf::Vector2f DialogueBox::getSize() const
{
    return box.getSize();
}

void DialogueBox::draw(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(dialogueText);
}

