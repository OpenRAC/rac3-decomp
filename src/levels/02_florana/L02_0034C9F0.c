#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_0034C9F0 */
typedef struct { vu0_v4 a; vu0_v4 b; } G_34C9F0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, f32, void *);
extern s32 func_003D5630(void);

s32 func_L02_0034C9F0(u8 *self) {
    u8 *d;
    vu0_v4 v, off;
    G_34C9F0 seg;
    f32 h;

    v = *(vu0_v4 *)(self + 0x10);
    d = *(u8 **)(self + 0x68);
    off.x = func_0038D098(*(f32 *)(self + 0xF8));
    off.y = func_0038D0B0(*(f32 *)(self + 0xF8));
    off.z = 0.0f;
    vec_add_ab(&v, &v, &off);
    h = func_003C3D30(&v, 0x20, 2.0f, 0);
    if (!(h < *(f32 *)(self + 0x18))) return 0;
    if (!(*(f32 *)(d + 0x7C) < __builtin_fabsf(h - *(f32 *)(self + 0x18)))) return 0;
    off.x = func_0038D098(*(f32 *)(self + 0xF8)) * 3.5f;
    off.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 3.5f;
    off.z = 0.0f;
    vec_add_ab(&v, self + 0x10, &off);
    h = func_003C3D30(&v, 0, 1.0f, 0);
    if (*(f32 *)(self + 0x18) - 5.0f < h) {
        seg.a = v;
        seg.b = v;
        seg.b.z = h - 2.0f;
        if (func_003D5630() != 0) goto hit;
    }
    return 2;
hit:
    *(f32 *)(d + 0xA18) = h;
    return 1;
}
/* localdecomp:end func_L02_0034C9F0 */

INCLUDE_ASM("asm/levels", func_L02_0034CB58);

/* localdecomp:start func_L02_0034F710 */
typedef struct { u8 p0[0x24]; s32 f24; u8 p1[0x44]; s32 f6C; u8 p2[0x24]; s32 f94; } S_34F710;
extern s32 func_L02_0034F958(void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L02_0034FC40(void *);
extern s32 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L02_003FB148(s32, s32, f32);
extern S_34F710 D_001CCFD0_34F710;
__asm__(".extern D_001CCFD0_34F710, 16");

s32 func_L02_0034F710(u8 *a0)
{
    u8 *p;
    s32 *q;
    s32 v;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L02_0034F958(a0) != 0) return 1;
    }
    if (*(s32 *)(p + 0x938) != 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x938), 2, 0);
    if (p[0x3E] == 2) {
        func_L02_0034FC40(a0);
        return 1;
    }
    if (*(s32 *)(p + 0x2EC) != 0 && a0[0xBC] == 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x2EC), 0, 0);
    q = func_L01_00447490(a0, 0x10000, 0);
    if (q != 0 && *(u8 **)((u8 *)q + 0x20) != 0) {
        s32 h = *(s16 *)(*(u8 **)((u8 *)q + 0x20) + 0xAA);
        if (h == 0x18BE || h == 0x184F) {
            *(f32 *)((u8 *)q + 0x2C) *= 0.75f;
        }
    }
    if (*(f32 *)(p + 0x2CC) > 0.0f) {
        if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) {
            if (*(s32 *)(p + 0x21C) == 0) *(s32 *)(p + 0x21C) = 100;
            if (*(s32 *)(p + 0xA3C) == 0 && D_001CCFD0_34F710.f6C == 0 && D_001CCFD0_34F710.f24 == -1
                && D_001CCFD0_34F710.f94 == 0 && *(f32 *)(p + 0x30) > 0.0f) {
                func_00382468(4);
                *(s32 *)(p + 0xA3C) = 1;
            }
            func_L02_0034FD58(a0);
        }
    }
    func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
    if ((u8)(a0[0x95] - 2) < 2) {
        v = (s32)*(f32 *)(p + 0x30);
        if (v < 0) v = 0;
        func_L02_003FB148(10, 0, (f32)v / (f32)*(s16 *)(p + 0x34));
    }
    return 0;
}
/* localdecomp:end func_L02_0034F710 */

INCLUDE_ASM("asm/levels", func_L02_0034F958);

/* localdecomp:start func_L02_0034FC40 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(s32, s32, s32);

void func_L02_0034FC40(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    func_L01_00315900((*(s32 *)((u8 *)temp_s0 + 0x2EC)), 0, 0);
    *(s32 *)((u8 *)temp_s0 + 0x2EC) = 0;
}
/* localdecomp:end func_L02_0034FC40 */

/* localdecomp:start func_L02_0034FC88 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L02_00350200(void *, s32);
extern u8 D_L02_001E1300[];

void func_L02_0034FC88(u8 *a0)
{
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_0038CAD0(p + 0x2D0);
    func_0038CB00(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_00451DF8(a0, p + 0x240, 2, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L02_001E1300, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (a0[0x20] != 3) {
        func_L02_00350200(a0, 1);
    }
}
/* localdecomp:end func_L02_0034FC88 */
