#include <dlfcn.h>
#include <plugin.h>
class PluginHandler {
  Plugin* (*_load)();
  void (*_unload)(Plugin*);
  void* handle;
  Plugin* instance;
  public:

  PluginHandler(std::string name) {
    instance = nullptr;
    handle = dlopen(name.c_str(), RTLD_LAZY);
    _load = (Plugin* (*)())dlsym(handle, "load");
    _unload = (void (*)(Plugin*))dlsym(handle, "unload");
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

Plugin* load_plugin(std::string name) {

}
