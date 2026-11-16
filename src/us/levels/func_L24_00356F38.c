#include "common.h"

/* NTSC-U counterpart of func_L24_00357F70 (src/levels/24_insomniac_museum/L24_00356100.c) */
#include "vu0.h"
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003BE4F0(void *, s32, s32, s32);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
#include "vu0.h"
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L24_00356F38 */
#include "vu0.h"
extern void func_003C0D70(void *, s32, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, u8 *);
extern s32 func_003C0B10(void *, s32, s32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, u8 *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BF4F8(void *, void *);
extern s32 func_L24_00357CC0(void *);
extern void func_L24_00356D18(u8 *);
extern f32 func_003BFB80(void *, void *, s32);
extern void func_003BFC18(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF910(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern void func_003886E8(f32 *, void *, f32);
extern void func_003C0E10(void *, void *, void *, f32, f32, f32);
extern f32 func_003887A0(void *);
extern void func_00388880(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 D_L24_001D673C_00356F38;

s32 func_L24_00356F38(void *arg0, void *arg1, void *arg2, s32 lvl, s32 anim) {
    u8 *obj = arg0;
    u8 *r = arg1;
    f32 *dir = arg2;
    f32 *t;
    s32 ret;
    s32 id;
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;
    f32 x4;
    f32 x5;
    f32 x6;
    u8 tmp[16];
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 k;
    f32 k2;

    t = *(f32 **)(*(u8 **)(obj + 0x68) + 0x1C);
    if (anim != -1) {
        id = anim;
    }
    x2 = *(f32 *)(r + 0x24);
    x3 = *(f32 *)(r + 0x28);
    x0 = *(f32 *)(r + 0x1C);
    x1 = *(f32 *)(r + 0x20);
    x6 = *(f32 *)(r + 0x2C);
    if (t != 0) {
        *(f32 *)(r + 0x30) = *t;
        *(f32 *)(r + 0x34) = *t;
    }
    r[0x14] = 0;
    ret = 1;
    switch (lvl) {
    default:
    case 1:
        ret = 0;
        r[7] = 0xFF;
        break;
    case 2:
        r[7] = 0xFF;
        if (anim != -1) {
            func_003C0D70(obj, anim, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x78);
            func_003BE4F0(obj, anim, r[0x78], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (func_003C0B10(obj, 0, &id, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x78)) {
            func_003BE4F0(obj, id, r[0x78], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (func_003C0B10(obj, 1, &id, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x78)) {
        } else if (r[0x11] != 0xFF) {
            x0 *= 0.5f;
            x1 *= 0.5f;
            x4 = (s8)r[0x6C];
            x5 = (s8)r[0x6D];
            func_003BE4F0(obj, r[0x11], r[0x78], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else {
            ret = 0;
        }
        break;
    case 3:
        r[7] = 0xFF;
        if (anim != -1) {
            func_003C0D70(obj, anim, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x79);
            func_003BE4F0(obj, anim, r[0x79], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (func_003C0B10(obj, 1, &id, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x79)) {
            func_003BE4F0(obj, id, r[0x79], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (func_003C0B10(obj, 0, &id, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x79)) {
            func_003BE4F0(obj, id, r[0x79], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (r[0x12] != 0xFF) {
            x0 *= 0.75f;
            x1 *= 0.75f;
            x4 = (s8)r[0x6E];
            x5 = (s8)r[0x6F];
            func_003BE4F0(obj, r[0x12], r[0x79], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else {
            ret = 0;
        }
        break;
    case 4:
        r[7] = 0xFF;
        *(u16 *)(r + 0x38) |= 1;
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) &= ~0x1000;
        if (anim != -1) {
            func_003C0D70(obj, anim, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x7A);
            func_003BE4F0(obj, id, r[0x7A], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (func_003C0B10(obj, 3, &id, &x0, &x1, &x2, &x3, &x4, &x5, &x6, r + 0x7A)) {
            func_003BE4F0(obj, id, r[0x7A], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (r[0x16] != 0xFF) {
            x4 = (s8)r[0x72];
            x5 = (s8)r[0x73];
            func_003BE4F0(obj, r[0x16], r[0x7A], 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else {
            ret = 0;
        }
        break;
    case 6:
        ret = 0;
        break;
    case 5:
        r[7] = 0xFF;
        *(u16 *)(r + 0x38) |= 2;
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) &= ~0x1000;
        if (anim != -1) {
            func_003C0D70(obj, anim, &x0, &x1, &x2, &x3, &x4, &x5, &x6, tmp);
            func_003BE4F0(obj, id, 0, 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (func_003C0B10(obj, 4, &id, &x0, &x1, &x2, &x3, &x4, &x5, &x6, tmp)) {
            func_003BE4F0(obj, id, 0, 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else if (r[0x17] != 0xFF) {
            x0 *= 1.5f;
            x1 *= 1.5f;
            x4 = (s8)r[0x72];
            x5 = (s8)r[0x73];
            func_003BE4F0(obj, r[0x17], 0, 3);
            *(f32 *)(obj + 0x44) = *(f32 *)(obj + 0x4C);
        } else {
            ret = 0;
        }
        *(f32 *)(r + 0x90) = 0.10471976548433304f;
        *(f32 *)(r + 0x94) = 0.41887906193733215f;
        break;
    }
    if (func_L24_00357CC0(obj) == 0) {
        func_003BF4F8(obj, r);
    } else {
        func_L24_00356D18(obj);
    }
    if (ret != 0) {
    if (lvl != 1) {
        if (D_L24_001D673C_00356F38 != 0) {
            k = func_003BFB80(obj, dir, 0);
            if (k < 1.0f) {
                k = 1.0f;
            }
            func_003BFC18(obj + 0x10, v30, 0);
            func_00388830(v50, dir, -1.0f);
            func_003BF910(v50, r + 0x64);
            k2 = func_00388730(v30, dir);
            func_00388830(v40, v30, k2);
            vec_sub_ab(dir, dir, v40);
            if (func_00388770(dir) < 1.0f) {
                func_00388830(dir, dir, 1.0f);
            }
            func_003886E8((f32 *)(r + 0x80), dir, x0);
            func_00388830(v40, v30, -x1 * k);
            vec_add_ab(r + 0x80, r + 0x80, v40);
        } else {
            func_003C0E10(obj, dir, dir, 5.0f, 0.7853982f, 4.0f);
            if (func_003887A0(dir) < 1.0f) {
                func_00388880(dir, dir, 1.0f);
            }
            if (dir[2] < 1.0f) {
                dir[2] = 1.0f;
            }
            *(f32 *)(r + 0x80) = dir[0] * x0;
            *(f32 *)(r + 0x84) = dir[1] * x0;
            *(f32 *)(r + 0x88) = dir[2] * x1;
            *(f32 *)(r + 0x64) = func_00389380(func_00388A28(dir[0], dir[1]), 3.14159f);
        }
        if (r[0x76] != 0 && lvl < 4) {
            *(f32 *)(r + 0x4C) = 0.0f;
            *(f32 *)(r + 0x50) = 0.0f;
            *(f32 *)(r + 0x54) = -1.0f;
            *(f32 *)(r + 0x60) = -1.0f;
        } else {
            *(f32 *)(r + 0x54) = x4;
            *(f32 *)(r + 0x60) = x5;
            *(f32 *)(r + 0x4C) = x2;
            *(f32 *)(r + 0x50) = x3;
            *(f32 *)(r + 0x2C) = x6;
        }
    }
    return 1;
    }
    return 0;
}
/* localdecomp:end func_L24_00356F38 */
