#ifndef PLUGIN
#define PLUGIN 1
#include <string>
class Plugin {
  public:
    Plugin() {};
    virtual ~Plugin() {};
    virtual std::string command(std::string command, std::string options) {return "";}
};


#define DEFINE_PLUGIN(classType, pluginName, pluginVersion)     \
  extern "C" {                                                  \
    std::shared_ptr<Plugin> load()                                         \
    {                                                           \
      return std::make_shared<classType>();                     \
    }                                                           \
                                                                \
    const char* name()                                          \
    {                                                           \
      return pluginName;                                        \
    }                                                           \
                                                                \
    const char* version()                                       \
    {                                                           \
      return pluginVersion;                                     \
    }                                                           \
  }

#endif /* ifndef PLUGIN */
