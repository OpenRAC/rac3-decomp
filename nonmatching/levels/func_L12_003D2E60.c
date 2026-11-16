/* NTSC-U draft (Claude wave C4): C of func_L12_003D1258, the NTSC-U twin of func_L12_003D2E60, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 0 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L12_003D1258", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (native check MATCH, 0 diff, no divs row needed, jump table 6 entries at D_L12_002BF200 verified with jt.py 0 mismatches) only with @ps2as added to the PAL file's line (float constant 0x3C8EFA35 = 0.017453292f as lui/ori/mtc1; with the PAL ...
 */
#include "common.h"

/* localdecomp:start func_L12_003D1258 */
typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1258;

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

extern G_003D1258 D_001A4BE0;
extern s32 D_001DEF20_sda;
extern s32 D_001DEF28_sda;
extern s32 D_001DEF2C_sda;
extern f32 D_001DEF38_sda;
extern f32 D_001DEF44_sda;
extern f32 D_001DEF48_sda;
extern f32 D_001DEF50_sda;
extern s32 D_001DEF5C_sda;
extern s32 D_001DEF60_sda;
extern s32 D_001DEF64_sda;
extern s32 D_001DEF68_sda;
__asm__(".extern D_001DEF20_sda, 4");
__asm__(".extern D_001DEF28_sda, 4");
__asm__(".extern D_001DEF2C_sda, 4");
__asm__(".extern D_001DEF38_sda, 4");
__asm__(".extern D_001DEF44_sda, 4");
__asm__(".extern D_001DEF48_sda, 4");
__asm__(".extern D_001DEF50_sda, 4");
__asm__(".extern D_001DEF5C_sda, 4");
__asm__(".extern D_001DEF60_sda, 4");
__asm__(".extern D_001DEF64_sda, 4");
__asm__(".extern D_001DEF68_sda, 4");
extern s32 func_L12_003D1730(void *, void *);
extern s32 func_L12_003D1880(void *, void *);
extern void func_L12_003D1AA8(void *, s32);
extern s32 func_L12_003D1B40(void *, void *, s32);
extern void func_L12_003D1BE8(void *, void *);
extern void func_L12_003D1D30(void *, void *);
extern void func_L12_003D1E38(void *, void *);
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
    if (a->b20 == 0 && func_L12_003D1730(a, s) == 0) {
        return;
    }
    if (func_L12_003D1880(a, s) == 0) {
        func_L12_003D1AA8(a, 1);
        return;
    }
    switch (a->b20) {
    case 1:
        if (func_L01_00452EC8(a) != 0) {
            func_003BDA38(a, 2, v);
            s->f40 = v[2] - a->f18;
            s->w270 = 0;
        }
        if (func_L12_003D1B40(a, s, 0) != 0) {
            if (s->w270 != 0) {
                if (func_00388398(&s->w270) != 0) {
                    func_003BE4F0(a, 1, 0, 10);
                    func_L01_00441FB8(a, 2, -1);
                }
            } else {
                s->w270 = D_001DEF20_sda;
            }
        }
        break;
    case 2:
        func_003BDA38(a, 2, v);
        s->f40 = v[2] - a->f18;
        if ((a->b60 & 2) != 0) {
            func_003BE4F0(a, 2, 0, 10);
            if (func_L12_003D1B40(a, s, 1) != 0) {
                s->w270 = (s->w140 == D_001A4BE0.f25C0 && D_001A4BE0.f19E0 != 0 && *(s16 *)(D_001A4BE0.f19E0 + 0xAA) == 0x1A17)
                              ? D_001DEF64_sda
                              : D_001DEF5C_sda;
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
            s->f278 = func_0037E250(D_001DEF44_sda * 0.017453292f, D_001DEF48_sda * 0.017453292f);
            s->w270 = func_0037E208(D_001DEF28_sda, D_001DEF2C_sda);
        }
        if (func_00388398(&s->w270) != 0) {
            if (func_L12_003D1B40(a, s, 1) != 0) {
                s->w270 = D_001DEF5C_sda;
                func_L01_00441FB8(a, 5, -1);
            } else if (func_L12_003D1B40(a, s, 0) != 0) {
                s->f274 = func_0037E2A8();
                s->f278 = func_0037E250(D_001DEF44_sda * 0.017453292f, D_001DEF48_sda * 0.017453292f);
                s->w270 = func_0037E208(D_001DEF28_sda, D_001DEF2C_sda);
            } else {
                func_003BE4F0(a, 4, 0, 10);
                func_L01_00441FB8(a, 3, -1);
            }
        } else if (D_001A4BE0.f19E0 != 0 && *(s16 *)(D_001A4BE0.f19E0 + 0xAA) == 0x1A17 && func_L12_003D1B40(a, s, 1) != 0) {
            s->w270 = (s->w140 == D_001A4BE0.f25C0) ? D_001DEF64_sda : D_001DEF5C_sda;
            func_L01_00441FB8(a, 5, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(a) != 0) {
            if (func_L01_0040C040((u8 *)a + 0x10, s->b130) < D_001DEF50_sda * D_001DEF50_sda) {
                s->f27C = func_L01_00440918(D_001DEF38_sda * 0.75f * 0.017453292f, D_001DEF38_sda * 0.017453292f);
            } else {
                s->f27C = 0.0f;
            }
        }
        if (func_00388398(&s->w270) != 0) {
            if (func_L12_003D1B40(a, s, 1) != 0) {
                func_L01_00441FB8(a, 6, -1);
            } else {
                func_L01_00441FB8(a, 4, -1);
            }
        } else if (func_L12_003D1B40(a, s, 1) != 0) {
            func_L12_003D1D30(a, s);
        }
        break;
    case 6:
        if (func_L01_00452EC8(a) != 0) {
            func_003BE4F0(a, 3, 0, 1);
            func_L12_003D1E38(a, s);
        }
        if ((a->b60 & 2) != 0) {
            if (s->w140 == D_001A4BE0.f25C0 && D_001A4BE0.f19E0 != 0 && *(s16 *)(D_001A4BE0.f19E0 + 0xAA) == 0x1A17) {
                s->w270 = D_001DEF68_sda;
            } else {
                s->w270 = D_001DEF60_sda;
            }
            func_003BE4F0(a, 2, 0, 1);
            func_L01_00441FB8(a, 5, -1);
        }
        break;
    }
    func_L12_003D1BE8(a, s);
}
/* localdecomp:end func_L12_003D1258 */
