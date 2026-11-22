#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B8F10 */
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, s32 delay, f32 unk);
extern u8 D_L03_001D66B0[8];

void func_L03_003B8F10(u8 *a0) {
    f32 size = func_003824E0(1.0f, 2.0f);
    s32 spin = func_00382468(2);
    if (spin == 0) {
        spin--;
    }
    func_L01_0046B458(a0 + 0x10, 0x11, size * 0.3f, size, 0x88202080, 0, spin, D_L03_001D66B0, 0, 0.0f);
}
/* localdecomp:end func_L03_003B8F10 */

/* localdecomp:start func_L03_003B8FA0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B8FA0;
extern void func_L01_00443B88(f32 *, f32, f32);

void func_L03_003B8FA0(V4_003B8FA0 *at, s32 n, s32 c1, s32 c2) {
    V4_003B8FA0 pos;
    V4_003B8FA0 vel;
    f32 size;
    s32 spin;
    u8 *p;
    u8 *pp = (u8 *)&pos;
    s32 i;

    pos = *at;
    for (i = 0; i < n; i++) {
        size = func_003824E0(1.0f, 2.0f);
        spin = func_00382468(2);
        if (spin == 0) {
            spin--;
        }
        func_L01_00443B88((f32 *)&vel, 0.05f, 0.25f);
        p = func_L01_0046B458(pp, 0x11, size * 0.1f, size, c1, 0, spin, &vel, 0, 0.0028800003f);
        if (p != 0) {
            p[9] = 0x74;
        }
        p = func_L01_0046B458(pp, 0x11, size * 0.07f, size * 0.7f, c2, 1, -spin, &vel, 0, 0.0028800003f);
        if (p != 0) {
            p[9] = 0x74;
        }
    }
}
/* localdecomp:end func_L03_003B8FA0 */

/* localdecomp:start func_L03_003B9130 */
extern void func_L01_00443B88(f32 *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
__asm__(".extern D_L03_001DEA8C, 4");
__asm__(".extern D_L03_001DEA90, 4");
__asm__(".extern D_L03_001DEA94, 4");
__asm__(".extern D_L03_001DEA98, 4");
extern f32 D_L03_001DEA8C;
extern f32 D_L03_001DEA90;
extern u8 D_L03_001DEA94;
extern f32 D_L03_001DEA98;

typedef struct {
    u8 *m;
    s32 w4;
    s16 h8;
    u16 hA;
    s32 pad0C;
    f32 v10[3];
} Ctl_3B9130;

void func_L03_003B9130(u8 *e, Ctl_3B9130 *s) {
    u8 *m;
    vu0_v4 d;
    s32 i;
    f32 f;
    f32 c;
    s32 w;
    if (s == 0) {
        return;
    }
    m = s->m;
    w = s->w4;
    if (m == 0 || w == 0) {
        return;
    }
    if ((u8)(m[0x20] + 2) < 2) {
        *(s16 *)(e + 0xA) = 0;
        return;
    }
    if (s->hA & 1) {
        e[2] = D_L03_001DEA94;
        *(vu0_q *)(e + 0x10) = *(vu0_q *)(m + 0x10);
        func_L01_00443B88(&d.x, D_L03_001DEA8C * 0.020000001f, D_L03_001DEA90 * 0.020000001f);
        c = D_L03_001DEA98 * 210000.0f;
        s->v10[0] = d.x;
        s->v10[1] = d.y;
        s->v10[2] = d.z;
        *(u32 *)(e + 4) = 0x88202080;
        *(f32 *)(e + 0xC) = c;
    }
    *(u32 *)(e + 4) = (*(u32 *)(e + 4) & 0xFFFFFF) | ((s32)((f32)*(s16 *)(e + 0xA) * 128.0f / (f32)s->h8) << 24);
    for (i = 0; i < 3; i++) {
        (&d.x)[i] = s->v10[i];
    }
    f = (f32)(s->h8 - *(s16 *)(e + 0xA));
    if (f < 1.0f) {
        f = 1.0f;
    }
    func_0038CE20(&d, &d, f);
    vec_add_ab(e + 0x10, m + 0x10, &d);
}
/* localdecomp:end func_L03_003B9130 */

/* localdecomp:start func_L03_003B92E8 */
#include "vu0.h"

extern void func_003C2F58(u8 *, s32, u8 *);

typedef struct {
    vu0_q v0;
    void *p10;
    s32 i14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} __attribute__((aligned(16))) Coll_3B92E8;

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
} G_3B92E8_003B92E8;

extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446748_003B92E8(void *, void *, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640_003B92E8(void *, s32, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_004AAC98_003B92E8(s32, s32, void *, s32);
extern void func_003A4F28(s32);
extern void func_003C2880(void *);
extern void func_L01_00404808_003B92E8(void *, void *);
extern void func_L03_003B97E0_003B92E8(u8 *a0);
extern u8 D_001A30B0[];
extern G_3B92E8_003B92E8 D_L03_001E9200_003B92E8;
extern s32 D_L03_001D6694_003B92E8;
__asm__(".extern D_L03_001D6694_003B92E8, 16");

static __inline__ void stop_3B92E8(u8 *m, u8 *s) {
    s32 id = *(s32 *)(s + 0x38);
    if (id != -1) {
        u8 *c = D_001A30B0 + id * 0x80;
        if (*(u8 **)(c + 0xDC) == *(u8 **)(m + 0xB8) && c[0xD0] != 0) {
            func_003A4F28(id);
        }
    }
    *(s32 *)(s + 0x38) = -1;
    func_003C2880(m);
}

void func_L03_003B92E8(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    u8 *c;
    u8 *o;
    u8 *t;
    s32 id;
    vu0_v4 d;
    vu0_v4 old;
    Coll_3B92E8 coll;

    if (m[0x20] == 0) {
        id = *(s32 *)(s + 0x38);
        if (id == -1 || *(u8 **)((c = D_001A30B0 + id * 0x80) + 0xDC) != *(u8 **)(m + 0xB8) || c[0xD0] == 0) {
            *(s32 *)(s + 0x38) = func_003A52A0(6, 4, *(u8 **)(m + 0xB8));
        }
        func_003C2F58(*(u8 **)(s + 0x30), *(s32 *)(s + 0x34), s + 0x10);
        func_003C2F58(*(u8 **)(s + 0x30), *(s32 *)(s + 0x34) - 0x20, s);
        if (*(s32 *)(s + 0x28) == 0) {
            *(f32 *)(s + 0x2C) += *(f32 *)(s + 0x20);
        } else {
            *(f32 *)(s + 0x2C) -= *(f32 *)(s + 0x20);
        }
        *(vu0_q *)&old = *(vu0_q *)(m + 0x10);
        vec_sub_ba(&d, s, s + 0x10);
        func_0038CF68(&d, &d, *(f32 *)(s + 0x2C));
        vec_add_ab(m + 0x10, s + 0x10, &d);
        func_L01_00446748_003B92E8(&coll, m, 1, 1.0f);
        coll.h1A = *(u16 *)(m + 0xAA);
        if (*(s32 *)(s + 0x28) == 0) {
            if (func_003D3CB0(&old, m + 0x10, 0, m, &coll) != 0 ||
                func_L01_003FB640_003B92E8(m + 0x10, 0, m, 0.3f) != 0) {
                if (D_L03_001E9200_003B92E8.f18 != 0 && (*(s16 *)(D_L03_001E9200_003B92E8.f18 + 0xAA) == 0x1C04 ||
                                                 *(s16 *)(D_L03_001E9200_003B92E8.f18 + 0xAA) == 0x1C06)) {
                    *(s32 *)(s + 0x28) = 1;
                    t = D_L03_001E9200_003B92E8.f18;
                    if (*(s16 *)(t + 0xAA) == 0x1C04 && *(s32 *)(*(u8 **)(t + 0x68) + 0x24) == 1) {
                        *(u8 **)(s + 0x24) = t;
                        t[0x20] = 1;
                        *(s32 *)(*(u8 **)(s + 0x24) + 0x98) = 0;
                    }
                    return;
                }
            }
        }
        if ((*(s32 *)(s + 0x28) == 0 && func_0038CF38(m + 0x10, s) <= *(f32 *)(s + 0x20) * 0.88f) ||
            (*(s32 *)(s + 0x28) == 1 && func_0038CF38(m + 0x10, s + 0x10) <= *(f32 *)(s + 0x20) * 0.88f)) {
            t = *(u8 **)(s + 0x24);
            if (t != 0) {
                t[0x20] = 2;
                o = *(u8 **)(m + 0xB8);
                if (o != 0 && *(s16 *)(o + 0xAA) == 0x1AE0) {
                    func_L01_004AAC98_003B92E8(7, 0, o, 0x1AE0);
                }
            }
            stop_3B92E8(m, s);
            return;
        }
        func_L01_00404808_003B92E8(func_L03_003B97E0_003B92E8, m);
        if (*(u8 **)(s + 0x24) != 0) {
            *(vu0_q *)(*(u8 **)(s + 0x24) + 0x10) = *(vu0_q *)(m + 0x10);
        }
    } else if (m[0x20] == 1) {
        if (D_L03_001D6694_003B92E8 != 7) {
            stop_3B92E8(m, s);
        }
    }
}
/* localdecomp:end func_L03_003B92E8 */

/* localdecomp:start func_L03_003B9688 */
typedef int u128_3B9760 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2F58(u8 *, s32, u8 *);

u8 *func_L03_003B9688(u8 *a0, s32 a1, f32 f) {
    u8 *m = func_003C24B0(0x1C19, 0x80);
    if (m != 0) {
        u8 *pv = *(u8 **)(m + 0x68);
        u8 *s;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(pv + 0x20) = f * 0.020000001f;
        *(s32 *)(pv + 0x28) = 0;
        *(s32 *)(pv + 0x2C) = 0;
        *(s32 *)(pv + 0x34) = a1;
        s = *(u8 **)(a0 + 0x68);
        func_003C2F58(*(u8 **)s, a1, pv + 0x10);
        func_003C2F58(*(u8 **)s, a1 - 0x20, pv);
        *(s32 *)(pv + 0x30) = *(s32 *)s;
        *(u128_3B9760 *)(m + 0x10) = *(u128_3B9760 *)(pv + 0x10);
    }
    return m;
}
/* localdecomp:end func_L03_003B9688 */

/* localdecomp:start func_L03_003B9760 */
extern void func_003D9508(u8 *, s32, u32, s32, f32, f32, f32);
__asm__(".extern D_L03_001DEAA0, 4");
__asm__(".extern D_L03_001DEAA4, 4");
extern s32 D_L03_001DEAA0;
extern s32 D_L03_001DEAA4;

void func_L03_003B9760(u8 *a0, u32 a1) {
    u128_3B9760 v = *(u128_3B9760 *)a0;
    func_003D9508((u8 *)&v, D_L03_001DEAA0, a1, 1, 0.75f, 0.0f, 0.0f);
    func_003D9508((u8 *)&v, D_L03_001DEAA4, 0x8020F020, 1, 0.5f, 0.08f, 0.0f);
}
/* localdecomp:end func_L03_003B9760 */

/* localdecomp:start func_L03_003B97E0 */
extern void func_L03_003B9760(u8 *a0, u32 a1);
extern void func_L01_0040A8C0(u128_3B9760 *a, u128_3B9760 *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 f0, f32 f1, f32 f2);
__asm__(".extern D_L03_001DEAA8, 4");
extern u32 D_L03_001DEAA8;

void func_L03_003B97E0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u128_3B9760 v;
    u128_3B9760 w;
    if (*(s32 *)(s + 0x28) == 0) {
        v = *(u128_3B9760 *)(a0 + 0x10);
        func_L03_003B9760((u8 *)&v, 0x80288020);
    }
    v = *(u128_3B9760 *)(s + 0x10);
    func_L03_003B9760((u8 *)&v, 0x80288020);
    v = *(u128_3B9760 *)(s + 0x10);
    w = *(u128_3B9760 *)(a0 + 0x10);
    func_L01_0040A8C0(&v, &w, 0x1C, 1, D_L03_001DEAA8, D_L03_001DEAA8, D_L03_001DEAA8, D_L03_001DEAA8, 0.4f, 1.0f, 0.0f);
}
/* localdecomp:end func_L03_003B97E0 */

/* localdecomp:start func_L03_003B9898 */
extern s32 D_L03_001DF4C0;
extern s32 func_L03_0043F5D0(s32, s32, f32);

void func_L03_003B9898(u8 *m) {
    u8 *p = *(u8 **)(m + 0xB8);
    s32 n;
    f32 a;
    if (p != 0) {
        *(long *)(m + 0x38) = *(long *)(p + 0x38);
    }
    n = 100;
    a = (f32)(D_L03_001DF4C0 % n) * 6.2831855f / (f32)n - 3.1415927f;
    *(u16 *)(m + 0x34) &= 0xFF7F;
    *(s32 *)(m + 0x78) = func_L03_0043F5D0(0x55200000, 0x55100000, a);
}
/* localdecomp:end func_L03_003B9898 */

/* localdecomp:start func_L03_003B9938 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32 a, s32 b);

u8 *func_L03_003B9938(u8 *a0) {
    u8 *m = func_003C24B0(7230, 128);
    if (m != 0) {
        *(u8 *)(m + 48) = 255;
        *(u16 *)(m + 52) &= ~0x80;
        *(s16 *)(m + 50) = 64;
        *(u8 *)(m + 49) = 1;
        *(u8 **)(m + 184) = a0;
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
    }
    return m;
}
/* localdecomp:end func_L03_003B9938 */
