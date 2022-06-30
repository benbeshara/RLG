//
// Created by Ben Beshara on 30/6/2022.
//

#include <string>
#include "GameStore.h"

static void doButtonClick(const std::string &widget) {
  GameStore *store = GameStore::GetInstance();
  const auto key = store->getState()->GetWidgetIDByName(widget);
  store->getState()->getWidget(key)->Toggle();
  TraceLog(LOG_INFO, "Clicked!");
}

static void addFuncs(chaiscript::ChaiScript *ctx) {
  ctx->add(chaiscript::fun(&doButtonClick), "doButtonClick");
}