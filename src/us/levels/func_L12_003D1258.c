#include "common.h"

/* NTSC-U counterpart of func_L12_003D2E60 (src/levels/shared/L12_003D2E60.c): func_003BE4F0's last argument 10 where PAL passes 8, $gp data 0x40 higher */
/* localdecomp:start func_L12_003D1258 */
typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1BE8;
typedef struct {
    u8 pad0[0x140];
    s32 f140;
    u8 pad144[0x160 - 0x144];
    u8 f160[0x1C8 - 0x160];
    f32 f1C8;
    u8 pad1CC[0x1E0 - 0x1CC];
    u8 f1E0[0x240 - 0x1E0];
    f32 f240;
    u8 pad244[0x274 - 0x244];
    f32 f274;
    f32 f278;
} P_003D1BE8;

typedef struct {
    u8 pad0[0x40];
    f32 f40;
    u8 pad44[0x130 - 0x44];
    u8 b130[0x10];
    s32 w140;
    u8 pad144[0x270 - 0x144];
    s32 w270;
    f32 f274;
    f32 f278;
    f32 f27C;
} P_003D1258;

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[0x60 - 0x21];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    P_003D1258 *p68;
} O_003D1258;

extern G_003D1BE8 D_001A4BE0_003D1258;
extern s32 D_L12_001DEF20;
extern s32 D_L12_001DEF28;
extern s32 D_L12_001DEF2C;
extern f32 D_L12_001DEF38;
extern f32 D_L12_001DEF44;
extern f32 D_L12_001DEF48;
extern f32 D_L12_001DEF50;
extern s32 D_L12_001DEF5C;
extern s32 D_L12_001DEF60;
extern s32 D_L12_001DEF64;
extern s32 D_L12_001DEF68;
__asm__(".extern D_L12_001DEF20, 4");
__asm__(".extern D_L12_001DEF28, 4");
__asm__(".extern D_L12_001DEF2C, 4");
__asm__(".extern D_L12_001DEF38, 4");
__asm__(".extern D_L12_001DEF44, 4");
__asm__(".extern D_L12_001DEF48, 4");
__asm__(".extern D_L12_001DEF50, 4");
__asm__(".extern D_L12_001DEF5C, 4");
__asm__(".extern D_L12_001DEF60, 4");
__asm__(".extern D_L12_001DEF64, 4");
__asm__(".extern D_L12_001DEF68, 4");
extern s32 func_L12_003D1730(u8 *, u8 *);
extern s32 func_L12_003D1880(u8 *, u8 *);
extern void func_L12_003D1AA8(u8 *, s32);
extern s32 func_L12_003D1B40(s32, u8 *, s32);
extern void func_L12_003D1BE8(u8 *, P_003D1BE8 *);
extern void func_L12_003D1D30(u8 *, u8 *);
extern void func_L12_003D1E38(u8 *, u8 *);
extern s32 func_L01_00452EC8(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_00388398(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_L01_00440918(f32, f32);

void func_L12_003D1258(O_003D1258 *a) {
    P_003D1258 *s;
    f32 v[4];

    s = a->p68;
    if (a->b20 == 0 && func_L12_003D1730((u8 *)a, (u8 *)s) == 0) {
        return;
    }
    if (func_L12_003D1880((u8 *)a, (u8 *)s) == 0) {
        func_L12_003D1AA8((u8 *)a, 1);
        return;
    }
    switch (a->b20) {
    case 1:
        if (func_L01_00452EC8(a) != 0) {
            func_003BDA38(a, 2, v);
            s->f40 = v[2] - a->f18;
            s->w270 = 0;
        }
        if (func_L12_003D1B40((s32)a, (u8 *)s, 0) != 0) {
            if (s->w270 != 0) {
                if (func_00388398(&s->w270) != 0) {
                    func_003BE4F0(a, 1, 0, 10);
                    func_L01_00441FB8(a, 2, -1);
                }
            } else {
                s->w270 = D_L12_001DEF20;
            }
        }
        break;
    case 2:
        func_003BDA38(a, 2, v);
        s->f40 = v[2] - a->f18;
        if ((a->b60 & 2) != 0) {
            func_003BE4F0(a, 2, 0, 10);
            if (func_L12_003D1B40((s32)a, (u8 *)s, 1) != 0) {
                s->w270 = (s->w140 == D_001A4BE0_003D1258.f25C0 && D_001A4BE0_003D1258.f19E0 != 0 && *(s16 *)(D_001A4BE0_003D1258.f19E0 + 0xAA) == 0x1A17)
                              ? D_L12_001DEF64
                              : D_L12_001DEF5C;
                func_L01_00441FB8(a, 5, -1);
            } else {
                func_L01_00441FB8(a, 4, -1);
            }
        }
        break;
    case 3:
        func_003BDA38(a, 2, v);
        s->f40 = v[2] - a->f18;
        if ((a->b60 & 2) != 0) {
            func_003BE4F0(a, 0, 0, 10);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a) != 0) {
            s->f274 = func_0037E2A8();
            s->f278 = func_0037E250(D_L12_001DEF44 * 0.017453292f, D_L12_001DEF48 * 0.017453292f);
            s->w270 = func_0037E208(D_L12_001DEF28, D_L12_001DEF2C);
        }
        if (func_00388398(&s->w270) != 0) {
            if (func_L12_003D1B40((s32)a, (u8 *)s, 1) != 0) {
                s->w270 = D_L12_001DEF5C;
                func_L01_00441FB8(a, 5, -1);
            } else if (func_L12_003D1B40((s32)a, (u8 *)s, 0) != 0) {
                s->f274 = func_0037E2A8();
                s->f278 = func_0037E250(D_L12_001DEF44 * 0.017453292f, D_L12_001DEF48 * 0.017453292f);
                s->w270 = func_0037E208(D_L12_001DEF28, D_L12_001DEF2C);
            } else {
                func_003BE4F0(a, 4, 0, 10);
                func_L01_00441FB8(a, 3, -1);
            }
        } else if (D_001A4BE0_003D1258.f19E0 != 0 && *(s16 *)(D_001A4BE0_003D1258.f19E0 + 0xAA) == 0x1A17 && func_L12_003D1B40((s32)a, (u8 *)s, 1) != 0) {
            s->w270 = (s->w140 == D_001A4BE0_003D1258.f25C0) ? D_L12_001DEF64 : D_L12_001DEF5C;
            func_L01_00441FB8(a, 5, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0) {
            if (func_L01_0040C040((u8 *)a + 0x10, s->b130) < D_L12_001DEF50 * D_L12_001DEF50) {
                s->f27C = func_L01_00440918(D_L12_001DEF38 * 0.75f * 0.017453292f, D_L12_001DEF38 * 0.017453292f);
            } else {
                s->f27C = 0.0f;
            }
        }
        if (func_00388398(&s->w270) != 0) {
            if (func_L12_003D1B40((s32)a, (u8 *)s, 1) != 0) {
                func_L01_00441FB8(a, 6, -1);
            } else {
                func_L01_00441FB8(a, 4, -1);
            }
        } else if (func_L12_003D1B40((s32)a, (u8 *)s, 1) != 0) {
            func_L12_003D1D30((u8 *)a, (u8 *)s);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a) != 0) {
            func_003BE4F0(a, 3, 0, 1);
            func_L12_003D1E38((u8 *)a, (u8 *)s);
        }
        if ((a->b60 & 2) != 0) {
            if (s->w140 == D_001A4BE0_003D1258.f25C0 && D_001A4BE0_003D1258.f19E0 != 0 && *(s16 *)(D_001A4BE0_003D1258.f19E0 + 0xAA) == 0x1A17) {
                s->w270 = D_L12_001DEF68;
            } else {
                s->w270 = D_L12_001DEF60;
            }
            func_003BE4F0(a, 2, 0, 1);
            func_L01_00441FB8(a, 5, -1);
        }
        break;
    }
    func_L12_003D1BE8((u8 *)a, (P_003D1BE8 *)s);
}
/* localdecomp:end func_L12_003D1258 */
