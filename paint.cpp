#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.cpp"

sf::Color colors[] = {
  sf::Color::Black,
  sf::Color::White,
  sf::Color::Red,
  sf::Color::Green,
  sf::Color::Blue,
  sf::Color::Yellow,
  sf::Color::Magenta,
  sf::Color::Cyan,
};

int main() {
  sf::RenderWindow window(sf::VideoMode(1400, 1000), "Pejncior2115");
  sf::VertexArray line;
  std::vector<sf::VertexArray> pixels;
  sf::Color color = sf::Color::Black;

  std::vector<Button> colorPalette;
  for (int i = 0; i < sizeof(colors); i++) {
    colorPalette.push_back(Button(sf::Vector2f((i+1) * 10 + i*50, 10), sf::Vector2f(50, 50), colors[i]));
  }

  window.setFramerateLimit(30);
  line.setPrimitiveType(sf::LinesStrip);

  while (window.isOpen()) {
    sf::Event event;
    sf::Vector2i pos = sf::Mouse::getPosition(window);

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (pos.y > 100) {
        // BUTTON PRESSED
        if (event.type == sf::Event::MouseButtonPressed)
          pixels.push_back(line);

        // BUTTON HOLD
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && pos.y > 100)
          pixels.back().append(sf::Vertex(sf::Vector2f(pos.x, pos.y), color));

        // BUTTON RELEASED
        if (event.type == sf::Event::MouseButtonReleased) 
          line.clear();
      } else {
        if (event.type == sf::Event::MouseButtonPressed) {
          for (auto btn : colorPalette) {
            if (btn.clicked(pos.x, pos.y)) {
              color = btn.rect.getFillColor();
              break;
            }
          }
        }
      }
    }

    window.clear(sf::Color::White);

    for (auto l : pixels) window.draw(l);
    for (auto btn : colorPalette) window.draw(btn.rect);

    window.display();
  }
  return 0;
}
