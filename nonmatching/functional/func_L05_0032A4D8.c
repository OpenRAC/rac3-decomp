/* functional: high. Written from the PAL asm with no draft; all 24 calls match retail in order and arguments (checked jal by jal). Stack slot offsets and the gp-relative loads differ in the compiled bytes (retail uses $gp for D_L05_001DC8B4..C8), same values. func_L01_00477ED0 is the 1-arg function: the extra register setup before it in retail is dead. */
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Q32A4D8;
extern f32 D_L05_001DC8B4;
extern f32 D_L05_001DC8B8;
extern f32 D_L05_001DC8C0;
extern f32 D_L05_001DC8C4;
extern f32 D_L05_001DC8C8;
extern s32 *D_L05_0021ED80[];
extern u8 *D_L05_001DFC80;
extern f32 func_L01_00477ED0(s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern f32 func_L05_0032A238(u8 *, u8 *, s32 *, f32, f32);
extern void func_L05_0032A360(u8 *, u8 *, s32, f32 *, f32);
extern void func_L01_003ABF48(u8 *, u8 *, void *, f32 *, f32 *);

s32 func_L05_0032A4D8(u8 *o, u8 *s) {
    u8 *tab = (u8 *)D_L05_0021ED80[*(s32 *)(s + 0x160)];
    u8 *e = D_L05_001DFC80 + (*(s32 *)(s + 0x90 + *(s32 *)(s + 0x15C) * 4) << 7);
    Q32A4D8 v10 = *(Q32A4D8 *)(o + 0x10);
    Q32A4D8 d0;
    Q32A4D8 v30;
    Q32A4D8 v40;
    f32 ang[3];
    s32 idx;
    s32 atEnd;
    s32 flag = 0;
    f32 target;
    f32 speed;
    f32 dot;
    f32 t;
    f32 frac;
    f32 sp50;
    f32 step;
    f32 r;
    f32 *a;

    target = func_L01_00477ED0(*(s32 *)(s + 0x160));
    if (*(f32 *)(s + 0x164) < 0.0f) {
        d0 = *(Q32A4D8 *)(tab + 0x10);
        v30.v[0] = ((f32 *)(s + 0x180))[0];
        v30.v[1] = ((f32 *)(s + 0x180))[1];
        v30.v[2] = ((f32 *)(s + 0x180))[2];
    } else {
        idx = (s32)*(f32 *)(s + 0x164);
        if (idx == *(s32 *)tab - 1) {
            d0 = *(Q32A4D8 *)(s + 0x190);
            v30 = *(Q32A4D8 *)(tab + idx * 16 + 0x10);
        } else {
            v30 = *(Q32A4D8 *)(tab + idx * 16 + 0x10);
            d0 = *(Q32A4D8 *)(tab + idx * 16 + 0x20);
        }
    }
    d0.v[0] = d0.v[0] - v30.v[0];
    d0.v[1] = d0.v[1] - v30.v[1];
    d0.v[2] = d0.v[2] - v30.v[2];
    func_0038CF68(&d0, &d0, 1.0f);
    dot = func_0038CE68(&d0, o + 0xC0);
    if (dot <= 0.0f) {
        speed = D_L05_001DC8B8;
    } else {
        f32 k = dot * D_L05_001DC8B4;
        if (1.0f < k) {
            k = 1.0f;
        }
        speed = D_L05_001DC8B8 + (20.0f - D_L05_001DC8B8) * k;
    }
    sp50 = 0.0f;
    func_003C41A0(&sp50, s + 0x168, target, 0.00320000015f, 0.00320000015f, speed * 0.0200000014f);
    t = func_L05_0032A238(s, tab, &idx, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168));
    *(f32 *)(s + 0x164) = t;
    atEnd = 0;
    if (!(idx < *(s32 *)tab - 1)) {
        idx = *(s32 *)tab - 1;
        atEnd = 1;
    }
    frac = t - (f32)idx;
    if (atEnd != 0 && 1.0f <= frac) {
        frac = 1.0f;
        flag = 1;
        *(f32 *)(s + 0x164) = t - *(f32 *)(s + 0x168) / *(f32 *)(tab + idx * 16 + 0x1C);
    }
    func_L05_0032A360(s, tab, idx, (f32 *)(o + 0x10), frac);
    ang[0] = 0.0f;
    if ((0.0f < *(f32 *)(s + 0x18C) && idx == -1) ||
        (*(f32 *)(s + 0x18C) < 0.0f && idx == 0)) {
        func_L01_003ABF48(o, s, &v10, &ang[0], &ang[1]);
        ang[0] = func_0038DAB8(ang[0], *(f32 *)(e + 0x70));
        if (0.436332315f < ang[1]) {
            ang[1] = 0.436332315f;
        } else if (ang[1] < -0.436332315f) {
            ang[1] = -0.436332315f;
        }
        ang[1] = func_0038DAB8(ang[1], *(f32 *)(e + 0x74));
        ang[2] = *(f32 *)(o + 0xF8);
    } else if (idx >= *(s32 *)tab - 2) {
        func_L01_003ABF48(o, s, &v10, &ang[0], &ang[1]);
        ang[0] = -ang[0];
        ang[1] = -ang[1];
        ang[0] = func_0038DAB8(ang[0], *(f32 *)(e + 0x70));
        if (0.436332315f < ang[1]) {
            ang[1] = 0.436332315f;
        } else if (ang[1] < -0.436332315f) {
            ang[1] = -0.436332315f;
        }
        ang[1] = func_0038DAB8(ang[1], *(f32 *)(e + 0x74));
        ang[2] = *(f32 *)(e + 0x78);
    } else {
        f32 lim = *(f32 *)(s + 0x168) * D_L05_001DC8C0;
        if (D_L05_001DC8C4 < lim) {
            lim = D_L05_001DC8C4;
        } else if (lim < D_L05_001DC8C8) {
            lim = D_L05_001DC8C8;
        }
        r = func_L05_0032A238(s, tab, &idx, *(f32 *)(s + 0x164), lim);
        idx = (s32)r;
        func_L05_0032A360(s, tab, idx, (f32 *)&v30, r - (f32)idx);
        v40.v[0] = v30.v[0] - *(f32 *)(o + 0x10);
        v40.v[1] = v30.v[1] - *(f32 *)(o + 0x14);
        v40.v[2] = v30.v[2] - *(f32 *)(o + 0x18);
        v40.v[3] = v30.v[3];
        r = -func_0038D160(func_0038CED8(&v40), v40.v[2]);
        ang[1] = r;
        if (0.436332315f < r) {
            ang[1] = 0.436332315f;
        } else if (r < -0.436332315f) {
            ang[1] = -0.436332315f;
        }
        ang[2] = func_0038D160(v40.v[0], v40.v[1]);
    }
    func_L01_00448890(o + 0xF4, ang[1], s + 0x174, 0, 0.000698131742f, 0.000698131742f, 0.104719758f);
    func_L01_00448890(o + 0xF8, ang[2], s + 0x178, 0, 0.00104719761f, 0.00104719761f, 0.104719758f);
    r = func_0038DAB8(ang[0], *(f32 *)(s + 0x178) * *(f32 *)(s + 0x168) * -50.0f);
    ang[0] = r;
    if (0.436332315f < r) {
        ang[0] = 0.436332315f;
    } else if (r < -0.436332315f) {
        ang[0] = -0.436332315f;
    }
    func_L01_00448890(o + 0xF0, ang[0], s + 0x170, 0, 0.000698131742f, 0.000698131742f, 0.104719758f);
    *(Q32A4D8 *)ang = *(Q32A4D8 *)(e + 0x70);
    if (!(0.00999999978f < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF0), ang[0]))) &&
        !(0.00999999978f < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF4), ang[1]))) &&
        !(0.00999999978f < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF8), ang[2])))) {
        return flag ^ 1;
    }
    return 1;
}
