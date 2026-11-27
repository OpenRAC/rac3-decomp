#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
extern s32 func_003AAEB8(void *);
extern void func_003AC638(s32, s32, s32, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

typedef struct { u8 p0[0xB0]; f32 fB0; } S_225980_3A7090;
extern S_225980_3A7090 D_00225900_003AC638;
extern s32 D_001D5C78;
extern s32 D_001D52F0;
extern s32 func_003A9CB0();
extern void func_003A9CA8(s32);
extern s32 func_003AAEA8();
extern void func_003873C0();
extern void func_003AA320_003AC638(s32, f32, f32, s32, f32, f32, f32);
/* localdecomp:start func_003AC638 */
/* func_003AC638: from the boot_elf twin func_003AC9F0, callees renamed through the pairs table; its in-body externs dropped (3ABD38.c declares them all at file scope). */
void func_003AC638(s32 object, s32 alpha, s32 rgb, f32 top, f32 bottom, f32 left, f32 right)
{
    s32 saved = func_003A9CB0();
    f32 old, factor, scale, x0, x1, one, neg;
    s32 *parts;
    func_003A9CA8(0);
    if (D_001D5C78) {
        old = D_00225900_003AC638.fB0;
        D_00225900_003AC638.fB0 = 0.6200000047683716f;
        one = 1.0f;
        func_003873C0();
        scale = one;
        factor = (bottom - top - 26.0f) / 112.0f;
        factor = factor * 0.3110000193119049f + 0.03750000149011612f;
        if (func_003AAEA8() == 1) scale = 0.8999999761581421f;
        parts = (s32 *)((u8 *)object + 0x5100);
        neg = -1.0f;
        alpha <<= 24;
        alpha |= rgb;
        func_003AA320_003AC638(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), left, top, alpha, neg, scale, factor);
        x0 = left + 16.0f;
        parts = (s32 *)((u8 *)parts + (D_001D52F0 << 2));
        func_003AA320_003AC638(*parts, right, top, alpha, one, scale, factor);
        x1 = right - 16.0f;
        factor = (right - left - 150.0f) / 306.0f;
        factor = factor * 0.43300002813339233f + 0.10199999809265137f;
        parts = (s32 *)((u8 *)object + 0x5110);
        func_003AA320_003AC638(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), x0, top, alpha, neg, one, factor);
        func_003AA320_003AC638(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), x1, top, alpha, one, one, factor);
        func_003AA320_003AC638(*(s32 *)((u8 *)parts + (D_001D52F0 << 2)), x0, bottom, alpha, neg, neg, factor);
        parts = (s32 *)((u8 *)parts + (D_001D52F0 << 2));
        func_003AA320_003AC638(*parts, x1, bottom, alpha, one, neg, factor);
        D_00225900_003AC638.fB0 = old;
        func_003873C0();
        func_003A9CA8(saved);
    }
}
/* localdecomp:end func_003AC638 */

LINKER_REMNANT("asm/remnants", func_003AC928);

/* localdecomp:start func_003AC940 */
s32 func_003AC940() {
}
/* localdecomp:end func_003AC940 */

typedef struct { s32 *p0; s32 *p4; u8 *p8; s32 *pC; u8 sub10[0x178]; s32 f188, f18C, f190; u8 p194[4]; s32 f198, f19C, f1A0, f1A4; f32 f1A8; u8 p1AC[4]; f32 f1B0; s32 f1B4; } O_A73A0;
extern f32 D_001D8434_003AC948;
extern f32 D_001D8438_003AC948;
extern void func_003AB458(void *, f32);
/* localdecomp:start func_003AC948 */
__asm__(".extern D_001D8434_003AC948, 4");
__asm__(".extern D_001D8438_003AC948, 4");
s32 func_003AC948(void *arg0) {
    O_A73A0 *o = arg0;
    s32 cnt = o->f198;
    s32 v = o->p8[3];
    u8 *p;
    u8 *q;
    s32 hi;
    if (cnt > 0) {
        v = v + 9;
        v = (v >= 0x81) ? 0x80 : v;
        o->f198 = cnt - 1;
    } else {
        v = v - 9;
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
        { s32 *r = (s32 *)func_003AAEB8(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003AAEB8(q); *r = (*r & 0xFFFFFF) | hi; }
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
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB458(q, k + 0.005f); }
            f = D_001D8434_003AC948;
            if (zero < f) {
                func_003AB458(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB458(p, g * 0.85f + 0.03f);
            f = D_001D8438_003AC948;
            if (zero <= f) {
                func_003AB458(p, f);
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
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB458(q, k + 0.005f); }
            f = D_001D8434_003AC948;
            if (zero < f) {
                func_003AB458(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB458(p, g * 0.85f + 0.03f);
            f = D_001D8438_003AC948;
            if (zero <= f) {
                func_003AB458(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}
/* localdecomp:end func_003AC948 */
