#include "wrath/content.h"
#include "wrath/path.h"
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <string_view>

void Wrath::ContentLoader::enroll(const std::string_view name, const std::filesystem::path& path)
{
  this->mTextures[name] = std::make_unique<sf::Texture>(path);
}

void Wrath::ContentLoader::enroll_relative(const std::string_view name, const std::filesystem::path& relative)
{
  std::string base = Wrath::get_base_directory();
  this->enroll(name, base / relative);
}

const sf::Texture& Wrath::ContentLoader::get(const std::string_view name) const
{
  return *this->mTextures.at(name);
}
