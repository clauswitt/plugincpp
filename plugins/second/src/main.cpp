#include <plugin.h>

class MyPlugin : public Plugin {
  public:
    virtual std::string command(std::string command, std::string options) {
      return command + " " + options;
    }
};

DEFINE_PLUGIN(MyPlugin, "Second Plugin", "0.0.1")
