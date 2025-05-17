#include "wrath/universe.h"
#include <SFML/Window/Event.hpp>
#include <optional>

inline void Wrath::Universe::event(std::optional<sf::Event>& event)
{
  if (this->m_active != nullptr)
  {
    this->m_active->event(event);
  }
}

inline void Wrath::Universe::process(float delta)
{
  if (this->m_active != nullptr)
  {
    this->m_active->process(delta);
  }
}

inline void Wrath::Universe::render()
{
  if (this->m_active != nullptr)
  {
    this->m_active->render();
  }
}
