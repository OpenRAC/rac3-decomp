#include "common.h"

/* localdecomp:start func_L03_003B1E38 */
typedef int Q_003B1E38 __attribute__((mode(TI)));
extern s32 D_001D6694;
__asm__(".extern D_001D6694, 16");
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern s32 func_L01_004BA800(void);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L03_003B2158(void *);
extern void func_L03_003B2518(void *);

void func_L03_003B1E38(u8 *obj) {
    u8 *v;
    u8 *p;

    v = *(u8 **)(obj + 0x68);
    if (D_001D6694 == 2) {
        obj[0x31] = 0;
        *(u16 *)(obj + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        obj[0x31] = 1;
        *(u16 *)(obj + 0x34) &= ~1;
    }
    switch (obj[0x20]) {
    case 0:
        if (D_001426E0[0x3D] != 0 && D_001426E0[0x85] == 0) {
            p = D_L03_001DFA80 + (*(s32 *)(v + 0x120) << 7);
            *(Q_003B1E38 *)(obj + 0x10) = *(Q_003B1E38 *)(p + 0x30);
            *(Q_003B1E38 *)(obj + 0xF0) = *(Q_003B1E38 *)(p + 0x70);
            if (obj[0x43] != 0) {
                func_003C3A10(obj, 0, 0, 8);
            }
            func_L01_004450F0(obj, 1, -1);
        } else if (D_00142CA0[0x1E] != 0) {
            if (obj[0x43] != 1) {
                func_003C3A10(obj, 1, 0, 8);
            }
            func_L01_004450F0(obj, 2, -1);
        } else {
            func_003C2880(obj);
            return;
        }
        break;
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(obj)) {
            if (obj[0x43] != 1) {
                func_003C3A10(obj, 1, 0, 8);
            }
            *(s32 *)(v + 0x12C) = (func_00382498(600, 800) * 5 + 2) / 6;
        }
        if (*(s32 *)(v + 0x114) == 0 && func_0038CAD0(v + 0x12C)) {
            *(s32 *)(v + 0x12C) = (func_00382498(600, 800) * 5 + 2) / 6;
            if (obj[0x43] != 2) {
                func_003C3A10(obj, 2, 0, 0x11);
            }
        }
        if ((obj[0x60] & 2) && obj[0x43] != 1) {
            func_003C3A10(obj, 1, 0, 0x11);
        }
        break;
    case 3:
        if (func_L01_004561B8(obj) && obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 8);
        }
        break;
    case 4:
        if (func_L01_004561B8(obj) && obj[0x43] != 4) {
            func_003C3A10(obj, 4, 0, 8);
        }
        break;
    case 5:
        if (func_L01_004561B8(obj) && obj[0x43] != 5) {
            func_003C3A10(obj, 5, 0, 8);
        }
        break;
    }
    func_L03_003B2158(obj);
    if (D_00142CA0[0x1E] != 0 && obj[0x20] != 1) {
        func_L03_003B2518(obj);
    }
}
/* localdecomp:end func_L03_003B1E38 */

/* localdecomp:start func_L03_003B2158 */
#include "vu0.h"

typedef int Q_003B2158 __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern u8 D_001A4CC0[];
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

/* PROVISIONAL, VU0 j-constraint form. Both paths share the vector subtraction. */
static __inline__ void aim_load_target_003B2158(vu0_q *x, vu0_q *y, const void *a, const void *b) {
    __asm__("lqc2 %1, %3\n\tlqc2 %0, %2"
            : "=j"(*x), "=j"(*y) : "m"(*(const vu0_v4 *)a), "m"(*(const vu0_v4 *)b));
}

static __inline__ void aim_load_adjusted_003B2158(vu0_q *x, vu0_q *y, const void *a, const void *b) {
    __asm__("lqc2 %0, %2\n\tlqc2 %1, %3"
            : "=j"(*x), "=j"(*y) : "m"(*(const vu0_v4 *)a), "m"(*(const vu0_v4 *)b));
}

void func_L03_003B2158(void *arg) {
    u8 *s = arg;
    u8 *t;
    f32 k1;
    f32 k2;
    f32 dir[4];
    f32 tgt[4];
    f32 pos[4];
    u8 *h;
    f32 ang;
    f32 yaw;
    f32 pitch;

    t = *(u8 **)(s + 0x68);
    k1 = 0.02f;
    k2 = 0.3f;
    if (s[0x42] == 2) {
        yaw = 0.0f;
        pitch = yaw;
    } else {
        vu0_q x, y, result;
        if (*(s32 *)(t + 0x128) != 0) {
            aim_load_target_003B2158(&x, &y, t + 0x100, s + 0x10);
        } else {
            if (func_0038CF38(s + 0x10, D_001A4C60) < 8.0f) {
                h = D_001A4C60 - 0x80;
                ang = func_0038D160(*(f32 *)(h + 0xE0) - *(f32 *)(s + 0x10), *(f32 *)(h + 0xE4) - *(f32 *)(s + 0x14));
                if (func_0038DBA0(*(f32 *)(s + 0xF8), ang) < 1.5707964f) {
                    if (func_0038CEA8(D_001A4C60 + 0x90) > 0.01f) {
                        *(s32 *)(t + 0x114) = 100;
                    } else {
                        func_0038CAD0(t + 0x114);
                    }
                    goto timer;
                }
            }
            if (*(s32 *)(t + 0x114) != 0) {
                *(s32 *)(t + 0x114) = 0;
                *(Q_003B2158 *)(t + 0x100) = *(Q_003B2158 *)D_001A4CC0;
            }
        timer:
            if (func_0038CAD0(t + 0x118)) {
                vec_add_ab(t + 0x100, s + 0x10, s + 0xC0);
            }
            if (*(s32 *)(t + 0x114) != 0) {
                k1 = 0.04f;
                k2 = 0.3f;
                *(Q_003B2158 *)tgt = *(Q_003B2158 *)D_001A4CC0;
            } else {
                *(Q_003B2158 *)tgt = *(Q_003B2158 *)(t + 0x100);
            }
            *(Q_003B2158 *)pos = *(Q_003B2158 *)(s + 0x10);
            pos[2] += 2.0f;
            aim_load_adjusted_003B2158(&x, &y, tgt, pos);
        }
        __asm__("vsub.xyz %0, %1, %2" : "=j"(result) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)dir) : "j"(result));
        yaw = func_0038DB00(func_0038D160(dir[0], dir[1]), *(f32 *)(s + 0xF8));
        pitch = -func_0038D160(func_0038CED8(dir), dir[2]);
    }
    if (yaw > 1.2217305f) {
        yaw = 1.2217305f;
    } else if (yaw < -1.2217305f) {
        yaw = -1.2217305f;
    }
    if (pitch > 0.5235988f) {
        pitch = 0.5235988f;
    } else if (pitch < -0.5235988f) {
        pitch = -0.5235988f;
    }
    *(f32 *)(t + 0x68) = yaw * 0.8f;
    *(f32 *)(t + 0xE8) = yaw * 0.2f;
    *(f32 *)(t + 0x64) = pitch;
    func_L01_0044E850(s, t, 0, k1 * 1.44f, k2 * 1.44f);
    func_L01_0044E850(s, t + 0x80, 1, k1 * 1.44f, k2 * 1.44f);
}
/* localdecomp:end func_L03_003B2158 */
