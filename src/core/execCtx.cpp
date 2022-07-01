#include "raylib.h"
#include "execCtx.h"
#include "guiBuilder.h"
#include "GameStore.h"
#include "scriptFns.h"
#include <chaiscript/chaiscript.hpp>
#include <json.hpp>
#include <string>

static void setGuiCanvasScale(Vector2 canvasSize) {
  GameStore *store = GameStore::GetInstance();
  store->getState()->SetGuiScale(
      {
          store->getConfig()->getConfig<int>(
              gameConfig::E_CONFIG::SCREEN_SIZE_X
          ) / canvasSize.x,
          store->getConfig()->getConfig<int>(
              gameConfig::E_CONFIG::SCREEN_SIZE_Y
          ) / canvasSize.y
      }
  );
}

void execCtx::parseFile(const std::string &fileName) {
  char fn_json[256];
  char fn_bin[256];
  
  sprintf(
      fn_json,
      "%s%s",
      fileName.c_str(),
      ".json"
  );
  
  sprintf(
      fn_bin,
      "%s%s",
      fileName.c_str(),
      ".bin"
  );
  
  std::ifstream i;
  i.open(fn_json);
  
  if (i.is_open()) {
    nlohmann::json j;
    i >> j;
    std::ofstream o;
    o.open(fn_bin);
    nlohmann::json::to_cbor(j, o);
    o.close();
    i.close();
  }
  
  i.open(fn_bin);
  
  if (!i.is_open()) {
    TraceLog(
        LOG_WARNING,
        "Parse Error: Layout not found"
    );
    
    return;
  }
  
  nlohmann::json j = nlohmann::json::from_cbor(i);
  
  this->parseLayout(j);
}

void execCtx::parseLayout(const nlohmann::json &json, std::optional<uint64_t> parentWidget,
                          std::optional<Vector2> canvasSize) {
  if (!canvasSize) {
    *canvasSize = {
        -1,
        -1
    };
  }
  for (auto &element: json) {
    if (element.value("meta", false)) {
      *canvasSize = {
          element["canvasSizeX"],
          element["canvasSizeY"]
      };
      
      setGuiCanvasScale(*canvasSize);
      continue;
    }
    
    std::string widget = element["widget"];
    auto name = element.value(
        "name",
        ""
    );
    auto props = element["props"];
    
    auto builder = new guiBuilder(
        widget,
        props,
        *canvasSize
    );
    
    uint64_t widgetId;
    
    if (parentWidget) {
      auto parent = dynamic_cast<Widget_Container_Draggable *>(
          state->widgetList.find(
              *parentWidget
          )->second
      );
      widgetId = parent->AddWidget(
          builder->widget,
          name,
          parentWidget
      );
    } else {
      widgetId = state->AddWidget(
          builder->widget,
          name
      );
    }
    
    if (element.contains("contains")) {
      this->parseLayout(
          element["contains"],
          widgetId,
          canvasSize
      );
    }
    
    TraceLog(
        LOG_INFO,
        widget.c_str()
    );
  }
}

execCtx::execCtx(State *State) {
  ctx->add(
      chaiscript::fun(&execCtx::parseFile, this),
      "parseFile"
  );
  addFuncs(ctx);
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
  std::string content(
      (std::istreambuf_iterator<char>(ifs)),
      (std::istreambuf_iterator<char>())
  );
  
  commandBuffer = content;
}

void execCtx::run() {
  if (verifyBuffer()) {
    ctx->eval(commandBuffer);
  }
}

void execCtx::runOnce(std::string cmd) {
  try {
    ctx->eval(cmd);
  } catch (chaiscript::Boxed_Value bv) {
    return;
  }
}