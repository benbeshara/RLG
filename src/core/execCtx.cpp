#include "raylib.h"
#include "execCtx.h"
#include "guiBuilder.h"
#include <chaiscript/chaiscript.hpp>
#include <json.hpp>
#include <string>

void execCtx::parseFile(const std::string &fileName) {
  std::ifstream i(fileName);
  if (!i.is_open()) {
    TraceLog(LOG_WARNING, "ParseFile: Script not found");
    return;
  }
  nlohmann::json j;
  i >> j;
  
  this->parseLayout(j);
}

void execCtx::parseLayout(const nlohmann::json &json, std::optional<uint64_t> parentWidget) {
  for (auto &element: json) {
    std::string widget = element["widget"];
    auto name = element.value("name", "");
    auto props = element["props"];
    
    auto builder = new guiBuilder(widget, props);
    
    uint64_t widgetId;
    
    if (parentWidget) {
      auto parent = dynamic_cast<Widget_Container_Draggable *>(state->widgetList.find(
          *parentWidget)->second);
      widgetId = parent->AddWidget(builder->widget, name);
    } else {
      widgetId = state->AddWidget(builder->widget, name);
    }
    
    if (element.contains("contains")) {
      this->parseLayout(element["contains"], widgetId);
    }
    
    TraceLog(LOG_INFO, widget.c_str());
  }
}

execCtx::execCtx(State *State) {
  ctx.add(chaiscript::fun(&execCtx::parseFile, this), "parseFile");
  state = State;
}

bool execCtx::verifyBuffer() {
  if (commandBuffer.length() > 0)
    return true;
  
  TraceLog(LOG_WARNING, "VerifyBuffer: Script not loaded");
  return false;
}

void execCtx::loadBuffer(const std::string &filename) {
  std::ifstream ifs(filename);
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()));
  
  commandBuffer = content;
}

void execCtx::run() {
  if (verifyBuffer()) {
    ctx.eval(commandBuffer);
  }
}

void execCtx::runOnce(std::string cmd) {
  ctx.eval(cmd);
}