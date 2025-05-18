#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <optional>
#include <string>
namespace Wrath
{
  class Game
  {
  public:
    Game(const std::string& title, sf::Vector2u size)
    {
      this->mTitle = title;
      this->mSize = size;
    };

    const std::string& title() const;
    void set_title(const std::string& title);

    const sf::Vector2u& size() const;
    void set_size(const sf::Vector2u& size);

    void close();

    virtual void event(std::optional<sf::Event> event) = 0;

    virtual void awake() = 0;
    virtual void process(float delta) = 0;
    virtual void render() = 0;

    virtual void leave() {};

    void create_and_run();

    sf::RenderWindow& window();
  protected:
    std::string mTitle;
    sf::Vector2u mSize;

    sf::RenderWindow mWindow;
  };
}
