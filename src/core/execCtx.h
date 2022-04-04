//
// Created by Ben Beshara on 25/3/2022.
//

#ifndef RLG_EXECCTX_H
#define RLG_EXECCTX_H

#include <string>
#include <chaiscript/chaiscript.hpp>
#include "state.h"

class execCtx {
public:
    execCtx(State* State);
    void run();
    void loadBuffer(std::string filename);

protected:
    State* state;
    void parseLayout(const std::string& fileName);
    bool verifyBuffer();
    chaiscript::ChaiScript ctx;
    std::string commandBuffer;
};

#endif //RLG_EXECCTX_H
