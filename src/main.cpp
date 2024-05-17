#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
  sf::RenderWindow window =
      sf::RenderWindow{{1920u, 1080u}, "CMake SFML Project"};
  window.setFramerateLimit(60);
  std::string fuenteRuta = "resources/fonts/Arial.ttf";
  sf::Font arial;
  if (!arial.loadFromFile(fuenteRuta))
    std::cerr << "Error al cargar la fuente" << std::endl;
  sf::Text texto;
  texto.setFont(arial);
  texto.setStyle(sf::Text::Bold);
  texto.setFillColor(sf::Color::Red);
  texto.setString("Hola mundo");
  texto.setCharacterSize(24);

  while (window.isOpen()) {
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(texto);
    window.display();
  }
}
