#include "common.h"

/* NTSC-U counterpart of func_L02_004C0358 (src/levels/shared/L02_004C0358.c) */
/* localdecomp:start func_L02_004BC110 */
#include "vu0.h"
typedef int Q_004C0358 __attribute__((mode(TI)));
typedef struct { Q_004C0358 r[3]; } M3_004C0358;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004C0358;
typedef struct {
    u8 pad0[5];
    u8 b5;
    u8 pad6[2];
    f32 f8;
    u8 padC[0x17];
    u8 b23;
    u8 pad24[4];
    s32 w28;
    u8 pad2C[0xC];
    void *p38;
    void *p3C;
} Obj_004C0358;

typedef struct {
    u8 pad0[0x90];
    Q_004C0358 q90;
    u8 padA0[0x6C0 - 0xA0];
    M3_004C0358 m6C0;
    V4_004C0358 v6F0;
    union { Q_004C0358 q; V4_004C0358 v; } u700;
    u8 pad710[0xE78 - 0x710];
    Obj_004C0358 *objs[2];
    u8 padE80[4];
    s32 wE84;
    u8 padE88[0x1434 - 0xE88];
    s16 h1434;
    u8 pad1436[0x16B0 - 0x1436];
    s32 w16B0;
    u8 pad16B4[0x25C0 - 0x16B4];
    u8 *p25C0;
    u8 pad25C4[8];
    s32 w25CC;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 b25E9;
    u8 pad25EA;
    u8 b25EB;
    u8 pad25EC[8];
    u8 b25F4;
    u8 pad25F5[0x2830 - 0x25F5];
    s32 w2830;
    s32 w2834;
} G_004C0358;
extern G_004C0358 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001425C0[];
typedef struct { u8 a[0x600]; u8 b[0x600]; } Buf_004C0358;
extern Buf_004C0358 D_L02_00252940[];
extern u8 D_L02_002C3200[];
typedef struct { u8 pad0[0xF8]; f32 fF8; u8 padFC[0x1A8 - 0xFC]; f32 f1A8; } C_004C0358;
extern C_004C0358 D_L02_002F2000;
__asm__(".extern D_L02_002F2000, 16");
extern s32 func_L01_0050DA08(s32);
extern void func_L01_004E6CB0(void);
extern s32 func_L01_004E5470(s32);
extern void func_L01_00437108(void *, void *, s32, s32, s32, s32);
extern void func_L01_00436D30(void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00436C90(void *, void *);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);
extern void func_003888C8(void *, void *, void *);



void func_L02_004BC110(void) {
    s32 i;
    s32 r;
    s32 v;
    s32 s;
    u8 *t;
    f32 f20;
    u8 m[0x30] __attribute__((aligned(16)));
    V4_004C0358 vec;
    u8 *q;
    M3_004C0358 *mp;

    if (D_001A4BE0.b25E9 != 0 && D_001A4BE0.b25EB != 0 && func_L01_0050DA08(-1) == 0) {
        func_L01_004E6CB0();
    }
    for (i = 0; i < 2; i++) {
        if (D_001A4BE0.objs[i] == 0) {
            continue;
        }
        D_001A4BE0.objs[i]->p38 = D_L02_00252940[i].a;
        D_001A4BE0.objs[i]->p3C = D_L02_00252940[i].b;
        r = func_L01_004E5470(0);
        if (r == D_001A4BE0.w2834) {
            t = D_L02_002C3200 + D_001425C0[r] * 0xF0;
            v = *(s32 *)(t + 0x28);
            if (D_001A4BE0.w25CC == 12) {
                v = *(s32 *)(t + 0x2C);
            }
            if (v != -1 && D_001A4BE0.objs[i]->b23 != v) {
                D_001A4BE0.w2830 = v;
                func_L01_00437108(D_001A4BE0.p25C0, D_001A4BE0.objs[i], v, 0, 8, 1);
            }
        }
        func_L01_00436D30(D_001A4BE0.p25C0, D_001A4BE0.objs[i]);
        s = D_001A4BE0.wE84;
        if (s != 0) {
            if (s == 2) {
                func_003BEBF8(&D_001A4BE0.objs[i]->f8, 0.0f, 0.25f);
            } else {
                func_003BEBF8(&D_001A4BE0.objs[i]->f8, 0.0f, 0.07f);
            }
            if (D_001A4BE0.objs[i]->f8 == 0.0f) {
                func_L01_00436C90(D_001A4BE0.p25C0, &D_001A4BE0.objs[i]);
                return;
            }
        } else {
            func_003BEBF8(&D_001A4BE0.objs[i]->f8, 1.0f, 0.2f);
            if (D_001A4BE0.objs[i]->b5 & 2) {
                if (D_001A4BE0.b25EB == 0) {
                    D_001A4BE0.wE84 = 1;
                    D_001A4BE0.objs[i]->w28 = 0;
                    D_001A4BE0.b25E9 = 0;
                    return;
                }
            }
        }
    }
    f20 = 0.0f;
    if (D_001A4BE0.h1434 == 0) {
        if (D_001A4BE0.w16B0 != 1 || func_L01_0045D358(0x28, 2, 0, 0) == 0) {
            f20 = func_00389380(D_L02_002F2000.f1A8, D_L02_002F2000.fF8);
        }
    }
    qzero(&vec);
    vec.z = f20;
    func_00388BD0(m, &vec);
    mp = &D_001A4BE0.m6C0;
    func_00388EB8(mp, mp, m);
    q = D_001A4BE0.p25C0;
    *mp = *(M3_004C0358 *)(q + 0xC0);
    qzero(&D_001A4BE0.v6F0);
    D_001A4BE0.v6F0.x = 1.0f;
    func_003888C8(&D_001A4BE0.v6F0, &D_001A4BE0.v6F0, &D_001A4BE0.m6C0);
    D_001A4BE0.u700.q = D_001A4BE0.q90;
    if (D_001A4BE0.b25F4 == 0) {
        D_001A4BE0.u700.v.z = func_00389380(D_001A4BE0.u700.v.z, f20);
    }
}
/* localdecomp:end func_L02_004BC110 */
