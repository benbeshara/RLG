#include "raylib-cpp.hpp"
#include "execCtx.h"
#include "guiBuilder.h"
#include <chaiscript/chaiscript.hpp>
#include <json.hpp>
#include <string>

void execCtx::parseLayout(const std::string& fileName) {
    std::ifstream i(fileName);
    nlohmann::json j;
    i >> j;

    for (auto &element : j){
        std::string widget = element["widget"];
        auto props = element["props"];

        auto builder = new guiBuilder(widget, props);

        state->AddWidget(builder->widget);

        TraceLog(LOG_INFO, widget.c_str());
    }
};

execCtx::execCtx(State* State) {
    ctx.add(chaiscript::fun(&execCtx::parseLayout, this), "parseLayout");
    state = State;
};

bool execCtx::verifyBuffer() {
  if (commandBuffer.length() > 0)
    return true;

  return false;
};

void execCtx::loadBuffer(std::string filename) {
    std::ifstream ifs(filename);
    std::string content( (std::istreambuf_iterator<char>(ifs)),
                         (std::istreambuf_iterator<char>()));

    commandBuffer = content;
}

void execCtx::run() {
  if (verifyBuffer()) {
    ctx.eval(commandBuffer);
  }
}