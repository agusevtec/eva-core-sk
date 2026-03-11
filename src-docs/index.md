# Why EVA?

EVA is a concept of comfortable user code. A set of principles that make Arduino development enjoyable rather than painful:

- **Self-documenting** — code reads like a story, not a puzzle
- **Testability** — components can be verified in isolation
- **Performance** — optimization focused on critical paths, not dogma
- **Refactoring-friendly** — changing structure doesn't break behavior

**eva-core-sk** is a concrete implementation of this concept—a library that puts these principles into practice.

---

### The Four Pillars

**First**, many components—either explicitly or implicitly—claim their own slice and only their slice of the famous Arduino loop(), and user code is encouraged to do the same. Timings become a natural part of the contract between objects—whether between user objects and library objects, or among user objects themselves.

**Second**, the library provides everything needed to structure user code in an object-oriented way, which gives predictable initialization. When you refactor—moving members, splitting classes—the initialization order follows automatically. You never have to hunt for a forgotten `init()` call.

**Third**, delegates via `Handler` bind events to methods naturally. Components do not poll. They notify when something happens.

**Fourth**, the layered architecture continues into user code, creating many connection points and making testing simple.

---

### Two Domains

eva-core-sk is organized into two distinct layers:

- **Core** — the engine: `Tickable`, `Handler`, `IReader`. These are the fundamental building blocks that make the concept work.
- **Survival Kit (SK)** — ready-to-use components: `Button`, `Switch`, `Timer`, `Indicator`, and more. These are what you reach for when building actual applications.

---

### The Result

When you write code in the spirit of EVA—composing components, letting them manage their own time, communicating through events—something unexpected happens.

Coming back to your own code later becomes **genuinely pleasant**. EVA makes your code feel like it was written by someone who **cared** about the person who would read it next—even if that person is future you.