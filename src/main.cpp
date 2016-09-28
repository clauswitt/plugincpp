#include <plugin.h>
#include <iostream>
#include "./plugin_handler.hpp"

int main(int argc, char *argv[])
{
  PluginHandler first( "plugins/first/libfirst_plugin.dylib" );
  std::cerr << "Loading plugin: " << first.get_name() << " - in version: " << first.get_version() << std::endl;
  Plugin* plugin = first.load();

  PluginHandler second( "plugins/second/libsecond_plugin.dylib" );
  std::cerr << "Loading plugin: " << second.get_name() << " - in version: " << second.get_version() << std::endl;
  Plugin* plugin2 = second.load();

  std::cerr << plugin->command("Something", "here") << std::endl;
  std::cerr << plugin2->command("Something", "here") << std::endl;
   return 0;
}
