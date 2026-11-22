#include "common.h"

/* NTSC-U counterpart of func_003ACD00 (boot_elf). */

typedef struct {
    s32 *p0;
    s32 *p4;
    u8 *p8;
    s32 *pC;
    u8 sub10[0x178];
    s32 f188, f18C, f190;
    u8 p194[4];
    s32 f198, f19C, f1A0, f1A4;
    f32 f1A8;
    u8 p1AC[4];
    f32 f1B0;
    s32 f1B4;
} O_ACB60;

extern f32 D_U_001D8434;
extern f32 D_U_001D8438;
extern s32 func_U_003AB0D0(void *);
extern void func_U_003AB670(void *, f32);

/* localdecomp:start func_U_003ACB60 */
__asm__(".extern D_U_001D8434, 4");
__asm__(".extern D_U_001D8438, 4");
s32 func_U_003ACB60(void *arg0) {
    O_ACB60 *o = arg0;
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
        { s32 *r = (s32 *)func_U_003AB0D0(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_U_003AB0D0(q); *r = (*r & 0xFFFFFF) | hi; }
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
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_U_003AB670(q, k + 0.005f); }
            f = D_U_001D8434;
            if (zero < f) {
                func_U_003AB670(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_U_003AB670(p, g * 0.85f + 0.03f);
            f = D_U_001D8438;
            if (zero <= f) {
                func_U_003AB670(p, f);
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
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_U_003AB670(q, k + 0.005f); }
            f = D_U_001D8434;
            if (zero < f) {
                func_U_003AB670(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_U_003AB670(p, g * 0.85f + 0.03f);
            f = D_U_001D8438;
            if (zero <= f) {
                func_U_003AB670(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}
/* localdecomp:end func_U_003ACB60 */
