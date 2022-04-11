//
// Created by Ben Beshara on 25/3/2022.
//

#ifndef RLG_EXECCTX_H
#define RLG_EXECCTX_H

#include <string>
#include <chaiscript/chaiscript.hpp>
#include "state.h"
#include "json.hpp"

class execCtx {
public:
  execCtx(State *State);
  
  void run();
  
  void loadBuffer(const std::string &filename);
  
  void runOnce(std::string cmd);
  
  chaiscript::ChaiScript ctx;

protected:
  State *state;
  
  void parseFile(const std::string &fileName);
  
  void parseLayout(const nlohmann::json &json, std::optional<uint64_t> parentWidget = std::nullopt);
  
  bool verifyBuffer();
  
  std::string commandBuffer;
};

#endif //RLG_EXECCTX_H
