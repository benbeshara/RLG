//
// Created by Ben Beshara on 11/4/2022.
//

#ifndef RLG_CMAKE_GAMESTORE_H
#define RLG_CMAKE_GAMESTORE_H


#include "state.h"
#include "execCtx.h"

class GameStore {

protected:
  GameStore() {};
  
  static GameStore *store;
  
  State *state = new State();
  execCtx *script = new execCtx(state);

public:
  GameStore(GameStore &other) = delete;
  
  void operator=(const GameStore &) = delete;
  
  static GameStore *GetInstance();
  
  State *getState() { return state; }
  
  execCtx *getScript() { return script; }
};


#endif //RLG_CMAKE_GAMESTORE_H
