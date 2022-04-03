#include "button.hpp"
#include <iostream>

Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color fill) {
  this->rect.setPosition(position);
  this->rect.setSize(size);
  this->rect.setFillColor(fill);
}

bool Button::clicked(int x, int y) {
  sf::Vector2f pos  = this->rect.getPosition();
  sf::Vector2f size = this->rect.getSize();

  return pos.x <= x && x <= pos.x + size.x && pos.y <= y && y <= pos.y + size.y;
}