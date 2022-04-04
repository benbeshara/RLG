#include "../widgets/WG_TextInput.h"
#include "../widgets/WG_Window.h"
#include "state.h"
#include "widget_container_draggable.h"
#include <chaiscript/chaiscript.hpp>

class Builder {
public:
  Builder(State defaultState);
  void fromScript(std::string script);
  void add(Widget *widget, Widget_Container_Draggable *parent = nullptr);

protected:
  chaiscript::ChaiScript ctx;
  State state;
};

Builder::Builder(State defaultState) {
  ctx.add(chaiscript::fun(&Builder::add, this), "AddWidget");
  ctx.add(chaiscript::constructor<WG_TextInput(const WG_TextInput &)>(),
          "WG_TextInput");
  ctx.add(chaiscript::constructor<WG_Window(const WG_Window &)>(), "WG_Window");
}

void Builder::fromScript(std::string script) { ctx.eval_file<void>(script); }

void Builder::add(Widget *widget, Widget_Container_Draggable *parent) {
  if (parent != nullptr) {
    parent->AddWidget(widget);
  } else {
    state.AddWidget(widget);
  }
}