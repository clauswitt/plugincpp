#include <plugin.h>

class MyPlugin : public Plugin {
  public:

    MyPlugin() {
    }

    ~MyPlugin() {

    }

    virtual std::string command(std::string command, std::string options) {
      return "OK";
    }


};

DEFINE_PLUGIN(MyPlugin, "First Plugin", "0.0.1")
