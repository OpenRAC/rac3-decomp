#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    s32 vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby_003A46C8;

/* localdecomp:start func_L11_003A2CD0 */
#include "vu0.h"
typedef int q_3A2CD0 __attribute__((mode(TI)));
__asm__(".extern D_L11_001DE098, 4");
__asm__(".extern D_L11_001DE0A8, 1");
__asm__(".extern D_L11_001DE0B8, 4");
extern f32 D_L11_001DE098;
extern u8 D_L11_001DE0A8;
extern f32 D_L11_001DE0B8;
extern void func_003C6680(void *, void *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, f32 *, u8 *, s32);
extern void func_003C6990(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L11_003A2CD0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *r;
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 d;

    if (v != 0) {
        r = a0 + 0xF0;
        pos = *(vu0_v4 *)(a0 + 0x10);
        rot = *(vu0_v4 *)r;
        if (a0[0x20] == 0) {
            func_003C6680(a0, v + 0x70, 0, 0, &D_L11_001DE098, 0, 0, 0, &D_L11_001DE0B8, &D_L11_001DE0A8, 0);
            func_L01_004450F0(a0, 1, -1);
        }
        func_003C6990(a0, v + 0x70, 0);
        vec_sub_ba(&d, &pos, a0 + 0x10);
        func_003C4DA8(v + 0x30, &d, &rot, r);
    }
}
/* localdecomp:end func_L11_003A2CD0 */

INCLUDE_ASM("asm/levels", func_L11_003A2DB0);

/* localdecomp:start func_L11_003A40B8 */
extern s32 func_L01_00451D38(void *, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003A40B8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x10];
    u8 st;

    if (a0[0x95] == 0) {
        *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108010, 0x40042004, 0.16755162f);
    } else if (a0[0x95] == 2) {
        st = a0[0x20];
        if (st == 6 || st == 8 || st == 7) {
            *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40101080, 0x40040420, 0.16755162f);
        } else {
            *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108080, 0x40084040, 0.16755162f);
        }
    } else {
        *(s32 *)(v + 0x324) = func_L01_00451D38(v + 0x328, 0x40108080, 0x40084040, 0.16755162f);
    }
    *(s32 *)(a0 + 0x78) = func_0038DBD8(*(s32 *)(v + 0x324), *(s32 *)(a0 + 0x78), 0.90400004f);
    func_003C2F58(a0, 0, buf);
    func_003D9508(buf, 0xB, *(s32 *)(a0 + 0x78), 1, 0.25f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003A40B8 */

/* localdecomp:start func_L11_003A41E0 */
extern u8 D_001A30B0[];
extern s32 func_L11_003A4410(u8 *);
extern void func_L11_003A45D0(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L11_003A41E0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx;
    u8 *e;

    if (a0[0x20] == 0 && func_L11_003A4410(a0) != 0) {
        return 1;
    }
    if (v[0x3E] == 2) {
        goto die;
    }
    if (0.0f < *(f32 *)(v + 0x30)) {
        idx = *(s32 *)(v + 0x2F4);
        if (idx == -1) {
            goto spawn;
        }
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) != a0 || e[0xD0] == 0) {
spawn:
            *(s32 *)(v + 0x2F4) = func_003A52A0(0, 4, a0);
        }
    }
    if (func_L01_00452FB0(a0, v + 0x160, 0, 0, 0) != 0) {
        func_L01_003A6BB0(a0);
    }
    func_L01_00452860(a0, v + 0x30, 0);
    if (v[0x5E] != 0) {
die:
        func_L11_003A45D0(a0);
        return 1;
    }
    if (v[0x5F] != 0) {
        func_L01_00404A10(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00404A10(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L11_003A41E0 */

/* localdecomp:start func_L11_003A4410 */
typedef int q_3A4410 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A4410;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L11_003A4410(u8 *a0)
{
    u8 *v;
    V4_3A4410 m[4];

    *(s32 *)(a0 + 0x78) = 0x7F7F1010;
    v = *(u8 **)(a0 + 0x68);
    *(q_3A4410 *)(v + 0x310) = *(q_3A4410 *)(a0 + 0x10);
    func_003C5180(a0 + 0x10, m, 0);
    func_L01_004515D8(a0 + 0xC0, &m[0], &m[1]);
    v[0x170] = 0xA;
    v[0x1A8] = 3;
    v[0x1DB] = 0xFF;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(f32 *)(v + 0x194) = 0.5f;
    v[0x1D7] = 1;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(u16 *)(a0 + 0x34) |= 0x100;
    *(f32 *)(v + 0x9C) = 0.0f;
    *(s32 *)(v + 0xA8) |= 1;
    *(f32 *)(v + 0x70) = 0.45f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x78) = 0.5f;
    *(f32 *)(v + 0x7C) = 60.0f;
    *(f32 *)(v + 0x80) = 1.3089969f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    func_L01_0045BD78(a0, 0.0064000003f, 0.060000002f, 0.010053097f, 0.25132743f);
    v[0x58] = 0x14;
    v[0x5A] = 0xE;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 1;
        *(f32 *)(v + 0x30) = 1.0f;
    }
    v[0x39] = 1;
    v[0x3E] = 1;
    *(f32 *)(v + 0x40) = 0.75f;
    func_L01_004450F0(a0, 1, 0);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L11_003A4410 */

/* localdecomp:start func_L11_003A45D0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L11_003A45D0(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 idx = *(s32 *)(v + 0x2F4);
    u8 *e;

    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 0x2F4) = -1;
    func_003A52A0(5, 0, a0);
    func_L01_00451FE0(a0, 0x7FFF, &D_L11_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_L01_004443E8(a0, 0, 3);
}
/* localdecomp:end func_L11_003A45D0 */

/* localdecomp:start func_L11_003A46C8 */
extern u8 D_L11_001E1780[];
extern void func_0038CAD0(s32);
extern void func_0038CB00(s32);
extern void func_L11_003A40B8(u8 *);
extern void func_L01_00404808(void (*)(u8 *), void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);

void func_L11_003A46C8(Moby_003A46C8 *m) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = m->vars;
    func_0038CAD0(temp_s1 + 0x2D0);
    func_0038CB00(temp_s1 + 0x2D4);
    temp_v1 = m->timer;
    if (temp_v1 <= 0xFFFEU) {
        m->timer = (u16) (temp_v1 + 1);
    }
    func_L01_00404808(func_L11_003A40B8, m);
    func_L01_00451DF8(m, (u8 *)temp_s1 + 0x240, 2, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L11_001E1780, &m->pos) < 1024.0f) {
        func_L01_004472C0(m);
        m->state = 30;
    }
}
/* localdecomp:end func_L11_003A46C8 */
