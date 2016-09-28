#include <dlfcn.h>
#include <plugin.h>
class PluginHandler {
  Plugin* (*_load)();
  void (*_unload)(Plugin*);
  void* handle;
  char* (*_get_name)();
  char* (*_get_version)();

  Plugin* instance;
  public:

  PluginHandler(std::string name) {
    instance = nullptr;
    handle = dlopen(name.c_str(), RTLD_LAZY);
    _load = (Plugin* (*)())dlsym(handle, "load");
    _unload = (void (*)(Plugin*))dlsym(handle, "unload");
    _get_name = (char* (*)())dlsym(handle, "name");
    _get_version = (char* (*)())dlsym(handle, "version");
  }

  std::string get_name() {
    return std::string(_get_name());
  }

  std::string get_version() {
    return std::string(_get_version());
  }

  Plugin* load() {
    if(instance==nullptr)
      instance = _load();
    return instance;
  }

  ~PluginHandler() {
    if(instance!=nullptr)
      _unload(instance);
  }

};

