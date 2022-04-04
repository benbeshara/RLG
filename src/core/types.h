#ifndef TYPES_H
#define TYPES_H

typedef struct Scriptable {
  execCtx ctx;
  std::string scriptName;
} Scriptable;

#endif /* TYPES_H */
