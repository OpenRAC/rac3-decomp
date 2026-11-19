#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003ABF48();
extern void *func_003ABEB8();
extern s32 func_003ABDD8(u8 *, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003ABD38 */
extern void func_00121760();
extern void func_003A9CB8();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;
void func_003ABD38(s32 *arg0)
{
  s32 *p;
  s32 n;
  s32 *new_var;
  new_var = arg0 + 7;
  func_00121760(D_001D8230);
  p = new_var;
  n = arg0[6];
  func_00121760(D_001D8270, p, n);
  if (n > 0)
  {
    do
    {
      p[1] += (s32) arg0;
      func_003A9CB8(p[1]);
      p += 2;
      D_001D5C84 = D_001D5C84 + 1;
      n--;
    }
    while (n != 0);
  }
  func_00121760(D_001D82A0);
}
/* localdecomp:end func_003ABD38 */

typedef struct { s32 k, v; } E_3A6830;
/* localdecomp:start func_003ABDD8 */
s32 func_003ABDD8(u8 *p, s32 k) {
    s32 n = *(s32 *)(p + 0x18);
    E_3A6830 *e = (E_3A6830 *)(p + 0x1C);
    s32 i;
    s32 r = 0;
    for (i = 0; i < n; i++) {
        if (e[i].k == k) {
            r = e[i].v;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_003ABDD8 */

/* localdecomp:start func_003ABE28 */
void *func_003ABE28(void *p) {
    return p;
}
/* localdecomp:end func_003ABE28 */

void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D82F8[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;
/* localdecomp:start func_003ABE30 */
void func_003ABE30(S_003A6888 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < 4U) {
        func_00116F98(D_001D82D8, 0x26, D_001D82F8);
    }
    arg0->f0 = arg2;
    arg0->f4 = arg3;
    arg0->f8 = arg1;
    arg0->f14 = 0;
    arg0->fC = 0;
    arg0->f10 = 0;
}
/* localdecomp:end func_003ABE30 */

LINKER_REMNANT("asm/remnants", func_003ABEB0);

void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D8320[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;
/* localdecomp:start func_003ABEB8 */
void *func_003ABEB8(S_003A6910 *pool) {
    void **p;
    u32 used;
    u32 next;

    p = pool->free;
    if (p != 0) {
        pool->free = *p;
        pool->count++;
        return p;
    }
    used = pool->used;
    next = used + pool->elem;
    if (pool->size < next) {
        func_00116F98(D_001D82D8, 0x54, D_001D8320);
        return 0;
    }
    { u8 *r = pool->base + used; pool->used = next; pool->count++; return r; }
}
/* localdecomp:end func_003ABEB8 */

/* localdecomp:start func_003ABF48 */
void func_003ABF48(void *a0, void *a1) {
    *(s32 *)a1 = *(s32 *)((u8 *)a0 + 0x14);
    *(s32 *)((u8 *)a0 + 0x14) = (s32)a1;
    *(s32 *)((u8 *)a0 + 0x10) = *(s32 *)((u8 *)a0 + 0x10) - 1;
}
/* localdecomp:end func_003ABF48 */

LINKER_REMNANT("asm/remnants", func_003ABF68);

extern u8 *func_003AB218(u8 *);
/* localdecomp:start func_003ABF70 */
u8 *func_003ABF70(u8 *p) {
    func_003AB218(p + 0x10);
    func_003AB218(p + 0x4C);
    return p;
}
/* localdecomp:end func_003ABF70 */

/* localdecomp:start func_003ABFA8 */
typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern s32 D_001D5C78;
extern u8 D_001D8370[], D_001D8380[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void func_003AB250();
extern void func_003AB428(u8 *, u8 *, s32);
extern void func_003AB458(void *, f32);
extern void func_003AAF00(void *, s32);
extern s32 func_003AAEB8(void *);
void func_003ABFA8(O_3A6A00 *o, s32 a) {
    s32 *t;
    o->b88 = 0;
    o->f18C = 0;
    o->f188 = 0;
    o->f1A8 = 0;
    o->f1A4 = 1;
    o->f1AC = 0;
    o->f1B4 = 0x28;
    o->f190 = 1;
    func_0011A264((s32)o->f1B8, 0, 0x78);
    if (a != 0) {
        {
            s32 *t0 = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(a));
            ((f32 *)t0)[0] = 255.0f;
            ((f32 *)t0)[1] = 108.0f;
            t0[2] = 0;
            t0[3] = 0;
            o->p0 = t0;
        }
        {
            s32 *t1 = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(a));
            ((f32 *)t1)[0] = 0.0f;
            ((f32 *)t1)[1] = 0.0f;
            t1[0] = 0x600E5092;
            t1[2] = 0;
            t1[3] = 0;
            o->p8 = t1;
        }
        {
            s32 *t2 = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(a));
            o->p4 = t2;
            t2[1] = 0;
            t2[2] = 0;
            t2[3] = 0;
            t2[0] = 0;
        }
        {
            s32 *t3 = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(a));
            o->pC = t3;
            t3[1] = 0;
            t3[2] = 0;
            t3[3] = 0;
            t3[0] = 0;
        }
    }
    func_003AB250(o->sub10, D_001D8370, a);
    func_003AB428(o->sub10, (u8 *)D_001D5C78 + 0x7090, 0xC);
    func_003AB458(o->sub10, 0.02f);
    func_003AAF00(o->sub10, 1);
    *(s32 *)func_003AAEB8(o->sub10) = 0x332299DE;
    func_003AB250(o->sub4C, D_001D8380, a);
    func_003AB428(o->sub4C, (u8 *)D_001D5C78 + 0x7090, 0xD);
    func_003AAF00(o->sub4C, 1);
    *(s32 *)func_003AAEB8(o->sub4C) = 0x332299DE;
    *o->pC = 0x8066CCFF;
    o->f198 = 0;
    *o->p4 = 0;
}
/* localdecomp:end func_003ABFA8 */

LINKER_REMNANT("asm/remnants", func_003AC1B0);

typedef struct {
    s16 h0, h2, h4, h6, h8, hA, hC, hE, h10;
    u16 h12;
    s16 h14, h16, h18, h1A;
} W_3A6C30;
extern char D_001D8388[], D_001D8398[], D_001D83A8[], D_001D83E0[], D_001D8418[], D_001D8420[], D_001D8430[];
extern s32 func_11B2E8();
extern void func_00391130();
extern void func_003911B8();
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_003AC638(s32, s32, s32, f32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003AC1D8);

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
