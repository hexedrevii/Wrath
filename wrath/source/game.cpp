#include "wrath/game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

void Wrath::Game::create_and_run()
{
  this->mWindow = sf::RenderWindow(
    sf::VideoMode(this->mSize),
    this->mTitle
  );

  this->awake();
  sf::Clock delta_timer;
  while (this->mWindow.isOpen())
  {
    sf::Time delta = delta_timer.restart();
    float delta_seconds = delta.asSeconds();

    while (std::optional<sf::Event> e = this->mWindow.pollEvent())
    {
      if (e->is<sf::Event::Closed>())
      {
        this->mWindow.close();
      }

      if (const sf::Event::Resized* r = e->getIf<sf::Event::Resized>())
      {
        sf::FloatRect visible_area(sf::Vector2f(0, 0), sf::Vector2f(r->size));
        this->mWindow.setView(sf::View(visible_area));
      }

      this->event(e);
    }

    this->process(delta_seconds);
    this->render();

    this->mWindow.display();
  }

  this->leave();
}

const std::string& Wrath::Game::title() const
{
  return this->mTitle;
}

void Wrath::Game::set_title(const std::string& title)
{
  this->mTitle = title;
  this->mWindow.setTitle(title);
}

const sf::Vector2u& Wrath::Game::size() const
{
  return this->mSize;
}

void Wrath::Game::set_size(const sf::Vector2u& size)
{
  this->mWindow.setSize(size);
}

sf::RenderWindow& Wrath::Game::window()
{
  return this->mWindow;
}


