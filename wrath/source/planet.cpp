#include "wrath/planet.h"
#include <SFML/Window/Event.hpp>
#include <optional>

void Wrath::Planet::enroll(std::shared_ptr<Wrath::Entity> entity)
{
  this->m_entities.push_back(entity);
}

void Wrath::Planet::event(std::optional<sf::Event>& event)
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->handle_events(event);
  }
}

void Wrath::Planet::process(float delta)
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->update(delta);
  }
}

void Wrath::Planet::render()
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->draw();
  }
}

void Wrath::Planet::leave()
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->destroy();
  }
}
