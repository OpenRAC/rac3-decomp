#include "common.h"

/* NTSC-U counterpart of func_L34_00350360 (src/levels/34_vidcomic_3/L34_00350360.c) */
extern s32 func_00388398(void *);

/* localdecomp:start func_L34_0034F640 */
#include "vu0.h"

extern f32 D_L34_001DD758_0034F640;
extern f32 D_L34_001DD75C_0034F640;
__asm__(".extern D_L34_001DD758_0034F640, 4");
__asm__(".extern D_L34_001DD75C_0034F640, 4");
extern u8 *D_001A71A0[];
extern f32 D_001A4C60[];
extern void func_L24_00439040(u8 *, s32, s32, s32, f32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_004479A8(void *, void *);
extern void func_L01_004A6D70(s32, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0032FE90_0034F640(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L03_0043C598(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_003BF4F8(void *, void *);
extern void func_003C0188(void *, void *, void *, s32, s32);
extern void func_00388880(void *, void *, f32);
extern void func_L01_00441FB8(u8 *, s32, s32);

void func_L34_0034F640(u8 *a0) {
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

    func_L24_00439040(a0, -1, 0, 0, D_L34_001DD758_0034F640, D_L34_001DD75C_0034F640);
    p = *(u8 **)(a0 + 0x68);
    r = (u8 *)func_L01_00444358(a0, 0x10000, 0);
    func_00388398(p + 0x25C);
    q = p + 0x180;
    func_L01_004479A8(a0, q);
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
        *(s32 *)(p + 0x25C) = 15;
        func_L01_004A6D70(0, a0);
        func_L01_004A6D70(4, a0);
        func_L01_004A6D70(5, a0);
        f = *(f32 *)(p + 0x50) - *(f32 *)(r + 0x2C);
        *(f32 *)(p + 0x50) = f;
        if (f <= 0.0f) {
            func_0039FE80(3, 0, a0);
            pv = &v;
            *pv = *(vu0_v4 *)(a0 + 0x10);
            v.z += 1.0f;
            func_00388830(&w, a0 + 0xC0, -0.75f);
            vec_add_ab(pv, pv, &w);
            func_L01_0032FE90_0034F640(pv, 1, 25, 20, 20, 20, 45, 2, 0.57f, 0.0f, 0.0f, 2.0f,
                1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            pu = &u;
            func_00388830(pu, r + 0x10, 0.06666667014360428f);
            func_L03_0043C598((s32)a0, 0xFF, (u8 *)pu, 3, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
            func_0039FE80(1, 0, a0);
            func_L01_00441FB8(a0, 0x42, -1);
        } else {
            func_0039FE80(2, 0, a0);
            p[0x187] = 0xFF;
            func_003BF4F8(a0, q);
            func_L01_00441FB8(a0, 8, -1);
            pe = &v;
            qzero(pe);
            pe->x = *(f32 *)(a0 + 0x10) - D_001A4C60[0];
            func_00388830(pe, pe, 0.11666667461395264f);
            func_003C0188(a0, p + 0x190, pe, 2, -1);
            v.y = 0.0f;
            func_00388880(pe, pe, 0.31666669249534607f);
            *(f32 *)(p + 0x210) = pe->x;
            *(f32 *)(p + 0x214) = 0.0f;
            *(f32 *)(p + 0x218) = 0.03333333507180214f;
        }
    }
end:
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L34_0034F640 */
