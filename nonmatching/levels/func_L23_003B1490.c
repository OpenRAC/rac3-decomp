/* func_L23_003B1490: near miss (Opus, 2026-11-08). Holostar boss/enemy AI update, 8,296 bytes, level 23 only,
   file src/levels/23_holostar_studios_clank/L23_003AD800.c (no other C there). Needs
   `-mvu0-use-vf0-vf2 ... @ps2as` on that file's line (11 vadd/vsub.xyz through include/vu0.h).
   Written from retail (all 14 states of switch (m->state 0x20) via jtbl_002C0220, the 0x95 pre-switch).
   Measured with the stock checker: 2030 of 2074 rows, 53.7% of lines exact, 90.6% of opcodes equal.
   What still differs:
   1. Stack layout / registers. Retail's frame has 0x60 bytes of locals and its vectors overlap between
      states (state 10: p@0 v@0x10 matrix@0x20; state 12: matrix@0 p@0x40 q@0x50; state 2: 0/0x10; the
      0x95 state 3: 0). Here every vector block is a static inline (Blk*), so cc1 gives each inline frame
      its own temp slot (a freed 16-byte slot cannot take a later 32/96-byte frame) and the frame is 0x90.
      Retail keeps m in $s2 and m->0x68 in $s3 with s0/s1 taken by block-local pointers (&p, &q, the
      D_001A4BE0 base); here m/t are $s3/$s4. Writing the vectors as block locals instead shares nothing
      either (tested), so this is the same per-statement-temporary layout as func_L39_00656F28.
   2. State 12's two loops: with the block inlined, loop.c does not hoist the invariants retail hoists
      (15.0f/17.0f/0.5f/4.0f in $f21-$f26, &p/&q/&hero in $s1/$s4-$s6); written in place they are hoisted
      (91.5% opcodes) but the frame grows. Retail also reads hero->0x2808 through a hero pointer register.
   3. Smaller: the 0x95 pre-switch needs `case 1: break;` for retail's slti tree (done); if/else (not ?:) for
      the gp tunable pairs; the 30C state chain is an if-chain (3, 2, 1), not a switch.
   Next: compare per state with ~/RACSwarm/plans/rac3-large/kit/casediff2.py --opc
   --jt 23_holostar_studios_clank:jtbl_002C0220 --cases. */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct V4_003B1490 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) V4_003B1490;

typedef struct M4_003B1490 {
    V4_003B1490 x;
    V4_003B1490 y;
    V4_003B1490 z;
    V4_003B1490 t;
} M4_003B1490;

__asm__(".extern D_L23_001DE2D4, 4");
__asm__(".extern D_L23_001DE328, 4");
__asm__(".extern D_L23_001DE33C, 4");
__asm__(".extern D_L23_001DE340, 4");
__asm__(".extern D_L23_001DE344, 4");
__asm__(".extern D_L23_001DE348, 4");
__asm__(".extern D_L23_001DE34C, 4");
__asm__(".extern D_L23_001DE350, 4");
__asm__(".extern D_L23_001DE354, 4");
__asm__(".extern D_L23_001DE358, 4");
__asm__(".extern D_L23_001DE35C, 4");
__asm__(".extern D_L23_001DE360, 4");
__asm__(".extern D_L23_001DE364, 4");
__asm__(".extern D_L23_001DE368, 4");
__asm__(".extern D_L23_001DE36C, 4");
__asm__(".extern D_L23_001DE370, 4");
__asm__(".extern D_L23_001DE374, 4");
__asm__(".extern D_L23_001DE378, 4");
__asm__(".extern D_L23_001DE37C, 4");
__asm__(".extern D_L23_001DE380, 4");
__asm__(".extern D_L23_001DE384, 4");
__asm__(".extern D_L23_001DE388, 4");
__asm__(".extern D_L23_001DE38C, 4");
__asm__(".extern D_L23_001DE390, 4");
__asm__(".extern D_L23_001DE394, 4");
__asm__(".extern D_L23_001DE398, 4");
__asm__(".extern D_L23_001DE39C, 4");
__asm__(".extern D_L23_001DE3A0, 4");
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 D_001A73E8 __attribute__((section(".data")));
extern u8 *D_L23_001DF240 __attribute__((section(".data")));
extern s32 D_L23_001DEC40 __attribute__((section(".data")));
extern u8 D_L23_001E1A40[];
extern s32 D_L23_001DE2D4;
extern f32 D_L23_001DE328;
extern f32 D_L23_001DE33C;
extern f32 D_L23_001DE340;
extern f32 D_L23_001DE344;
extern f32 D_L23_001DE348;
extern s32 D_L23_001DE34C;
extern f32 D_L23_001DE350;
extern f32 D_L23_001DE354;
extern f32 D_L23_001DE358;
extern s32 D_L23_001DE35C;
extern s32 D_L23_001DE360;
extern s32 D_L23_001DE364;
extern s32 D_L23_001DE368;
extern f32 D_L23_001DE36C;
extern s32 D_L23_001DE370;
extern f32 D_L23_001DE374;
extern f32 D_L23_001DE378;
extern f32 D_L23_001DE37C;
extern f32 D_L23_001DE380;
extern s32 D_L23_001DE384;
extern f32 D_L23_001DE388;
extern s32 D_L23_001DE38C;
extern s32 D_L23_001DE390;
extern f32 D_L23_001DE394;
extern f32 D_L23_001DE398;
extern s32 D_L23_001DE39C;
extern f32 D_L23_001DE3A0;

extern void func_L23_003B34F8(void);
extern void func_L23_003B3908(u8 *);
extern void func_L23_003B3BB8(u8 *, u8 *, s32, f32);
extern void func_L23_003B4108(u8 *, u8 *, s32, void *, f32, f32);
extern void func_L23_003BB7C8(u8 *, void *, void *, s32, f32, f32);
extern void func_L23_00456AA8(void *, void *, s32, s32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern f32 func_L01_0040E570(u8 *, u8 *);
extern f32 func_L01_004395E0(u8 *);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0045AA30(u8 *, void *);
extern void func_L01_003A9928(u8 *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C2F58(u8 *, s32, void *);
extern void func_003C2EC0(u8 *, s32, void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(f32 *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);

static inline void Anim_003B1490(u8 *m, s32 a, s32 b) {
    if (m[0x43] != a) {
        func_003C3A10(m, a, 0, b);
    }
}

static inline void Back_003B1490(u8 *m) {
    switch (m[0x95]) {
    case 1:
        func_L01_004450F0(m, 1, -1);
        break;
    case 2:
        func_L01_004450F0(m, 2, -1);
        break;
    case 3:
        func_L01_004450F0(m, 7, -1);
        break;
    default:
        func_L01_004450F0(m, 1, 1);
        break;
    }
}

static inline void Blk1_003B1490(u8 *m, u8 *t) {
    V4_003B1490 v;


    *(u128_t *)(t + 0x170) = *(u128_t *)D_001A4C60;
    func_003C2F58(m, (*(s32 *)(t + 0x304) & 1) ^ 1, &v);
    *(f32 *)(t + 0x344) = -func_0038D160(func_0038CF38(&v, t + 0x170), *(f32 *)(t + 0x178) - v.z);
}

static inline void Blk2_003B1490(u8 *m, u8 *t) {
    V4_003B1490 v;
    f32 x;
    f32 y;


    x = func_0038CF38(D_001A4C60, m + 0x10) / D_L23_001DE344;
    y = D_L23_001DE358;
    if (*(s32 *)(t + 0x398) == 0) {
        y = D_L23_001DE354;
    }
    func_0038CE20(&v, D_001A4BE0 + 0x110, x * y);
    vec_add_ba(t + 0x170, &v, D_001A4BE0 + 0xE0);
}

static inline void Blk3_003B1490(u8 *m, u8 *t) {
    V4_003B1490 v0;
    V4_003B1490 v1;
    f32 x;
    f32 y;


    vec_sub_ab(&v0, D_001A4C60, D_L23_001DF240 + *(s32 *)(t + 0x320) * 0x80 + 0x30);
    x = func_0038D160(v0.x, v0.y);
    vec_sub_ab(&v1, m + 0x10, D_L23_001DF240 + *(s32 *)(t + 0x320) * 0x80 + 0x30);
    if (func_0038DBA0(func_0038D160(v1.x, v1.y), x) < 0.0f) {
        y = func_0038DB00(x, 2.0943952f);
    } else {
        y = func_0038DAB8(x, 2.0943952f);
    }
    *(f32 *)(t + 0x360) = func_0038D098(y) * (100.0f - func_0038CEA8(&v0));
    *(f32 *)(t + 0x364) = func_0038D0B0(y) * (100.0f - func_0038CEA8(&v0));
    *(s32 *)(t + 0x368) = 0;
    vec_add_ba(t + 0x360, t + 0x360, D_L23_001DF240 + *(s32 *)(t + 0x320) * 0x80 + 0x30);
}

static inline void Blk4_003B1490(u8 *m, u8 *t) {
    V4_003B1490 v;


    *(u128_t *)&v = *(u128_t *)(m + 0x10);
    func_L23_003B4108(t + 0x360, m, *(s32 *)(t + 0x310), &v, 30.0f, 50.0f);
    *(u16 *)(m + 0x96) = 0;
    *(f32 *)(t + 0x34C) = 0.0f;
    *(s32 *)(t + 0x334) = 0;
}

static inline void Blk5_003B1490(u8 *m, u8 *t, f32 x) {
    V4_003B1490 v;

    x = x / 5.0f;
    *(f32 *)(t + 0x328) = func_003C4088(0.0f, *(f32 *)(t + 0x39C), 1.0f - x * x);
    *(u128_t *)&v = *(u128_t *)(m + 0x10);
    v.z = *(f32 *)(t + 0x378) + *(f32 *)(t + 0x328);
    vec_sub_ba(&v, &v, m + 0x10);
    func_L01_0045AA30(m, &v);
}

static inline void Blk6_003B1490(u8 *m, u8 *t) {
    V4_003B1490 p;
    V4_003B1490 v;
    M4_003B1490 j;
    f32 x;
    f32 y;


    func_003C2EC0(m, (*(s32 *)(t + 0x304) & 1) ^ 1, &j);
    *(u128_t *)&p = *(u128_t *)&j.t;
    if (*(s32 *)(t + 0x300) == 3) {
        vec_sub_ba(&v, t + 0x170, &p);
        x = func_0038CED8(&v.x);
        v.x = func_0038D098(*(f32 *)(m + 0xF8)) * x;
        v.y = func_0038D0B0(*(f32 *)(m + 0xF8)) * x;
        func_0038CF68(&v, &v, D_L23_001DE344);
    } else {
        v.x = func_0038D098(*(f32 *)(m + 0xF8)) * D_L23_001DE344;
        v.y = func_0038D0B0(*(f32 *)(m + 0xF8)) * D_L23_001DE344;
        v.z = 0.0f;
    }
    func_L23_003BB7C8(m, &p, &v, D_L23_001DE34C, D_L23_001DE348, D_L23_001DE350);
    *(f32 *)(t + 0x34C) = 0.0f;
}

static inline void Blk7_003B1490(u8 *m, u8 *t) {
    M4_003B1490 j;
    V4_003B1490 p;
    V4_003B1490 q;
    s32 a;
    s32 i;
    f32 k;
    f32 x;
    f32 y;


    func_003C2EC0(m, 2, &j);
    for (i = 0; i < 4; i++) {
        a = D_L23_001DEC40 + i * 4;
        k = (f32)(D_L23_001DE390 - *(s32 *)(t + 0x330)) / 50.0f;
        x = (f32)(a % 16);
        if (!(k > 1.0f)) {
            x *= k;
        }
        x = x / 15.0f;
        func_0038CE20(&p, &j, D_L23_001DE37C - D_L23_001DE380);
        p.z = 0.0f;
        vec_add_ab(&p, &p, &j.t);
        *(u128_t *)&q = *(u128_t *)&j.t;
        func_003C4098(&p, &q, &p, x);
        y = func_003C4088(1.0f, D_L23_001DE380, x);
        if (*(s32 *)(t + 0x348) == 0) {
            if (func_L01_00446780(m, &p, D_L23_001DE384, 5, 1, 0, y, D_L23_001DE388, 0.0f) != 0 &&
                *(u8 **)(D_001A4BE0 + 0x2808) == m) {
                *(s32 *)(t + 0x348) = 1;
                *(s32 *)(t + 0x330) -= 0x32;
            }
        }
    }
    for (i = 0; i < D_L23_001DE39C; i++) {
        *(u128_t *)&p = *(u128_t *)&j.t;
        a = D_L23_001DE390 - *(s32 *)(t + 0x330);
        x = (f32)a / 17.0f;
        if (x > 1.0f) {
            x = 1.0f;
        }
        y = func_003824E0(0.0f, x);
        func_00382580(&q, 0.0f, D_L23_001DE398);
        q.x += j.x.x;
        q.y += j.x.y;
        func_0038CF68(&q, &q, D_L23_001DE394);
        a = func_00382498(0x11, 0x19);
        func_L23_00456AA8(&p, &q, a, func_00382498(0x11, 0x19), (y * 0.5f + 0.5f) * 4.0f);
    }
    if (*(s32 *)(t + 0x330) <= 0) {
        m[0xBC] = 3;
        Anim_003B1490(m, 0x19, 5);
    }
}

static inline void Blk8_003B1490(u8 *m, u8 *t) {
    V4_003B1490 v;
    V4_003B1490 w;
    f32 x;
    f32 y;


    x = *(f32 *)(t + 0x380);
    y = D_L23_001DE33C;
    if (x < y) {
        y = x;
    }
    *(f32 *)(t + 0x380) = x - y;
    v.x = func_0038D098(*(f32 *)(t + 0x384)) * y;
    v.y = func_0038D0B0(*(f32 *)(t + 0x384)) * y;
    v.z = 0.0f;
    func_L01_0045AA30(m, &v);
    w.x = func_0038D098(*(f32 *)(t + 0x384)) * D_L23_001DE328;
    w.y = func_0038D0B0(*(f32 *)(t + 0x384)) * D_L23_001DE328;
    w.z = 0.0f;
    vec_add_ba(&w, &w, m + 0x10);
    w.z += D_L23_001DE328;
    func_L01_00446780(m, &w, D_L23_001DE370, 0, 1, 0, D_L23_001DE328, 100.0f, 1.0f);
}

void func_L23_003B1490(u8 *m) {
    u8 *t;
    u8 *r;
    s32 a;
    s32 b;
    s32 i;
    f32 x;
    f32 y;
    f32 d;
    f32 e;
    f32 k;

    t = *(u8 **)(m + 0x68);
    func_L23_003B34F8();
    switch (m[0x95]) {
    case 1:
        break;
    case 2:
        if (*(s32 *)(t + 0x300) != 3) {
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        if (*(s32 *)(t + 0x30C) == 3) {
            if (*(s32 *)(t + 0x300) == 3) {
                Blk1_003B1490(m, t);
            } else {
                Blk2_003B1490(m, t);
            }
        }
        break;
    }
    switch (m[0x20]) {
    case 1:
        if (func_L01_004561B8(m) != 0) {
            Anim_003B1490(m, 0, 8);
            *(s32 *)(t + 0x31C) = 0;
            *(f32 *)(t + 0x308) = *(f32 *)(m + 0xF8);
            *(s32 *)(t + 0x300) = 0;
            *(u128_t *)(t + 0x360) = *(u128_t *)(m + 0x10);
        } else {
            if (*(s32 *)(t + 0x31C) != 8) {
                a = m[0x43];
                if (a == 1 && func_L01_0044E1B8(m, 100.0f) != 0) {
                    *(f32 *)(t + 0x360) = func_0038D098(func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10),
                                                                     *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14))) * 10.0f;
                    *(f32 *)(t + 0x364) = func_0038D0B0(func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10),
                                                                     *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14))) * 10.0f;
                    *(s32 *)(t + 0x368) = 0;
                    vec_add_ab(t + 0x360, t + 0x360, m + 0x10);
                    *(f32 *)(t + 0x308) = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(t + 0x360),
                                                        *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(t + 0x364));
                    *(s32 *)(t + 0x300) = a;
                    Anim_003B1490(m, 0xD, 0x11);
                } else if (*(s32 *)(t + 0x31C) == 0xFA) {
                    *(u128_t *)(t + 0x360) = *(u128_t *)(m + 0x10);
                    *(f32 *)(t + 0x308) = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10),
                                                        *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14));
                    *(s32 *)(t + 0x300) = 0;
                    Anim_003B1490(m, 2, 8);
                } else if (m[0x43] == 2 && func_L01_0044E1B8(m, 78.0f) != 0) {
                    *(s32 *)(t + 0x300) = 0;
                    Anim_003B1490(m, 0, 8);
                }
            } else {
                Anim_003B1490(m, 1, 8);
                *(s32 *)(t + 0x300) = 0;
            }
        }
        func_L23_003B3BB8(m, t + 0x360, *(s32 *)(t + 0x300), *(f32 *)(t + 0x308));
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            Anim_003B1490(m, 4, 5);
        }
        d = func_L01_0040E570(t + 0x360, D_001A4C60);
        e = func_L01_0040E570(m + 0x10, D_001A4C60);
        if (d < 6400.0f) {
            Blk3_003B1490(m, t);
        }
        if (e < 900.0f) {
            Anim_003B1490(m, 6, 0x19);
            x = *(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10);
            y = *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14);
        } else if (*(f32 *)(t + 0xA4) < *(f32 *)(t + 0x13C)) {
            Anim_003B1490(m, 5, 0x19);
            x = *(f32 *)(t + 0x360) - *(f32 *)(m + 0x10);
            y = *(f32 *)(t + 0x364) - *(f32 *)(m + 0x14);
        } else {
            Anim_003B1490(m, 4, 8);
            x = *(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10);
            y = *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14);
        }
        *(f32 *)(t + 0x308) = func_0038D160(x, y);
        func_L23_003B3BB8(m, t + 0x360, 3, *(f32 *)(t + 0x308));
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            Anim_003B1490(m, 3, 8);
            *(s32 *)(t + 0x300) = 0;
            *(f32 *)(t + 0x328) = 0.0f;
            *(s32 *)(t + 0x304) = 0;
            *(s32 *)(t + 0x30C) = 0;
            *(f32 *)(t + 0x34C) = 0.0f;
            *(s32 *)(t + 0x334) = 0;
        }
        if (func_L01_0044E1B8(m, 8.0f) != 0) {
            *(s32 *)(t + 0x300) = 3;
            *(f32 *)(t + 0x324) = D_L23_001DE3A0;
        }
        if (m[0x42] == m[0x43] && (m[0x60] & 2)) {
            Anim_003B1490(m, 4, 5);
            if (m[0x94] == 6) {
                func_L01_004450F0(m, 6, -1);
            } else if (m[0x94] == 5) {
                func_L01_004450F0(m, 5, -1);
            } else {
                Back_003B1490(m);
            }
        }
        func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300), *(f32 *)(m + 0xF8));
        break;
    case 4:
        if (*(u16 *)(m + 0x96) >= 0x97 || func_L01_004561B8(m) != 0) {
            Blk4_003B1490(m, t);
        }
        *(f32 *)(t + 0x308) = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10),
                                            *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14));
        if (m[0x43] != 0x1A) {
            if (func_L01_0040E570(m + 0x10, t + 0x360) < *(f32 *)(t + 0xA4) * *(f32 *)(t + 0xA4)) {
                Anim_003B1490(m, 0x1A, 5);
            } else {
                *(s32 *)(t + 0x300) = 3;
                if (fabs_asm(func_0038DBA0(func_0038D160(*(f32 *)(t + 0x360) - *(f32 *)(m + 0x10),
                                                         *(f32 *)(t + 0x364) - *(f32 *)(m + 0x14)),
                                           *(f32 *)(t + 0x308))) > 1.5707964f) {
                    Anim_003B1490(m, 6, 8);
                } else {
                    Anim_003B1490(m, 5, 8);
                }
            }
            func_L23_003B3BB8(m, t + 0x360, 3, *(f32 *)(t + 0x308));
        } else if (m[0x42] == m[0x43]) {
            x = func_L01_004395E0(m);
            if (!(x <= 5.0f)) {
                func_L23_003B3BB8(m, m + 0x10, 0, *(f32 *)(m + 0xF8));
            } else {
                Blk5_003B1490(m, t, x);
            }
            if (func_L01_0044E1B8(m, 5.0f) != 0) {
                *(f32 *)(D_L23_001E1A40 + 0x20) = 0.3f;
                *(s32 *)(D_L23_001E1A40 + 0x28) = 0x21;
                *(s32 *)(D_L23_001E1A40 + 0x2C) = 0;
            }
            if (m[0x60] & 2) {
                Anim_003B1490(m, 0, 5);
                Back_003B1490(m);
            }
        } else {
            func_L23_003B3BB8(m, t + 0x360, 3, *(f32 *)(t + 0x308));
        }
        break;
    case 5:
        *(u128_t *)(t + 0x360) = *(u128_t *)D_001A4C60;
        *(f32 *)(t + 0x308) = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10),
                                            *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14));
        if (*(s32 *)(t + 0x300) == 3) {
            if (fabs_asm(func_0038DBA0(func_0038D160(*(f32 *)(t + 0x360) - *(f32 *)(m + 0x10),
                                                     *(f32 *)(t + 0x364) - *(f32 *)(m + 0x14)),
                                       *(f32 *)(t + 0x308))) > 1.5707964f) {
                Anim_003B1490(m, 6, 8);
            } else {
                Anim_003B1490(m, 5, 8);
            }
        } else if (*(s16 *)(t + 0x184) == 0 && *(u16 *)(m + 0x96) >= 0x33) {
            func_L01_004450F0(m, 3, -1);
        } else {
            *(s32 *)(t + 0x300) = 2;
            Anim_003B1490(m, 0x14, 8);
        }
        func_L23_003B3BB8(m, t + 0x360, *(s32 *)(t + 0x300), *(f32 *)(t + 0x308));
        if (func_L01_0040E570(m + 0x10, D_001A4C60) <= *(f32 *)(t + 0x32C) * *(f32 *)(t + 0x32C)) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 6:
        if (*(s32 *)(t + 0x300) != 3) {
            func_L01_004450F0(m, 3, -1);
            break;
        }
        if (func_L01_004561B8(m) != 0) {
            Anim_003B1490(m, 6, 8);
            *(f32 *)(t + 0x360) = func_0038D098(func_0038DAB8(func_L01_00443A18(0.0f, 1.0471976f),
                                                              func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(D_001A4BE0 + 0x80),
                                                                            *(f32 *)(m + 0x14) - *(f32 *)(D_001A4BE0 + 0x84)))) *
                                  *(f32 *)(t + 0x32C);
            *(f32 *)(t + 0x364) = func_0038D0B0(func_0038DAB8(func_L01_00443A18(0.0f, 1.0471976f),
                                                              func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(D_001A4BE0 + 0x80),
                                                                            *(f32 *)(m + 0x14) - *(f32 *)(D_001A4BE0 + 0x84)))) *
                                  *(f32 *)(t + 0x32C);
            *(s32 *)(t + 0x368) = 0;
            vec_add_ab(t + 0x360, t + 0x360, D_001A4C60);
            *(f32 *)(t + 0x308) = func_0038D160(*(f32 *)(D_001A4BE0 + 0x80) - *(f32 *)(m + 0x10),
                                                *(f32 *)(D_001A4BE0 + 0x84) - *(f32 *)(m + 0x14));
        }
        func_L23_003B3BB8(m, t + 0x360, 3, *(f32 *)(t + 0x308));
        if (func_L01_0040E570(m + 0x10, t + 0x360) <= *(f32 *)(t + 0xA4) * *(f32 *)(t + 0xA4) ||
            *(u16 *)(m + 0x96) >= 0xFB) {
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 7:
        if (*(s32 *)(t + 0x304) == 0 && func_L01_004561B8(m) != 0) {
            if (*(s32 *)(t + 0x300) == 3) {
                if (*(s32 *)(t + 0x334) != 0) {
                    Anim_003B1490(m, 8, 5);
                } else {
                    Anim_003B1490(m, 4, 5);
                }
            } else if (*(s32 *)(t + 0x334) != 0) {
                Anim_003B1490(m, 0xF, 5);
            } else {
                Anim_003B1490(m, 0, 5);
            }
        }
        func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300) != 3 ? 0 : 3,
                          func_0038D160(*(f32 *)(t + 0x170) - *(f32 *)(m + 0x10), *(f32 *)(t + 0x174) - *(f32 *)(m + 0x14)));
        d = func_L01_0040E570(m + 0x10, D_001A4C60);
        if (*(s32 *)(t + 0x30C) == 3 && d < 196.0f) {
            *(s32 *)(t + 0x304) = 0;
        }
        if (d > 100.0f) {
            *(s32 *)(t + 0x38C) = 0;
        }
        b = *(s32 *)(t + 0x30C);
        if (b == 1 && *(s32 *)(t + 0x38C) >= 3) {
            *(s32 *)(t + 0x304) = 0;
            *(f32 *)(t + 0x32C) = 30.0f;
            func_L01_004450F0(m, 6, -1);
            break;
        }
        if (*(s32 *)(t + 0x304) <= 0) {
            a = D_L23_001DE2D4;
            if (a < 0) {
                if (*(s32 *)(t + 0x300) == 3) {
                    if (b == 0) {
                        if (*(s32 *)(t + 0x398) != 0) {
                            a = D_L23_001DE368;
                        } else {
                            a = D_L23_001DE364;
                        }
                        *(s32 *)(t + 0x304) = a;
                        *(s32 *)(t + 0x30C) = 3;
                    } else {
                        func_L01_004450F0(m, 4, -1);
                        *(s32 *)(t + 0x30C) = 0;
                    }
                    break;
                }
                if (d < 100.0f && b != 1) {
                    *(s32 *)(t + 0x304) = *(s32 *)(t + 0x398) != 0 ? func_00382498(2, 4) : 2;
                    a = 1;
                } else if (d >= 196.0f && *(s32 *)(t + 0x30C) != 3) {
                    if (*(s32 *)(t + 0x398) != 0) {
                        a = D_L23_001DE360;
                    } else {
                        a = D_L23_001DE35C;
                    }
                    *(s32 *)(t + 0x304) = a;
                    a = 3;
                } else {
                    if (*(s32 *)(t + 0x330) > 0) {
                        a = 2;
                        b = 1;
                    } else if (*(s32 *)(t + 0x398) != 0) {
                        a = 1;
                        b = 2;
                    } else {
                        a = 2;
                        b = 1;
                    }
                    *(s32 *)(t + 0x304) = a;
                    a = b;
                }
            }
            *(s32 *)(t + 0x30C) = a;
        }
        if (*(s32 *)(t + 0x30C) == 3) {
            if (d < 196.0f) {
                *(f32 *)(t + 0x32C) = 30.0f;
                if (*(s32 *)(t + 0x334) != 0) {
                    func_L01_004450F0(m, 9, -1);
                } else {
                    func_L01_004450F0(m, 6, -1);
                }
            } else if (d > 2500.0f) {
                *(f32 *)(t + 0x32C) = 30.0f;
                if (*(s32 *)(t + 0x334) != 0) {
                    func_L01_004450F0(m, 9, -1);
                } else {
                    func_L01_004450F0(m, 5, -1);
                }
            } else if (*(s32 *)(t + 0x334) == 0) {
                func_L01_004450F0(m, 8, -1);
            } else {
                func_L01_004450F0(m, 0xA, -1);
            }
        } else if (*(s32 *)(t + 0x30C) == 2) {
            if (*(s32 *)(t + 0x334) != 0) {
                func_L01_004450F0(m, 9, -1);
            } else if (d < 100.0f) {
                *(f32 *)(t + 0x32C) = 16.0f;
                func_L01_004450F0(m, 6, -1);
            } else if (d > 324.0f) {
                *(f32 *)(t + 0x32C) = 16.0f;
                func_L01_004450F0(m, 5, -1);
            } else if (*(s32 *)(t + 0x300) == 3) {
                func_L01_004450F0(m, 4, -1);
            } else {
                func_L01_004450F0(m, 0xC, -1);
            }
        } else if (*(s32 *)(t + 0x30C) == 1) {
            if (*(s32 *)(t + 0x334) != 0) {
                func_L01_004450F0(m, 9, -1);
            } else if (d > 100.0f) {
                *(f32 *)(t + 0x32C) = 9.0f;
                func_L01_004450F0(m, 5, -1);
            } else if (*(s32 *)(t + 0x300) == 3) {
                func_L01_004450F0(m, 4, -1);
            } else {
                func_L01_004450F0(m, 0xB, -1);
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(t + 0x300) == 3) {
                Anim_003B1490(m, 7, 5);
            } else {
                Anim_003B1490(m, 0xE, 5);
            }
        }
        if (m[0x42] == m[0x43] && (m[0x60] & 2)) {
            if (*(s32 *)(t + 0x300) == 3) {
                Anim_003B1490(m, 8, 5);
            } else {
                Anim_003B1490(m, 0xF, 5);
            }
            *(s32 *)(t + 0x334) = 1;
            func_L01_004450F0(m, 7, -1);
        }
        func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300) != 3 ? 0 : 3,
                          func_0038D160(*(f32 *)(t + 0x170) - *(f32 *)(m + 0x10), *(f32 *)(t + 0x174) - *(f32 *)(m + 0x14)));
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(t + 0x300) == 3) {
                Anim_003B1490(m, 0xB, 5);
            } else {
                Anim_003B1490(m, 0x12, 5);
            }
        }
        if (m[0x42] == m[0x43] && (m[0x60] & 2)) {
            if (*(s32 *)(t + 0x300) == 3) {
                Anim_003B1490(m, 4, 5);
            } else {
                Anim_003B1490(m, 0, 5);
            }
            *(s32 *)(t + 0x334) = 0;
            func_L01_004450F0(m, 7, -1);
        }
        func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300) != 3 ? 0 : 3,
                          func_0038D160(*(f32 *)(t + 0x170) - *(f32 *)(m + 0x10), *(f32 *)(t + 0x174) - *(f32 *)(m + 0x14)));
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(t + 0x300) == 3) {
                if (*(s32 *)(t + 0x304) & 1) {
                    Anim_003B1490(m, 0xA, 5);
                } else {
                    Anim_003B1490(m, 9, 5);
                }
            } else if (*(s32 *)(t + 0x304) & 1) {
                Anim_003B1490(m, 0x11, 5);
            } else {
                Anim_003B1490(m, 0x10, 5);
            }
            *(f32 *)(m + 0x48) = *(s32 *)(t + 0x398) != 0 ? 2.0f : 1.5f;
        }
        x = func_L01_004395E0(m);
        if (x < 47.0f || x > 52.0f) {
            func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300) != 3 ? 0 : 3,
                              func_0038D160(*(f32 *)(t + 0x170) - *(f32 *)(m + 0x10), *(f32 *)(t + 0x174) - *(f32 *)(m + 0x14)));
        } else {
            func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300) != 3 ? 0 : 3, *(f32 *)(m + 0xF8));
        }
        if (func_L01_0044E1B8(m, 47.0f) != 0) {
            Blk6_003B1490(m, t);
        }
        if (func_L01_0044E1B8(m, 64.0f) != 0) {
            *(s32 *)(t + 0x304) -= 1;
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(t + 0x304) & 1) {
                Anim_003B1490(m, 0x15, 5);
            } else {
                Anim_003B1490(m, 0x16, 5);
            }
            *(f32 *)(m + 0x48) = *(s32 *)(t + 0x398) != 0 ? 2.0f : 1.5f;
        }
        x = func_L01_004395E0(m);
        if (x >= 23.0f && x <= 26.0f) {
            if (*(s32 *)(t + 0x304) & 1) {
                func_L01_004468C8(m, 4, D_L23_001DE370, 0, 1, 0, D_L23_001DE36C, D_L23_001DE374, 1.0f);
            } else {
                func_L01_004468C8(m, 3, D_L23_001DE370, 0, 1, 0, D_L23_001DE36C, D_L23_001DE374, 1.0f);
            }
        }
        if (*(u8 **)(D_001A4BE0 + 0x2808) == m) {
            *(s32 *)(t + 0x38C) += 1;
            *(u8 **)(D_001A4BE0 + 0x2808) = 0;
            if (*(s32 *)(t + 0x38C) >= 3) {
                *(s32 *)(t + 0x304) = 1;
            }
        }
        if (x >= 23.0f && x <= 25.0f) {
            x = x - 23.0f;
            *(f32 *)(t + 0x110) = func_0038D098(*(f32 *)(m + 0xF8)) * (D_L23_001DE378 * x * 0.5f);
            *(f32 *)(t + 0x114) = func_0038D0B0(*(f32 *)(m + 0xF8)) * (D_L23_001DE378 * x * 0.5f);
            *(s32 *)(t + 0x118) = 0;
        }
        if (func_L01_0044E1B8(m, 43.0f) != 0) {
            *(f32 *)(m + 0x48) = 1.0f;
            *(s32 *)(t + 0x304) -= 1;
            func_L01_004450F0(m, 7, -1);
            *(f32 *)(t + 0x34C) = 0.0f;
        }
        if (*(s32 *)(t + 0x398) != 0) {
            func_L23_003B3BB8(m, m + 0x10, 0,
                              func_0038D160(*(f32 *)(t + 0x170) - *(f32 *)(m + 0x10), *(f32 *)(t + 0x174) - *(f32 *)(m + 0x14)));
        } else {
            func_L23_003B3BB8(m, m + 0x10, 0, *(f32 *)(m + 0xF8));
        }
        break;
    case 12:
        if (func_L01_004561B8(m) != 0) {
            m[0xBC] = 1;
            Anim_003B1490(m, 0x17, 5);
            D_001A73E8 = 0;
            *(s32 *)(t + 0x348) = 0;
        }
        if (m[0x42] == m[0x43] && (m[0x60] & 2) && m[0xBC] == 1) {
            *(s32 *)(t + 0x330) = D_L23_001DE390;
            m[0xBC] = 2;
            Anim_003B1490(m, 0x18, 0);
        }
        if (m[0xBC] == 2) {
            Blk7_003B1490(m, t);
        }
        if (m[0x42] == m[0x43] && (m[0x60] & 2) && m[0xBC] == 3) {
            Anim_003B1490(m, 0, 5);
            *(s32 *)(t + 0x304) -= 1;
            *(s32 *)(t + 0x330) = D_L23_001DE38C;
            func_L01_004450F0(m, 7, -1);
            *(f32 *)(t + 0x34C) = 0.0f;
        }
        func_L23_003B3BB8(m, m + 0x10, 0, *(f32 *)(m + 0xF8));
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            if (*(s32 *)(t + 0x300) == 3) {
                Anim_003B1490(m, 0xC, 3);
            } else {
                Anim_003B1490(m, 0x13, 3);
                *(f32 *)(m + 0x48) = 2.0f;
            }
            x = *(f32 *)(t + 0x30);
            y = *(f32 *)(t + 0x338) - x;
            *(f32 *)(t + 0x338) = x;
            *(s32 *)(t + 0x30C) = -1;
            *(s32 *)(t + 0x304) = 0;
            *(f32 *)(t + 0x34C) += y;
            if (m[0x94] == 0xC) {
                *(s32 *)(t + 0x330) = D_L23_001DE38C;
            }
        }
        {
            Blk8_003B1490(m, t);
        }
        *(s32 *)(t + 0x33C) = D_L23_001DEC40 + 2;
        if ((m[0x43] == 0x13 && func_L01_0044E1B8(m, 18.0f) != 0) || (m[0x60] & 2)) {
            *(f32 *)(m + 0x48) = 1.0f;
            switch (m[0x95]) {
            case 1:
                func_L01_004450F0(m, 1, -1);
                break;
            case 2:
                func_L01_004450F0(m, 2, -1);
                break;
            case 3:
                if (*(s32 *)(t + 0x300) != 3) {
                    if (D_L23_001DE340 <= *(f32 *)(t + 0x34C)) {
                        *(f32 *)(t + 0x32C) = 30.0f;
                        func_L01_004450F0(m, 6, -1);
                    } else {
                        func_L01_004450F0(m, m[0x94], -1);
                    }
                } else {
                    func_L01_004450F0(m, 7, -1);
                }
                break;
            }
        }
        func_L23_003B3BB8(m, m + 0x10, *(s32 *)(t + 0x300) != 3 ? 0 : 3, *(f32 *)(m + 0xF8));
        break;
    case 14:
        if (func_L01_004561B8(m) != 0) {
            Anim_003B1490(m, 0x1B, 8);
        } else if (func_L01_0044E1B8(m, 84.0f) != 0) {
            *(f32 *)(m + 0x48) = 0.0f;
            func_L01_003A9928(m);
        }
        break;
    }
    func_L23_003B3908(m);
}
