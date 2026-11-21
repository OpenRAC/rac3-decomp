#include "common.h"

/* NTSC-U version of func_003AC948 (frontbin): 9 -> 8; -9 -> -8 */
#include "common.h"





typedef struct { s32 k, v; } E_3A6830;
void func_00116F98(void *, s32, void *);
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;
void func_00116F98(void *, s32, void *);
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;
typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern void func_U_003A5EB0(void *, f32);
extern s32 func_U_003A5910(void *);
typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern s32 func_11B2E8();
typedef struct { u8 p0[0xB0]; f32 fB0; } S_225980_3A7090;
typedef struct { s32 *p0; s32 *p4; u8 *p8; s32 *pC; u8 sub10[0x178]; s32 f188, f18C, f190; u8 p194[4]; s32 f198, f19C, f1A0, f1A4; f32 f1A8; u8 p1AC[4]; f32 f1B0; s32 f1B4; } O_A73A0;
extern f32 D_U_001D8434_003AC948;
extern f32 D_U_001D8438_003AC948;
extern void func_U_003A5EB0(void *, f32);
/* localdecomp:start func_U_003A73A0 */
__asm__(".extern D_U_001D8434_003AC948, 4");
__asm__(".extern D_U_001D8438_003AC948, 4");
s32 func_U_003A73A0(void *arg0) {
    O_A73A0 *o = arg0;
    s32 cnt = o->f198;
    s32 v = o->p8[3];
    u8 *p;
    u8 *q;
    s32 hi;
    if (cnt > 0) {
        v = v + 8;
        v = (v >= 0x81) ? 0x80 : v;
        o->f198 = cnt - 1;
    } else {
        v = v - 8;
        v = (v <= -1) ? 0 : v;
    }
    if (v == 0) {
        *o->p4 = 0;
    } else {
        f32 k14 = 14.0f;
        f32 k23 = 23.5f;
        f32 g = 0.0f;
        f32 zero;
        hi = v << 24;
        p = (u8 *)o + 0x10;
        q = (u8 *)o + 0x4C;
        { s32 *r = (s32 *)o->p8; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = o->pC; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_U_003A5910(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_U_003A5910(q); *r = (*r & 0xFFFFFF) | hi; }
        switch (o->f1A4) {
        case 0: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_U_003A5EB0(q, k + 0.005f); }
            f = D_U_001D8434_003AC948;
            if (zero < f) {
                func_U_003A5EB0(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_U_003A5EB0(p, g * 0.85f + 0.03f);
            f = D_U_001D8438_003AC948;
            if (zero <= f) {
                func_U_003A5EB0(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 1: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_U_003A5EB0(q, k + 0.005f); }
            f = D_U_001D8434_003AC948;
            if (zero < f) {
                func_U_003A5EB0(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_U_003A5EB0(p, g * 0.85f + 0.03f);
            f = D_U_001D8438_003AC948;
            if (zero <= f) {
                func_U_003A5EB0(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}
/* localdecomp:end func_U_003A73A0 */
