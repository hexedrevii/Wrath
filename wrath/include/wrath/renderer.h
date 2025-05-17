#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
namespace Wrath
{
  class Renderer
  {
  public:
    const sf::Vector2i dimensions;

    Renderer(sf::RenderWindow& window, int width, int height);
    Renderer(sf::RenderWindow& window, sf::Vector2i size);

    void attach(sf::Color colour);
    void detach();

    void detach_and_draw();
  private:
    sf::RenderTexture m_texture;
    sf::RenderWindow& m_window;
  };
}
