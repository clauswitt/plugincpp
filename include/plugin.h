#ifndef PLUGIN
#define PLUGIN value
#include <string>
class Plugin {
  public:
    Plugin() {};
    virtual ~Plugin() {};
    virtual std::string command(std::string command, std::string options) {return "";};
};


#define DEFINE_PLUGIN(classType, pluginName, pluginVersion)     \
  extern "C" {                                                  \
    Plugin* load()                                              \
    {                                                           \
      return new classType;                                     \
    }                                                           \
                                                                \
    void unload( Plugin* object )                               \
    {                                                           \
      delete object;                                            \
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
