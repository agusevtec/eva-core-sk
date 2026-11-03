# Ecosystem

**EVA Core | EVA Survival Kit** is an architectural core that naturally serves as a base layer for many applications.

## Ecosystem Projects

Currently, the following projects are part of the ecosystem:

- EVA Filters — signal filtering library — https://github.com/agusevtec/eva-filters

- EVA Motors — micro-motor drivers and their behavioral modifiers — https://github.com/agusevtec/eva-motors

- EVA Boxy — declarative GUI framework — https://github.com/agusevtec/eva-boxy

Each project follows the same architectural principles, so they compose naturally: a filter feeds a motor driver, an indicator reacts to a timer, and everything is driven by a single eva::tac() call.

## Join the Ecosystem

If you publish a library that uses EVA Core directly, or through one of the ecosystem projects, you are welcome to have it listed here — just open an Issue in the EVA Core repository to get in touch and add your project to the ecosystem. As a matter of community convention (not a trademark license), ecosystem members are also welcome to use EVA as part of their library name or namespace to indicate that the project belongs to the ecosystem.
