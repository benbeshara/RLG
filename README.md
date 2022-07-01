# Untitled

This repo is the underlying engine for an untitled text-based exploration and adventure game

## Technology used:

- C++17
- Raylib
- `nlohmann::json`
- ChaiScript

## Features

As the game utilises mostly text and UI, work has primarily gone toward the creation of the widget and state machine
systems.
___

- Widgets are derived from a base class that provides simple support for providing and determining focus and
  visibility. __Some of these functions are widget-dependant and require some expected functionality to be implemented
  using the provided virtual functions__
- The 'engine' and widgets are scriptable with ChaiScript and I've done my best to make this easily extensible
- Layouts and Config are written in JSON which is converted to binary CBOR at runtime, so that smaller, more efficient
  files can be distributed in a release. JSON files take priority for development purposes.

### What's planned

- Exposing the core game systems to scripts
- A visual layout editor
- Extending graphics and sound
- PhysicsFS (https://www.icculus.org/physfs/)

### Things to note

This project is primarily me putting real effort into re-familiarising myself with C and C++ after years of working in
web and cloud tech, so there's going to be some evolution and inconsitencies I'll clean up eventually. Life is a
classroom, and modern debuggers are basically magic