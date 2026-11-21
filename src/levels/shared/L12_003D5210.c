#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L12_003D4B18.c, which this file was cut from */
extern f32 func_0038CEA8(void *);

/* localdecomp:start func_L12_003D5210 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D5210;
__asm__(".extern D_L12_001DEF6C, 4");
extern f32 D_L12_001DEF6C;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_004669B0(void *, s32, void *, u32, s32, f32, f32, f32, f32);
extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);

void func_L12_003D5210(u8 *m, void *dir, V4_003D5210 *at) {
    V4_003D5210 pos;
    V4_003D5210 vel;
    V4_003D5210 p;
    V4_003D5210 d;
    s32 r;
    u32 color;
    f32 speed;
    f32 s;

    pos = *at;
    p = *(V4_003D5210 *)(m + 0x10);
    func_0038CE20(&p, m + 0xC0, -1.2f);
    vec_add_ab(&p, &p, m + 0x10);
    speed = func_0038CEA8(dir) * D_L12_001DEF6C;
    func_0038CE20(&vel, m + 0xC0, speed);
    r = func_00382498(0x20, 0x40);
    color = 0x7F000000 | ((r + 8) << 16) | (r << 8) | r;
    func_L01_004669B0(&p, func_00382498(0, 2) - 1, &vel, color, 0, 0.25f, 0.8f, 1.01f, func_003824E0(0.75f, 1.0f) * 210000.0f);
    vec_sub_ba(&d, m + 0x10, &pos);
    func_0038CE20(&d, &d, 0.5f);
    vec_add_ab(&p, &p, &d);
    r = func_00382498(0x40, 0x80);
    color = 0x40000000 | (r << 16) | (r << 8) | r;
    s = func_003824E0(1.25f, 1.75f) * 210000.0f;
    func_L01_004668A0(&p, &vel, color, 0x101010, (func_00382498(0x19, 0x1E) * 5 + 2) / 6, s);
}
/* localdecomp:end func_L12_003D5210 */

/* localdecomp:start func_L12_003D5418 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003D5418;

extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00448690(void *, s32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L12_003D5418(void *arg0, void *arg1, void *arg2, f32 speed) {
    u8 *o = arg0;
    u8 *m = arg1;
    V4_003D5418 t;
    V4_003D5418 d;
    f32 s;
    f32 yaw;

    t = *(V4_003D5418 *)arg2;
    vec_sub_ba(&d, &t, o + 0x10);
    s = speed * 1.3f;
    if (o[0x20] == 3) {
        s *= 1.5f;
        yaw = 1.5707964f;
    } else {
        yaw = -func_0038D160(func_0038CED8(&d), d.z);
        if (o[0x20] == 2) {
            s *= 0.75f;
        }
    }
    func_L01_00448690(o + 0xF4, 0, yaw, s);
    if (o[0x20] == 3) {
        speed *= 0.25f;
    } else if (o[0x20] == 2) {
        speed *= 0.5f;
    }
    yaw = func_0038D160(d.x, d.y);
    func_L01_00448690(o + 0xF8, 0, yaw, speed);
    func_0038D308(o + 0xC0, o + 0xF0);
    func_0038CE20(m, o + 0xC0, *(f32 *)(m + 0x38));
}
/* localdecomp:end func_L12_003D5418 */

/* localdecomp:start func_L12_003D5570 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern vu0_v4 D_001A4CB0;
extern vu0_v4 D_001A4D00;
__asm__(".extern D_L12_001DEF74, 4");
extern f32 D_L12_001DEF74;
__asm__(".extern D_L12_001DEF78, 4");
extern f32 D_L12_001DEF78;
__asm__(".extern D_L12_001DEF7C, 4");
extern f32 D_L12_001DEF7C;
__asm__(".extern D_L12_001DEF80, 4");
extern f32 D_L12_001DEF80;
__asm__(".extern D_L12_001DEF88, 4");
extern f32 D_L12_001DEF88;
__asm__(".extern D_L12_001DEF8C, 4");
extern f32 D_L12_001DEF8C;
__asm__(".extern D_L12_001DEF94, 4");
extern f32 D_L12_001DEF94;
__asm__(".extern D_L12_001DEF98, 4");
extern f32 D_L12_001DEF98;
__asm__(".extern D_L12_001DEF9C, 4");
extern f32 D_L12_001DEF9C;
__asm__(".extern D_L12_001DEFA0, 4");
extern f32 D_L12_001DEFA0;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern u8 *func_00382348(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L12_003D5418(void *, void *, void *, f32);

void func_L12_003D5570(u8 *o, u8 *p) {
    vu0_v4 dir;
    vu0_v4 delta;
    vu0_v4 goal;
    vu0_v4 point;
    u8 *e;
    u8 *ride;
    u8 *info;
    u8 *tgt;
    s32 riding1A17;
    s32 riding;
    f32 d;
    f32 len;
    f32 k;

    riding1A17 = 0;
    riding = 0;
    e = *(u8 **)(p + 0x28);
    if (e == 0) {
        if ((u32)(o[0x20] - 2) >= 2) {
            return;
        }
        *(u128_t *)&goal = *(u128_t *)(p + 0x10);
    } else {
        u8 *h = D_001A4BE0;

        if (e == *(u8 **)(h + 0x25C0)) {
            if (*(s32 *)(h + 0x2850) <= 0) {
                *(s32 *)(p + 0x28) = 0;
                return;
            }
            ride = *(u8 **)(h + 0x19E0);
            if (ride != 0) {
                *(u128_t *)&goal = *(u128_t *)(h + 0xD0);
                if (*(s16 *)(ride + 0xAA) == 0x1A17) {
                    riding1A17 = 1;
                } else {
                    riding = 1;
                }
            }
            if (riding1A17 == 0 && (riding != 0 || o[0x20] == 3 || o[0x20] == 2)) {
                *(u128_t *)&goal = *(u128_t *)&D_001A4CB0;
            } else {
                if (riding1A17 != 0) {
                    u8 *hero = D_001A4BE0;

                    func_0038CE20(&dir, *(u8 **)(*(u8 **)(*(u8 **)(hero + 0x19E0) + 0x68) + 0x6D0) + 0xC0, 0.5f);
                } else {
                    *(u128_t *)&dir = *(u128_t *)&D_001A4D00;
                }
                d = func_0038CF00(&D_001A4CB0, o + 0x10);
                func_0038CE20(&delta, &dir, d / *(f32 *)(p + 0x38));
                delta.z = 0.0f;
                vec_add_ab(&goal, &D_001A4CB0, &delta);
                vec_sub_ab(&delta, &goal, o + 0x10);
                vec_sub_ab(&dir, &D_001A4CB0, o + 0x10);
                if (func_0038CE68(&delta, &dir) < 0.3f) {
                    *(u128_t *)&goal = *(u128_t *)&D_001A4CB0;
                }
            }
        } else {
            info = func_00382348(e);
            if (info != 0 && *(f32 *)info <= 0.0f) {
                *(s32 *)(p + 0x28) = 0;
                return;
            }
            tgt = *(u8 **)(p + 0x28);
            if (tgt == 0 || tgt[0x20] == 0xFE || tgt[0x20] == 0xFD) {
                *(s32 *)(p + 0x28) = 0;
                return;
            }
            *(u128_t *)&goal = *(u128_t *)(tgt + 0x10);
            if (info != 0) {
                goal.z = goal.z + *(f32 *)(info + 0x10);
            }
        }
        *(u128_t *)(p + 0x10) = *(u128_t *)&goal;
    }
    vec_sub_ab(&delta, &goal, o + 0x10);
    if (riding1A17 == 0 && o[0x20] == 1) {
        if (func_0038CE68(&delta, o + 0xC0) < 0.0f) {
            *(s32 *)(p + 0x28) = 0;
            if (*(s32 *)(p + 0x24) >= 0x22) {
                *(s32 *)(p + 0x24) = func_00382498(0x11, 0x21);
            }
            return;
        }
    }
    if (riding1A17 != 0) {
        if (func_0038CED8(&delta) < D_L12_001DEF9C) {
            *(u128_t *)&point = *(u128_t *)&goal;
        } else {
            func_0038CF68(&point, &delta, D_L12_001DEFA0);
            vec_add_ab(&point, &point, o + 0x10);
            point.z = goal.z + D_L12_001DEFA0;
        }
        k = D_L12_001DEF98;
    } else if (riding != 0) {
        *(u128_t *)&point = *(u128_t *)&goal;
        k = D_L12_001DEF94;
    } else {
        len = func_0038CED8(&delta);
        if (len < D_L12_001DEF8C) {
            if (o[0x20] != 3) {
                func_L01_004450F0(o, 3, -1);
            }
            *(u128_t *)&point = *(u128_t *)&goal;
            k = D_L12_001DEF88;
        } else if (len < D_L12_001DEF7C) {
            if (o[0x20] == 1) {
                *(s32 *)(o + 0x98) = 0;
                func_L01_004450F0(o, 2, -1);
            }
            func_0038CF68(&point, &delta, D_L12_001DEF78);
            vec_add_ab(&point, &point, o + 0x10);
            point.z = goal.z + D_L12_001DEF80;
            k = D_L12_001DEF88;
        } else {
            if (D_L12_001DEF7C + 0.25f < len) {
                if (o[0x20] == 2) {
                    func_L01_004450F0(o, 1, -1);
                }
            }
            func_0038CF68(&point, &delta, D_L12_001DEF78);
            vec_add_ab(&point, &point, o + 0x10);
            point.z = goal.z + D_L12_001DEF78;
            k = D_L12_001DEF74;
        }
    }
    func_L12_003D5418(o, p, &point, k);
}
/* localdecomp:end func_L12_003D5570 */
