#ifndef STRUCTS_PAD_H
#define STRUCTS_PAD_H

/*
 * A controller port's record: the first at D_001CD0C0, the same on PAL and NTSC-U. The hero
 * reads the held mask at +0x1A0 (the jump tests bit 0x40). Its size is not stated (hero.toml
 * gives 0x1B0, but fields reach past it).
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md) at c9306a5:
 * re/SCUS-97353/hero.toml, docs/research/hero-controller.md and re/SCUS-97353/symbols.toml.
 * Read in UYA NTSC-U's code and data, some of it checked in the running game; R&C3 and UYA are
 * one game, so the layouts hold for PAL, but level data sits at other addresses in each
 * release and level. Only the fields it names: gaps are pad_*, and a field whose size it
 * doesn't state, or that lies inside another, is a comment at its offset. A field named like a
 * names.h macro ends in _.
 */

#include "common.h"
#include "structs/vector.h"

struct Pad {
    u8 pad_0[0x2 - 0x0];
    u16 buttons;                   /* 0x002: Raw DualShock button bits, active low (0xFFFF none pressed) */
    u8 raw_sticks[4];              /* 0x004: Raw stick bytes +4..+7 (left stick at +6, +7) */
    /* 0x006: lx (inside the field above): Raw left stick x (0-255, centre about 127) */
    /* 0x007: ly (inside the field above): Raw left stick y (0-255, up is 0) */
    u8 pad_8[0x100 - 0x8];
    f32 rx;                        /* 0x100: Right stick x after the dead zone; start of the float array (sticks, then pre... */
    f32 ry;                        /* 0x104: Right stick y; negative pushed up */
    f32 lx_f;                      /* 0x108: Processed left stick x */
    f32 ly_f;                      /* 0x10C: Processed left stick y (Flux zoom: minus +0x10C = pushed up) */
    u8 pad_110[0x128 - 0x110];
    f32 pressure_cross;            /* 0x128: Cross pressure */
    f32 pressure_square;           /* 0x12C: Square pressure */
    u8 pad_130[0x134 - 0x130];
    f32 pressure_r1;               /* 0x134: R1 pressure */
    u8 pad_138[0x13C - 0x138];
    f32 pressure_r2;               /* 0x13C: R2 pressure */
    u8 pad_140[0x1A0 - 0x140];
    u32 held;                      /* 0x1A0: Held-button mask the hero code tests (jump 0x40, Circle fires); also the stic... */
    u8 pad_1A4[0x1B0 - 0x1A4];
    /* 0x1B0: dpad (size not stated): The real d-pad, the hero's fallback under a 0.25 stick. Beyond hero.toml's re... */
    u8 pad_1B0[0x1C0 - 0x1B0];
    /* 0x1C0: menu_held (size not stated): Held buttons in the game's byte-swapped mask (vendor menu) */
    u8 pad_1C0[0x1C4 - 0x1C0];
    /* 0x1C4: menu_pressed (size not stated): New presses in the same mask (vendor menu) */
    u8 pad_1C4[0x1CC - 0x1C4];
    /* 0x1CC: input_block (size not stated): Set to 2 every frame to block gameplay input (quick select ring) */
    u8 pad_1CC[0x1D4 - 0x1CC];
    /* 0x1D4: hands_off_stick (size not stated): Set when no direction bit is set (d-pad or stick past its dead zone) */
    u8 pad_1D4[0x1DC - 0x1D4];
    /* 0x1DC: terminal_id (size not stated): Pad terminal id: 0x79 for a DualShock 2 in pressure mode */
    u8 pad_1DC[0x1E0 - 0x1DC];
    /* 0x1E0: press_ring (size not stated): 30-frame ring of button presses (pad_pressed_within) */
    u8 pad_1E0[0x258 - 0x1E0];
    /* 0x258: angle_ring (size not stated): 30-frame ring of stick angles */
    u8 pad_258[0x2D0 - 0x258];
    /* 0x2D0: length_ring (size not stated): 30-frame ring of stick lengths */
};

#endif /* STRUCTS_PAD_H */
