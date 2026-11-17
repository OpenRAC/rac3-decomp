/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00457E08, the NTSC-U twin of func_L01_0045B110, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0045A6F0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0045B110 (src/levels/shared/L01_0045A6F0.c) */
/* localdecomp:start func_L01_00457E08 */
typedef struct Rec_0045B110 {
    u8 pad0[0x49];
    u8 b49;
    u16 h4A;
} Rec_0045B110;
typedef struct Obj_0045B110 {
    u8 pad0[0x10];
    u8 v10[8];
    f32 f18;
    u8 pad1C[0x43 - 0x1C];
    u8 b43;
    u8 pad44[4];
    f32 f48;
} Obj_0045B110;
typedef struct Dsc_0045B110 {
    u8 pad0[8];
    f32 f8;
    f32 fC;
    f32 f10;
    u8 pad14[0x28 - 0x14];
    f32 f28;
    u8 pad2C[0x34 - 0x2C];
    f32 f34;
    s32 w38;
    u8 pad3C[0x50 - 0x3C];
    u8 v50[8];
    f32 f58;
    u8 pad5C[0x90 - 0x5C];
    f32 f90;
    s32 w94;
    u8 pad98[4];
    s32 w9C;
    u8 padA0[8];
    f32 fA8;
    u8 padAC[4];
    f32 fB0;
    f32 fB4;
    u8 padB8[8];
    s16 hC0;
    s16 hC2;
    u8 padC4[8];
    f32 fCC;
    f32 fD0;
    f32 fD4;
    s32 wD8;
    u8 padDC[0xE6 - 0xDC];
    u8 bE6;
    u8 bE7;
    u8 bE8;
    u8 bE9;
    u8 bEA;
} Dsc_0045B110;

extern void func_L01_004583C0(void *, void *, f32);
extern void func_L01_004585E8(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern Rec_0045B110 *func_L01_00445EB8(void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388800(void *, void *);
extern s32 func_L01_00459DA8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00459E50(void *, void *);
extern void func_L01_00443A90(void *, void *, s32, void *, f32);

void func_L01_00457E08(Obj_0045B110 *obj, Dsc_0045B110 *d, void *pos) {
    s32 hit;
    f32 f;
    f32 g;
    Rec_0045B110 *r;

    hit = 0;
    func_L01_004583C0(obj, d, 0.0f);
    if (obj->f18 < d->f90 - d->f8) {
        hit = 1;
        d->w94 |= 2;
    }
    if (((*(u8 *)&d->w38 ^ 1) & 1) && d->hC2 < 5 && d->f90 + d->fC < obj->f18) {
        hit = 1;
        d->w94 |= 1;
    }
    if (d->hC0 != 0) {
        f = func_00388A28(d->f58, func_003887A0(d->v50));
        if (d->f10 < f) {
            hit = 1;
            d->w94 |= 4;
        }
    }
    if (d->wD8 != -1 && d->hC0 != 0) {
        r = func_L01_00445EB8(obj);
        if (r != 0 && r->b49 != 0 && r->h4A != 0 && ((r->h4A >> d->wD8) & 1)) {
            hit = 1;
            d->w94 |= 0x200;
        }
    }
    if (hit) {
        func_L01_004585E8(obj, d);
        func_L01_004583C0(obj, d, 0.0f);
    }
    if (obj->f18 <= d->f90) {
        if (d->f90 <= obj->f18 - d->fA8) {
            obj->f18 = d->f90;
        }
        d->hC2 = 0;
        d->hC0 = d->hC0 + 1;
    } else {
        d->hC0 = 0;
        d->hC2 = d->hC2 + 1;
    }
    if (d->w38 & 0x400) {
        d->fCC = func_003887C8(obj->v10, pos);
    } else {
        d->fCC = func_00388800(obj->v10, pos);
    }
    if (d->fCC <= d->f34) {
        d->w94 |= 0x80;
    }
    if (d->w9C & 1) {
        if (func_L01_00459DA8(obj) != 0) {
            d->w9C &= ~1;
        } else {
            d->w94 |= 0x100;
        }
    }
    if (d->w38 & 0x80) {
        if (obj->b43 == d->bE8 || obj->b43 == d->bE9) {
            f = d->fD0 == 0.0f ? d->f28 : d->fD0;
            f = d->fB0 / f;
            obj->f48 = f;
            if (d->fD4 < f) {
                obj->f48 = d->fD4;
            } else {
                g = 1.0f / d->fD4;
                if (f < g) {
                    obj->f48 = g;
                }
            }
        }
    }
    if (d->w38 & 0x40) {
        if ((d->w9C & 2) && d->fB4 != 0.0f) {
            if (obj->b43 == d->bE8 || obj->b43 == d->bE9) {
                d->bEA = obj->b43;
                if (0.0f < d->fB4) {
                    func_003BE4F0(obj, d->bE6, 0, 10);
                } else {
                    func_003BE4F0(obj, d->bE7, 0, 10);
                }
            }
        } else {
            if (obj->b43 == d->bE6 || obj->b43 == d->bE7) {
                if (d->bEA != 0xFF) {
                    func_003BE4F0(obj, d->bEA, 0, 10);
                }
            }
        }
    }
    if (d->w38 & 0x200) {
        if (func_L01_00459E50(obj, d) != 0) {
            func_L01_00443A90(obj, 0, 0x10000, obj->v10, 255.0f);
        }
    }
}
/* localdecomp:end func_L01_00457E08 */
