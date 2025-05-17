#pragma once

#include "wrath/component.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <optional>
#include <vector>
namespace Wrath
{
  class Entity
  {
  public:
    sf::Vector2f position = sf::Vector2f();
    sf::Vector2f velocity = sf::Vector2f();

    /// @brief Add a new component to the entity.
    /// @tparam TComponent The component type.
    /// @param ...args The constructor arguments for the component.
    template <typename TComponent, typename... TArgs>
    void enroll_component(TArgs &&...args);

    /// @brief Add a new component to the entity.
    /// @param component The component to add.
    void enroll_component(std::shared_ptr<Wrath::Component> component);

    /// @brief Should be called once when an event happens.
    virtual void event(std::optional<sf::Event>& event) {};

    /// @brief Should be called once when the entity is first created.
    virtual void awake() {};

    /// @brief Should be called every frame, before render.
    virtual void process(float delta) {};

    /// @brief Should be called every frame, after process.
    virtual void render() {};

    /// @brief Should be called once, when the entity is destroyed.
    virtual void leave() {};

    void handle_events(std::optional<sf::Event>& event);

    /// @brief This processes the components then the entity.
    void update(float delta);

    /// @brief This renders the components then the entity.
    void draw();

    /// @brief This calls leave() on all components then the entity.
    void destroy();

  private:
    std::vector<std::shared_ptr<Wrath::Component>> m_components;
  };
}
