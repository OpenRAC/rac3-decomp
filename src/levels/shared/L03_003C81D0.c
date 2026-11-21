#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003C81D0 */
typedef struct {
    u8 pad0[0x80];
    vu0_v4 pos;
    u8 pad90[0x98 - 0x90];
    f32 f98;
    u8 pad9C[0x238 - 0x9C];
    s32 f238;
    u8 pad23C[0x360 - 0x23C];
    s32 f360;
    u8 pad364[0x1228 - 0x364];
    s32 f1228;
    u8 pad122C[0x1318 - 0x122C];
    s32 f1318;
    u8 pad131C[0x25C0 - 0x131C];
    u8 *moby;
    s32 state;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 body_kind;
    u8 pad25E5[0x25F8 - 0x25E5];
    s32 f25F8;
    u8 pad25FC[0x2604 - 0x25FC];
    s32 f2604;
    u8 pad2608[0x288C - 0x2608];
    s16 f288C;
    u8 pad288E[0x2920 - 0x288E];
} Hero_003C81D0;
extern Hero_003C81D0 D_001A4BE0_003C81D0;
extern u8 *D_001D52FC;
extern u8 D_001A30B0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s16 D_001426A0[];
extern s32 D_L03_002428C0[];
extern s32 D_L03_002E52F0[];
extern f32 D_L03_001DEEA0[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DEEA0, 4");
typedef struct {
    u8 pad0[0x8A];
    u16 max;
    u8 pad8C[0xF0 - 0x8C];
} __attribute__((aligned(16))) R_003C81D0;
extern R_003C81D0 D_L03_002C49C0[];
typedef struct {
    s32 list[4];
    s32 timer;
    s32 f14;
    u8 f18[4];
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
} M_003C81D0;

extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_005003D0(s32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern f32 func_L01_004C93D8(void);
extern void func_L01_004C94B0(void);
extern s32 func_L01_004561B8(void *);
extern void func_L03_003C8900(void);
extern void func_L03_003C8918(u8 *m);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00511A40(void *, s32, f32);
extern s32 func_L01_00511A98(void);
extern void func_L01_00504E38(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00381CB0(void);
extern s32 func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L02_003C5DC0(s32);
extern void func_L01_003EC9E0(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L03_003C81D0(u8 *a0) {
    M_003C81D0 *m = *(M_003C81D0 **)(a0 + 0x68);
    s32 r;
    s32 t;
    u8 *e;
    s32 idx;
    f32 f;

    switch (a0[0x20]) {
    case 0:
        *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.65f;
        *(f32 *)(a0 + 0x48) = 0.5f;
        m->timer = 0;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (m->f14 != 0 && D_001A4BE0_003C81D0.state != 0x74) {
            m->f14 = 0;
            func_L01_005003D0(0, 0);
            D_001A4BE0_003C81D0.f25F8 = m->f1C;
            D_001A4BE0_003C81D0.f2604 = m->f20;
        }
        if (D_001A4BE0_003C81D0.body_kind == 0 && D_001A4BE0_003C81D0.f288C == 0 && func_0038CAD0(&m->timer) &&
            D_L03_002E52F0[0] == 0 && D_L03_002E52F0[9] == -1 &&
            func_L01_0040E570(a0 + 0x10, &D_001A4BE0_003C81D0.pos) < 1.5f && D_001A4BE0_003C81D0.f360 != 0) {
            f = D_001A4BE0_003C81D0.f98;
            if (-1.5707964f < f && f < 1.5707964f) {
                func_L01_00452560(0, 1, 0x8BB, 1, 0, 0, 0);
                if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                    if (func_L01_004C93D8() != 0.0f) {
                        R_003C81D0 t;
                        func_L01_004C94B0();
                        D_001427F0[0x16]++;
                        t = D_L03_002C49C0[D_001425C0[0x16]];
                        if (t.max < D_001427F0[0x16]) {
                            D_001427F0[0x16] = t.max;
                        }
                    }
                    func_L01_004450F0(a0, 3, -1);
                }
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            *(vu0_v4 *)(&D_001A4BE0_003C81D0.pos) = *(vu0_v4 *)(a0 + 0x10);
            D_001A4BE0_003C81D0.pos.z += 0.2f;
            func_L01_005003D0(0x74, 1);
            m->timer = 0x2A;
        }
        ((void (*)(u8 *))func_L03_003C8900)(a0);
        if (func_0038CAD0(&m->timer)) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        D_001A4BE0_003C81D0.f238 = 0x25;
        if (func_L01_004561B8(a0)) {
            vu0_v4 v;
            m->f1C = D_001A4BE0_003C81D0.f1228;
            m->f20 = D_001A4BE0_003C81D0.f1318;
            func_0038D000(&v, D_L03_001DEEA0, a0 + 0xC0);
            vec_add_ab(&v, &v, a0 + 0x10);
            func_L01_00511A40(&v, 0, *(f32 *)(a0 + 0xF8));
        }
        r = func_L01_00511A98();
        if (r == 2 && D_001A4BE0_003C81D0.moby[0x42] == D_001A4BE0_003C81D0.moby[0x43]) {
            D_001A4BE0_003C81D0.f2604 = r;
            D_001A4BE0_003C81D0.f25F8 = 1;
            func_L01_004450F0(a0, 4, -1);
            break;
        }
        if ((*(u16 *)(a0 + 0x96))++ >= 0xFB) {
            func_L01_00504E38(0);
            D_001A4BE0_003C81D0.f25F8 = m->f1C;
            D_001A4BE0_003C81D0.f2604 = m->f20;
            func_L01_004450F0(a0, 1, -1);
        } else if (r == 0) {
            D_001A4BE0_003C81D0.f25F8 = m->f1C;
            D_001A4BE0_003C81D0.f2604 = m->f20;
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            func_L01_005003D0(0x74, 1);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 0);
            }
            a0[0xBC] = 0;
        }
        ((void (*)(u8 *))func_L03_003C8900)(a0);
        if (a0[0x60] & 2) {
            if (a0[0x43] != 2) {
                func_003C3A10(a0, 2, 0, 0);
            }
            m->f28 = func_00381CB0();
            func_L01_005147A8(0);
            if (func_00381CB0() != m->f28) {
                func_L01_00425978(D_001426A0[0]);
            }
            ((s32 (*)(s32, s32, s32, s32, s32))func_003A0EC0)(5, 1, 3, 0, 0);
            a0[0xBC] = 1;
        } else if ((t = a0[0xBC]) == 1) {
            func_L01_005003D0(0x74, 1);
            if (D_L03_002428C0[0x768 / 4] != 0) {
                func_L02_003C5DC0(m->list[D_L03_002428C0[0x768 / 4] - 1]);
                func_L01_003EC9E0(m->list[D_L03_002428C0[0x768 / 4] - 1]);
                D_L03_002428C0[0x768 / 4] = 0;
                m->f14 = t;
                if (m->f24 == -1 || *(u8 **)((e = D_001A30B0 + (m->f24 << 7)) + 0xDC) != a0 || e[0xD0] == 0) {
                    m->f24 = func_003A52A0(4, 4, a0);
                }
                func_003A52A0(5, 0, a0);
                func_L01_004450F0(a0, 5, -1);
            } else {
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 0);
                }
                m->f14 = 0;
                if (func_00381CB0() != m->f28) {
                    func_L01_005147A8(m->f28);
                    func_L01_00425978(D_001426A0[0]);
                }
                func_L01_004450F0(a0, 6, -1);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(a0)) {
            func_L01_00425978(D_001426A0[0]);
            m->timer = 0xB7;
        }
        ((void (*)(u8 *))func_L03_003C8900)(a0);
        func_L03_003C8918(a0);
        if (func_0038CAD0(&m->timer)) {
            idx = m->f24;
            if (idx != -1 && *(u8 **)((e = D_001A30B0 + (idx << 7)) + 0xDC) == a0 && e[0xD0] != 0) {
                func_003A4F28(idx);
            }
            m->f24 = -1;
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 0);
            }
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 6:
        ((void (*)(u8 *))func_L03_003C8900)(a0);
        if (a0[0x60] & 2) {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 0);
            }
            m->timer = m->f14 ? 200 : 100;
            if (m->f14 == 0) {
                func_L01_005003D0(0, 0);
                D_001A4BE0_003C81D0.f25F8 = m->f1C;
                D_001A4BE0_003C81D0.f2604 = m->f20;
            }
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    if (a0[0x31] != 0) {
        func_L01_00451DB8(a0, m->f18, 0x7FA0A0A0, 0x7F505050, 0.16755162f);
    }
}
/* localdecomp:end func_L03_003C81D0 */

/* localdecomp:start func_L03_003C8900 */
extern u8 D_001A4BE0[];
void func_L03_003C8900(void) {
    u8 *p = D_001A4BE0;
    s32 v = 2;
    *(s32 *)(p + 568) = v;
    *(s16 *)(p + 546) = v;
}
/* localdecomp:end func_L03_003C8900 */

/* localdecomp:start func_L03_003C8918 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L03_00458A70(void *, void *, f32, s32, s32, s32);
extern s32 D_L03_001DF4C0;

void func_L03_003C8918(u8 *m) {
    s32 i;
    f32 a;
    f32 t;
    s32 n;
    vu0_v4 p;
    vu0_v4 v;

    for (i = 0; i < 16; i++) {
        a = 0.0f;
        if ((D_L03_001DF4C0 & 3) != (i & 3)) {
            continue;
        }
        a = func_0038DAB8(a, (f32)i * 6.2831855f * 0.0625f);
        p.x = func_0038D098(a) * 1.05f;
        p.y = func_0038D0B0(a) * 1.05f;
        *(s32 *)&p.z = 0;
        vec_add_ab(&p, m + 0x10, &p);
        func_00382580(&v, 0.004f, 0.008f);
        v.z += func_003824E0(0.026f, 0.032f);
        t = func_003824E0(0.1f, 0.25f);
        n = (func_00382498(15, 30) * 5 + 2) / 6;
        func_L03_00458A70(&p, &v, t, n, func_00382498(-8, 8), 0x60FFFFFF);
    }
}
/* localdecomp:end func_L03_003C8918 */

/* localdecomp:start func_L03_003C8AC0 */
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern s32 D_L03_002428C0_003C8AC0[];
extern f32 D_L03_001DEED0_003C8AC0;
extern f32 D_L03_001DEED4_003C8AC0;
extern f32 D_L03_001DEED8_003C8AC0;
extern void func_L01_00450DE8_003C8AC0(void *, void *, f32, f32, f32);
extern f32 func_L01_0040E570_003C8AC0(void *, void *);
extern void func_L01_00452560_003C8AC0(s32, s32, s32, s32, s32, s32, s32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L01_004450F0_003C8AC0(void *, s32, s32);
extern s32 func_L01_004561B8_003C8AC0(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00443B88_003C8AC0(void *, f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L03_00458A70_003C8AC0(void *, void *, f32, s32, s32, s32);
extern void func_L01_00451DB8_003C8AC0(void *, void *, s32, s32, f32);
extern void func_L03_003C8F78_003C8AC0(u8 *o);

void func_L03_003C8AC0(u8 *a0) {
    u8 *m;
    vu0_v4 p;
    vu0_v4 r;
    vu0_v4 pos;
    s32 n;
    s32 i;
    f32 len;
    f32 x;
    f32 y;
    f32 f;
    s32 col;
    s32 c1;
    s32 c2;
    s32 k;
    f32 sz;

    m = *(u8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        func_L01_004450F0_003C8AC0(a0, 1, -1);
        break;
    case 1:
        func_L01_00450DE8_003C8AC0(a0, &pos, D_L03_001DEED0_003C8AC0, D_L03_001DEED4_003C8AC0, D_L03_001DEED8_003C8AC0);
        if (D_001A4BE0[0x25E4] == 0 && *(s16 *)(D_001A4BE0 + 0x288C) == 0 &&
            func_L01_0040E570_003C8AC0(&pos, D_001A4BE0 + 0x80) < 1.44f && *(s32 *)(D_001A4BE0 + 0x360) != 0) {
            f = *(f32 *)(D_001A4BE0 + 0x98);
            if (-3.1415927f < f && f < 0.0f) {
                func_L01_00452560_003C8AC0(0, 1, 0x8BC, 1, 0, 0, 0);
                if (*(s32 *)(D_001D52FC + 0x1A4) & 0x10) {
                    func_003A0EC0(5, 1, 2, 0, 0);
                }
            }
        }
        if (D_L03_002428C0_003C8AC0[0x76C / 4] != 0) {
            D_L03_002428C0_003C8AC0[0x76C / 4] = 0;
            func_L01_004450F0_003C8AC0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8_003C8AC0(a0)) {
            n = 30;
            *(s32 *)m = 100;
        } else {
            n = 5;
            if (func_0038CAD0(m)) {
                func_L01_004450F0_003C8AC0(a0, 1, -1);
            }
        }
        for (i = 0; i < n; i++) {
            func_L01_00443B88_003C8AC0(&r, 0.020000001f, 0.040000002f);
            len = func_0038CED8(&r);
            if (func_00382468(2)) {
                p.x = func_003824E0(-3.0f, 3.0f) + func_003824E0(0.3f, 1.0f) * r.x / len + 2.4f;
                p.y = func_003824E0(0.3f, 1.0f) * r.y / len + -1.4f;
            } else {
                p.x = func_003824E0(0.3f, 1.0f) * r.x / len + 2.4f;
                x = func_003824E0(-0.5f, 3.0f);
                y = func_003824E0(-0.5f, 4.0f);
                p.y = x + y + func_003824E0(0.3f, 1.0f) * r.y / len;
            }
            p.z = func_003824E0(0.5f, 3.0f);
            vec_add_ba(&p, &p, a0 + 0x10);
            c1 = func_00382468(0x7F);
            c2 = func_00382468(0x7F);
            col = func_0038DBD8(0x7F000000 | (c1 << 16) | (c2 << 8) | func_00382468(0x7F), 0x7FB0B0B0, 0.8f);
            sz = func_003824E0(1.2f, 2.4f);
            k = (func_00382498(30, 80) * 5 + 2) / 6;
            func_L03_00458A70_003C8AC0(&p, &r, sz, k, func_00382498(-4, 4), col);
        }
        break;
    }
    if (a0[0x31] != 0) {
        func_L01_00451DB8_003C8AC0(a0, m + 4, 0x7FA0A0A0, 0x7F505050, 0.16755162f);
    }
    func_L03_003C8F78_003C8AC0(a0);
}
/* localdecomp:end func_L03_003C8AC0 */

/* localdecomp:start func_L03_003C8F78 */
#include "vu0.h"

extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046C470_003C8F78(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern f32 D_L03_001DEEB0_003C8F78[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DEEB0_003C8F78, 4");
extern f32 D_L03_001DEEC0_003C8F78[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DEEC0_003C8F78, 4");
extern u8 D_L03_001D66B0_003C8F78[] __attribute__((section(".sdata")));

typedef struct { u8 pad[8]; f32 vel[2]; f32 pos[2]; s32 tm[2]; } M_3C8F78_003C8F78;

void func_L03_003C8F78(u8 *o) {
    M_3C8F78_003C8F78 *m = *(M_3C8F78_003C8F78 **)(o + 0x68);
    s32 i;
    f32 t;
    f32 s;
    vu0_v4 v;

    for (i = 0; i < 2; i++) {
        if (func_0038CAD0(&m->tm[i])) {
            m->tm[i] = func_00382498(0xA7, 0x14D);
            m->pos[i] = 0.0f;
            m->vel[i] = func_003824E0(0.020000001f, 0.060000002f);
        }
        t = m->pos[i] += m->vel[i];
        if (t > 0.0f && t <= 1.0f) {
            func_0038CDF8(&v, D_L03_001DEEB0_003C8F78, D_L03_001DEEC0_003C8F78, t);
            v.y += (f32)i * 0.3f;
            s = func_003824E0(0.3f, 0.7f);
            func_L01_0046C470_003C8F78(&v, D_L03_001D66B0_003C8F78, 0x4010A090, s, 2, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
}
/* localdecomp:end func_L03_003C8F78 */
