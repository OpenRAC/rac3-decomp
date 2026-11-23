#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003EFE98(void *, s32);
extern void func_003EF288();
extern void func_003EF1B8();
extern void func_003EF288(void *, s32, s32, s32, s32);
extern void *malloc(s32, s32) __asm__("func_003F2388");
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EF1B8 */
typedef struct S_003E9C50_obj S_003E9C50_obj;
typedef struct {
    u8 pad0[8];
    void (*f8)(S_003E9C50_obj *, s32);
    void (*fC)(S_003E9C50_obj *);
} S_003E9C50_vt;
struct S_003E9C50_obj { s32 f0; S_003E9C50_vt *vt; };
typedef struct {
    u8 pad0[0xC]; s32 fC; u8 pad10[0x38]; u16 f48; u8 pad4A[4]; s8 f4E; u8 pad4F; S_003E9C50_obj *f50;
} S_003E9C50;

void func_003EF1B8(S_003E9C50 *arg0, s32 arg1) {
    S_003E9C50_obj *o;

    if (arg0->f48 != arg1) {
        arg0->f48 = arg1;
        if ((u16)arg1 != 0) {
            o = arg0->f50;
            if (o != 0) {
                if ((o->f0 ^ 4) == 0) {
                    o->vt->fC(o);
                }
                if (arg0->fC & 0x8000) {
                    arg0->f4E = 4;
                    return;
                }
                arg0->f50->vt->f8(arg0->f50, arg1 - 1);
            }
        }
    }
}
/* localdecomp:end func_003EF1B8 */

/* localdecomp:start func_003EF250 */
__asm__(".extern D_001D9760_g, 4");
extern s32 D_001D9760_g;
extern s32 func_003EDBA8(s32, s32);
s32 func_003EF250(s32 p, s32 k) {
    if (k != D_001D9760_g) return func_003EDBA8(p, k);
    return 1;
}
/* localdecomp:end func_003EF250 */

/* localdecomp:start func_003EF280 */
extern s32 D_001D9760_g;
s32 func_003EF280(void) {
    return D_001D9760_g;
}
/* localdecomp:end func_003EF280 */

/* localdecomp:start func_003EF288 */
void func_003EF288(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x38) = a1;
    *(s32 *)((u8 *)a0 + 0x3c) = a2;
    *(s32 *)((u8 *)a0 + 0x40) = a3;
    *(s32 *)((u8 *)a0 + 0x44) = a4;
}
/* localdecomp:end func_003EF288 */

/* localdecomp:start func_003EF2A0 */
void func_003EF2A0(u8 *p, f32 *a) {
    *(f32 *)(p + 0x10) = a[0] + (a[2] - a[0]) * 0.5f;
    *(f32 *)(p + 0x14) = a[1] + (a[3] - a[1]) * 0.5f;
}
/* localdecomp:end func_003EF2A0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EF2E0);

typedef struct { s32 f0; s32 *vt4; } OB_3EA078;
typedef struct { u8 p0[8]; s32 f8; s32 fC; } PP_3EA078;
typedef struct { u8 pad0[0x20]; f32 f20, f24; s32 f28; f32 f2C; u8 pad1[0x8]; s32 f38; u8 pad2[0x14]; OB_3EA078 *f50; } O_3EA078;
extern f32 D_001D9698;
extern f32 D_001D969C;
extern unsigned long func_0039ACA8(s32);
extern void func_0038B120(s32, s32, s32, s32, s32, s32, s32, s32, f32, unsigned long, unsigned long);
/* localdecomp:start func_003EF5E0 */
extern s32 func_003EDAF8();
extern f32 D_001D9698 __attribute__((section(".rodata")));
extern f32 D_001D969C __attribute__((section(".rodata")));
s32 func_003EF5E0(O_3EA078 *o, f32 *r) {
    OB_3EA078 *ob = o->f50;
    s32 k38;
    if ((ob->f0 ^ 2) == 0) {
        k38 = o->f38;
        if (func_003EDAF8(o, 0x40)) {
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
            res = func_0039ACA8((s32)pp);
            func_0038B120((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C), (s32)(w * D_001D9698), (s32)(h * D_001D969C), 0, 0, a, b, sc, (unsigned long)(u32)k28, res);
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
            res = func_0039ACA8((s32)pp);
            func_0038B120((s32)(x0 * D_001D9698), (s32)(y0 * D_001D969C), (s32)(x1 * D_001D9698), (s32)(y1 * D_001D969C), 0, 0, a, b, sc, (unsigned long)(u32)k38, res);
        }
    }
    return 0;
}
/* localdecomp:end func_003EF5E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003EF7F8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CC30);

typedef struct { u8 b[16]; } B16_3EA648;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648;
extern s32 func_0011A264(void *, s32, s32);
/* localdecomp:start func_003EFBB0 */
/* US draft of func_003EFBB0 (rac3-uya-decomp func_003EA648, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


typedef struct { u8 b[16]; } B16_3EA648_3EFBB0;
typedef struct { u8 pad[0x10]; f32 f10, f14, f18, f1C, f20, f24; } O_3EA648_3EFBB0;
extern s32 func_0011A264(void *, s32, s32);
extern s32 func_003EDAF8(void *, s32);
extern void func_003EDB40(void *, s32 *, s32 *);
void func_003EFBB0(O_3EA648_3EFBB0 *o, f32 *p, f32 *out, s32 flag) {
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
        func_003EDB40(o, &k1, &k2);
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
    if (func_003EDAF8(o, 0x40)) {
        dx = o->f20;
        dy = o->f24;
        func_0011A264(t, 0, 0x10);
        *(B16_3EA648_3EFBB0 *)t = *(B16_3EA648_3EFBB0 *)out;
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
/* localdecomp:end func_003EFBB0 */

/* localdecomp:start func_003EFE10 */
s32 func_003EFE10(void *arg0, s32 arg1) {
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
/* localdecomp:end func_003EFE10 */

/* localdecomp:start func_003EFE98 */
void func_003EFE98(void *p, s32 v) {
    *((u8 *)p + 0x4C) = v;
    if ((u8)v == 0) {
        *((u8 *)p + 0x4C) = 1;
    }
}
/* localdecomp:end func_003EFE98 */
