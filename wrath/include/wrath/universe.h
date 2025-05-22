#pragma once

#include "wrath/world.h"
#include <SFML/Window/Event.hpp>
#include <memory>
#include <optional>

namespace Wrath
{
  /// @brief Represents a world handler.
  class Universe
  {
  public:
    /// @brief Set the active world.
    void set(std::unique_ptr<Wrath::World> next);
    template <typename TWorld, typename... TArgs> void set(TArgs &&...args);

    /// @brief Get the active world, casted to a specific type.
    template<typename TWorld> TWorld* get();

    /// @brief Handle world events.
    void event(std::optional<sf::Event> &event);

    /// @brief Process the world.
    void process(float delta);

    /// @brief Render the world.
    void render();

  private:
    std::unique_ptr<World> m_active;
  };

  template <typename TWorld, typename... TArgs>
  inline void Wrath::Universe::set(TArgs &&...args)
  {
    static_assert(std::is_base_of<World, TWorld>::value, "TWorld must derive from World");

    if (this->m_active != nullptr)
    {
      this->m_active->leave();
    }

    this->m_active = std::make_unique<TWorld>(std::forward<TArgs>(args)...);
    this->m_active->awake();
  }

  template<typename TWorld>
  inline TWorld* Wrath::Universe::get()
  {
    static_assert(std::is_base_of<World, TWorld>::value, "TWorld must derive from World");
    return dynamic_cast<TWorld*>(this->m_active.get());
  }
}
