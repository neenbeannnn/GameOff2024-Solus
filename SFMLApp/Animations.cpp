#include "Animations.h"

Animations::Animations(sf::Texture& texture, sf::Vector2u imageCount, float switchTime)
    : imageCount(imageCount), switchTime(switchTime), totalTime(0.0f) {
    currentImage.x = 0;
    uvRect.width = texture.getSize().x / imageCount.x;
    uvRect.height = texture.getSize().y / imageCount.y;
}

void Animations::update(int row, float deltaTime) {
    currentImage.y = row; // Set the row for animation
    totalTime += deltaTime;

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x) {
            currentImage.x = 0; // Loop back to the first frame
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

sf::IntRect Animations::getUVRect() const {
    return uvRect;
}
