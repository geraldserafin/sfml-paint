#include <SFML/Graphics.hpp>

class Button {
public:
  sf::RectangleShape rect;
  Button(sf::Vector2f position, sf::Vector2f size, sf::Color fill);
  bool clicked(int x, int y);
};