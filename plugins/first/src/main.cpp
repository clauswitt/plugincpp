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

extern "C" Plugin* load()
{
  return new MyPlugin;
}

extern "C" void unload( Plugin* object )
{
  delete object;
}
