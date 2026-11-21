#include "common.h"
#include "vu0.h"

__asm__(".extern D_001D545C, 16");
__asm__(".extern D_L04_001DD988, 8");

/* localdecomp:start func_L04_00379A18 */
extern s32 D_L04_001DD988[2];

s32 *func_L04_00379A18(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 8;
        return D_L04_001DD988;
    }
    return 0;
}
/* localdecomp:end func_L04_00379A18 */

/* localdecomp:start func_L04_00379A38 */
extern void func_L04_00379B28(u8 *, u8 *);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00404A10_00379A38(void *, void *);
extern void func_L04_00379D10(u8 *);
extern void func_L04_0037A190(u8 *);
extern s32 D_001D545C;

void func_L04_00379A38(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 pos;
    f32 r;
    if (*(u16 *)(m + 0x34) & 0x80) {
        return;
    }
    switch (m[0x20]) {
    case 0:
        func_L04_00379B28(m, v);
        break;
    case 1:
        *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
        pos.w = 4.0f;
        r = 40.0f;
        if (D_001D545C == 11) {
            r = 255.0f;
        }
        if (func_0038DC20(&pos, r) != -1) {
            if (func_L01_00456250(m) != 0) {
                func_L01_00404A10_00379A38(func_L04_00379D10, m);
            } else if (*(s32 *)(v + 4) != 6) {
                func_L01_00404A10_00379A38(func_L04_0037A190, m);
            }
        }
        break;
    }
}
/* localdecomp:end func_L04_00379A38 */

/* localdecomp:start func_L04_00379B28 */
extern u8 *func_L04_003BAA98(u8 *);
extern u8 *func_L04_003BAF58(u8 *);
extern u8 *func_L04_003BB2E0(u8 *);
extern void func_L01_004AA7E8(void *, s32);

void func_L04_00379B28(u8 *m, u8 *v) {
    u8 *c;
    s32 t;
    if (D_001D545C == 11) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
    } else {
        m[0x30] = 0x28;
        *(s16 *)(m + 0x32) = 0x28;
    }
    *(s32 *)v = 0;
    m[0x20] = 1;
    c = 0;
    t = *(s32 *)(v + 4);
    if (t != -1 || *(s32 *)(v + 8) != t) {
        if (t != 0) {
            c = func_L04_003BAA98(m);
        } else if (*(s32 *)(v + 8) != 0) {
            c = func_L04_003BAF58(m);
        } else {
            c = func_L04_003BB2E0(m);
        }
    }
    if (*(s32 *)(v + 4) == 6) {
        *(s32 *)(c + 0x98) = 0;
        *(u16 *)(c + 0x34) = (*(u16 *)(c + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(c, 1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    if (*(s32 *)(v + 4) == 5) {
        *(u16 *)(c + 0x34) |= 0x41;
    }
    *(u16 *)(m + 0x34) |= 0x41;
}
/* localdecomp:end func_L04_00379B28 */

/* localdecomp:start func_L04_00379C68 */
f32 func_L04_00379C68(void *arg0) {
    s32 temp_v1;
    void *temp_a0;

    temp_a0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v1 = *(s32 *)((u8 *)temp_a0 + 4);
    if (((temp_v1 != -1) || ((*(s32 *)((u8 *)temp_a0 + 8)) != temp_v1)) && ((temp_v1 != 0) || ((*(s32 *)((u8 *)temp_a0 + 8)) != 0))) {
        return 0.5f;
    }
    return 0.25f;
}
/* localdecomp:end func_L04_00379C68 */

/* localdecomp:start func_L04_00379CC0 */
extern f32 func_L04_00379C68(void *arg0);
extern void func_0038CE20(void *, void *, f32);

void func_L04_00379CC0(u8 *a0, void *out) {
    f32 s = func_L04_00379C68(a0);
    func_0038CE20(out, a0 + 0xC0, s);
    vec_add_ba(out, out, a0 + 0x10);
}
/* localdecomp:end func_L04_00379CC0 */

/* localdecomp:start func_L04_00379D10 */
extern s32 D_001D545C;
extern u8 D_L04_001E2840[];
extern f32 func_L04_00379C68(void *arg0);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003A9440(s32, unsigned long);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L04_00379D10(u8 *m) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 t;
    s32 *v = *(s32 **)(m + 0x68);
    f32 s, d, k, r, q, sz;
    s32 c1, c0;
    s32 i;

    s = func_L04_00379C68(m);
    d = func_L01_0040E548(D_L04_001E2840, m + 0x10);
    if (D_001D545C == 11) {
        if (d > 65025.0f) {
            return;
        }
        if (d > 46225.0f) {
            k = (sqrt_asm(d) - 215.0f) * 0.025f;
            c0 = func_0038DBD8(0x7FD00250, 0x7F000000, k);
            c1 = func_0038DBD8(0xD03050, 0, k);
        } else {
            k = 0.0f;
            c0 = 0x7FD00250;
            c1 = 0xD03050;
        }
    } else {
        if (d > 1600.0f) {
            return;
        }
        if (d > 1024.0f) {
            k = (sqrt_asm(d) - 32.0f) * 0.125f;
            c0 = func_0038DBD8(0x7FD00250, 0x7F000000, k);
            c1 = func_0038DBD8(0xD03050, 0, k);
        } else {
            k = 0.0f;
            c0 = 0x7FD00250;
            c1 = 0xD03050;
        }
    }
    func_003A9440(0x47, 0x53001);
    for (i = 0; i < 5; i++) {
        r = func_00382538();
        q = func_L01_00443A18(0.35f, 0.5f);
        func_0038CE20(&t, m + 0xC0, s);
        vec_add_ab(&a, &t, m + 0x10);
        func_0038CE20(&t, m + 0xD0, func_0038D098(r) * q * 0.25f);
        vec_add_ab(&a, &t, &a);
        func_0038CE20(&t, m + 0xE0, func_0038D0B0(r) * q * 0.25f);
        vec_add_ab(&a, &t, &a);
        func_0038CE20(&t, m + 0xC0, func_003824E0(2.0f, 3.5f));
        vec_add_ab(&b, &t, &a);
        func_0038CE20(&t, m + 0xD0, func_0038D098(r) * q);
        vec_add_ab(&b, &t, &b);
        func_0038CE20(&t, m + 0xE0, func_0038D0B0(r) * q);
        vec_add_ab(&b, &t, &b);
        func_L01_0040A8C0(&a, &b, 0x2B, 1, func_003824E0(0.1f, 0.2f), 3.5f, 0.0f, c0, c0, c1, c1);
    }
    func_0038CE20(&a, m + 0xC0, s);
    vec_add_ba(&a, &a, m + 0x10);
    c0 = func_0038DBD8(0xF0FF6070, 0xF0000000, k);
    if (v[1] == 6) {
        sz = func_003824E0(3.9f, 4.3f);
        func_003D9508(&a, 0x31, c0, 1, sz, 1.5f, func_00382538());
    } else {
        sz = func_003824E0(0.6f, 0.9f);
        func_003D9508(&a, 0x31, c0, 1, sz, 0.5f, func_00382538());
    }
}
/* localdecomp:end func_L04_00379D10 */

/* localdecomp:start func_L04_0037A190 */
void func_L04_0037A190(u8 *m) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 t;
    f32 s, d, k, r, q, sz;
    s32 c1, c0;
    s32 i;

    s = func_L04_00379C68(m);
    d = func_L01_0040E548(D_L04_001E2840, m + 0x10);
    if (D_001D545C == 11) {
        if (d > 10200.0f) {
            return;
        }
        if (d > 46225.0f) {
            k = (sqrt_asm(d) - 215.0f) * 0.025f;
            c0 = func_0038DBD8(0x7FC00000, 0x7F000000, k);
            c1 = func_0038DBD8(0xD00000, 0, k);
        } else {
            k = 0.0f;
            c0 = 0x7FC00000;
            c1 = 0xD00000;
        }
    } else {
        if (d > 1600.0f) {
            return;
        }
        if (d > 1024.0f) {
            k = (sqrt_asm(d) - 32.0f) * 0.125f;
            c0 = func_0038DBD8(0x7FC00000, 0x7F000000, k);
            c1 = func_0038DBD8(0xD00000, 0, k);
        } else {
            k = 0.0f;
            c0 = 0x7FC00000;
            c1 = 0xD00000;
        }
    }
    func_003A9440(0x47, 0x53001);
    for (i = 0; i < 3; i++) {
        r = func_00382538();
        q = func_L01_00443A18(0.35f, 0.5f);
        func_0038CE20(&t, m + 0xC0, s);
        vec_add_ab(&a, &t, m + 0x10);
        func_0038CE20(&t, m + 0xD0, func_0038D098(r) * q * 0.25f);
        vec_add_ab(&a, &t, &a);
        func_0038CE20(&t, m + 0xE0, func_0038D0B0(r) * q * 0.25f);
        vec_add_ab(&a, &t, &a);
        func_0038CE20(&t, m + 0xC0, func_003824E0(1.0f, 1.5f));
        vec_add_ab(&b, &t, &a);
        func_0038CE20(&t, m + 0xD0, func_0038D098(r) * q);
        vec_add_ab(&b, &t, &b);
        func_0038CE20(&t, m + 0xE0, func_0038D0B0(r) * q);
        vec_add_ab(&b, &t, &b);
        func_L01_0040A8C0(&a, &b, 0x2B, 1, func_003824E0(0.1f, 0.2f), 3.5f, 0.0f, c0, c0, c1, c1);
    }
    func_0038CE20(&a, m + 0xC0, s);
    vec_add_ab(&a, &a, m + 0x10);
    c0 = func_0038DBD8(func_0038DBD8(0x7FFF2020, 0x50FF2020, func_003824E0(0.0f, 1.0f)), 0x50000000, k);
    sz = func_003824E0(0.5f, 0.8f);
    func_003D9508(&a, 0x31, c0, 1, sz, 0.3f, func_00382538());
}
/* localdecomp:end func_L04_0037A190 */

/* localdecomp:start func_L04_0037A5B8 */
typedef struct {
    u8 pad[0x68];
    s32 *w68;
} Moby_003791A0;

extern void func_L01_00456230(Moby_003791A0 *, s32);

void func_L04_0037A5B8(Moby_003791A0 *m, s32 value, s32 force) {
    s32 *p = m->w68;
    if (p == 0) return;
    if (force == 0 && *p != value) return;
    *p = value;
    func_L01_00456230(m, force);
}
/* localdecomp:end func_L04_0037A5B8 */
