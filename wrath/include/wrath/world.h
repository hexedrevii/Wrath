#pragma once

#include <SFML/Window/Event.hpp>
#include <optional>
namespace Wrath
{
  /// @brief Represents the default world class.
  class World
  {
  public:
    virtual ~World() = default;

    /// @brief Ran when an event happens.
    virtual void event(std::optional<sf::Event> &event) {};

    /// @brief Ran once when the world is created.
    virtual void awake() {};

    /// @brief Ran every frame before render.
    virtual void process(float delta) {};

    /// @brief Ran every frame after process.
    virtual void render() {};

    /// @brief Ran when the world is changed by the universe.
    virtual void leave() {};
  };
}
