//
// Created by Ben Beshara on 11/4/2022.
//

#include <string>
#include "GameStore.h"

GameStore *GameStore::store = 0;

GameStore *GameStore::GetInstance() {
  if (store == nullptr) {
    store = new GameStore();
  }
  return store;
}