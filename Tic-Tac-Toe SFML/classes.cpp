#include <iostream>
#include <SFML/Graphics.hpp>

class Cats : public sf::Sprite
{
private:
    sf::Texture* texture;
public:
    Cats(const sf::Vector2f& position, const std::string filename)
    {
        texture = new sf::Texture();
        if (!texture->loadFromFile(filename))
        {
            std::cout << "Failed to load texture from " << filename << std::endl;
        }
        else
        {
            setTexture(*texture, true);
            setPosition(position);
        }
    }

};

class Rectangles
{
private:
    int x, y, z, w;
    std::vector<sf::Sprite> sprites;
public:
    Rectangles(int a, int b, int c, int d)
    {
        x = a, y = b, z = c, w = d;
    }

    sf::Vector2f returnCoords()
    {
        sf::Vector2f coords = sf::Vector2f(x, y);
        return coords;
    }

    bool ifContains(const sf::Vector2i& mousePos)
    {
        if (mousePos.x > x && mousePos.x < z && mousePos.y > y && mousePos.y < w)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
