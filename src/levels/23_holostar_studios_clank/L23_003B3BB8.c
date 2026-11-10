#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 pos[2]; s32 color0; s32 x24; s32 color1; } Sparks;
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 id; u8 pad4[0xC]; u128_t pos; u8 path[0x10]; } Vars_3B5068;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xC];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3B5068 *vars;
} Moby_3B5068;

INCLUDE_ASM("asm/levels", func_L23_003B3BB8);

INCLUDE_ASM("asm/levels", func_L23_003B3EA8);

INCLUDE_ASM("asm/levels", func_L23_003B4108);

/* localdecomp:start func_L23_003B44E8 */
void func_L23_003B44E8(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x390) = 0;
}
/* localdecomp:end func_L23_003B44E8 */

INCLUDE_ASM("asm/levels", func_L23_003B44F8);

INCLUDE_ASM("asm/levels", func_L23_003B48D0);

INCLUDE_ASM("asm/levels", func_L23_003B4AD0);

/* localdecomp:start func_L23_003B5068 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E001C;
__asm__(".extern D_L23_001E001C, 16");
extern u8 *D_L23_001E0014_3B5068;
__asm__(".extern D_L23_001E0014_3B5068, 4");
extern s16 D_L23_0023A3C0[];
extern Moby_3B5068 *D_L23_001DE410;
__asm__(".extern D_L23_001DE410, 4");
extern s32 D_L23_001DE134;
__asm__(".extern D_L23_001DE134, 4");
extern f32 func_0038CEA8(f32 *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B5068(Moby_3B5068 *o)
{
    Vars_3B5068 *v = o->vars;
    u16 *p;
    u8 *e;
    u8 *found = 0;

    p = D_L23_001D6764[v->id];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
        e = D_L23_001E001C + ((*p & 0x7FFF) << 6);
        if (e == 0)
            break;
        if (D_L23_0023A3C0[(D_L23_001E0014_3B5068 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1D21) {
            found = e;
            break;
        }
        p++;
    }
    o->pos = *(u128_t *)(found + 0x30);
    o->scale *= func_0038CEA8((f32 *)(found + 0x20));
    o->x34 |= 0x41;
    if (D_L23_001DE410 == 0)
        D_L23_001DE410 = o;
    v->pos = o->pos;
    D_L23_001DE134 = 0;
    func_L01_0044ED88(o, v->path, 0x10, -1, v->id, -1, 7, 0);
    o->x34 |= 0x41;
    func_L01_004450F0(o, 1, -1);
}
/* localdecomp:end func_L23_003B5068 */

/* localdecomp:start func_L23_003B51C0 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_00382498(s32 a, s32 b);

u8 *func_L23_003B51C0(u8 *object, u8 *skip, f32 radius) {
    u8 *list[64];
    s32 n = 0;
    u16 *p;
    u8 *e;
    if (object == 0)
        return 0;
    {
        p = D_L23_0021C0E0[object[0x21]];
        while (object[0x21] != 0xFF && object[0x21] <= D_L23_001DF198 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[object[0x21]])) {
            e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            if (n < 0x40 && e != skip && e[0x20] < 3 && func_L01_0040E570(object + 0x10, e + 0x10) < radius) {
                list[n++] = e;
            }
            p++;
        }
    }
    if (n > 0)
        return list[func_00382498(0, n - 1)];
    return 0;
}
/* localdecomp:end func_L23_003B51C0 */

INCLUDE_ASM("asm/levels", func_L23_003B5318);

/* localdecomp:start func_L23_003B54A0 */
extern u16 **D_L23_001D6764;
extern u8 *D_L23_001E0014;
extern s16 D_L23_0023A3C0[];

s32 func_L23_003B54A0(s32 arg0) {
    u16 *p;
    u8 *e;

    p = D_L23_001D6764[arg0];
    while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[arg0])) {
        e = D_L23_001E0014 + ((*p & 0x7FFF) << 5);
        if (e == 0) {
            break;
        }
        if (D_L23_0023A3C0[e[0x1D]] == 0x1D21) {
            return 1;
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L23_003B54A0 */

/* localdecomp:start func_L23_003B5538 */
__asm__(".extern D_L23_001DE3B0, 4");
__asm__(".extern D_L23_001DE420, 4");
__asm__(".extern D_L23_001DE424, 4");
__asm__(".extern D_L23_001DE428, 4");
extern s32 D_L23_001DE3B0;
extern s32 D_L23_001DE420;
extern f32 D_L23_001DE424;
extern f32 D_L23_001DE428;
extern Sparks D_L23_002A3A80;
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L23_003B5538(void)
{
    s32 i;
    u32 color;
    f32 size;

    func_L01_0040C948(&D_L23_002A3A80, &D_L23_001DE3B0);
    for (i = 0; i < 2; i++) {
        color = func_0038DBD8(D_L23_002A3A80.color0, D_L23_002A3A80.color1, func_003824E0(0.0f, 1.0f)) | 0x60000000;
        size = D_L23_001DE428 * func_003824E0(0.75f, 1.25f);
        func_003D9508(&D_L23_002A3A80.pos[i], D_L23_001DE420, color, 1, size, D_L23_001DE424, func_003824E0(-3.1415927f, 3.1415927f));
    }
}
/* localdecomp:end func_L23_003B5538 */

INCLUDE_ASM("asm/levels", func_L23_003B5628);

/* localdecomp:start func_L23_003B5760 */
extern void func_L23_003B67B0(void *owner, void *p, int z, float f, float g);

void func_L23_003B5760(unsigned char *owner)
{
    func_L23_003B67B0(owner, owner + 0x10, 0, *(float *)(owner + 0xF8), 0.0f);
}
/* localdecomp:end func_L23_003B5760 */

/* localdecomp:start func_L23_003B5788 */
extern void func_L23_003B67B0(void *, void *, int, float, float);

void func_L23_003B5788(char *obj, float x) {
    func_L23_003B67B0(obj, *(char **)(obj + 0x68) + 0x320, 3, *(float *)(obj + 0xF8), x);
}
/* localdecomp:end func_L23_003B5788 */

INCLUDE_ASM("asm/levels", func_L23_003B57B8);

INCLUDE_ASM("asm/levels", func_L23_003B6390);

INCLUDE_ASM("asm/levels", func_L23_003B65F0);

INCLUDE_ASM("asm/levels", func_L23_003B67B0);

/* localdecomp:start func_L23_003B6990 */
extern u8 D_001A4BE0[];
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L03_00433C70(void *, Vec4 *, Vec4 *, s32, f32, f32, s32, s32, s32);

void func_L23_003B6990(u8 *obj) {
    u8 *vars = *(u8 **)(obj + 0x68);
    Vec4 a;
    Vec4 b;
    u8 inRange = 0;
    f32 d;

    if (*(s32 *)(vars + 0x2CC) == 1) {
        func_003C2F58(obj, 1, &a);
        func_003C2F58(obj, 2, &b);
        d = func_L01_004395E0(obj);
        inRange = (10.0f <= d && d <= 16.0f);
    }
    if (*(s32 *)(vars + 0x304) == 0 && *(u8 **)(D_001A4BE0 + 0x2808) == obj) {
        *(s32 *)(vars + 0x304) = 1;
    }
    if (inRange) {
        func_L03_00433C70(obj, &a, &b, 1, 1.0f, 1.0f, 0, 1, 0);
    }
}
/* localdecomp:end func_L23_003B6990 */

/* localdecomp:start func_L23_003B6A80 */
void func_0038CAD0(s32);

void func_L23_003B6A80(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CAD0(temp_s0 + 0x2C0);
    func_0038CAD0(temp_s0 + 0x2C4);
    func_0038CAD0(temp_s0 + 0x300);
}
/* localdecomp:end func_L23_003B6A80 */

INCLUDE_ASM("asm/levels", func_L23_003B6AD0);

/* localdecomp:start func_L23_003B6C90 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

void func_L23_003B6C90(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L23_0021C0E0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L23_001DF198 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L23_0021C0E0[a0[0x21]])) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && a0[0x95] == 2) {
            func_L01_004450F0(e, 6, 3);
        }
        p++;
    }
}
/* localdecomp:end func_L23_003B6C90 */

/* localdecomp:start func_L23_003B6D78 */
extern u16 *D_L23_0021C0E0[];
extern u8 *D_L23_001DF15C;
__asm__(".extern D_L23_001DF15C, 16");
extern s32 D_L23_001DF198;
__asm__(".extern D_L23_001DF198, 16");
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003B6D78(s32 a0) {
    u16 *p;
    u8 *e;

    p = D_L23_0021C0E0[a0];
    if ((a0 & 0xFF) == 0xFF || a0 > D_L23_001DF198 || p == 0) {
        return;
    }
    for (;;) {
        e = D_L23_001DF15C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            return;
        }
        if (*(s16 *)(e + 0xAA) == 0x1BE3 && e[0x95] == 1) {
            func_L01_004450F0(e, 4, 2);
        }
        p++;
        if ((a0 & 0xFF) == 0xFF) {
            return;
        }
        if (a0 > D_L23_001DF198) {
            return;
        }
        if (p == 0) {
            return;
        }
        if ((s16)p[-1] >= 0) {
            continue;
        }
        if (p == D_L23_0021C0E0[a0]) {
            continue;
        }
        return;
    }
}
/* localdecomp:end func_L23_003B6D78 */
