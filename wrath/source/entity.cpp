#include "wrath/entity.h"
#include <SFML/Window/Event.hpp>

void Wrath::Entity::handle_events(std::optional<sf::Event>& event)
{
  for (std::shared_ptr<Wrath::Component> &component : this->m_components)
  {
    component->event(event);
  }

  this->event(event);
}

void Wrath::Entity::update(float delta)
{
  for (std::shared_ptr<Wrath::Component> &component : this->m_components)
  {
    component->process(delta);
  }

  this->process(delta);
}

void Wrath::Entity::draw()
{
  for (std::shared_ptr<Wrath::Component> &component : this->m_components)
  {
    component->render();
  }

  this->render();
}

void Wrath::Entity::destroy()
{
  for (std::shared_ptr<Wrath::Component> &component : this->m_components)
  {
    component->leave();
  }

  this->leave();
}

template <typename TComponent, typename... TArgs>
inline void Wrath::Entity::enroll_component(TArgs &&...args)
{
  static_assert(std::is_base_of<Wrath::Component, TComponent>::value, "TComponent must derive from Component");

  std::shared_ptr<TComponent> component = std::make_shared<TComponent>(std::forward<TArgs>(args)...);
  component->id = this->m_components.size();
  component->parent = this;

  this->m_components.emplace_back(component);
}

inline void Wrath::Entity::enroll_component(std::shared_ptr<Component> component)
{
  if (component->id == -1)
    component->id = this->m_components.size();
  if (component->parent == nullptr)
    component->parent = this;

  this->m_components.push_back(component);
}
