//
// Created by Ben Beshara on 30/6/2022.
//

#include <string>
#include "GameStore.h"
#include "../widgets/WG_TextInput.h"

static void doButtonClick(const std::string &widget) {
  GameStore *store = GameStore::GetInstance();
  store->getState()->GetWidgetByNameDeep(widget)->Toggle();
  TraceLog(LOG_INFO, "Clicked!");
}

static void changeText(const std::string &widget, const std::string &text) {
  GameStore *store = GameStore::GetInstance();
  auto *t = dynamic_cast<WG_TextInput *>(store->getState()->GetWidgetByNameDeep(widget));
  t->SetText(text);
}

static void addFuncs(chaiscript::ChaiScript *ctx) {
  ctx->add(chaiscript::fun(&doButtonClick), "doButtonClick");
  ctx->add(chaiscript::fun(&changeText), "changeText");
}