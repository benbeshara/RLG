//
// Created by Ben Beshara on 11/4/2022.
//

#include <string>
#include "GameStore.h"

GameStore *GameStore::store = nullptr;

GameStore *GameStore::GetInstance() {
  if (store == nullptr) {
    store = new GameStore();
  }
  return store;
}

void GameStore::quit() {
  store->getState()->quit();
}