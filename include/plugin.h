#ifndef PLUGIN
#define PLUGIN value
#include <string>
class Plugin {
  public:
    Plugin() {};
    virtual ~Plugin() {};
    virtual std::string command(std::string command, std::string options) {return "";};
};

#endif /* ifndef PLUGIN */
