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

EVA is a concept of comfortable user code — a set of principles that make
Arduino development enjoyable rather than painful. When user code is designed
as a set of interacting components, these principles make it comfortable to
work with:

**Getting time from `loop()` should be simple.**
A component should have a simple way to get time from the `loop()` cycle — without
threading an `update()` method through every object.

**Notifying another component should be simple.**
A component should have a simple way to notify through another component's method.

**Components should be embeddable mid-chain.**
A component should be embeddable into the middle of a data-processing chain, not
only at its end.

Together, these principles shape user code that is:
- **Self-documenting** — code reads like a story, not a puzzle
- **Testable** — components can be verified in isolation
- **Refactoring-friendly** — changing structure doesn't break behavior

### Implementation

**EVA Core** is a concrete implementation of this concept — an architectural
core that puts these principles into practice. It provides the fundamental
building blocks for event-driven Arduino applications:

- `Tickable` — time from `loop()`
- `IHandler` — notification through another component's method
- `IReader` — composable data-processing chains

**EVA Survival Kit (SK)** is a set of ready-to-use components — `Button`,
`Switch`, `Timer`, `Indicator`, `Heartbeat` and more. These are what you reach for when
building actual applications. The components themselves are built on the same
principles internally.

Core and SK are shipped together as a single package, `eva-core-sk`.

---

### An Example of EVA Core in Action

Picture a device that receives a stream of frames and must assemble them into a packet: accumulate several frames, wait until a full packet is ready, and only then hand it over to the application logic. Three roles: **frame source**, **packet assembler**, **packet consumer**.

Here is what this nesting doll looks like. `FrameSource` is the innermost layer, `PacketConsumer` is the outermost by ownership:

```
        ┌──────────────────────────────────────────────┐
        │ PacketConsumer                               │
        │   ┌──────────────────────────────────────┐   │
        │   │ PacketAssembler                      │   │
        │   │   ┌──────────────────────────────┐   │   │
        │   │   │ FrameSource                  │   │   │
        │   │   │   (innermost layer)          │   │   │
        │   │   └──────────────────────────────┘   │   │
        │   └──────────────────────────────────────┘   │
        └──────────────────────────────────────────────┘
```

```cpp
#include <evaTac.h>
#include <evaHandler.h>
#include <evaTickable.h>

class FrameSource : public eva::Tickable {
public:
  FrameSource(eva::IHandler &h)
    : frameHandler(h) {}

private:
  // Own slice of loop(): no update() is called into us from outside.
  void tick() override {
    // ...
    if (true/* a frame has arrived */)
      frameHandler.invoke(this, { 0 /*ON_FRAME*/, 0 /*frameId*/ });  // dataflow out
  }

private:
  eva::IHandler &frameHandler;
};

class PacketAssembler {
public:
  PacketAssembler(eva::IHandler &h)
    : packetHandler(h) {}

private:
  // Inbound dataflow: frames arrive here, no update() involved.
  eva::Handler<PacketAssembler> onFrameHandler{ this, &PacketAssembler::onFrame };
  void onFrame(void *sender, eva::CallbackInfo cbinfo) {
    // ...
    if (true/* packet is assembled */)
      packetHandler.invoke(this, { 0/*ON_ASSEMBLED*/, 0 /*PACKED_ID*/});  // dataflow out
  }

private:
  FrameSource frameSource{ onFrameHandler };
  eva::IHandler &packetHandler;
};

class PacketConsumer {
  // Inbound dataflow: packets arrive here, no update() involved.
  eva::Handler<PacketConsumer> onPacketHandler{ this, &PacketConsumer::onPacket };

  PacketAssembler assembler{ onPacketHandler };

  void onPacket(void *sender, eva::CallbackInfo cbinfo) {
    /* handled the packet */
  }
};

void setup() {
  static PacketConsumer consumer;
}

void loop() {
  eva::tac();  // the only place time is pulled; dataflow is separate
}
```

#### What is good here

Hard ownership does not mean hard coupling.

**`update()` is not threaded through the layers.**
Time reaches only `FrameSource` — from `tac()`. `PacketAssembler` and `PacketConsumer` take no part in the time loop: they do not transfer `update()` to `FrameSource`. The depth of composition is **not equal** to the depth of `update()` propagation.

**`IHandler` is the only channel — that is where weak coupling comes from.**
No layer holds a reference to the concrete type of its neighbour. `FrameSource` holds `IHandler&` — it does not know it is talking to a `PacketAssembler`. `PacketAssembler` holds `IHandler&` — it does not know it is talking to a `PacketConsumer`. The only thing any layer can do with its neighbour is `invoke()`. That is the entire contract, and it is one-directional: data flows inward, and there is no back channel in the type at all. Replace any layer with another `IHandler` — the neighbours do not change. That is weak coupling: hard ownership, soft dependencies.

**What this gives you.**
You can nest a fourth, fifth, tenth layer — `FrameSource` does not change. You can replace `FrameSource` — `PacketAssembler` does not change. You can replace `PacketAssembler` — `PacketConsumer` does not change. `loop()` never changes.

#### One sentence

> Hard ownership, soft dependencies: each layer knows only an `IHandler&` for its neighbour and receives time from `tac()` instead of passing `update()` down the chain. `loop()` never changes.

---

When you write code in the spirit of EVA—composing components, letting them
manage their own time, communicating through events—something unexpected
happens.

Coming back to your own code later becomes **genuinely pleasant**. EVA makes
your code feel like it was written by someone who **cared** about the person who
would read it next—even if that person is future you.
