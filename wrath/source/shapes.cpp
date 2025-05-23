#include "wrath/shapes.h"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>

void Wrath::draw_rectangle_lines(sf::RenderTarget &target, sf::FloatRect &rect, sf::Color colour)
{
  std::array vertices = {
    sf::Vertex { sf::Vector2f(rect.position.x - 1, rect.position.y), colour },
    sf::Vertex { sf::Vector2f(rect.position.x + rect.size.x, rect.position.y), colour },
    sf::Vertex { sf::Vector2f(rect.position.x + rect.size.x, rect.position.y + rect.size.y), colour },
    sf::Vertex { sf::Vector2f(rect.position.x, rect.position.y + rect.size.y), colour },
    sf::Vertex { rect.position, colour }
  };

  target.draw(vertices.data(), vertices.size(), sf::PrimitiveType::LineStrip);
}
