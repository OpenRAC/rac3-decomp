#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003B2668 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L05_003B27F8(u8 *, f32, f32, f32, u8);

void func_L05_003B2668(u8 *p) {
    u8 *s = *(u8 **)(p + 0x68);
    f32 f;
    f32 sn;
    f32 cs;
    f32 a;
    f32 b;
    u8 idx;

    f = *(f32 *)(s + 0x29C);
    *(f32 *)(s + 0x29C) = f + (f > 0.8f ? 0.02f : 0.08f);
    if (*(f32 *)(s + 0x29C) > 0.95f) {
        *(f32 *)(s + 0x29C) = 0.95f;
    }
    sn = func_0038D0B0(*(f32 *)(s + 0x29C) * 3.1415927f * 0.5f);
    cs = func_0038D098(*(f32 *)(s + 0x29C) * 3.1415927f * 0.5f);
    cs = 1.0f - cs;
    idx = (s32)((1.0f - cs) * 128.0f);
    b = sn * 0.6f + -0.3f + 1.0f;
    a = sn * 10.0f + 5.0f;
    func_L05_003B27F8(p, a, 0.0f, -0.2617994f, idx);
    func_L05_003B27F8(p, a * b, 0.61086524f, -0.2617994f, idx);
}
/* localdecomp:end func_L05_003B2668 */

/* localdecomp:start func_L05_003B27F8 */
typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 x50, x54, x58, x5C, x60, x64, x68, x6C;
    long x70, x78, x80, x88;
} S_3B27F8;
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L05_003B27F8(u8 *p, f32 scale, f32 rx, f32 ry, u8 alpha) {
    vu0_v4 v;
    vu0_v4 rot[3];
    vu0_v4 m[3];
    vu0_v4 t;
    vu0_v4 pos;
    S_3B27F8 s;
    s32 i;
    s32 c;

    *(vu0_q *)&v = 0;
    v.x = rx;
    v.y = ry;
    func_0038D308(rot, &v);
    func_0038D5F0(m, p + 0xC0, rot);
    func_0038CF68(&t, &m[2], -1.8f);
    vec_add_ab(&pos, p + 0x10, &t);
    s.x78 = func_00389598(0x3D);
    s.x88 = ((long)alpha << 32) | 0x48;
    c = (alpha << 24) | 0x204080;
    s.x80 = 0xFF9000000260L;
    s.x70 = 0;
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    for (i = 0; i < 4; i++) {
        s.m[i].x = (i & 1) == 0 ? -1.0f : 1.0f;
        s.m[i].y = (i < 2) ? -1.0f : 1.0f;
        s.m[i].z = 0.0f;
        s.m[i].w = 1.0f;
        func_0038D000(&s.m[i], &s.m[i], m);
        func_0038CE20(&s.m[i], &s.m[i], scale);
        vec_add_ba(&s.m[i], &pos, &s.m[i]);
    }
    s.x50 = 0.0f;
    s.x54 = 0.0f;
    s.x58 = 1.0f;
    s.x5C = 0.0f;
    s.x60 = 0.0f;
    s.x64 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L05_003B27F8 */

/* localdecomp:start func_L05_003B29D0 */
typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_3B29D0;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern long func_00389598(s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003A9440(s32, long);
extern void func_003D2DA0(void *, void *, s32);

void func_L05_003B29D0(u8 *p) {
    vu0_v4 pos;
    vu0_v4 t;
    S_3B29D0 s;
    u8 *v;
    f32 f;
    f32 sc;
    f32 ang;
    f32 r;
    s32 i;
    s32 j;
    s32 a;
    s32 c;

    v = *(u8 **)(p + 0x68);
    *(f32 *)(v + 0x29C) += 0.04f;
    if (*(f32 *)(v + 0x29C) > 1.0f) {
        *(f32 *)(v + 0x29C) = 1.0f;
        return;
    }
    func_0038CF68(&t, p + 0xE0, 1.0f);
    vec_add_ba(&pos, p + 0x10, &t);
    *(f32 *)(v + 0x298) = func_0038DAB8(*(f32 *)(v + 0x298), 0.05235988f);
    f = *(f32 *)(v + 0x29C);
    if (f < 0.5f) {
        sc = (f + f) * 45.0f + 5.0f;
    } else {
        sc = 50.0f;
    }
    a = (u8)(s32)((1.0f - f) * 128.0f);
    s.x78 = func_00389598(v[0x2C3] + 0x64);
    s.x88 = ((long)a << 32) | 0x4A;
    c = (a << 24) | 0x808080;
    s.x80 = 0xFF9000000260L;
    s.x70 = 0;
    s.c4C = c;
    s.c48 = c;
    s.c44 = c;
    s.c40 = c;
    for (i = 0; i < 4; i++) {
        s.m[i].x = 0.0f;
        s.m[i].y = (i & 1) == 0 ? -1.0f : 1.0f;
        s.m[i].z = (i < 2) ? -1.0f : 1.0f;
        s.m[i].w = 1.0f;
        func_0038D000(&s.m[i], &s.m[i], p + 0xC0);
        func_0038CE20(&s.m[i], &s.m[i], sc);
        vec_add_ba(&s.m[i], &pos, &s.m[i]);
    }
    ang = func_0038DB00(6.2831855f, *(f32 *)(v + 0x298));
    for (j = 0; j < 4; j++) {
        if (j < 2) {
            s.uv[j][0] = func_0038D098(ang) * 0.70710677f + 0.5f;
            s.uv[j][1] = func_0038D0B0(ang) * 0.70710677f + 0.5f;
        } else {
            s.uv[j ^ 1][0] = func_0038D098(ang) * 0.70710677f + 0.5f;
            s.uv[j ^ 1][1] = func_0038D0B0(ang) * 0.70710677f + 0.5f;
        }
        ang = func_0038DAB8(ang, 1.5707964f);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&s, 0, 0);
    f = 1.0f - f * 0.25f;
    ang = *(f32 *)(v + 0x298);
    for (j = 0; j < 4; j++) {
        if (j < 2) {
            r = f * 0.70710677f;
            s.uv[j][0] = r * func_0038D098(ang) + 0.5f;
            r *= func_0038D0B0(ang);
            r += 0.5f;
            s.uv[j][1] = r;
        } else {
            r = f * 0.70710677f;
            s.uv[j ^ 1][0] = r * func_0038D098(ang) + 0.5f;
            r *= func_0038D0B0(ang);
            r += 0.5f;
            s.uv[j ^ 1][1] = r;
        }
        ang = func_0038DAB8(ang, 1.5707964f);
    }
    s.x78 = func_00389598(0x68);
    s.x80 = 0xFF9000000260L;
    s.x70 = 5;
    s.x88 = 0x8000000054L;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&s, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L05_003B29D0 */

/* localdecomp:start func_L05_003B2E40 */
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L05_003B2E40(u8 *p) {
    s32 r;
    s32 a;

    a = 0;
    if (*(u8 *)(*(u8 **)(p + 0x68) + 0x2B8) < 3) {
        a = 3 - *(u8 *)(*(u8 **)(p + 0x68) + 0x2B8);
    }
    r = func_00382498(a, 2);
    switch (r) {
    case 0:
        func_L01_004450F0((s32) p, 9, -1);
        return;
    case 1:
        func_L01_004450F0((s32) p, 0xC, -1);
        return;
    case 2:
        func_L01_004450F0((s32) p, 0xF, -1);
        return;
    }
}
/* localdecomp:end func_L05_003B2E40 */

/* localdecomp:start func_L05_003B2EF0 */
__asm__(".extern D_001D545C, 4");
typedef struct { u8 pad[0x18]; u8 *f18; } S_3B2EF0;
extern u8 D_001BBC40[];
__asm__(".extern D_001D5570, 16");
extern u8 D_001D5570[8];
extern u8 D_001A4BE0[];
extern S_3B2EF0 D_L05_001EA6C0;
extern s32 D_001D545C;
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern u8 *func_L01_0045B958(u8 *);
s32 func_L05_003B2EF0(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    u8 *h1; u8 *h2; S_3B2EF0 *g1; S_3B2EF0 *g2;
    u8 *p;
    s32 id;
    if (*(s32 *)(st + 0x20) != 0) {
        if (D_001BBC40[self[0xB0] + (D_001D545C << 4)] & 0x80) return 1;
    }
    if (*(s32 *)(st + 0x30) != 0) {
        if (D_001D5570[*(s32 *)(st + 0x30)] != 0) return 1;
    }
    h1 = D_001A4BE0;
    if (*(u8 **)(h1 + 0x35C) == self) {
        if (*(s32 *)(h1 + 0x360) >= 2) return 1;
    }
    if (func_L01_003FB640(self + 0x10, 1, self, *(f32 *)(self + 0x2C) * 1.1f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24)) != 0) {
        g1 = &D_L05_001EA6C0;
        if (g1->f18 != 0) {
            h2 = D_001A4BE0;
            if (g1->f18 == *(u8 **)(h2 + 0x25C0) && *(u8 **)(h2 + 0x35C) == self) {
                if (*(s32 *)(st + 0x20) != 0) {
                    func_L01_0043B510(self[0xB0]);
                    func_L01_004A3610(h2 + 0x80, h2 + 0x90);
                }
                return 1;
            }
            g2 = &D_L05_001EA6C0;
            if (*(u16 *)(g2->f18 + 0x34) & 0x20) {
                p = func_L01_0045B958(g2->f18);
                if (p != 0 && (*(u8 **)(p + 0x88) == self || *(u8 **)(p + 0x84) == self)) {
                    id = *(s16 *)(g2->f18 + 0xAA);
                    if (id == 0x1A4E || id == 0x1AA0 || id == 0x1BD3 || id == 0x16BE || id == 0x1BA0) return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003B2EF0 */
