# Why EVA?

If you come from Java, C#, JavaScript, or Python — EVA is just three letters,
and your natural habitat. OOP, delegates, events, composition over inheritance,
predictable construction — all the things you already reach for. The only twist
is that features are assembled at compile time via template decorators instead
of runtime polymorphism. Think of it as your comfy slippers, tailored for a
microcontroller.

If you grew up in the Arduino world — read on.

---

## Extremely Versatile Architecture (EVA)

### Declaration

EVA is a concept of comfortable user code. A set of principles that make Arduino
development enjoyable rather than painful:

- **Self-documenting** — code reads like a story, not a puzzle
- **Testability** — components can be verified in isolation
- **Refactoring-friendly** — changing structure doesn't break behavior

---

### The Three Core Principles

The layered architecture continues into user code in an object-oriented way
through three principles:

**Everything that needs time joins a single update chain.**

Getting time from loop() should be simple. When you design a component,
you should have a simple way to get time from the loop() cycle — without 
threading an update() method through every object.

**Components don't poll, they notify.**

Notifying another component should be simple. When you design components, 
you should have a simple way to notify through another component's method

**Flexibility without performance loss**

Components should be embeddable mid-chain. You should have a way to embed 
components into the middle of a data-processing chain, not only at its end.

---

### Implementation

EVA Core | EVA Survival Kit (eva-core-sk) is a concrete implementation of this
concept—a library that puts these principles into practice. Architectural core
with essential components for event-driven Arduino applications.

**eva-core-sk** is organized into two distinct domains:

- **Core** — the engine: `Tickable`, `Handler`, `IReader`, `Heartbeat`. These
  are the fundamental building blocks that make the concept work.
- **Survival Kit (SK)** — ready-to-use components: `Button`, `Switch`, `Timer`,
  `Indicator`, and more. These are what you reach for when building actual
  applications.

---

### The Result

When you write code in the spirit of EVA—composing components, letting them
manage their own time, communicating through events—something unexpected
happens.

Coming back to your own code later becomes **genuinely pleasant**. EVA makes
your code feel like it was written by someone who **cared** about the person who
would read it next—even if that person is future you.