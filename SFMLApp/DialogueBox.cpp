
#include "DialogueBox.h"
#include <iostream>

DialogueBox::DialogueBox()
{
}

void DialogueBox::init(const std::string& fontFile, const std::string& text, const sf::Vector2f& size, const sf::Vector2f& position)
{


    if (!font.loadFromFile(fontFile)) {
        std::cerr << "Failed to load font" << std::endl;
    }

    box.setSize(size);
    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(3.0f);
    box.setOutlineColor(sf::Color::Black);
    box.setPosition(position);

    dialogueText.setFont(font);
    dialogueText.setString(text);
    dialogueText.setCharacterSize(20);
    dialogueText.setFillColor(sf::Color::Black);
    dialogueText.setPosition(position.x + 20, position.y + 20);
}

//returns a bool to check if there are more lines to display
bool DialogueBox::iterThruText()
{
    if (lineIter != lines.end())
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

