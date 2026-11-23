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

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003EFBB0);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031CC60);

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
