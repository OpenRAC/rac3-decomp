#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L28_0039D530);

/* localdecomp:start func_L28_0039E820 */
typedef int q_0039E820 __attribute__((mode(TI)));
extern s32 func_L28_0039EBC8(void *);
extern void func_003C2880(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 func_L01_0044CE88(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_L02_003A5138(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L28_0039EDB8(u8 *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
s32 func_L28_0039E820(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    s32 t;
    vu0_v4 v;
    if (a0[0x20] == 0) {
        if (func_L28_0039EBC8(a0) != 0) return 1;
    }
    if (*(f32 *)(a0 + 0x18) < *(f32 *)(st + 0x1A8) - 200.0f) {
        func_003C2880(a0);
        return 1;
    }
    func_L01_0044ABD0(a0, st + 0x180);
    p = func_L01_00447490(a0, 0x10000, 0);
    if (func_0038CB00(st + 0x36) == 0) p = 0;
    if (p != 0) {
        *(f32 *)(st + 0x30) -= *(f32 *)(p + 0x2C);
        if (*(u8 **)(p + 0x20) != a0) goto chase;
    } else {
        if (!(*(f32 *)(st + 0x30) <= 0.0f)) goto done;
        if (a0[0x20] == 8) goto done;
        if (a0[0x20] == 9) goto done;
    }
    func_L01_004450F0(a0, 9, -1);
    goto hit;
chase:
            st[0x47] = func_L01_0044CE88(*(u8 **)(p + 0x20));
            func_0038CF68(&v, p + 0x10, -1.0f);
            if (abs_asm(func_0038CE68(&v, a0 + 0xE0) < 0.9f)) *(q_0039E820 *)(a0 + 0xC0) = *(q_0039E820 *)&v;
            func_0038CE90(a0 + 0xD0, a0 + 0xE0, a0 + 0xC0);
            func_0038CF68(a0 + 0xD0, a0 + 0xD0, 1.0f);
            func_0038CE90(a0 + 0xC0, a0 + 0xD0, a0 + 0xE0);
            func_0038CF68(a0 + 0xC0, a0 + 0xC0, 1.0f);
            *(s16 *)(st + 0x36) = 0x11;
            func_003C4A40(a0, st + 0x180);
            func_L01_004450F0(a0, 8, -1);
hit:
    func_L02_003A5138(a0);
done:
    a0[0xA8] = 0xFF;
    func_L01_00452860(a0, st + 0x30, 0);
    if (st[0x5E] != 0) {
        func_L28_0039EDB8(a0);
        return 1;
    }
    if (st[0x3E] == 2) return 1;
    if (st[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x190), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x194), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x198), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(st + 0x19C), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        t = a0[0x20];
        if ((u32)(t - 3) < 2 || t == 1) {
            func_L01_00456C98(a0, *(s32 *)(st + 0x190), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x194), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(st + 0x198), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(st + 0x19C), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L28_0039E820 */

INCLUDE_ASM("asm/levels", func_L28_0039EBC8);

/* localdecomp:start func_L28_0039EDB8 */
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L28_0039D038(void *);
extern void func_L01_004443E8(u8 *, s32, s32);
typedef int q_0039EDB8 __attribute__((mode(TI)));
static __inline__ void spawn_0039EDB8(u8 *self, u8 *st, f32 side) {
    vu0_v4 a, b;
    u8 *m;
    u8 *d;
    m = func_003C24B0(0x1B5D, 0x200);
    if (m != 0) {
        func_L01_00456160(m, self);
        *(u16 *)(m + 0x34) |= 0x20;
        func_L01_0044A7D0(m);
        d = *(u8 **)(m + 0x68);
        *(s32 *)(d + 0x180) = *(s32 *)(st + 0x190);
        *(s32 *)(d + 0x188) = *(s32 *)(st + 0x198);
        *(f32 *)(d + 0x18C) = *(f32 *)(st + 0x19C);
        *(f32 *)(d + 0x184) = *(f32 *)(st + 0x194);
        *(u8 **)(d + 0x1C) = d + 0x70;
        *(u8 **)(d + 0xC) = d + 0x160;
        *(u8 **)(d + 0x0) = d + 0x30;
        *(s16 *)(d + 0x36) = 0x1E;
        *(s32 *)(d + 0x1BC) = 2;
        func_0038CF68(&a, self + 0xD0, side);
        vec_add_ab(m + 0x10, &a, self + 0x10);
        func_0038CF68(&b, self + 0xE0, 0.6f);
        vec_add_ab(m + 0x10, &b, m + 0x10);
        *(q_0039EDB8 *)(m + 0xC0) = *(q_0039EDB8 *)(self + 0xC0);
        *(q_0039EDB8 *)(m + 0xD0) = *(q_0039EDB8 *)(self + 0xD0);
        *(q_0039EDB8 *)(m + 0xE0) = *(q_0039EDB8 *)(self + 0xE0);
        *(s16 *)(m + 0xB6) = 0x14;
        func_L28_0039D038(m);
    }
}
void func_L28_0039EDB8(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    func_003A52A0(0, 0, self);
    func_003A52A0(1, 0, self);
    spawn_0039EDB8(self, st, 0.5f);
    spawn_0039EDB8(self, st, -0.5f);
    func_L01_004443E8(self, 0, 3);
    *(u16 *)(self + 0x34) &= 0xFFDF;
}
/* localdecomp:end func_L28_0039EDB8 */

/* localdecomp:start func_L28_0039F010 */
extern u8 D_L28_001E1540[];
extern void func_L01_00404808(void *, void *);
extern void func_L08_0039F4E8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_0039F010(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L28_001E1540, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00404808(func_L08_0039F4E8, a0);
    t = func_0038DAB8(*(f32 *)(d + 0x1DC), 0.15358898f);
    *(f32 *)(d + 0x1DC) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_0039F010 */
