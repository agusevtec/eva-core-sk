# EVA Ecosystem: An Invitation to Collaborate

## What is EVA?

EVA is not just a library—it's an architectural ecosystem for Arduino. Its goal is to make code modular, predictable, and reusable, regardless of project complexity.

Projects in the EVA ecosystem live in the `eva` namespace and are built around three key ideas:

- **Tickable** — everything that needs time becomes part of a single cycle
- **Handler** — events instead of polling
- **Template composition** — flexibility without performance loss

Each module solves its own specific task, but they all speak the same language—the language of EVA.

## An Invitation to Collaborate

You are an Arduino library author. Your project solves a specific hardware problem: GMS, GPS, or any other sensors - its own hard-earned solutions, great!

I propose we join forces.

### Why This Might Interest You

1. **Your library becomes part of an ecosystem** — EVA users will use it "out of the box," knowing it follows the same architectural principles.

2. **Clean examples** — Instead of code with `millis()` and flags, you can show examples where your library is embedded in a solid architecture:
   - GPS parser could be a `Tickable` component
   - GSM modem could be with callbacks instead of blocking on serial answers of AT commands

3. **Less support burden** — Many user problems stem not from your library, but from how they call it. EVA-core-sk takes care of time management and events, leaving you with just the logic.

4. **Increased visibility** — Every project in the ecosystem references others. Your library will be seen alongside names already familiar to the community.

### What I Ask From You

- Willingness to look at your library from a new perspective
- Readiness to add example(s) using EVA-core-sk
- (Optional) Minor interface adaptations if they make users' lives easier

### What I Provide

- Help with integration, writing examples, documentation
- A link to your project from the EVA documentation
- Word about your library as part of the ecosystem

## How to Start

If this idea resonates with you—write me. I'll send a small template showing how your library might look in the EVA architecture. From there, it's up to you: use it, decline it, or just take a look.

EVA grows only with the community. And every collaboration makes it stronger.
