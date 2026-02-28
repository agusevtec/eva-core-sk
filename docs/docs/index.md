# Why Publish Another "Button Library"?

EVA it's a concept.

The idea is simple: instead of fighting with `loop()` and filling it with ever-growing state-checking code, you build your application from components that know how to update themselves. One call to `eva::tac()` drives everything.

For years, I waited for Arduino to release something similar as an official standard. That never happened.

So I built **eva-core-sk** — a concrete implementation of this concept, packaged as a library. It comes in two parts:

- **Core** — the engine: `Tickable`, `Handler`, `IReader`

- **Survival Kit (SK)** — ready‑to‑use components: `Button`, `Switch`, `Timer`, `Indicator` and more.

The individual pieces are trivial. But bringing a few key techniques together changes everything.

- Many components either explicitly or implicitly—claim their own slice of the famous Arduino `loop()`, and user code is encouraged to do the same. Time management becomes a natural part of the contract between objects—whether between user objects and library objects, or among user objects themselves.

- The library provides everything needed to structure user code in an object-oriented way, which gives predictable initialization. Everything can be built as static objects and starts running in `setup()`. When you refactor—moving members, splitting classes—the initialization order follows automatically. You never have to hunt for a forgotten `init()` call.

- Delegates via `Handler` bind events to methods naturally. Components do not poll. They notify when something happens.

- The layered architecture continues into user code, creating many connection points and making testing simple.

And that changes everything. Coding application logic—and coming back to your own code later—is now simply enjoyable.

