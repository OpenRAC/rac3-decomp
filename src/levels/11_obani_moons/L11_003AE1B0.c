#include "common.h"
#include "vu0.h"

typedef struct List_003AE1B0 {
    u8 pad0[0x44];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u32 *entries[1];
} List_003AE1B0;

/* localdecomp:start func_L11_003AE1B0 */
extern s32 D_L11_001D6694;
extern u8 D_001D5471;
extern List_003AE1B0 D_L11_001E5AC0;
extern u8 D_L11_001E02A0;
extern u8 D_L11_001E02A1;
extern f32 D_L11_001E02C0;
extern f32 D_L11_001E02C4;
extern f32 D_L11_001E02C8;
extern void func_L01_0043A430(u32 *, s32, u8 *);

void func_L11_003AE1B0(u8 *arg) {
    u32 *elem;
    s32 i;

    if (D_L11_001D6694 == 2) {
        if (D_001D5471 != 0) {
            for (i = 0; i < D_L11_001E5AC0.count; i++) {
                elem = D_L11_001E5AC0.entries[i];
                if (*(s16 *)((u8 *)elem + 0xAA) == *(s16 *)(arg + 0xAA)) {
                    if (D_L11_001E02A1 == 0) {
                        func_L01_0043A430(elem, 0, &D_L11_001E02A0);
                        D_L11_001E02C0 = 2.75f;
                        D_L11_001E02C4 = 2.75f;
                        D_L11_001E02C8 = 2.75f;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L11_003AE1B0 */

/* localdecomp:start func_L11_003AE290 */
typedef int q_3AE290 __attribute__((mode(TI)));
extern s32 D_L11_001D6694;
extern u8 D_001D5470;

extern u8 D_001D5545;
typedef struct {
    u8 pad0[0x80];
    u8 f80[0x60];
    vu0_v4 fE0;
    u8 pad0F0[0x20];
    u8 f110[0x250];
    s32 f360;
} P_3AE290;
extern P_3AE290 D_001A4BE0;
extern vu0_v4 D_L11_001E84E0;
extern u8 *D_L11_001DEE1C;
extern u8 D_L11_001E1780[];
extern s32 func_L01_004BA800(void);
extern void func_L11_003AE1B0(u8 *);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00456230(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_004472C0(void *);

void func_L11_003AE290(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 tgt;
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 u0;
    vu0_v4 p0;
    vu0_v4 p1;
    vu0_v4 p2;
    vu0_v4 p3;
    vu0_v4 u1[2];
    s32 flag;
    f32 s0, s1, e, t;

    if (D_L11_001D6694 == 2) {
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        return;
    }
    if (func_L01_004BA800() == 0) {
        a0[0x31] = 1;
        *(u16 *)(a0 + 0x34) &= 0xFFFE;
    }
    func_L11_003AE1B0(a0);
    switch (a0[0x20]) {
    case 0: {
        q_3AE290 qa, qb, qp;
        func_003C5180(a0 + 0x10, &tgt, 0);
        func_L01_004515D8(a0 + 0xC0, &tgt, &pos);
        func_0038CF68(&p0, a0 + 0xE0, 0.5f);
        func_0038CF68(&p1, a0 + 0xE0, -4.0f);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(p0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(p1));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(qb));
        if (func_003D3CB0(&p0, &p1, 2, (s32)a0, 0) != 0) {
            *(vu0_v4 *)(a0 + 0x10) = D_L11_001E84E0;
            func_003C5180(a0 + 0x10, &p2, 0);
            func_L01_004515D8(a0 + 0xC0, &p2, &p3);
        }
        func_L01_004450F0(a0, 1, -1);
        if (D_001D5545 != 0) {
            func_003C2880(a0);
            return;
        }
        break;
    }
    case 1:
        if (func_L01_0040E548(a0 + 0x10, D_001A4BE0.f80) < 100.0f) {
            if (D_001A4BE0.f360 != 0) {
                func_L01_00456230(D_L11_001DEE1C + (*(s32 *)(v + 0x120) << 8), 1);
                func_L01_004450F0(a0, 2, -1);
            }
        }
        break;
    }
    if (a0[0x20] != 0) {
        if (a0[0x43] == 0 && func_0038CAD0(v + 0x11C) != 0) {
            *(s32 *)(v + 0x11C) = (s32)((func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f);
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, 8);
            }
        } else if (a0[0x60] & 2) {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
        }
    }
    s0 = 0.02f;
    s1 = 0.3f;
    flag = 0;
    if (a0[0x43] == 0) {
        f32 ang;
        flag = 1;
        if (func_0038CF38(a0 + 0x10, D_001A4BE0.f80) < 8.0f) {
            ang = func_0038D160(D_001A4BE0.fE0.x - *(f32 *)(a0 + 0x10), D_001A4BE0.fE0.y - *(f32 *)(a0 + 0x14));
            ang = func_0038DBA0(*(f32 *)(a0 + 0xF8), ang);
            if (ang < 1.5707964f) {
                if (0.01f < func_0038CEA8(D_001A4BE0.f110)) {
                    *(s32 *)(v + 0x114) = 100;
                } else {
                    func_0038CAD0(v + 0x114);
                }
            } else {
                goto z;
            }
        } else {
z:
            if (*(s32 *)(v + 0x114) != 0) {
                *(s32 *)(v + 0x114) = 0;
                *(q_3AE290 *)(v + 0x100) = *(q_3AE290 *)&D_001A4BE0.fE0;
            }
        }
        if (func_0038CAD0(v + 0x118) != 0) {
            e = 6.0f;
            *(s32 *)(v + 0x118) = (s32)((func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / e);
            ang = func_0038DAB8(*(f32 *)(a0 + 0xF8), func_003824E0(-90.0f, 90.0f) * 0.017453292f);
            t = func_003824E0(0.0f, 30.0f) * 0.017453292f;
            func_00382760(v + 0x100, e, ang, t);
            {
                q_3AE290 qa, qb, qr;
                __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(v + 0x100)));
                __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(a0 + 0x10)));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
                __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(v + 0x100)) : "j"(qr));
            }
        }
        if (*(s32 *)(v + 0x114) != 0) {
            s0 = 0.04f;
            s1 = 0.3f;
            *(q_3AE290 *)&tgt = *(q_3AE290 *)&D_001A4BE0.fE0;
        } else {
            tgt = *(vu0_v4 *)(v + 0x100);
        }
    }
    if (flag != 0) {
        f32 ang, ang2;
        pos = *(vu0_v4 *)(a0 + 0x10);
        pos.z += 2.0f;
        vec_sub_ab(&d, &tgt, &pos);
        ang = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(a0 + 0xF8));
        ang2 = -func_0038D160(func_0038CED8(&d), d.z);
        if (1.5707964f < ang) {
            ang = 1.5707964f;
        } else if (ang < -1.5707964f) {
            ang = -1.5707964f;
        }
        if (0.5235988f < ang2) {
            ang2 = 0.5235988f;
        } else if (ang2 < -0.5235988f) {
            ang2 = -0.5235988f;
        }
        *(f32 *)(v + 0x64) = ang2;
        *(f32 *)(v + 0x68) = ang * 0.6f;
        *(f32 *)(v + 0xE8) = ang * 0.4f;
    }
    if ((&D_001D5470)[1] != 0) {
        *(f32 *)(v + 0x70) = 2.75f;
    }
    func_L01_0044E850(a0, v, 0, s0 * 1.44f, s1 * 1.44f);
    func_L01_0044E850(a0, v + 0x80, 1, s0 * 1.44f, s1 * 1.44f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L11_001E1780, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 30;
        }
    }
}
/* localdecomp:end func_L11_003AE290 */

/* localdecomp:start func_L11_003AE938 */
typedef int q_3AE938 __attribute__((mode(TI)));
__asm__(".extern D_L11_001DE138, 4");
__asm__(".extern D_L11_001DE13C, 4");
__asm__(".extern D_L11_001DE140, 4");
__asm__(".extern D_L11_001DE144, 4");
__asm__(".extern D_L11_001DE148, 4");
__asm__(".extern D_L11_001DE14C, 4");
__asm__(".extern D_L11_001DE150, 4");
extern s32 D_L11_001DE138;
extern s32 D_L11_001DE13C;
extern f32 D_L11_001DE140;
extern f32 D_L11_001DE144;
extern f32 D_L11_001DE148;
extern f32 D_L11_001DE14C;
extern f32 D_L11_001DE150;
extern void func_0038CE20(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, f32, s32, s32);

void func_L11_003AE938(u8 *a0)
{
    q_3AE938 m[4];
    q_3AE938 p;
    u8 *v;
    f32 t;

    p = *(q_3AE938 *)(a0 + 0x10);
    m[0] = *(q_3AE938 *)(a0 + 0xC0);
    m[1] = *(q_3AE938 *)(a0 + 0xD0);
    m[2] = *(q_3AE938 *)(a0 + 0xE0);
    m[3] = p;
    v = *(u8 **)(a0 + 0x68);
    func_0038CE20(&m[0], &m[0], D_L11_001DE140);
    func_0038CE20(&m[1], &m[1], D_L11_001DE144);
    func_0038CE20(&m[2], &m[2], D_L11_001DE148);
    t = D_L11_001DE14C + D_L11_001DE150 * 1.2f;
    D_L11_001DE14C = t;
    if (1.0f < t) {
        D_L11_001DE14C = t - 1.0f;
    }
    func_003D9740(m, D_L11_001DE138, (*(s32 *)(v + 0xC) << 24) | 0x20AF20, D_L11_001DE14C, D_L11_001DE13C, 1);
}
/* localdecomp:end func_L11_003AE938 */

/* localdecomp:start func_L11_003AEA18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3AEA18;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001A30B0[];
extern u8 D_001426E0[];
extern u8 *D_L11_001DEE1C;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern s32 func_L01_00456250(void *);
extern void func_0039EF28(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004048D0(void (*)(u8 *), void *);
extern void func_L11_003AE938(u8 *);

void func_L11_003AEA18(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    V4_3AEA18 m[4];
    s32 idx;
    u8 *e;

    if (a0[0x20] == 0) {
        *(u16 *)(a0 + 0x34) |= 0x141;
        func_003C5180(a0 + 0x10, m, 0);
        func_L01_004515D8(a0 + 0xC0, &m[0], &m[1]);
        a0[0x20] = 1;
        if (D_001BBC40[a0[0xB0] + D_001D545C * 16] & 0x80) {
            goto kill;
        }
        if (v[2] == -1) {
            goto spawn;
        }
        e = D_001A30B0 + (v[2] << 7);
        if (*(u8 **)(e + 0xDC) != a0 || e[0xD0] == 0) {
spawn:
            v[2] = func_003A52A0(0, 4, a0);
        }
        v[3] = 0xFF;
    }
    if (a0[0x20] == 1) {
        if (func_L01_00456250(D_L11_001DEE1C + (v[1] << 8)) != 0) {
            idx = v[2];
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            v[2] = -1;
            func_003A52A0(1, 0, a0);
            if (D_001426E0[0x21] == 0) {
                D_001426E0[0x21] = 1;
                func_0039EF28(a0);
            }
            func_L01_004450F0(a0, 2, -1);
        }
    }
    if (a0[0x20] == 2) {
        v[3] -= 2;
        if (v[3] < 0) {
kill:
            func_003C2880(a0);
            return;
        }
    }
    func_L01_004048D0(func_L11_003AE938, a0);
}
/* localdecomp:end func_L11_003AEA18 */

/* localdecomp:start func_L11_003AEBE8 */
typedef struct { u8 pad0[0x20]; } M2_3AEBE8;
typedef struct {
    vu0_v4 f0;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0x2C - 0x1C];
    s32 f2C;
    u8 pad30[0x40 - 0x30];
    s32 f40;
} V_3AEBE8;
extern vu0_v4 D_L11_001E84E0;
extern s32 D_L11_001E1020[12] __attribute__((section(".sdata")));
__asm__(".extern D_L11_001DE160, 4");
extern s32 D_L11_001DE160;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00451290(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_004C85C8(void *, s32, s32, f32, f32, f32);
extern void func_L11_003AF6B8(u8 *);

u8 *func_L11_003AEBE8(vu0_v4 *pos, s32 a1, vu0_v4 *a2)
{
    vu0_v4 s0[2];
    vu0_v4 mtx;
    vu0_v4 a;
    vu0_v4 b;
    u8 *m;
    V_3AEBE8 *v;
    s32 i;

    s0[0] = *a2;
    m = func_003C24B0(0x1C55, 0x80);
    if (m != 0) {
        *(s32 *)(m + 0xB8) = a1;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        v = *(V_3AEBE8 **)(m + 0x68);
        *(vu0_v4 *)(m + 0x10) = *pos;
        func_L01_00451290(m, &mtx, 1);
        func_0038CF68(&a, &mtx, 3.0f);
        func_0038CF68(&b, &mtx, -3.0f);
        vec_add_ba(&a, &a, m + 0x10);
        vec_add_ab(&b, &b, m + 0x10);
        if (func_003D3CB0(&a, &b, 2, *(s32 *)(m + 0xB8), 0) != 0) {
            *(vu0_v4 *)(m + 0x10) = D_L11_001E84E0;
            func_0038CF68(&a, &mtx, 0.75f);
            vec_add_ab(m + 0x10, m + 0x10, &a);
        }
        v->f14 = (D_L11_001DE160 * 5 + 2) / 6;
        v->f0 = s0[0];
        v->f10 = func_L01_004C85C8(m, 0, 6, 1.0f, 1.0f, 1.0f);
        m[0x20] = 0;
        v->f18 = 0;
        func_L11_003AF6B8(m);
        v->f2C = 4;
        for (i = 0; i < 12; i++) {
            if (D_L11_001E1020[i] == 0) {
                D_L11_001E1020[i] = 1;
                v->f40 = i;
                break;
            }
        }
    }
    return m;
}
/* localdecomp:end func_L11_003AEBE8 */

/* localdecomp:start func_L11_003AEDE8 */
typedef struct {
    vu0_v4 f0;
    s32 f10;
    s32 f14;
    f32 f18;
    s32 f1C;
    u8 pad20[0x2C - 0x20];
    s32 f2C;
    u8 pad30[0x40 - 0x30];
    s32 f40;
    s32 f44;
} V_3AEDE8;
extern s32 D_L11_001E1020[12] __attribute__((section(".sdata")));
extern u8 D_001A30B0[];
extern void func_L01_004C8688(s32, void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004C8668(s32);
extern void func_003A4F28(s32);
extern void func_003C2880(void *);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00451290(void *, void *, s32);
extern s32 func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_00382348(s32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L11_003AF6B8(u8 *);
extern void func_L11_003AFD48(u8 *);
extern void func_L11_003AFF60(u8 *);
extern void func_L11_003AF058(u8 *);
extern void func_L01_00404808(void *, void *);

void func_L11_003AEDE8(u8 *m)
{
    V_3AEDE8 *v = *(V_3AEDE8 **)(m + 0x68);
    vu0_v4 mtx;
    vu0_v4 dir;
    vu0_v4 a;
    vu0_v4 b;
    s32 idx;
    u8 *e;
    u8 *p;
    f32 s;
    f32 t;

    func_L01_004C8688(v->f10, v, 0);
    vec_add_ab(m + 0x10, m + 0x10, v);
    if (func_0038CAD0(&v->f14) != 0) {
        func_L01_004C8668(v->f10);
        D_L11_001E1020[v->f40] = 0;
        idx = v->f44;
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
        }
        v->f44 = -1;
        func_003C2880(m);
        return;
    }
    if (v->f44 == -1) {
        goto spawn;
    }
    e = D_001A30B0 + (v->f44 << 7);
    if (*(u8 **)(e + 0xDC) != m || e[0xD0] == 0) {
spawn:
        v->f44 = func_L01_004AAC98(7, 4, m, 0x1BF6);
    }
    s = 1.0f;
    func_L01_00451290(m, &mtx, 1);
    func_0038CE90(&dir, &mtx, v);
    func_0038CF68(&a, &dir, v->f18);
    vec_add_ba(&a, &a, m + 0x10);
    func_0038CF68(&b, &dir, -v->f18);
    vec_add_ab(&b, &b, m + 0x10);
    p = func_00382348(*(s32 *)(m + 0xB8));
    if (p != 0) {
        s = (f32)p[0x14];
    }
    func_L03_00433C70(m, &a, &b, 1, 0, 1, 0, s, 0.0f);
    if (v->f1C == 0) {
        v->f2C = 4;
        func_L11_003AF6B8(m);
    }
    func_L11_003AFD48(m);
    func_L01_00404808(func_L11_003AFF60, m);
    func_L01_00404808(func_L11_003AF058, m);
    t = v->f18 + 0.040000003f;
    v->f18 = t;
    if (1.5f < t) {
        v->f18 = 1.5f;
    }
}
/* localdecomp:end func_L11_003AEDE8 */

/* localdecomp:start func_L11_003AF058 */
extern u8 D_L11_001D66B0;
extern u8 *D_L11_0021E6C8[];
extern void func_L01_00451290(void *, void *, s32);
extern s32 func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L11_003AF058(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 mtx;
    vu0_v4 dir;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 s;
    f32 sc;
    u8 *q;

    func_L01_00451290(a0, &mtx, 1);
    func_0038CE90(&dir, &mtx, v);
    func_0038CF68(&a, &dir, *(f32 *)(v + 0x18));
    vec_add_ab(&a, &a, a0 + 0x10);
    func_0038CF68(&b, &dir, -*(f32 *)(v + 0x18));
    vec_add_ab(&b, &b, a0 + 0x10);
    p = a;
    func_00382580(&r, 0.025f, 0.15f);
    vec_add_ba(&r, &r, &p);
    vec_sub_ab(&s, &p, &r);
    func_0038CF68(&s, &s, 0.015000001f);
    func_L01_004735F0(&r, &s, 6, 1.0f);
    sc = (func_L01_00443A18(0.0f, 0.15f) + 0.75f) * 210000.0f;
    if (func_00382468(2) != 0) {
        q = func_L01_0046A610(&p, &D_L11_001D66B0, 6, 6, 0x904020, (s32)func_L01_00443A18(1.0f, -1.0f), sc * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[2] = D_L11_0021E6C8[0][1];
        }
    }
    p.x += func_L01_00443A18(0.0f, 0.04f);
    p.y += func_L01_00443A18(0.0f, 0.04f);
    p.z += func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2) != 0) {
        q = func_L01_0046A610(&p, &D_L11_001D66B0, 6, 0x6F, 0x804020, (s32)func_L01_00443A18(1.0f, -1.0f), sc * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8[0][0];
        }
        q = func_L01_0046A610(&p, &D_L11_001D66B0, 6, 0x6F, 0x802080, (s32)func_L01_00443A18(1.0f, -1.0f), sc * 1.25f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8[0][0];
        }
    }
    p = b;
    func_00382580(&r, 0.025f, 0.15f);
    vec_add_ba(&r, &r, &p);
    vec_sub_ab(&s, &p, &r);
    func_0038CF68(&s, &s, 0.015000001f);
    func_L01_004735F0(&r, &s, 6, 1.0f);
    sc = (func_L01_00443A18(0.0f, 0.15f) + 0.75f) * 210000.0f;
    if (func_00382468(2) != 0) {
        q = func_L01_0046A610(&p, &D_L11_001D66B0, 6, 6, 0x904020, (s32)func_L01_00443A18(1.0f, -1.0f), sc * 3.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[2] = D_L11_0021E6C8[0][1];
        }
    }
    p.x += func_L01_00443A18(0.0f, 0.04f);
    p.y += func_L01_00443A18(0.0f, 0.04f);
    p.z += func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2) != 0) {
        q = func_L01_0046A610(&p, &D_L11_001D66B0, 6, 0x6F, 0x804020, (s32)func_L01_00443A18(1.0f, -1.0f), sc * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8[0][0];
        }
        q = func_L01_0046A610(&p, &D_L11_001D66B0, 6, 0x6F, 0x802080, (s32)func_L01_00443A18(1.0f, -1.0f), sc * 1.25f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (q != 0) {
            q[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            q[2] = D_L11_0021E6C8[0][0];
        }
    }
}
/* localdecomp:end func_L11_003AF058 */

/* localdecomp:start func_L11_003AF6B8 */
typedef struct Obj_3AF6B8 {
    vu0_v4 pos;
    u8 pad10[0x18 - 0x10];
    f32 f18;
    s32 f1C;
    s32 f20;
    u8 f24[0x30 - 0x24];
    f32 f30;
    f32 f34;
    f32 f38;
    u8 pad3C[0x40 - 0x3C];
    s32 f40;
} Obj_3AF6B8;

__asm__(".extern D_L11_001DE1E0, 4");
__asm__(".extern D_L11_001DE1E4, 4");
__asm__(".extern D_L11_001DE1B8, 4");
__asm__(".extern D_L11_001DE1BC, 4");
__asm__(".extern D_L11_001DE1D0, 4");
extern s32 D_L11_001DE1E0;
extern s32 D_L11_001DE1E4;
extern f32 D_L11_001DE1B8;
extern f32 D_L11_001DE1BC;
extern f32 D_L11_001DE1D0;
extern vu0_v4 D_L11_002A2820[][32];
extern vu0_v4 D_L11_002A4020[][32];
extern vu0_v4 D_L11_002A5820[][4][4];
extern vu0_v4 D_L11_002A6420[][4][4];
extern u8 D_L11_001E1700[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538();
extern void func_0038D328(void *, void *);
extern void func_L01_00451290(void *, void *, s32);
extern s32 func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_00382468(s32);

static __inline__ void vcopy_3AF6B8(vu0_v4 *d, vu0_v4 *s)
{
    *(vu0_q *)d = *(vu0_q *)s;
}

void func_L11_003AF6B8(u8 *arg)
{
    vu0_v4 A[32];
    vu0_v4 B[32];
    vu0_v4 t0;
    vu0_v4 t1;
    vu0_v4 m[4];
    vu0_v4 c;
    Obj_3AF6B8 *v;
    s32 r;
    s32 n1;
    s32 n2;
    f32 w;
    f32 f;
    s32 i;
    s32 p;
    s32 q;
    s32 j;
    s32 jj;
    s32 k;
    s32 kk;
    vu0_q row;

    n1 = (D_L11_001DE1E0 * 5 + 2) / 6;
    n2 = (D_L11_001DE1E4 * 5 + 2) / 6;
    *(f32 *)(arg + 0x1C) = 1.0f;
    v = *(Obj_3AF6B8 **)(arg + 0x68);
    r = func_00382498(n1, n2);
    v->f1C = r;
    v->f20 = r;
    w = func_003824E0(v->f18 * 1.9f, v->f18 * 2.1f);
    for (i = 0; i < 32; i++) {
        f = (f32)i / 31.0f;
        f = (0.5f - f) * w;
        if (i < 3 || i > 28) {
            qzero(&A[i]);
            qzero(&B[i]);
        } else {
            func_L01_00443B88(&A[i], 0.0f, D_L11_001DE1B8);
            func_L01_00443B88(&B[i], 0.0f, D_L11_001DE1BC * 0.0200000014f);
        }
        A[i].w = 1.0f;
        A[i].y += f;
    }
    for (p = 0; p < 32; p++) {
        if (p == 0 || p == 31) {
            vcopy_3AF6B8(&D_L11_002A2820[v->f40][p], &A[p]);
            vcopy_3AF6B8(&D_L11_002A4020[v->f40][p], &B[p]);
        } else {
            vec_add_ab(&t0, &A[p - 1], &A[p]);
            vec_add_ba(&t0, &t0, &A[p + 1]);
            func_0038CE20(&D_L11_002A2820[v->f40][p], &t0, 0.333f);
            vec_add_ba(&t0, &B[p - 1], &B[p]);
            vec_add_ba(&t0, &t0, &B[p + 1]);
            func_0038CE20(&D_L11_002A4020[v->f40][p], &t0, 0.333f);
        }
    }
    for (q = 0; q < 4; q++) {
        func_L01_00443B88(&t0, D_L11_001DE1B8, D_L11_001DE1B8);
        k = (s32)func_003824E0((f32)q * 6.0f, (f32)(q + 1) * 6.0f) + 4;
        v->f24[q] = k;
        vcopy_3AF6B8(&D_L11_002A5820[v->f40][0][q], &D_L11_002A2820[v->f40][k]);
        vcopy_3AF6B8(&D_L11_002A6420[v->f40][0][q], &D_L11_002A4020[v->f40][k]);
        for (j = 1; j < 4; j++) {
            func_L01_00443B88(&t1, 0.1f, 0.1f);
            func_L01_00443B88(&D_L11_002A6420[v->f40][j][q], 0.0f, D_L11_001DE1BC * 0.0200000014f);
            vec_add_ba(&D_L11_002A5820[v->f40][j][q], &D_L11_002A5820[v->f40][j - 1][q], &t0);
            vec_add_ba(&D_L11_002A5820[v->f40][j][q], &D_L11_002A5820[v->f40][j][q], &t1);
        }
    }
    if (func_0038CF38(arg + 0x10, D_L11_001E1700) >= 4.0f) {
        v->f38 = *(f32 *)(arg + 0xF8);
        v->f34 = *(f32 *)(arg + 0xF4);
        v->f34 += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
        v->f30 = func_00382538();
        func_0038D328(m, &v->f30);
        row = *(vu0_q *)&v->pos;
        *(vu0_q *)&m[0] = row;
        func_L01_00451290(arg, &t0, 1);
        row = *(vu0_q *)&t0;
        *(vu0_q *)&m[2] = row;
        func_0038CE90(&m[1], &m[0], &m[2]);
        func_0038CF68(&m[0], &m[0], 1.0f);
        func_0038CF68(&m[1], &m[1], 1.0f);
        func_0038CF68(&m[2], &m[2], 1.0f);
        row = *(vu0_q *)(arg + 0x10);
        *(vu0_q *)&m[3] = row;
        func_003C48A8(m, &v->f30);
        for (kk = 0; kk < 32; kk += 8) {
            func_0038D028(&t1, &D_L11_002A2820[v->f40][kk], m);
            vcopy_3AF6B8(&c, &D_L11_002A4020[v->f40][kk]);
            c.w = D_L11_001DE1D0;
            func_00382468(2);
        }
        for (jj = 0; jj < 2; jj++) {
            func_0038D028(&c, &D_L11_002A5820[v->f40][3][jj], m);
            vcopy_3AF6B8(&t1, &D_L11_002A6420[v->f40][3][jj]);
            t1.w = D_L11_001DE1D0;
            func_00382468(2);
        }
    }
}
/* localdecomp:end func_L11_003AF6B8 */

/* localdecomp:start func_L11_003AFD48 */
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
    u8 f24[4];
    s32 f28;
    u8 pad2C[0x40 - 0x2C];
    s32 f40;
} V_3AFD48;
extern vu0_v4 D_L11_002A2820[][32];
extern vu0_v4 D_L11_002A4020[][32];
extern vu0_v4 D_L11_002A5820[][4][4];
extern vu0_v4 D_L11_002A6420[][4][4];
extern s32 D_L11_001DE188;
extern s32 D_L11_001DE18C;
extern s32 D_L11_001DE190;
extern s32 D_L11_001DE1E8;
extern s32 D_L11_001DE1EC;
__asm__(".extern D_L11_001DE188, 4");
__asm__(".extern D_L11_001DE18C, 4");
__asm__(".extern D_L11_001DE190, 4");
__asm__(".extern D_L11_001DE1E8, 4");
__asm__(".extern D_L11_001DE1EC, 4");
extern s32 func_0038DBD8(s32, s32, f32);

void func_L11_003AFD48(u8 *a0)
{
    V_3AFD48 *v = *(V_3AFD48 **)(a0 + 0x68);
    s32 i, j, k;

    if (v->f1C != 0) {
        v->f1C--;
        for (i = 4; i < 27; i++) {
            vec_add_ab(&D_L11_002A2820[v->f40][i], &D_L11_002A2820[v->f40][i], &D_L11_002A4020[v->f40][i]);
        }
        for (j = 0; j < 4.0f; j++) {
            for (k = 1; k < 4; k++) {
                vec_add_ab(&D_L11_002A5820[v->f40][k][j], &D_L11_002A5820[v->f40][k][j], &D_L11_002A6420[v->f40][k][j]);
            }
        }
        for (i = 0; i < 4; i++) {
            *(vu0_q *)&D_L11_002A5820[v->f40][0][i] = *(vu0_q *)&D_L11_002A2820[v->f40][v->f24[i]];
        }
    }
    if (v->f1C > D_L11_001DE1E8) {
        v->f28 = func_0038DBD8(D_L11_001DE18C, D_L11_001DE188, (f32)(v->f1C - D_L11_001DE1E8) / (f32)(v->f20 - D_L11_001DE1E8));
    } else if (v->f1C > D_L11_001DE1EC) {
        v->f28 = func_0038DBD8(D_L11_001DE190, D_L11_001DE18C, (f32)(v->f1C - D_L11_001DE1EC) / (f32)(D_L11_001DE1E8 - D_L11_001DE1EC));
    } else {
        v->f28 = 0;
    }
}
/* localdecomp:end func_L11_003AFD48 */

INCLUDE_ASM("asm/levels", func_L11_003AFF60);
