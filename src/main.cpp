#include <dirent.h>
#include <plugin.h>
#include <iostream>
#include <vector>
#include "./plugin_handler.hpp"

std::vector<PluginHandler> load_plugins() {
  std::vector<PluginHandler> plugins;

  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir ("plugins/bin")) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      if(ent->d_name[0] != '.')
        plugins.push_back(PluginHandler("plugins/bin/" + std::string(ent->d_name)));
    }
    closedir (dir);
  }
  return plugins;
}

int main(int argc, char *argv[])
{
  auto plugins = load_plugins();
  for (auto ph : plugins) {
    ph.load();
    std::cerr << "Auto loaded plugin: " << ph.get_name() << ", version: " << ph.get_version() << std::endl;
  }
   return 0;
}
