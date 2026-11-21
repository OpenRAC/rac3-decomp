#include "common.h"

/* declared by functions of L35_003A29A8.c, which this file was cut from */
extern u8 D_001A4BE0[];
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L35_003A3FC8(u8 *);
extern void func_L35_003A3D10(u8 *);
extern void func_L35_003A4180(u8 *, s32);
extern void func_L35_003A3E40(u8 *);

/* localdecomp:start func_L35_003A3D10 */
#include "vu0.h"

extern s32 func_00382498(s32, s32);
extern void func_003C2F58(void *, s32, void *);

extern f32 func_L30_0034C9F8(void *);
extern u8 *D_L35_001DF980;

typedef struct {
    s32 a;
    s32 b;
    f32 da;
    f32 db;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
} E_003A3D10;

void func_L35_003A3D10(u8 *m) {
    u8 *v;
    E_003A3D10 *e;
    vu0_v4 d;

    v = *(u8 **)(m + 0x68);
    if (*(s32 *)(v + 0x184) != 0) {
        *(s32 *)(v + 0x180) = func_00382498(0, *(s32 *)(v + 0x188) - 1);
    } else {
        *(s32 *)(v + 0x180) = (*(s32 *)(v + 0x180) + 1) % *(s32 *)(v + 0x188);
    }
    e = (E_003A3D10 *)(v + 0x100) + *(s32 *)(v + 0x180);
    if (e->f1C != 2) {
        func_003C2F58(m, 2, &d);
        vec_sub_ba(&d, D_L35_001DF980 + e->a * 128 + 0x30, &d);
        e->da = func_L30_0034C9F8(&d);
        func_003C2F58(m, 2, &d);
        vec_sub_ba(&d, D_L35_001DF980 + e->b * 128 + 0x30, &d);
        e->db = func_L30_0034C9F8(&d);
    }
    *(s32 *)(v + 0x19C) = (e->f18 * 5 + 2) / 6;
}
/* localdecomp:end func_L35_003A3D10 */

/* localdecomp:start func_L35_003A3E40 */
#include "vu0.h"

extern f32 D_001A4C64[];
extern void func_L31_003473F0(void *, f32, f32);
extern f32 D_L35_001DEA04;
__asm__(".extern D_L35_001DEA04, 4");
extern f32 D_L35_001DEA2C;
__asm__(".extern D_L35_001DEA2C, 4");
extern f32 D_L35_001DEA54;
__asm__(".extern D_L35_001DEA54, 4");

void func_L35_003A3E40(u8 *a) {
    u8 *st;
    u8 *r;
    f32 dmg;
    f32 v[4] __attribute__((aligned(16)));

    st = *(u8 **)(a + 0x68);
    func_0038CAD0(st + 0xF4);
    func_L01_0044ABD0(a, st + 0x40);
    r = (u8 *)func_L01_00447490(a, 0x10000, 0);
    if (r != 0) {
        a[0xA8] = 0xFF;
        dmg = *(f32 *)(r + 0x2C);
        if (0.0f < dmg) {
            if (a[0x20] != 0x42 && *(s32 *)(st + 0xF4) == 0) {
                *(s32 *)(st + 0xF4) = 0xC;
                *(f32 *)st = *(f32 *)st - dmg;
                func_003C4A40(a, st + 0x40);
                if (*(f32 *)st <= 0.0f) {
                    func_L35_003A4180(a, 0x42);
                    func_0038CF68(st + 0xE0, r + 0x10, D_L35_001DEA04);
                } else {
                    func_L35_003A4180(a, 1);
                    func_0038CF68(v, r + 0x10, D_L35_001DEA2C);
                    vec_add_ab(st + 0xE0, st + 0xE0, v);
                }
            }
        }
    }
    if (*(f32 *)(a + 0x18) < *(f32 *)(st + 0xD8) - 2.0f) {
        if (a[0x20] != 0x42) {
            func_L35_003A4180(a, 0x42);
        }
    }
    *(f32 *)(a + 0x14) = D_001A4C64[0];
    if (a[0x20] != 0x42) {
        func_L31_003473F0(a + 0x10, D_L35_001DEA54, D_L35_001DEA54);
    }
}
/* localdecomp:end func_L35_003A3E40 */

/* localdecomp:start func_L35_003A3FC8 */
#include "vu0.h"

typedef struct V_003A3FC8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A3FC8;

typedef struct E_003A3FC8 {
    s32 a;
    s32 b;
    f32 da;
    f32 db;
    s32 pad[3];
    s32 state;
} E_003A3FC8;

typedef struct O_003A3FC8 {
    u8 pad0[0xD0];
    u8 d0[0x30];
    E_003A3FC8 e[4];
    s32 x180;
    s32 x184;
    s32 count;
    s32 x18C;
    s32 x190;
    s32 x194;
    s32 x198;
    s32 x19C;
} O_003A3FC8;

extern u8 *D_L35_001DF980;
extern s32 D_L35_001DEA38;
__asm__(".extern D_L35_001DEA38, 4");
extern f32 D_L35_001DEA1C;
__asm__(".extern D_L35_001DEA1C, 4");
extern V_003A3FC8 D_L35_001E1D80 __attribute__((section(".sdata")));
extern void func_L31_00346998(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L30_0034C9F8(void *);

void func_L35_003A3FC8(u8 *a0) {
    O_003A3FC8 *v = *(O_003A3FC8 **)(a0 + 0x68);
    V_003A3FC8 d;
    s32 i;

    func_L31_00346998(a0, v->d0);
    v->x194 = 0;
    v->x180 = -1;
    v->x198 = 0;
    v->x19C = 0;
    v->count = 0;
    for (i = 0; i < 4; i++) {
        if (v->e[i].a != -1 && v->e[i].b != -1) {
            v->count = i + 1;
            func_003C2F58(a0, 2, &d);
            vec_sub_ba(&d, D_L35_001DF980 + v->e[i].a * 128 + 0x30, &d);
            v->e[i].da = func_L30_0034C9F8(&d);
            func_003C2F58(a0, 2, &d);
            vec_sub_ba(&d, D_L35_001DF980 + v->e[i].b * 128 + 0x30, &d);
            v->e[i].db = func_L30_0034C9F8(&d);
        } else if (v->e[i].state == 2) {
            v->count = i + 1;
        }
    }
    if (D_L35_001DEA38 == 0) {
        qzero(&D_L35_001E1D80);
        D_L35_001DEA38 = 1;
        D_L35_001E1D80.z += D_L35_001DEA1C;
    }
}
/* localdecomp:end func_L35_003A3FC8 */
