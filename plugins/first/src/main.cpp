#include <plugin.h>

class MyPlugin : public Plugin {
  public:

    MyPlugin() {
    }

    ~MyPlugin() {

    }

    std::string get_value() {

      return "THIS IS INTERNAL TO THE PLUGIN";
    
    }

    virtual std::string command(std::string command, std::string options) {
      return get_value();
    }


};

DEFINE_PLUGIN(MyPlugin, "First Plugin", "0.0.1")
