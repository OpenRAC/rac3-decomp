#ifndef STRUCTS_EFFECTS_H
#define STRUCTS_EFFECTS_H

/*
 * Particles, lights and sound slots. struct Particle is one of a pool of 0x800 (the pool's
 * pointer is at 0x1E02F8 on NTSC-U Veldin); its type (0-0x80) picks its update. struct
 * LightSlot is one of 8 (0x1F1BC0 on NTSC-U Veldin). struct SoundSlot is one of 52 at
 * D_001A3170 (the same on PAL and NTSC-U).
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md) at c9306a5:
 * docs/research/effects.md and re/SCUS-97353/symbols.toml. Read in UYA NTSC-U's code and data,
 * some of it checked in the running game; R&C3 and UYA are one game, so the layouts hold for
 * PAL, but level data sits at other addresses in each release and level. Only the fields it
 * names: gaps are pad_*, and a field whose size it doesn't state, or that lies inside another,
 * is a comment at its offset. A field named like a names.h macro ends in _.
 */

#include "common.h"
#include "structs/vector.h"

struct Particle {
    u8 type;                       /* 0x000: Particle type (0-0x80), picks its update */
    s8 flags;                      /* 0x001: Flags; negative skips it */
    u8 texture;                    /* 0x002: Its particle texture */
    u8 render;                     /* 0x003: Render byte */
    u32 rgba;                      /* 0x004: RGBA, R in the low byte, 0x80 opaque */
    u8 spin;                       /* 0x008: Spin */
    u8 render2;                    /* 0x009: Render byte: low nibble x 0.25 u off the depth for the near fade, high nibble... */
    /* 0x00A: life (size not stated): Life in frames; freed on the step that takes it to 0 */
    u8 pad_A[0xC - 0xA];
    /* 0x00C: size (size not stated): Size, world units x 210000; corners are size from the middle */
    u8 pad_C[0x10 - 0xC];
    Vec4f position;                /* 0x010: Position */
    Vec4f velocity;                /* 0x020: Velocity */
    /* 0x02C: gravity (size not stated): Gravity, along the level's up where it has a gravity centre */
    /* 0x030: size_step (size not stated): Size a frame */
    u8 pad_30[0x34 - 0x30];
    u8 alpha_step;                 /* 0x034: Alpha a frame */
    u8 spin_step;                  /* 0x035: Spin a frame */
    u8 pad_36[0x3C - 0x36];
    void *update;                  /* 0x03C: An optional update of its own */
};
/* size 0x40 */

struct LightSlot {
    f32 colour[3];                 /* 0x000: Colour as floats (light_add takes a word, red low, each byte over 128) */
    /* 0x00C: arg2 (size not stated): light_add's second argument (meaning not read) */
    u8 pad_C[0x10 - 0xC];
    Vec4f position;                /* 0x010: Position */
    /* 0x01C: radius (inside the field above): Radius r; mobys get colour x (1 - d/r) */
};
/* size 0x20 */

struct SoundSlot {
    /* 0x000: handle (size not stated): The sound library's handle */
    u8 pad_0[0x4 - 0x0];
    /* 0x004: entry (size not stated): The entry (class sound table entry) */
    u8 pad_4[0x8 - 0x4];
    /* 0x008: sound (size not stated): The sound number */
    u8 pad_8[0xA - 0x8];
    /* 0x00A: entry_index (size not stated): The class's entry index */
    u8 pad_A[0xC - 0xA];
    /* 0x00C: volume_scale (size not stated): The volume scale. Doubt: effects.md gives the slot's own scale at +0x5C */
    u8 pad_C[0x10 - 0xC];
    /* 0x010: state (size not stated): State: 7 starting, 1 playing, 4 stopping */
    u8 pad_10[0x14 - 0x10];
    /* 0x014: pitch (size not stated): The pitch */
    u8 pad_14[0x18 - 0x14];
    /* 0x018: lib_arg (size not stated): Passed to the library's play call after the pan, before the random pitch; mea... */
    u8 pad_18[0x1C - 0x18];
    struct Moby *moby;             /* 0x01C: The moby playing it */
    Vec4f position;                /* 0x020: The position */
    u8 pad_30[0x5C - 0x30];
    /* 0x05C: scale (size not stated): The slot's own scale, 0x400 unless set; multiplies the distance volume */
    u8 pad_5C[0x80 - 0x5C];
};
/* size 0x80 */

#endif /* STRUCTS_EFFECTS_H */
