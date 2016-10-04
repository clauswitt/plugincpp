#include <dlfcn.h>
#include <plugin.h>
class PluginHandler {
  std::shared_ptr<Plugin> (*_load)();
  void* handle;
  char* (*_get_name)();
  char* (*_get_version)();

  std::shared_ptr<Plugin> instance;
  public:

  PluginHandler(std::string name) {
    handle = dlopen(name.c_str(), RTLD_LAZY);
    _load = (std::shared_ptr<Plugin> (*)())dlsym(handle, "load");
    _get_name = (char* (*)())dlsym(handle, "name");
    _get_version = (char* (*)())dlsym(handle, "version");
  }

  std::string get_name() {
    return std::string(_get_name());
  }

  std::string get_version() {
    return std::string(_get_version());
  }

  std::shared_ptr<Plugin> load() {
    if(!instance)
      instance = _load();
    return instance;
  }

};

