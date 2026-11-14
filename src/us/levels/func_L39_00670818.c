#include "common.h"

/* NTSC-U counterpart of func_L39_00673160 (src/levels/shared/L39_00672828.c) */
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L39_00670818 */
typedef struct Ent_00673160 {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8[0x2C - 8];
    u8 b2C;
    u8 b2D;
    u8 pad2E[0x50 - 0x2E];
} Ent_00673160;

typedef struct Lst_00673160 {
    u8 pad0[0x20];
    struct Lst_00673160 *next;
} Lst_00673160;

typedef struct Net_00673160 {
    u8 pad0[0xC31];
    u8 bC31;
    u8 padC32[2];
    s32 wC34;
} Net_00673160;

typedef struct G_00673160 {
    u8 pad0[0x1A14];
    u8 b1A14;
    u8 pad1A15[0x2558 - 0x1A15];
    Net_00673160 *p2558;
} G_00673160;

typedef struct Ctx_00673160 {
    u8 pad0[0x364];
    Ent_00673160 *p364;
    G_00673160 *p368;
} Ctx_00673160;

extern s32 D_001A5F78[];
extern void func_00388550(void *, void *, s32);

s32 func_L39_00670818(void *p, s32 a1, s32 a2, s32 a3) {
    Ctx_00673160 *a0 = p;
    u8 id = a1;
    Ent_00673160 *e;
    s32 t;

    if (a0->p364 == 0) return 0;
    e = a0->p364;
    while (e->b2 != id || (a2 != 0 && (e->b3 & 0xC) == 0)) {
        e = *(Ent_00673160 **)((u8 *)e + 0x20);
        if (e == 0) return 0;
    }
    if (e == 0 || D_001A5F78[0] < e->w4) return 0;
    if (a0->p368->b1A14 == 0) {
        t = e->h0;
        if (t == 6 || t == 12) {
            s32 b = e->b2D;
            s32 c = e->b2C;
            if ((a0->p368->p2558->wC34 < b && b - a0->p368->p2558->wC34 < 100) ||
                (b < a0->p368->p2558->wC34 && b + 256 - a0->p368->p2558->wC34 < 100)) {
                return 0;
            }
            if (a0->p368->p2558->wC34 == b && c < a0->p368->p2558->bC31) return 0;
        }
    }
    if (*(s32 *)((u8 *)a0->p368 + 0x478 + id * 0x50) != e->h0) return 0;
    if (a3 != 0) {
        func_00388550((void *)a3, e, 0x50);
        *(u8 *)(a3 + 2) = id;
    }
    return e->b3;
}
/* localdecomp:end func_L39_00670818 */
