#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003F0250(void *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3EE290.c's earlier functions */
extern s32 func_003EDEB0();
extern void func_003EDEF8();
extern s32 func_003EDEB0(void *, s32);
extern char D_001D9670[];
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 func_0011A264(void *, s32, s32);
extern void func_003EDD40(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
s32 func_003EDEB0(void *p, s32 mask);
void func_003EDEF8(void *p, s32 *a, s32 *b);
extern void func_003EDEF8(void *, s32 *, s32 *);
extern s32 func_003F2738();

/* localdecomp:start func_003EF658 */
/* from frontbin's twin (already C) */
void func_003EF658(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EF658 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EF698);

typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
extern s32 func_003EDEB0();
extern unsigned long func_0039B088(s32);
extern void func_0038B500(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
/* localdecomp:start func_003EF998 */
/* the same code as frontbin's func_003EF5E0 */
s32 func_003EF998(O_3EA078 *o, f32 *r) {
    OB_3EA078 *ob = o->f50;
    s32 k38;
    if ((ob->f0 ^ 2) == 0) {
        k38 = o->f38;
        if (func_003EDEB0(o, 0x40)) {
            f32 x1, y1, x0, y0, ox, oy, sc, w, h;
            s32 a, b, k28;
            unsigned long res;
            PP_3EA078 *pp;
            ox = o->f20;
            oy = o->f24;
            k28 = o->f28;
            pp = (PP_3EA078 *)((s32 (*)())*(s32 *)((u8 *)ob->vt4 + 0x18))(ob);
            x0 = r[0] + ox;
            y0 = r[1] + oy;
            x1 = r[2] + ox;
            y1 = r[3] + oy;
            sc = o->f2C;
            a = pp->f8;
            b = pp->fC;
            w = x1 - x0;
            h = y1 - y0;
            res = func_0039B088((s32)pp);
            func_0038B500((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C), (s32)(w * D_001D9698), (s32)(h * D_001D969C), 0, 0, a, b, sc, (unsigned long)(u32)k28, res);
        }
        {
            f32 x1, y1, x0, y0, sc;
            s32 a, b;
            unsigned long res;
            PP_3EA078 *pp;
            pp = (PP_3EA078 *)((s32 (*)())*(s32 *)((u8 *)ob->vt4 + 0x18))(ob);
            x0 = r[0];
            y0 = r[1];
            x1 = r[2] - x0;
            y1 = r[3] - y0;
            sc = o->f2C;
            a = pp->f8;
            b = pp->fC;
            res = func_0039B088((s32)pp);
            func_0038B500((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C), (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, 0, a, b, sc, (unsigned long)(u32)k38, res);
        }
    }
    return 0;
}
/* localdecomp:end func_003EF998 */

/* localdecomp:start func_003EFBB0 */
typedef struct { u32 c0, c1, c2, c3; } Color_003EFBB0;
typedef struct VT_003EFBB0 {
    u8 pad[0x20];
    void (*fill)(void *o, s32 a1, f32 *rect, s32 one);
} VT_003EFBB0;
typedef struct CVT_003EFBB0 {
    u8 pad[8];
    void (*fade)(void *c, s32 v);
} CVT_003EFBB0;
typedef struct { s32 f0; CVT_003EFBB0 *vt4; } Child_003EFBB0;
typedef struct {
    u8 pad0[8];
    VT_003EFBB0 *vt;
    u8 padC[0x14];
    f32 offx, offy;
    u32 background;
    u8 pad2C[0xC];
    u32 col0, col1, col2, col3;
    u16 count;
    u8 pad4A[2];
    u8 max, t, state;
    u8 pad4F;
    Child_003EFBB0 *child;
} Obj_003EFBB0;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern s32 func_003EDEB0(void *, s32);
extern void func_003EE0A8(void *, f32 *);
extern s32 func_003EF998();
extern void func_003EF698();
extern void func_0038C6F0(s32, s32, s32, s32, s32, Color_003EFBB0);

static __inline__ Color_003EFBB0 colors_003EFBB0(u32 c) {
    return (Color_003EFBB0){ c, c, c, c };
}

static __inline__ void fill_003EFBB0(Color_003EFBB0 c, f32 x0, f32 y0, f32 x1, f32 y1) {
    func_0038C6F0((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C),
                  (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, c);
}

void func_003EFBB0(Obj_003EFBB0 *o, s32 a1)
{
    f32 rect[4];
    s32 invisible = 0;
    u32 c0 = o->col0, c1 = o->col1, c2 = o->col2, c3 = o->col3;
    u32 al0, al1, al2, al3;
    s32 diff;

    if (o->child != 0) {
        al0 = c0 >> 24;
        al1 = c1 >> 24;
        al2 = c2 >> 24;
        al3 = c3 >> 24;
        switch (o->state) {
        case 0:
            o->t = 0;
            break;
        case 4:
            o->t = o->t + 1;
            if (o->max < o->t) {
                o->t = o->max;
                o->state = 2;
            }
            goto fade;
        case 2:
            o->child->vt4->fade(o->child, o->count - 1);
            o->state = 3;
        case 3:
            o->t = o->max;
            if ((o->child->f0 ^ 2) == 0) {
                o->state = 1;
            }
            al3 = 0;
            al2 = 0;
            al1 = 0;
            al0 = 0;
            break;
        case 1:
            o->t = o->t - 1;
            if (o->t == 0) {
                o->state = 0;
                o->t = 0;
            }
        fade:
            diff = o->max - o->t;
            al0 = (u8)((s32)(al0 * diff) / o->max);
            al1 = (u8)((s32)(al1 * diff) / o->max);
            al2 = (u8)((s32)(al2 * diff) / o->max);
            al3 = (u8)((s32)(al3 * diff) / o->max);
            break;
        }
        {
        s32 inv = al0 == 0 && al1 == 0 && al2 == 0 && al3 == 0;
        o->col0 = (al0 << 24) | (c0 & 0xFFFFFF);
        o->col1 = (al1 << 24) | (c1 & 0xFFFFFF);
        o->col2 = (al2 << 24) | (c2 & 0xFFFFFF);
        o->col3 = (al3 << 24) | (c3 & 0xFFFFFF);
        invisible = inv;
        }
    }

    o->vt->fill(o, a1, rect, 1);
    func_003EE0A8(o, rect);
    if (!invisible) {
        s32 more = 1;

        if (o->count != 0) {
            if (o->child != 0) {
                more = func_003EF998(o, rect);
            } else {
                func_003EF698(o, rect);
                more = 0;
            }
        }
        if (more != 0) {
            if (func_003EDEB0(o, 0x40)) {
                fill_003EFBB0(colors_003EFBB0(o->background), rect[0] + o->offx, rect[1] + o->offy,
                              rect[2] + o->offx, rect[3] + o->offy);
            }
            fill_003EFBB0((Color_003EFBB0){ o->col0, o->col1, o->col2, o->col3 },
                          rect[0], rect[1], rect[2], rect[3]);
        }
    }
    if (o->child != 0) {
        o->col0 = c0;
        o->col1 = c1;
        o->col2 = c2;
        o->col3 = c3;
    }
}
/* localdecomp:end func_003EFBB0 */

typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EFF68 */
extern void (*D_001D9A40_00382B20[1])(s32);
s32 func_003EDEB0(void *p, s32 mask);
void func_003EDEF8(void *p, s32 *a, s32 *b);
typedef struct { u8 b[16]; } B16_3E98B8_3EEE20_xr003EFF68;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3E98B8_3EEE20_xr003EFF68;
extern void func_003EDEF8(void *, s32 *, s32 *);

void func_003EFF68(O_3E98B8_3EEE20_xr003EFF68 *o, f32 *p, f32 *out, s32 flag) {
    f32 sy = 2.0f;
    f32 ay = 0.0f;
    f32 sx = 2.0f;
    f32 ax = 0.0f;
    f32 t[4];
    f32 x0, y0, h, dx, dy;
    s32 k1, k2;
    if (flag) do {
        k1 = 0;
        k2 = 0;
        func_003EDEF8(o, &k1, &k2);
        if (k1 != 3) {
            if (k1 == 1) {
                ax = 1.0f;
            } else {
                sx = 2.0f;
                ax = -1.0f;
            }
        }
        if (k2 != 3) {
            if (k2 == 2) {
                sy = 2.0f;
                ay = -1.0f;
            } else {
                sy = 2.0f;
                ay = 1.0f;
            }
        }
    } while (0);
    x0 = o->f10;
    x0 = (p[2] - p[0]) * x0 + p[0];
    y0 = o->f14;
    y0 = (p[3] - p[1]) * y0 + p[1];
    out[0] = (x0 - o->f18 / sx) + (ax * o->f18) / sx;
    h = o->f1C;
    out[1] = (y0 - h / sy) + (ay * h) / sy;
    out[2] = out[0] + o->f18;
    out[3] = out[1] + o->f1C;
    if (func_003EDEB0(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3E98B8_3EEE20_xr003EFF68 *)t = *(B16_3E98B8_3EEE20_xr003EFF68 *)out;
        t[0] += dx;
        t[2] += dx;
        t[1] += dy;
        t[3] += dy;
        out[0] = (t[0] < out[0]) ? t[0] : out[0];
        out[2] = (out[2] < t[2]) ? t[2] : out[2];
        out[3] = (out[3] < t[3]) ? t[3] : out[3];
        out[1] = (t[1] < out[1]) ? t[1] : out[1];
    }
}
/* localdecomp:end func_003EFF68 */

/* localdecomp:start func_003F01C8 */
s32 func_003F01C8(void *arg0, s32 arg1) {
    s32 (*temp_v0)(s32);
    s32 temp_v1;
    void *temp_a0;

    if ((*(u16 *)((u8 *)(arg0) + 0x48)) != 0) {
        temp_a0 = (*(void **)((u8 *)(arg0) + 0x50));
        if ((temp_a0 != 0) && ((temp_v1 = (*(s32 *)((u8 *)(temp_a0) + 0)), ((temp_v1 ^ 1) == 0)) || ((temp_v1 ^ 8) == 0))) {
            (*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(temp_a0) + 4))) + 8))(temp_a0, (*(u16 *)((u8 *)(arg0) + 0x48)) - 1);
        }
    }
    temp_v0 = (*(s32 (**)(s32))((u8 *)(arg0) + 0x34));
    if (temp_v0 != 0) {
        temp_v0(arg1);
    }
    return 0;
}
/* localdecomp:end func_003F01C8 */

/* localdecomp:start func_003F0250 */
void func_003F0250(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003F0250 */
