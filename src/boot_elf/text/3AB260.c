#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003F2740(s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AB260 */
extern s32 D_001DA070;
s32 func_003AB260(void) {
    return D_001DA070;
}
/* localdecomp:end func_003AB260 */

/* localdecomp:start func_003AB268 */
s32 func_003AB268(void *p) {
    return *(s32 *)((u8 *)p + 0x4);
}
/* localdecomp:end func_003AB268 */

/* localdecomp:start func_003AB270 */
s32 func_003AB270(void *p) {
    return *(s32 *)((u8 *)p + 0xC);
}
/* localdecomp:end func_003AB270 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB278);

/* localdecomp:start func_003AB288 */
void func_003AB288(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)a0) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)a0) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)a0) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)a0) + 0xc) = a4;
}
/* localdecomp:end func_003AB288 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB2B0);

/* localdecomp:start func_003AB2B8 */
void func_003AB2B8(void *a0, s32 a1) {
    s32 *v0 = *(s32 **)((u8 *)a0 + 0x10);
    if (a1 != 0) {
        *(f32 *)v0 = 1.0f;
    } else {
        *v0 = 0;
    }
}
/* localdecomp:end func_003AB2B8 */

/* localdecomp:start func_003AB2D8 */
typedef struct { s32 x0; s32 x4; u8 pad[0xD]; u8 b15; u8 pad2[0xA]; s32 x20; } S_3A5978;
extern void func_003AC300();
void func_003AB2D8(S_3A5978 *p, s32 v) {
    if (v != p->x4) {
        if (p->x20 && !p->b15) {
            func_003AC300(p->x20, p->x4);
            p->b15 = 1;
        }
        p->x4 = v;
    }
}
/* localdecomp:end func_003AB2D8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB340);

/* localdecomp:start func_003AB348 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[4]; u8 f18; u8 pad3[7]; s32 f20; } S_3A59E8;
extern void func_003AC300();
void func_003AB348(S_3A59E8 *s, s32 v) {
    if (v == s->f10) return;
    if (s->f20 != 0 && s->f18 == 0) {
        func_003AC300(s->f20, s->f10);
        s->f18 = 1;
    }
    s->f10 = v;
}
/* localdecomp:end func_003AB348 */

/* localdecomp:start func_003AB3B0 */
void func_003AB3B0(void *a0, f32 a1, f32 a2, f32 a3, f32 a4) {
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0) = a1;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 4) = a2;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 8) = a3;
    *(f32 *)((u8 *)(*(void **)((u8 *)a0 + 4)) + 0xc) = a4;
}
/* localdecomp:end func_003AB3B0 */

extern s32 D_001D8218[];

/* localdecomp:start func_003AB3D8 */
extern s32 D_001D8218[];
u8 *func_003AB3D8(u8 *p) { *(s32 **)(p + 0x24) = D_001D8218; return p; }
/* localdecomp:end func_003AB3D8 */

/* localdecomp:start func_003AB3F0 */
typedef struct { s32 *p0; s32 *p4; s32 *p8; s32 *pC; s32 *p10; u8 b14; u8 b15; u8 b16; u8 b17; u8 b18; u8 pad[3]; s32 w1C; s32 w20; } O_A5A90;
void func_003AB3F0(o, a1, a2) O_A5A90 *o; s32 a1; s32 a2; {
    s32 *t; s32 x;
    o->w20 = a2;
    if (a2 != 0) {
        t = (s32 *)func_003F2740(0x10, (s32)func_003AC270(a2));
        x = o->w20;
        o->p0 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2740(0x10, (s32)func_003AC270(x));
        x = o->w20;
        o->p8 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2740(0x10, (s32)func_003AC270(x));
        x = o->w20;
        o->p4 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2740(0x10, (s32)func_003AC270(x));
        x = o->w20;
        o->pC = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
        t = (s32 *)func_003F2740(0x10, (s32)func_003AC270(x));
        o->p10 = t;
        t[1] = 0; t[2] = 0; t[3] = 0; t[0] = 0;
    }
    o->w1C = a1;
    o->b17 = 0; o->b14 = 0; o->b16 = 0; o->b15 = 0; o->b18 = 0;
    func_003AB2B8(o, 1);
}
/* localdecomp:end func_003AB3F0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB518);

extern void func_003AC300();
extern s32 func_003F2738();
extern s32 D_001D8218[];
/* localdecomp:start func_003AB520 */
void func_003AB520(u8 *p, s32 f) {
    *(s32 **)(p + 0x24) = D_001D8218;
    if (*(s32 *)(p + 0x20) != 0) {
        if (p[0x14] == 0) func_003AC300(*(s32 *)(p + 0x20), *(s32 *)(p + 0));
        if (p[0x16] == 0) func_003AC300(*(s32 *)(p + 0x20), *(s32 *)(p + 8));
        if (p[0x15] == 0) func_003AC300(*(s32 *)(p + 0x20), *(s32 *)(p + 4));
        if (p[0x17] == 0) func_003AC300(*(s32 *)(p + 0x20), *(s32 *)(p + 0xC));
    }
    if (f & 1) func_003F2738(p);
}
/* localdecomp:end func_003AB520 */

/* localdecomp:start func_003AB5D0 */
extern u8 *func_003AB3D8(u8 *);
extern u8 D_001D8200[];
u8 *func_003AB5D0(u8 *p) {
    func_003AB3D8(p);
    *(u8 **)(p + 0x24) = D_001D8200;
    return p;
}
/* localdecomp:end func_003AB5D0 */

/* localdecomp:start func_003AB608 */
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

extern void func_003AB3F0();
extern void *func_003AC270();
extern s32 func_003F2740(s32, s32);

void func_003AB608(Object_003A5CA8 *object) {
    s32 *allocation;
    s32 source;
    register f32 *values;

    func_003AB3F0(object);
    if (object->source != 0) {
        allocation = (s32 *)func_003F2740(0x10, (s32)func_003AC270(object->source));
        source = object->source;
        object->first = allocation;
        allocation[1] = 0;
        allocation[2] = 0;
        allocation[3] = 0;
        allocation[0] = 0;

        allocation = (s32 *)func_003F2740(0x10, (s32)func_003AC270(source));
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
/* localdecomp:end func_003AB608 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB6B8);

/* PAL candidate for func_003AB6C0: the pointer stored at p+0x24 is the address
   of the byte array D_001D8200 (unknown size, so the compiler loads it with
   lui/addiu instead of a $gp-relative addiu, like the retail does). */

/* localdecomp:start func_003AB6C0 */
extern void func_003AB520();
extern void func_003AC300();
extern u8 D_001D8200[];

void func_003AB6C0(void *arg0, s32 arg1) {
    s32 temp_a0;

    (*(u8 **)((u8 *)(arg0) + 0x24)) = D_001D8200;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x20));
    if (temp_a0 != 0) {
        if ((*(u8 *)((u8 *)(arg0) + 0x38)) == 0) {
            func_003AC300(temp_a0, (*(s32 *)((u8 *)(arg0) + 0x28)));
        }
        if ((*(u8 *)((u8 *)(arg0) + 0x39)) == 0) {
            func_003AC300((*(s32 *)((u8 *)(arg0) + 0x20)), (*(s32 *)((u8 *)(arg0) + 0x2C)));
        }
    }
    func_003AB520(arg0, arg1);
}
/* localdecomp:end func_003AB6C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB738);

/* localdecomp:start func_003AB748 */
s32 func_003AB748(void *p) {
    return *(s32 *)((u8 *)p + 0x2C);
}
/* localdecomp:end func_003AB748 */

/* localdecomp:start func_003AB750 */
typedef struct { f32 x, y; } V2_3A5DF0;
typedef struct { V2_3A5DF0 *f0; V2_3A5DF0 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x18]; f32 *f2C; u8 p30[4]; s32 f34; } O_3A5DF0;
extern void func_003AA6D8(s32, s32, f32, f32, f32, f32, f32);
extern f32 D_001DA078[];
extern s32 D_001DA070_003AB750[];
void func_003AB750(O_3A5DF0 *o) {
    f32 zero = 0.0f;
    if (*o->f10 != zero && o->f34 != 0) {
        f32 z0 = zero, z1 = zero;
        f32 x = o->f0->x + zero;
        f32 y = o->f0->y + zero;
        s32 fl = *o->fC;
        func_003AA6D8(o->f34, fl, x, y, o->f4->x, o->f4->y * D_001DA078[0] + (D_001DA070_003AB750[0] == 1 ? z0 : z1), *o->f2C);
    }
}
/* localdecomp:end func_003AB750 */

/* localdecomp:start func_003AB7E0 */
extern s32 func_003AC190(u8 *, s32);
void func_003AB7E0(u8 *p, u8 *a, s32 b) {
    *(s32 *)(p + 0x34) = func_003AC190(a, b);
}
/* localdecomp:end func_003AB7E0 */

/* localdecomp:start func_003AB810 */
void func_003AB810(void *p, f32 value) {
    **(f32 **)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003AB810 */

/* localdecomp:start func_003AB820 */
extern u8 *func_003AB3D8(u8 *);
extern u8 D_001D81B8[];
u8 *func_003AB820(u8 *p) {
    func_003AB3D8(p);
    *(u8 **)(p + 0x24) = D_001D81B8;
    return p;
}
/* localdecomp:end func_003AB820 */

/* localdecomp:start func_003AB858 */
typedef struct { u8 pad[0x28]; u8 b; u8 pad2[7]; s32 a; s32 c; s32 d; } S_3A5EF8;
extern void func_003AB3F0();
void func_003AB858(S_3A5EF8 *s, s32 a, s32 b, s32 c, s32 d) {
    func_003AB3F0(s, c, d);
    s->a = a;
    s->b = b;
    s->c = 100;
    s->d = 0x80000000;
}
/* localdecomp:end func_003AB858 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB8B8);

extern u8 D_001D81B8[];
/* localdecomp:start func_003AB8C0 */
void func_003AB8C0(u8 *p) {
    *(void **)(p + 0x24) = D_001D81B8;
    ((void (*)(void *))func_003AB520)(p);
}
/* localdecomp:end func_003AB8C0 */

/* localdecomp:start func_003AB8E8 */
void func_003AB8E8(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 4) = a2;
}
/* localdecomp:end func_003AB8E8 */

/* localdecomp:start func_003AB900 */
void func_003AB900(void *a0, s32 a1, s32 a2) {
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 8) = a1;
    *(s32 *)((u8 *)(*(void **)((u8 *)a0 + 0xc)) + 0xc) = a2;
}
/* localdecomp:end func_003AB900 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AB918);

/* localdecomp:start func_003AB928 */
typedef struct { f32 *p0; f32 *p4; u8 p8[4]; s32 *pC; f32 *p10; u8 p14[0x1C]; u32 f30; u8 p34[4]; s32 f38; } O_3A5FC8;
extern s32 D_001D81A8;
extern void func_0038C6F0(s32, s32, s32, s32, unsigned long, s32);
void func_003AB928(O_3A5FC8 *o) {
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
        func_0038C6F0((s32)x, (s32)y, (s32)(x + (f32)o->f30), y2 = (s32)(y + h), e, (s32)buf);
        buf[0] = o->pC[0];
        buf[1] = o->pC[1];
        func_0038C6F0((s32)x, (s32)y, (s32)(x + w), y2, e, (s32)buf);
    }
}
/* localdecomp:end func_003AB928 */

/* localdecomp:start func_003ABAF0 */
extern u8 *func_003AB3D8(u8 *);
extern u8 D_001D81E8[];
u8 *func_003ABAF0(u8 *p) {
    func_003AB3D8(p);
    *(u8 **)(p + 0x24) = D_001D81E8;
    return p;
}
/* localdecomp:end func_003ABAF0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003ABB28);

/* localdecomp:start func_003ABB30 */
void func_003AB3F0();
void *func_003F2740_003ABB30(s32, void *);                  /* extern */

void func_003ABB30(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    func_003AB3F0();
    if (arg2 != 0) {
        temp_v0 = func_003F2740_003ABB30(0x10, func_003AC270((*(s32 *)((u8 *)(arg0) + 0x20))));
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
/* localdecomp:end func_003ABB30 */

/* localdecomp:start func_003ABBD8 */
s32 func_003ABBD8(void *p) {
    return *(s32 *)((u8 *)p + 0x28);
}
/* localdecomp:end func_003ABBD8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003ABBE0);

extern void func_003AC300();

/* localdecomp:start func_003ABBE8 */
/* the same code as frontbin's func_003AB830 */
void func_003ABBE8(void *arg0, s32 arg1) {
    s32 temp_a0;
    *(u8 **)((u8 *)arg0 + 0x24) = D_001D81E8;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x20));
    if ((temp_a0 != 0) && ((*(u8 *)((u8 *)(arg0) + 0x2C)) == 0)) {
        func_003AC300(temp_a0, (*(s32 *)((u8 *)(arg0) + 0x28)));
    }
    func_003AB520(arg0, arg1);
}
/* localdecomp:end func_003ABBE8 */

/* localdecomp:start func_003ABC48 */
typedef struct { f32 *p0; f32 *p4; u8 p8[4]; u32 *pC; f32 *p10; u8 p14[0x14]; f32 *p28; } S_62E8;
extern u8 D_001D81AC_003ABC48;
extern u32 D_001D81B0_003ABC48;
__asm__(".extern D_001D81AC_003ABC48, 4");
__asm__(".extern D_001D81B0_003ABC48, 4");
extern s32 func_00396D48();
extern void func_00397230();
void func_003ABC48(S_62E8 *a) {
    u32 loc[4];
    if (*a->p10 != 0.0f) {
        if (D_001D81AC_003ABC48 != 0) {
            *a->pC = (*a->pC & 0xFF000000) | (D_001D81B0_003ABC48 & 0xFFFFFF);
        }
        loc[0] = *a->pC;
        loc[1] = *a->pC;
        loc[2] = *a->pC;
        loc[3] = *a->pC;
        func_00397230(func_00396D48((s32)a->p28[0], (s32)a->p28[1]), (s32)a->p0[0], (s32)a->p0[1], (s32)a->p4[0], (s32)a->p4[1], loc);
    }
}
/* localdecomp:end func_003ABC48 */

/* localdecomp:start func_003ABD40 */
void func_003ABD40(u8 *p, s32 a, s32 b) {
    (*(f32 **)(p + 0x28))[0] = a;
    (*(f32 **)(p + 0x28))[1] = b;
}
/* localdecomp:end func_003ABD40 */

/* localdecomp:start func_003ABD70 */
extern u8 *func_003AB3D8(u8 *);
extern s32 D_001D81D0[];
u8 *func_003ABD70(u8 *p) {
    func_003AB3D8(p);
    *(u8 **)(p + 0x24) = (u8 *)D_001D81D0;
    return p;
}
/* localdecomp:end func_003ABD70 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003ABDA8);
