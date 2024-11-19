#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // Load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        m_tileSize = tileSize;
        m_width = width;
        m_height = height;
        m_tiles.assign(tiles, tiles + width * height);

        // Resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // Populate the vertex array, with one quad per tile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // Get the current tile number
                int tileNumber = tiles[i + j * width];

                // Find its position in the tileset texture
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // Get a pointer to the current tile's quad
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // Define its 4 corners
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // Define its 4 texture coordinates
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

    bool isSolidTile(int x, int y) const {
        if (x < 0 || x >= static_cast<int>(m_width) || y < 0 || y >= static_cast<int>(m_height))
            return true; // Out of bounds is considered solid

        int tileNumber = m_tiles[x + y * m_width];
        return tileNumber == 22 || tileNumber == 23 || tileNumber == 54 || tileNumber == 55; // Only tiles 22, 23, 54, and 55 are considered solid
    }

    sf::Vector2u getTileSize() const { return m_tileSize; }

    void setDebugDrawing(bool enabled) { m_debugDrawing = enabled; }

    void setScale(float scaleX, float scaleY) {
        m_scaleX = scaleX;
        m_scaleY = scaleY;
    }

    float getScaleX() const { return m_scaleX; }
    float getScaleY() const { return m_scaleY; }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // Apply the transform
        states.transform *= getTransform();
        states.transform.scale(m_scaleX, m_scaleY);

        // Apply the tileset texture
        states.texture = &m_tileset;

        // Draw the vertex array
        target.draw(m_vertices, states);

        // Draw debug grid if enabled
        if (m_debugDrawing)
        {
            sf::RectangleShape tileOutline(sf::Vector2f(m_tileSize.x, m_tileSize.y));
            tileOutline.setFillColor(sf::Color::Transparent);
            tileOutline.setOutlineThickness(1.0f);
            tileOutline.setOutlineColor(sf::Color::Red);

            for (unsigned int i = 0; i < m_width; ++i)
            {
                for (unsigned int j = 0; j < m_height; ++j)
                {
                    tileOutline.setPosition(i * m_tileSize.x, j * m_tileSize.y);
                    target.draw(tileOutline, states);
                }
            }
        }
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Vector2u m_tileSize;
    std::vector<int> m_tiles;
    unsigned int m_width;
    unsigned int m_height;
    bool m_debugDrawing = false;
    float m_scaleX = 1.0f;
    float m_scaleY = 1.0f;
};

#endif // TILEMAP_H
