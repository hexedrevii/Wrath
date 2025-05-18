#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>
#include <memory>
#include <string_view>
#include <unordered_map>
namespace Wrath
{
  class ContentLoader
  {
  public:
    void enroll(const std::string_view name, const std::filesystem::path& path);
    void enroll_relative(const std::string_view name, const std::filesystem::path& relative);

    const sf::Texture& get(const std::string_view name) const;
  private:
    std::unordered_map<std::string_view, std::unique_ptr<sf::Texture>> mTextures;
  };
}
