#include "wrath/planet.h"
#include <SFML/Window/Event.hpp>
#include <optional>

template <typename TEntity, typename... TArgs>
inline std::weak_ptr<TEntity> Wrath::Planet::enroll(TArgs &&...args)
{
  // Compile-time check... C++ is not a sane language bro
  static_assert(std::is_base_of<Wrath::Entity, TEntity>::value,
                "TEntity must derive from Entity");

  std::shared_ptr<TEntity> entity =
      std::make_shared<TEntity>(std::forward<TArgs>(args)...);
  entity->awake();

  this->m_entities.emplace_back(entity);

  return entity;
}

inline void Wrath::Planet::enroll(std::shared_ptr<Wrath::Entity> entity)
{
  this->m_entities.push_back(entity);
}

inline void Wrath::Planet::event(std::optional<sf::Event>& event)
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->handle_events(event);
  }
}

inline void Wrath::Planet::process(float delta)
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->update(delta);
  }
}

inline void Wrath::Planet::render()
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->draw();
  }
}

inline void Wrath::Planet::leave()
{
  for (std::shared_ptr<Wrath::Entity> &entity : this->m_entities)
  {
    entity->destroy();
  }
}
