#include "wrath/renderer.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <algorithm>

Wrath::Renderer::Renderer(sf::RenderWindow& window, int width, int height)
  : m_window(window), dimensions(sf::Vector2i(width, height))
{
  this->m_texture = sf::RenderTexture(sf::Vector2u(width, height));
}

Wrath::Renderer::Renderer(sf::RenderWindow& window, sf::Vector2i size)
  : m_window(window), dimensions(size)
{
  this->m_texture = sf::RenderTexture(sf::Vector2u(size.x, size.y));
}

void Wrath::Renderer::attach(sf::Color colour)
{
  this->m_texture.clear(colour);
}

void Wrath::Renderer::detach()
{
  this->m_texture.display();
}

void Wrath::Renderer::detach_and_draw()
{
  this->detach();

  sf::Sprite tx(this->m_texture.getTexture());

  sf::Vector2u size = this->m_window.getSize();

  float scale = std::min(
    static_cast<float>(size.x) / this->dimensions.x,
    static_cast<float>(size.y) / this->dimensions.y
  );

  tx.setPosition(
    sf::Vector2f(
      (size.x - (dimensions.x * scale)) * 0.5f,
      (size.y - (dimensions.y * scale)) * 0.5f
    )
  );

  tx.setScale(sf::Vector2f(scale, scale));
  this->m_window.draw(tx);
}
