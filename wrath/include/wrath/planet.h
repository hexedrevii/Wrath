#pragma once

#include "wrath/entity.h"
#include <SFML/Window/Event.hpp>
#include <memory>
#include <optional>
namespace Wrath
{
  class Planet
  {
  public:
    /// @brief Enroll a new entity into the planet.
    /// @param ...args The constructor args for the entity.
    /// @return The new entity
    template <typename TEntity, typename... TArgs>
    std::weak_ptr<TEntity> enroll(TArgs &&...args);

    /// @brief Enroll an entity to the planet.
    /// @param entity The entity to enroll
    void enroll(std::shared_ptr<Wrath::Entity> entity);

    /// @brief Should be called once when an event happens.
    virtual void event(std::optional<sf::Event>& event);

    /// @brief Should be called once a frame, before render.
    void process(float delta);

    /// @brief Should be called once a frame, after process.
    void render();

    /// @brief Should be called once, right before the planet is destroyed.
    void leave();

  private:
    std::vector<std::shared_ptr<Wrath::Entity>> m_entities;
  };
}
