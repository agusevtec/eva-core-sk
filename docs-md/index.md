# Why EVA?

## Extremely Versatile Architecture (EVA)

### Declaration

EVA is a concept of comfortable user code. A set of principles that make Arduino development enjoyable rather than painful:

- **Self-documenting** — code reads like a story, not a puzzle
- **Testability** — components can be verified in isolation
- **Performance** — optimization focused on critical paths, not dogma
- **Refactoring-friendly** — changing structure doesn't break behavior

---

### The Three Pillars

**Event-Driven Execution Over Polling.**
Many components—either explicitly or implicitly—claim their own slice and only their slice of the famous Arduino `loop()`, and user code is encouraged to do the same. Timings become a natural part of the contract between objects—whether between user objects and library objects, or among user objects themselves. Components do not poll; they notify when something happens via lightweight `Handler` delegates that bind events to methods naturally.

**Propagation of Object-Oriented Architecture to User Code.**
The layered architecture continues into user code in an object-oriented way. This creates many connection points, enables predictable initialization, and makes testing simple.

**Feature Construction via Template Decorators.**
Instead of bloated classes trying to solve every edge case, complex behaviors are assembled out of simple primitives using template decorators. You wrap and compose functionality at compile time without paying a runtime memory penalty.

---

### Implementation

EVA Core | EVA Survival Kit (eva-core-sk) is a concrete implementation of this concept—a library that puts these principles into practice. Architectural core with essential components for event-driven Arduino applications.

**eva-core-sk** is organized into two distinct domains:

- **Core** — the engine: `Tickable`, `Handler`, `IReader`, `Heartbeat`. These are the fundamental building blocks that make the concept work.
- **Survival Kit (SK)** — ready-to-use components: `Button`, `Switch`, `Timer`, `Indicator`, and more. These are what you reach for when building actual applications.

---

### The Result

When you write code in the spirit of EVA—composing components, letting them manage their own time, communicating through events—something unexpected happens.

Coming back to your own code later becomes **genuinely pleasant**. EVA makes your code feel like it was written by someone who **cared** about the person who would read it next—even if that person is future you.