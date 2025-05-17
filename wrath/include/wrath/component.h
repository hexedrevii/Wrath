#pragma once

#include <SFML/Window/Event.hpp>
#include <optional>
namespace Wrath
{
  class Entity;

  class Component
  {
  public:
    /// @brief Entity parent of the component
    Wrath::Entity *parent = nullptr;
    int id = -1;

    /// @brief Should be called once when an event happens.
    virtual void event(std::optional<sf::Event>& event) {};

    /// @brief Should be called every frame, before render.
    virtual void render() {};

    /// @brief Should be called every frame, after process.
    virtual void process(float delta) {};

    /// @brief Should be called once, when the component is destroyed.
    virtual void leave() {};
  };
}
