#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
namespace Wrath
{
  void draw_rectangle_lines(sf::RenderTarget& target, sf::FloatRect& rect, sf::Color colour);
}
