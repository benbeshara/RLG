# Untitled
This repo is the underlying engine for an untitled text-based exploration and adventure game

## Technology used:
- C++11
- Raylib and Raylib-CPP

## Structure
As the game utilises mostly text and UI, work has primarily gone toward the creation of the widget and state machine systems.
___
- __Widgets are derived from a base class that provides simple support for providing and determinign focus and visibility. Some of these functions are widget-dependant and requrie some expected functionality to be implemented using the provided vitual functions__