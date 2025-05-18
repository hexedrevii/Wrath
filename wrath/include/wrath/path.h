#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__APPLE__)
#include <limits.h>
#include <mach-o/dyld.h>
#else
#include <linux/limits.h>
#include <unistd.h>
#endif

namespace Wrath
{
  /// @brief Get the binary directory path.
  inline const std::string get_base_directory()
  {
    char path[PATH_MAX];

#if defined(_WIN32)
    if (GetModuleFileNameA(NULL, path, MAX_PATH) == 0)
      return "";

    std::string full_path(path);
    return full_path.substr(0, full_path.find_last_of("\\/"));

#elif defined(__APPLE__)
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) != 0)
      return "";

    std::string full_path(path);
    return full_path.substr(0, full_path.find_last_of("/"));
#else
    ssize_t count = readlink("/proc/self/exe", path, PATH_MAX);
    if (count == -1)
      return "";

    std::string full_path(path, count);
    return full_path.substr(0, full_path.find_last_of("/"));
#endif
  }

  inline sf::Texture load_texture_relative(const std::filesystem::path& relative)
  {
    std::string base = Wrath::get_base_directory();
    return sf::Texture(base / relative);
  }
}
