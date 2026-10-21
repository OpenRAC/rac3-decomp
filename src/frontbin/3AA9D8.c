#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003F2388(s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AA9D8 */
extern char D_001D8160[];
extern void func_003AA910();
void func_003AA9D8(u8 *p) {
    *(void **)(p + 4) = D_001D8160;
    func_003AA910(p);
}
/* localdecomp:end func_003AA9D8 */

typedef struct K_3A54A0 { struct K_3A54A0 *next; u8 p4[4]; f32 t; f32 v[4]; } K_3A54A0;
typedef struct { u8 p0[0xC]; K_3A54A0 *k; u32 n; s32 mode; } H_3A54A0;
typedef struct { u8 p0[8]; H_3A54A0 *h; } O_3A54A0;
INCLUDE_ASM("asm/nonmatchings/text", func_003AAA00);

/* localdecomp:start func_003AAB68 */
extern u8 D_001D8178[];

void func_003AAB68(void *a0) {
    register void *dest __asm__("$2");    // $v0 ($2)
    register s32 val __asm__("$3");       // $v1 ($3)

    // Force the exact 64-bit move instruction (daddu) at offset 0.
    // This generates the exact machine code bytes for 0x0080102d.
    __asm__ volatile("daddu %0, %1, $0" : "=r"(dest) : "r"(a0));

    val = (s32)&D_001D8178;

    __asm__ volatile("" : : "r"(dest), "r"(val));

    *(s32 *)dest = val;
}
/* localdecomp:end func_003AAB68 */

/* localdecomp:start func_003AAB80 */
extern u8 D_001D8178[];
extern s32 func_003F2380();
void func_003AAB80(void **p, s32 f) { *p = D_001D8178; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003AAB80 */

/* localdecomp:start func_003AABB0 */
void func_003AABB0(s32 unused, f32 *out, f32 *a, f32 *b, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[0] + t * b[0];
    out[1] = s * a[1] + t * b[1];
    out[2] = s * a[2] + t * b[2];
    out[3] = s * a[3] + t * b[3];
}
/* localdecomp:end func_003AABB0 */

/* localdecomp:start func_003AAC20 */
extern s32 func_0038DBD8(f32, s32, s32);
void func_003AAC20(f32 f, s32 x, s32 *out, s32 *a, s32 *b) {
    out[0] = func_0038DBD8(f, a[0], b[0]);
    out[1] = func_0038DBD8(f, a[1], b[1]);
    out[2] = func_0038DBD8(f, a[2], b[2]);
    out[3] = func_0038DBD8(f, a[3], b[3]);
}
/* localdecomp:end func_003AAC20 */

LINKER_REMNANT("asm/remnants", func_003AACB0);

/* localdecomp:start func_003AACC0 */
extern f32 func_003AF2A0(f32, f32, f32, f32, f32);
void func_003AACC0(u8 *p, f32 *out, f32 t) {
    *out = func_003AF2A0(t, 0.0f, *(f32 *)(p + 8), *(f32 *)(p + 0xC), 1.0f);
}
/* localdecomp:end func_003AACC0 */

LINKER_REMNANT("asm/remnants", func_003AAD00);

/* localdecomp:start func_003AAD10 */
extern u8 D_001D80E8[];
extern void func_003ABF48();
extern void func_003AA910();
void func_003AAD10(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001D80E8;
    func_003ABF48(*(void **)(p + 0x2C), *(s32 *)(p + 0x28));
    func_003AA910(p, f);
}
/* localdecomp:end func_003AAD10 */

/* localdecomp:start func_003AAD60 */
void func_003AAD60(f32 *a, f32 *out, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[2] + t * a[3];
    out[1] = s * a[4] + t * a[5];
    out[2] = s * a[6] + t * a[7];
    out[3] = s * a[8] + t * a[9];
}
/* localdecomp:end func_003AAD60 */

LINKER_REMNANT("asm/remnants", func_003AADD0);

/* localdecomp:start func_003AADE0 */
extern void func_003AA910();
void func_003AADE0(void) {
    func_003AA910();
}
/* localdecomp:end func_003AADE0 */

/* localdecomp:start func_003AAE00 */
extern void func_003AA910();
void func_003AAE00(void) {
    func_003AA910();
}
/* localdecomp:end func_003AAE00 */

extern s32 D_001D8118[];
extern void func_003AAB80();
/* localdecomp:start func_003AAE20 */
extern s32 D_001D8118[2];
extern void func_003AAB80();
void func_003AAE20(void **p, s32 f) {
    *p = D_001D8118;
    func_003AAB80(p, f);
}
/* localdecomp:end func_003AAE20 */

extern s32 D_001D8100[];
extern void func_003AAB80();
/* localdecomp:start func_003AAE40 */
extern s32 D_001D8100[2];
extern void func_003AAB80();
void func_003AAE40(void **p, s32 f) {
    *p = D_001D8100;
    func_003AAB80(p, f);
}
/* localdecomp:end func_003AAE40 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AAE60);

/* localdecomp:start func_003AAEA8 */
extern s32 D_001DA070;
s32 func_003AAEA8(void) {
    return D_001DA070;
}
/* localdecomp:end func_003AAEA8 */

/* localdecomp:start func_003AAEB0 */
s32 func_003AAEB0(void *p) {
    return *(s32 *)((u8 *)p + 0x4);
}
/* localdecomp:end func_003AAEB0 */

/* localdecomp:start func_003AAEB8 */
s32 func_003AAEB8(void *p) {
    return *(s32 *)((u8 *)p + 0xC);
}
/* localdecomp:end func_003AAEB8 */

LINKER_REMNANT("asm/remnants", func_003AAEC0);

/* localdecomp:start func_003AAED0 */
void func_003AAED0(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)a0) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)a0) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)a0) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)a0) + 0xc) = a4;
}
/* localdecomp:end func_003AAED0 */

LINKER_REMNANT("asm/remnants", func_003AAEF8);

/* localdecomp:start func_003AAF00 */
void func_003AAF00(void *a0, s32 a1) {
    s32 *v0 = *(s32 **)((u8 *)a0 + 0x10);
    if (a1 != 0) {
        *(f32 *)v0 = 1.0f;
    } else {
        *v0 = 0;
    }
}
/* localdecomp:end func_003AAF00 */

/* localdecomp:start func_003AAF20 */
typedef struct { s32 x0; s32 x4; u8 pad[0xD]; u8 b15; u8 pad2[0xA]; s32 x20; } S_3A5978;
extern void func_003ABF48();
void func_003AAF20(S_3A5978 *p, s32 v) {
    if (v != p->x4) {
        if (p->x20 && !p->b15) {
            func_003ABF48(p->x20, p->x4);
            p->b15 = 1;
        }
        p->x4 = v;
    }
}
/* localdecomp:end func_003AAF20 */

LINKER_REMNANT("asm/remnants", func_003AAF88);

/* localdecomp:start func_003AAF90 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[4]; u8 f18; u8 pad3[7]; s32 f20; } S_3A59E8;
extern void func_003ABF48();
void func_003AAF90(S_3A59E8 *s, s32 v) {
    if (v == s->f10) return;
    if (s->f20 != 0 && s->f18 == 0) {
        func_003ABF48(s->f20, s->f10);
        s->f18 = 1;
    }
    s->f10 = v;
}
/* localdecomp:end func_003AAF90 */

/* localdecomp:start func_003AAFF8 */
void func_003AAFF8(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0xc) = a4;
}
/* localdecomp:end func_003AAFF8 */

extern s32 D_001D8218[];
/* localdecomp:start func_003AB020 */
extern s32 D_001D8218[];
u8 *func_003AB020(u8 *p) { *(s32 **)(p + 0x24) = D_001D8218; return p; }
/* localdecomp:end func_003AB020 */

/* localdecomp:start func_003AB038 */
typedef struct { s32 *p0; s32 *p4; s32 *p8; s32 *pC; s32 *p10; u8 b14; u8 b15; u8 b16; u8 b17; u8 b18; u8 pad[3]; s32 w1C; s32 w20; } O_A5A90;
void func_003AB038(o, a1, a2) O_A5A90 *o; s32 a1; s32 a2; {
    s32 *t; s32 x;
    o->w20 = a2;
    if (a2 != 0) {
        t = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(a2));
        x = o->w20;
        o->p0 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(x));
        x = o->w20;
        o->p8 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(x));
        x = o->w20;
        o->p4 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(x));
        x = o->w20;
        o->pC = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(x));
        o->p10 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
    }
    o->w1C = a1;
    o->b17 = 0; o->b14 = 0; o->b16 = 0; o->b15 = 0; o->b18 = 0;
    func_003AAF00(o, 1);
}
/* localdecomp:end func_003AB038 */

LINKER_REMNANT("asm/remnants", func_003AB160);

extern void func_003ABF48();
extern s32 func_003F2380();
extern s32 D_001D8218[];
/* localdecomp:start func_003AB168 */
void func_003AB168(u8 *p, s32 f) {
    *(s32 **)(p + 0x24) = D_001D8218;
    if (*(s32 *)(p + 0x20) != 0) {
        if (p[0x14] == 0) func_003ABF48(*(s32 *)(p + 0x20), *(s32 *)(p + 0));
        if (p[0x16] == 0) func_003ABF48(*(s32 *)(p + 0x20), *(s32 *)(p + 8));
        if (p[0x15] == 0) func_003ABF48(*(s32 *)(p + 0x20), *(s32 *)(p + 4));
        if (p[0x17] == 0) func_003ABF48(*(s32 *)(p + 0x20), *(s32 *)(p + 0xC));
    }
    if (f & 1) func_003F2380(p);
}
/* localdecomp:end func_003AB168 */

/* localdecomp:start func_003AB218 */
extern u8 *func_003AB020(u8 *);
extern u8 D_001D8200[];
u8 *func_003AB218(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = D_001D8200;
    return p;
}
/* localdecomp:end func_003AB218 */

/* localdecomp:start func_003AB250 */
typedef struct {
    u8 pad0[4];
    f32 *values;
    u8 pad8[0x18];
    s32 source;
    u8 pad24[4];
    s32 *first;
    s32 *second;
    u8 pad30[8];
    u8 flag38;
    u8 flag39;
    u8 flag3A;
} Object_003A5CA8;

extern void func_003AB038();
extern void *func_003ABEB8();
extern s32 func_003F2388(s32, s32);

void func_003AB250(Object_003A5CA8 *object) {
    s32 *allocation;
    s32 source;
    register f32 *values __asm__("$3");

    func_003AB038(object);
    if (object->source != 0) {
        allocation = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(object->source));
        source = object->source;
        object->first = allocation;
        allocation[1] = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[0] = 0;

        allocation = (s32 *)func_003F2388(0x10, (s32)func_003ABEB8(source));
        values = object->values;
        object->second = allocation;
        allocation[1] = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[0] = 0;

        values[0] = 1.0f;
        object->values[1] = 1.0f;
        object->values[2] = 1.0f;
        object->flag3A = 0;
    } else {
        object->flag3A = 0;
    }
    object->flag39 = 0;
    object->flag38 = 0;
}
/* localdecomp:end func_003AB250 */

LINKER_REMNANT("asm/remnants", func_003AB300);

/* PAL candidate for func_003AB308 (frontbin, file 3AA9D8.c).
   The US draft stored &D_001D8200_003AB168, a `s32` extern, so -G8 made the
   compiler reach it through $gp (addiu $v0, $gp, ...). Retail materialises the
   address with lui/addiu, so the global is used through its incomplete-array
   declaration (extern u8 D_001D8200[], as elsewhere in this file): an unknown
   size keeps it out of small data. */

/* localdecomp:start func_003AB308 */
extern void func_003AB168();
extern void func_003ABF48();
extern u8 D_001D8200[];

void func_003AB308(void *arg0, s32 arg1) {
    s32 temp_a0;

    *(u8 **)((u8 *)(arg0) + 0x24) = D_001D8200;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x20));
    if (temp_a0 != 0) {
        if ((*(u8 *)((u8 *)(arg0) + 0x38)) == 0) {
            func_003ABF48(temp_a0, (*(s32 *)((u8 *)(arg0) + 0x28)));
        }
        if ((*(u8 *)((u8 *)(arg0) + 0x39)) == 0) {
            func_003ABF48((*(s32 *)((u8 *)(arg0) + 0x20)), (*(s32 *)((u8 *)(arg0) + 0x2C)));
        }
    }
    func_003AB168(arg0, arg1);
}
/* localdecomp:end func_003AB308 */

LINKER_REMNANT("asm/remnants", func_003AB380);

/* localdecomp:start func_003AB390 */
s32 func_003AB390(void *p) {
    return *(s32 *)((u8 *)p + 0x2C);
}
/* localdecomp:end func_003AB390 */

/* localdecomp:start func_003AB398 */
typedef struct { f32 x, y; } V2_3A5DF0;
typedef struct { V2_3A5DF0 *f0; V2_3A5DF0 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x18]; f32 *f2C; u8 p30[4]; s32 f34; } O_3A5DF0;
extern void func_003AA320(s32, s32, f32, f32, f32, f32, f32);
extern f32 D_001DA078[];
extern s32 D_001DA070_003AB398[];
void func_003AB398(O_3A5DF0 *o) {
    f32 zero = 0.0f;
    if (*o->f10 != zero && o->f34 != 0) {
        f32 z0 = zero, z1 = zero;
        f32 x = o->f0->x + zero;
        f32 y = o->f0->y + zero;
        s32 fl = *o->fC;
        func_003AA320(o->f34, fl, x, y, o->f4->x, o->f4->y * D_001DA078[0] + (D_001DA070_003AB398[0] == 1 ? z0 : z1), *o->f2C);
    }
}
/* localdecomp:end func_003AB398 */

/* localdecomp:start func_003AB428 */
extern s32 func_003ABDD8(u8 *, s32);
void func_003AB428(u8 *p, u8 *a, s32 b) {
    *(s32 *)(p + 0x34) = func_003ABDD8(a, b);
}
/* localdecomp:end func_003AB428 */

/* localdecomp:start func_003AB458 */
void func_003AB458(void *p, f32 value) {
    **(f32 **)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003AB458 */

/* localdecomp:start func_003AB468 */
extern u8 *func_003AB020(u8 *);
extern u8 D_001D81B8[];
u8 *func_003AB468(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = D_001D81B8;
    return p;
}
/* localdecomp:end func_003AB468 */

/* localdecomp:start func_003AB4A0 */
typedef struct { u8 pad[0x28]; u8 b; u8 pad2[7]; s32 a; s32 c; s32 d; } S_3A5EF8;
extern void func_003AB038();
void func_003AB4A0(S_3A5EF8 *s, s32 a, s32 b, s32 c, s32 d) {
    func_003AB038(s, c, d);
    s->a = a;
    s->b = b;
    s->c = 100;
    s->d = 0x80000000;
}
/* localdecomp:end func_003AB4A0 */

LINKER_REMNANT("asm/remnants", func_003AB500);

extern u8 D_001D81B8[];
/* localdecomp:start func_003AB508 */
void func_003AB508(u8 *p) {
    *(void **)(p + 0x24) = D_001D81B8;
    ((void (*)(void *))func_003AB168)(p);
}
/* localdecomp:end func_003AB508 */

/* localdecomp:start func_003AB530 */
void func_003AB530(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 4) = a2;
}
/* localdecomp:end func_003AB530 */

/* localdecomp:start func_003AB548 */
void func_003AB548(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 8) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0xc) = a2;
}
/* localdecomp:end func_003AB548 */

LINKER_REMNANT("asm/remnants", func_003AB560);

/* localdecomp:start func_003AB570 */
typedef struct { f32 *p0; f32 *p4; u8 p8[4]; s32 *pC; f32 *p10; u8 p14[0x1C]; u32 f30; u8 p34[4]; s32 f38; } O_3A5FC8;
extern s32 D_001D81A8;
extern void func_0038C310(s32, s32, s32, s32, unsigned long, s32);
void func_003AB570(O_3A5FC8 *o) {
    f32 x; f32 y; f32 w; f32 h; unsigned long e; s32 buf[2]; s32 y2;
    f32 *pos; f32 *sz;
    if (*o->p10 != 0.0f) {
        pos = o->p0;
        sz = o->p4;
        x = pos[0];
        y = pos[1];
        e = D_001D81A8;
        sz[0] = ((f32)o->f30 < sz[0]) ? (f32)o->f30 : o->p4[0];
        w = o->p4[0];
        h = o->p4[1];
        buf[0] = o->f38;
        buf[1] = o->f38;
        func_0038C310((s32)x, (s32)y, (s32)(x + (f32)o->f30), y2 = (s32)(y + h), e, (s32)buf);
        buf[0] = o->pC[0];
        buf[1] = o->pC[1];
        func_0038C310((s32)x, (s32)y, (s32)(x + w), y2, e, (s32)buf);
    }
}
/* localdecomp:end func_003AB570 */

/* localdecomp:start func_003AB738 */
extern u8 *func_003AB020(u8 *);
extern u8 D_001D81E8[];
u8 *func_003AB738(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = D_001D81E8;
    return p;
}
/* localdecomp:end func_003AB738 */

LINKER_REMNANT("asm/remnants", func_003AB770);

/* localdecomp:start func_003AB778 */
void func_003AB038();
void *func_003F2388_003AB778(s32, void *);                  /* extern */

void func_003AB778(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    func_003AB038();
    if (arg2 != 0) {
        temp_v0 = func_003F2388_003AB778(0x10, func_003ABEB8((*(s32 *)((u8 *)(arg0) + 0x20))));
        (*(void **)((u8 *)(arg0) + 0x28)) = temp_v0;
        (*(s32 *)((u8 *)(temp_v0) + 4)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 8)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0xC)) = 0;
        (*(s32 *)((u8 *)(temp_v0) + 0)) = 0;
    }
    (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x28))) + 0)) = 0;
    (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x28))) + 4)) = 0;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0))) + 0)) = 100.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0))) + 4)) = 100.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 0)) = 64.0f;
    (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 4))) + 4)) = 64.0f;
    (*(s8 *)((u8 *)(arg0) + 0x2C)) = 0;
}
/* localdecomp:end func_003AB778 */

/* localdecomp:start func_003AB820 */
s32 func_003AB820(void *p) {
    return *(s32 *)((u8 *)p + 0x28);
}
/* localdecomp:end func_003AB820 */

LINKER_REMNANT("asm/remnants", func_003AB828);

extern void func_003ABF48();
extern s32 D_001D81E8_003AB168;
INCLUDE_ASM("asm/nonmatchings/text", func_003AB830);

/* localdecomp:start func_003AB890 */
typedef struct { f32 *p0; f32 *p4; u8 p8[4]; u32 *pC; f32 *p10; u8 p14[0x14]; f32 *p28; } S_62E8;
extern u8 D_001D81AC_003AB890;
extern u32 D_001D81B0_003AB890;
__asm__(".extern D_001D81AC_003AB890, 4");
__asm__(".extern D_001D81B0_003AB890, 4");
extern s32 func_00396968();
extern void func_00396E50();
void func_003AB890(S_62E8 *a) {
    u32 loc[4];
    if (*a->p10 != 0.0f) {
        if (D_001D81AC_003AB890 != 0) {
            *a->pC = (*a->pC & 0xFF000000) | (D_001D81B0_003AB890 & 0xFFFFFF);
        }
        loc[0] = *a->pC;
        loc[1] = *a->pC;
        loc[2] = *a->pC;
        loc[3] = *a->pC;
        func_00396E50(func_00396968((s32)a->p28[0], (s32)a->p28[1]), (s32)a->p0[0], (s32)a->p0[1], (s32)a->p4[0], (s32)a->p4[1], loc);
    }
}
/* localdecomp:end func_003AB890 */

/* localdecomp:start func_003AB988 */
void func_003AB988(u8 *p, s32 a, s32 b) {
    (*(f32 **)(p + 0x28))[0] = a;
    (*(f32 **)(p + 0x28))[1] = b;
}
/* localdecomp:end func_003AB988 */

/* localdecomp:start func_003AB9B8 */
extern u8 *func_003AB020(u8 *);
extern s32 D_001D81D0[];
u8 *func_003AB9B8(u8 *p) {
    func_003AB020(p);
    *(u8 **)(p + 0x24) = (u8 *)D_001D81D0;
    return p;
}
/* localdecomp:end func_003AB9B8 */

LINKER_REMNANT("asm/remnants", func_003AB9F0);

extern s32 D_003357E0[];
typedef struct { u8 pad[4]; f32 *v; u8 p2[0x28-8]; void *p28; u8 p3[4]; long l30; s32 w38; s32 w3C; } S_3A6450;
INCLUDE_ASM("asm/nonmatchings/text", func_003AB9F8);

extern s32 D_001D81D0[];
/* localdecomp:start func_003ABA58 */
extern s32 D_001D81D0[];

void func_003ABA58(void *p) {
    *(s32 **)((u8 *)p + 0x24) = &D_001D81D0[0];
    ((void (*)(void *))func_003AB168)(p);
}
/* localdecomp:end func_003ABA58 */

/* localdecomp:start func_003ABA80 */
void func_003ABA80(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x3C) = value;
}
/* localdecomp:end func_003ABA80 */

/* localdecomp:start func_003ABA88 */
void func_003ABA88(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003ABA88 */

/* localdecomp:start func_003ABA90 */
extern void func_00390D70(s32, s32, s32, f32);
void func_003ABA90(u8 *p) {
    func_00390D70(*(s32 *)(p + 0x38), -1, *(s32 *)(p + 0x28), **(f32 **)(p + 4));
}
/* localdecomp:end func_003ABA90 */

LINKER_REMNANT("asm/remnants", func_003ABAC0);

/* localdecomp:start func_003ABAC8 */
typedef struct { f32 x, y; } V2_A6520;
typedef struct { V2_A6520 *f0; V2_A6520 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x14]; s32 f28; u8 p2C[4]; s32 f30; u8 p34[4]; s32 f38; s32 f3C; } O_A6520;
extern s32 func_003ABA90_A6520();
extern long func_00389598(s32);

extern void func_00391078_A6520(f32, f32, f32, s32, s32, s32, s32, s32);
void func_003ABAC8(O_A6520 *o) {
    s32 t;
    f32 x;
    V2_A6520 *p0;
    V2_A6520 *p4;
    s32 a;
    if (*o->f10 != 0.0f && o->f38 != 0) {
        t = func_003ABA90_A6520(o);
        x = o->f0->x;
        switch (o->f3C) {
        case 0:
            break;
        case 1:
            x -= (f32)(t >> 1);
            break;
        case 2:
            x -= (f32)t;
            break;
        }
        a = *o->fC;
        p0 = o->f0;
        p4 = o->f4;
        func_00391078_A6520(x, p0->y, p4->x, a, o->f38, t, ((s32 (*)(s32))func_00389598)(o->f30), o->f28);
    }
}
/* localdecomp:end func_003ABAC8 */

/* localdecomp:start func_003ABBE0 */
void func_003ABBE0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x34) = value;
}
/* localdecomp:end func_003ABBE0 */

typedef struct { u8 p0[4]; f32 *f4; u8 p8[0x28]; u32 f30; u32 f34; } O_A6640;
INCLUDE_ASM("asm/nonmatchings/text", func_003ABBE8);

/* localdecomp:start func_003ABD10 */
void func_003ABD10(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003ABD10 */

/* localdecomp:start func_003ABD18 */
void func_003ABD18(void *a0, s32 a1) {
    f32 result;
    void *p;
    __asm__ volatile (
        "mtc1 %2, %0\n"
        "nop\n"
        "cvt.s.w %0, %0\n"
        "lw %1, 4(%3)\n"
        : "=f"(result), "=r"(p)
        : "r"(a1), "r"(a0)
    );
    *(f32 *)((u8 *)p + 4) = result;
}
/* localdecomp:end func_003ABD18 */

/* localdecomp:start func_003ABD30 */
void func_003ABD30(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003ABD30 */
