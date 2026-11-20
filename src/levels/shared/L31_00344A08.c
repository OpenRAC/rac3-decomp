#include "common.h"

/* localdecomp:start func_L31_00344A08 */
typedef struct {
    u8 pad0[0x180];
    s16 x180[12];
    s32 x198;
    s32 x19C;
    s32 x1A0;
    u8 x1A4;
    u8 x1A5;
    u8 x1A6;
    u8 x1A7;
    u8 x1A8;
    u8 x1A9;
    u8 pad1AA[2];
    s32 x1AC;
    s32 x1B0;
} V_344A08;

extern s32 D_L31_001DF340;
extern u8 *D_L31_001DF79C;
extern f32 D_001A4C60[];
extern void func_L31_00344F00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00456230(void *, s32);
extern void func_003C2880(void *);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L31_00347CB8(s32, s32, s32, void *);
extern void *func_L31_00344FC8(void *);
extern void func_L31_00344C30(void *, void *, void *);
extern void func_L31_00345398(void *, void *, void *);

void func_L31_00344A08(u8 *o) {
    V_344A08 *p = *(V_344A08 **)(o + 0x68);
    u8 buf[16];
    void *q;
    s32 sum;
    s32 i;

    switch (o[0x20]) {
    case 0:
        func_L31_00344F00(o);
        func_L01_004450F0(o, 2, -1);
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            p->x1AC = D_L31_001DF340;
        }
        if (p->x1A8 != 0 && p->x1AC + p->x1A0 < D_L31_001DF340) {
            if (p->x1B0 != -1) {
                func_L01_00456230(D_L31_001DF79C + (p->x1B0 << 8), 1);
            }
            func_003C2880(o);
            break;
        }
        if (func_L01_00456500(D_001A4C60, p->x19C) != 0 || p->x1A8 != 0) {
            sum = 0;
            for (i = 0; i < p->x1A5; i++) {
                sum += p->x180[i];
                if (func_L31_00347CB8(p->x1A0, p->x1AC + sum, 5, &p->x198) != 0) {
                    q = func_L31_00344FC8(o);
                    func_L31_00344C30(o, q, buf);
                    func_L31_00345398(o, q, buf);
                    p->x198 = D_L31_001DF340;
                }
            }
        } else if (p->x1A9 != 0) {
            p->x1AC = D_L31_001DF340;
        }
        break;
    case 2:
        if (p->x1A7 != 0 && func_L01_00456250(o) == 0) {
            break;
        }
        if (p->x1A8 != 0 && func_L01_00456500(D_001A4C60, p->x19C) == 0) {
            break;
        }
        func_L01_004450F0(o, 1, -1);
        break;
    }
}
/* localdecomp:end func_L31_00344A08 */

/* localdecomp:start func_L31_00344C30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00344C30;
typedef int Q_00344C30 __attribute__((mode(TI)));
typedef struct {
    u8 pad_00[3];
    u8 kind;
    s32 idx;
    u8 pad_08[0x28];
} E_00344C30;
typedef struct { E_00344C30 e[8]; } S_00344C30;
__asm__(".extern D_L31_001DCFB4, 4");
extern f32 D_L31_001DCFB4;
extern u8 *D_L31_001DF880;
extern u8 D_001A4BE0[];
extern V_00344C30 D_001A4C60_00344C30;
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L30_0034CCD0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003824E0(f32, f32);
void func_L31_00344C30(void *o, void *q, void *buf) {
    u8 *a0 = o;
    s32 a1 = (s32)q;
    V_00344C30 *a2 = buf;
    V_00344C30 v;
    V_00344C30 b;
    V_00344C30 c;
    S_00344C30 *base;
    E_00344C30 *e;
    s32 found;
    s32 k;
    u8 *hero;

    base = *(S_00344C30 **)(a0 + 0x68);
    found = 0;
    func_L30_0034CDC0(&b.x, &b.y, &b.z, &b.w, D_L31_001DCFB4);
    e = &base->e[a1];
    if (e->kind < 2) {
        v = D_001A4C60_00344C30;
        if (e->kind == 0) {
            v.x = b.x;
        } else {
            v.x = b.y;
        }
        if (base->e[a1].idx >= 0) {
            v.z = *(f32 *)(D_L31_001DF880 + base->e[a1].idx * 128 + 0x38);
            *a2 = v;
            return;
        }
        hero = D_001A4BE0;
        for (k = 0; k < 4 && !found; k++) {
            v.z = func_003C4088(*(f32 *)(hero + 0x88), b.w, (f32)k / 3.0f);
            v.z = func_003C3D30(&v, 0, 0, 0.5f);
            if (b.z < v.z && v.z < b.w) {
                found = 1;
                *a2 = v;
            }
        }
        if (!found) {
            *a2 = D_001A4C60_00344C30;
        }
    } else if ((u8)(e->kind - 2) < 2) {
        *a2 = D_001A4C60_00344C30;
        if (e->kind == 2) {
            a2->z = b.w;
        } else {
            a2->z = b.z;
        }
        if (base->e[a1].idx >= 0) {
            func_L30_0034CCD0(D_L31_001DF880 + base->e[a1].idx * 128, &c.x, &c.y, &c.z, &c.w);
            a2->x = func_003824E0(c.x, c.y);
        } else {
            f32 lo = b.x;
            f32 hi = b.y;
            a2->x = func_003C4088(lo, hi, func_003824E0(0.15f, 0.85f));
        }
    } else if (e->kind == 4) {
        *(Q_00344C30 *)a2 = *(Q_00344C30 *)(D_L31_001DF880 + base->e[a1].idx * 128 + 0x30);
        func_L30_0034CCD0(D_L31_001DF880 + base->e[a1].idx * 128, &c.x, &c.y, &c.z, &c.w);
        a2->x = func_003824E0(c.x, c.y);
        a2->z = func_003824E0(c.z, c.w);
    }
}
/* localdecomp:end func_L31_00344C30 */
