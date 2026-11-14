#include "common.h"

/* declared by functions of L34_0034F718.c, which this file was cut from */
extern s32 func_0038CAD0(void *);

/* localdecomp:start func_L34_00350360 */
#include "vu0.h"

extern f32 D_001DD718;
extern f32 D_001DD71C;
__asm__(".extern D_001DD718, 4");
__asm__(".extern D_001DD71C, 4");
extern u8 *D_001A71A0[];
extern f32 D_001A4C60[];
extern void func_L24_0043C3B0(u8 *, s32, s32, s32, f32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_004AA760(s32, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_003C4A40(void *, void *);
extern void func_003C56E0(void *, void *, void *, s32, s32);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L34_00350360(u8 *a0) {
    u8 *p;
    u8 *r;
    u8 *e;
    f32 f;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 u;
    vu0_v4 *pv;
    vu0_v4 *pu;
    vu0_v4 *pe;
    u8 *q;

    func_L24_0043C3B0(a0, -1, 0, 0, D_001DD718, D_001DD71C);
    p = *(u8 **)(a0 + 0x68);
    r = (u8 *)func_L01_00447490(a0, 0x10000, 0);
    func_0038CAD0(p + 0x25C);
    q = p + 0x180;
    func_L01_0044ABD0(a0, q);
    if (r == 0) {
        return;
    }
    if (0.0f < *(f32 *)(r + 0x2C)) {
        e = *(u8 **)(r + 0x20);
        if (*(s32 *)(p + 0x25C) != 0) {
            if (e == 0 || e == D_001A71A0[0]) {
                goto end;
            }
        }
        if (e != 0) {
            if (*(s16 *)(e + 0xAA) == 0x15AD || *(s16 *)(e + 0xAA) == 0x13A1) {
                goto end;
            }
        }
        if (a0[0x20] == 0x42) {
            goto end;
        }
        *(s32 *)(p + 0x25C) = 12;
        func_L01_004AA760(0, a0);
        func_L01_004AA760(4, a0);
        func_L01_004AA760(5, a0);
        f = *(f32 *)(p + 0x50) - *(f32 *)(r + 0x2C);
        *(f32 *)(p + 0x50) = f;
        if (f <= 0.0f) {
            func_003A52A0(3, 0, a0);
            pv = &v;
            *pv = *(vu0_v4 *)(a0 + 0x10);
            v.z += 1.0f;
            func_0038CF68(&w, a0 + 0xC0, -0.75f);
            vec_add_ab(pv, pv, &w);
            func_L01_003303B8(pv, 1, 25, 20, 20, 20, 45, 2, 0.57f, 0.0f, 0.0f, 2.0f,
                1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            pu = &u;
            func_0038CF68(pu, r + 0x10, 0.0800000057f);
            func_L03_0043FC00((s32)a0, 0xFF, (u8 *)pu, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
            func_003A52A0(1, 0, a0);
            func_L01_004450F0(a0, 0x42, -1);
        } else {
            func_003A52A0(2, 0, a0);
            p[0x187] = 0xFF;
            func_003C4A40(a0, q);
            func_L01_004450F0(a0, 8, -1);
            pe = &v;
            qzero(pe);
            pe->x = *(f32 *)(a0 + 0x10) - D_001A4C60[0];
            func_0038CF68(pe, pe, 0.140000015f);
            func_003C56E0(a0, p + 0x190, pe, 2, -1);
            v.y = 0.0f;
            func_0038CFB8(pe, pe, 0.380000025f);
            *(f32 *)(p + 0x210) = pe->x;
            *(f32 *)(p + 0x214) = 0.0f;
            *(f32 *)(p + 0x218) = 0.0400000028f;
        }
    }
end:
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L34_00350360 */
