#include "common.h"
#include "vu0.h"

/* declared by functions of L07_003A9DB0.c, which this file was cut from */
void func_L07_00334740(void *);
void func_L07_00334800();
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

/* localdecomp:start func_L07_003ACA00 */
void func_L07_00334740(void *);
void func_L07_003ACA90(void *, s32);

void func_L07_003ACA00(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    *(s32 *)(d + 0x56C) = 0;
    *(s32 *)(d + 0x188) &= ~0x10;
    func_L07_00334740(obj);
    func_L07_003ACA90(obj, 1);
}
/* localdecomp:end func_L07_003ACA00 */

/* localdecomp:start func_L07_003ACA48 */
void func_L07_00334800();
void func_L07_003ACA90(void *, s32);

void func_L07_003ACA48(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003ACA90(arg0, 2);
}
/* localdecomp:end func_L07_003ACA48 */

/* localdecomp:start func_L07_003ACA90 */
void func_L07_003ACA90(void *obj, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L07_003AD058(void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    u8 *p = obj;
    u8 *s = *(u8 **)(p + 0x68);
    f32 r;
    switch (state) {
    case 1: break;
    case 2:
        if (p[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        break;
    case 4:
        if (p[0x43] != 4) func_003C3A10(obj, 4, 0, 4);
        *(f32 *)(s + 0x170) = 0.0026000002399086952f;
        *(f32 *)(s + 0x174) = 0.0026000002399086952f;
        *(f32 *)(s + 0x178) = 0.1300000101327896f;
        *(u16 *)(p + 0x34) |= 0x5000;
        break;
    case 6:
        if (p[0x43] != 3) func_003C3A10(obj, 3, 0, 4);
        break;
    case 7:
        *(f32 *)(s + 0x170) = 0.0026000002399086952f;
        *(f32 *)(s + 0x174) = 0.0026000002399086952f;
        *(f32 *)(s + 0x178) = 0.1300000101327896f;
        if (p[0x43] != 4) func_003C3A10(obj, 4, 0, 4);
        break;
    case 8:
        *(u32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 0.0014000000664964318f;
        *(f32 *)(s + 0x174) = 0.0014000000664964318f;
        *(f32 *)(s + 0x178) = 0.07000000774860382f;
        if (p[0x43] != 3) func_003C3A10(obj, 3, 0, 4);
        break;
    case 10:
        *(s16 *)(s + 0x564) = 0;
        func_L07_003AD058(obj);
        s[0x566] = 0;
        r = func_003824E0(0.0f, 1.0f);
        if (r < 0.5f) {
            s[0x567] = 1;
            if (p[0x43] != 5) func_003C3A10(obj, 5, 0, 2);
        } else if (r < 1.0f) {
            s[0x567] = 2;
            if (p[0x43] != 6) func_003C3A10(obj, 6, 0, 2);
        } else {
            s[0x567] = 3;
            if (p[0x43] != 7) func_003C3A10(obj, 7, 0, 2);
            state = 11;
        }
        break;
    case 12:
        if (p[0x43] != 8) func_003C3A10(obj, 8, 0, 2);
        break;
    case 13:
        *(u32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 0.0014000000664964318f;
        *(f32 *)(s + 0x174) = 0.0014000000664964318f;
        *(f32 *)(s + 0x178) = 0.07000000774860382f;
        if (p[0x43] != 3) func_003C3A10(obj, 3, 0, 4);
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003ACA90 */

/* localdecomp:start func_L07_003ACD58 */
extern s32 D_L07_001DEF40;

void func_L07_003ACD58(u8 *obj, f32 dt)
{
    extern void func_L03_0032FAF0(void *, void *, f32, f32);
    extern void func_L07_00333DB8(void *, void *, s32, s32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_L07_00332CF0(void *, void *, void *, f32);
    extern void func_L01_0045A7A8(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
    vu0_v4 vec;
    vu0_v4 old;
    vu0_v4 delta;
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *pos;
    f32 angle;
    f32 other;

    func_L03_0032FAF0(&vec, s + 0x130, *(f32 *)(s + 0x254), dt);
    if ((D_L07_001DEF40 & 7) == (((s32)obj >> 8) & 7)) {
        func_L07_00333DB8(*(void **)(s + 0x240), obj, 0, 0, dt);
        *(f32 *)(s + 0x258) = func_L07_00332CF0(*(void **)(s + 0x240), obj, &vec,
            func_0038DB00(*(f32 *)(s + 0x250), *(f32 *)(s + 0x254)) * 0.25f);
    }
    *(vu0_q *)&old = *(vu0_q *)(obj + 0x10);
    pos = obj + 0x10;
    func_L01_0045A7A8(obj, &vec, *(f32 *)(s + 0x258));
    vec_sub_ba(&delta, obj + 0x10, &old);
    *(f32 *)(s + 0x56C) = func_0038DAB8(*(f32 *)(s + 0x56C), func_0038CE68(&delta, obj + 0xC0) / 0.3f);
    if ((*(s32 *)(s + 0x188) & 0x10) && func_L01_0040E570(&old, pos) > 0.0001f) {
        angle = func_0038D160(*(f32 *)(obj + 0x10) - old.x, *(f32 *)(obj + 0x14) - old.y);
        other = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(s + 0x134) - *(f32 *)(obj + 0x14));
        if (func_0038DBA0(other, angle) > 1.5707964f) {
            angle = func_0038DAB8(angle, 3.1415927f);
        }
        func_L01_00448890(obj + 0xF8, s + 0x204, 0, angle, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    }
}
/* localdecomp:end func_L07_003ACD58 */

/* localdecomp:start func_L07_003ACF40 */
typedef struct {
    u8 pad_0[0x25C0];
    void *moby;         /* 0x25C0 */
} S_003ACF40_HERO;

extern S_003ACF40_HERO D_001A4BE0;
extern void *D_001ECC80[];

extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern s32 func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);

void func_L07_003ACF40(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    f32 v[3];
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i < 2; i++) {
        if ((s[0x567] >> i) & 1) {
            func_003C2F58(arg0, i, v);
            n = func_L01_00446780(arg0, v, 0x10001, 0, 1, 0, 0.5625f, (f32)s[0x44], 1.0f);
            for (j = 0; j < n; j++) {
                if (D_001ECC80[j] == D_001A4BE0.moby) {
                    s[0x566] = 1;
                    break;
                }
            }
        }
    }
}
/* localdecomp:end func_L07_003ACF40 */

/* localdecomp:start func_L07_003AD058 */
void func_L07_003AD058(void *arg0) {
    s32 var_v1;
    void *var_v0;

    var_v1 = 1;
    var_v0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x560;
    do {
        *(s8 *)((u8 *)var_v0 + 2) = 0;
        var_v1 -= 1;
        (*(s8 *)var_v0) = 0;
        var_v0 += 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_L07_003AD058 */

/* localdecomp:start func_L07_003AD088 */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

void func_L07_003AD088(void *arg0) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *p = s + 0x562;
    u8 *q = s + 0x560;
    s32 ten = 10;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s[0x567] >> i) & 1) {
            u8 *t = q + i;
            u8 *r = s + 0x562;
            if (++p[i - 2] > 10) {
                p[i - 2] = ten;
                p[i] = (p[i] + 1) % ten;
            }
            func_003C2F58(arg0, i, (f32 *)(s + 0x420 + i * 0xA0 + ((r[i] + *t - 1) % ten) * 16));
        }
    }
}
/* localdecomp:end func_L07_003AD088 */

/* localdecomp:start func_L07_003AD180 */
void func_L07_003AD210(void *, void *, s32, s32, s32);

void func_L07_003AD180(void *arg0) {
    u8 *s2 = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *p = s2 + 0x562;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s2[0x567] >> i) & 1) {
            func_L07_003AD210(arg0, s2 + 0x420 + i * 0xA0, p[-2], p[0], s2[0x568] + 0x64);
        }
        p++;
    }
}
/* localdecomp:end func_L07_003AD180 */

INCLUDE_ASM("asm/levels", func_L07_003AD210);
