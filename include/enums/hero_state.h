#ifndef HERO_STATE_H
#define HERO_STATE_H

/*
 * The hero's state numbers (struct Hero's state and prev_state) and state types (state_type).
 *
 * From open-rac-engine (GPL-3.0-or-later; THIRD_PARTY_NOTICES.md), docs/research/hero-controller.md
 * at c9306a5: "State numbers" and the sections on each move. Its numbers were read in UYA NTSC-U's
 * and R&C3 PAL's code and seen in traces of the running game; R&C3 and UYA are one game, so they
 * hold for both releases. Enumerations only: fields keep their integer types.
 * States not listed (5, 12, 13, 16, 25, 26, 28, 40, 41, 50, 52, 62, ...) exist but were not named.
 */

enum HeroStateId {
    HERO_STATE_IDLE = 0x0,
    HERO_STATE_LOOK = 0x1,              /* first person, L1 held */
    HERO_STATE_WALK = 0x2,
    HERO_STATE_SKID = 0x3,
    HERO_STATE_CROUCH = 0x4,
    HERO_STATE_FALL = 0x6,
    HERO_STATE_JUMP = 0x7,
    HERO_STATE_GLIDE = 0x8,
    HERO_STATE_RUN_JUMP = 0x9,
    HERO_STATE_LONG_JUMP = 0xA,
    HERO_STATE_FLIP_JUMP = 0xB,
    HERO_STATE_DOUBLE_JUMP = 0xE,
    HERO_STATE_HELI_JUMP = 0xF,         /* the jump from a crouch */
    HERO_STATE_WALL_JUMP = 0x11,
    HERO_STATE_WATER_JUMP = 0x12,       /* X pressed while swimming on the surface */
    HERO_STATE_COMBO_ATTACK = 0x13,     /* the wrench combo */
    HERO_STATE_JUMP_ATTACK = 0x14,
    HERO_STATE_THROW_ATTACK = 0x15,     /* the thrown wrench */
    HERO_STATE_GET_HIT = 0x16,
    HERO_STATE_LEDGE_GRAB = 0x17,       /* the ledge states are 23-27 */
    HERO_STATE_LEDGE_IDLE = 0x18,
    HERO_STATE_LEDGE_JUMP = 0x1B,
    HERO_STATE_TARGETING = 0x1D,        /* a gun out, aiming */
    HERO_STATE_GRIND = 0x27,            /* the grind states are 39-42 and 62 */
    HERO_STATE_GRIND_ATTACK = 0x2A,
    HERO_STATE_UNDERWATER_IDLE = 0x33,  /* the underwater states are 50-52 */
    HERO_STATE_SURFACE_SWIM = 0x35,
    HERO_STATE_SURFACE_IDLE = 0x36,
    HERO_STATE_DEATH = 0x39,            /* from get hit, when health is below 1 */
    HERO_STATE_SKID_TO_POSITION = 0x65, /* a scripted move */
    HERO_STATE_WADE = 0x75,
    HERO_STATE_ZIP_LINE = 0x76
};

enum HeroStateType {
    HERO_TYPE_IDLE = 0x0,               /* idle, look, targeting */
    HERO_TYPE_WALK = 0x1,
    HERO_TYPE_FALL = 0x2,
    HERO_TYPE_LEDGE = 0x3,
    HERO_TYPE_JUMP = 0x4,               /* every jump, the ledge jump too */
    HERO_TYPE_ATTACK = 0x6,
    HERO_TYPE_GET_HIT = 0x7,
    HERO_TYPE_CROUCH = 0xC,
    HERO_TYPE_UNDERWATER = 0x11,        /* states 50-52 */
    HERO_TYPE_SURFACE = 0x12,           /* states 53-54 */
    HERO_TYPE_SCRIPTED = 0x18           /* skid to position */
};

#endif /* HERO_STATE_H */
