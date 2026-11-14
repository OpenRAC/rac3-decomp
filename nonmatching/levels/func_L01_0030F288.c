/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0030EF98, the NTSC-U twin of func_L01_0030F288, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 5 words differ with its file's flags.
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0030F288 (src/levels/shared/L01_0030E630.c) */

/* localdecomp:start func_L01_0030EF98 */
typedef int s128_0030EF98 __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s32 i[0xA80]; u8 *ptr[0xA80]; s128_0030EF98 q[0x2A0]; } Hero;
typedef struct { u8 pad0[0x88]; u16 w88; u8 pad8A[0xF0 - 0x8A]; } RecF0;
extern s32 D_L01_001D673C;
extern Hero D_001A4BE0;
extern u8 D_001425C0[];
extern RecF0 D_L01_002C5640[];
extern s32 func_L01_0050D978(s32);
extern f32 func_0037E2A8(void);
extern void func_003BFC18(void *, void *, s32);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0044DE28(void *, void *, void *, s32, f32);
extern u8 *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 func_L01_0044E300(void *);
extern void func_003C26C8(void *);
extern void func_L01_004475D0(void *);
extern void func_L01_0030E7F8(void);

u8 *func_L01_0030EF98(void *a0, s32 a1, s32 a2, s32 a3) {
    RecF0 *tb;
    u8 *map;
    f32 v20[4];
    f32 v30[4];
    f32 f20;
    u8 *r;
    u8 *s1;
    s32 t;

    func_L01_0050D978(a1);
    map = D_001425C0;
    tb = D_L01_002C5640;
    *(s128_0030EF98 *)v30 = 0;
    v30[2] = func_0037E2A8();
    *(s128_0030EF98 *)v20 = *(s128_0030EF98 *)v30;
    if (D_L01_001D673C != 0) {
        func_003BFC18(a0, v30, 1);
        v20[1] = func_00388A28(v30[2], func_003887A0(v30));
        v20[2] = func_00388A28(v30[0], v30[1]);
    }
    func_L01_00440A88(v30, 0.0333333351f, 0.0666666701f);
    func_L01_0044DE28(D_001A4BE0.ptr[0x25C0 / 4], v30, v30, 0, func_0037E250(4.0f, 8.0f) * 0.0166666675f);
    f20 = func_0037E250(180.0f, 360.0f);
    r = func_L01_003F5830(D_001A4BE0.ptr[0x25C0 / 4], 2, 0xCDB, 0, a0, v20, v30, 0xFF, f20,
                          func_0037E250(10.0f, 15.0f), 0xB4, 0, 0x80);
    if (r != 0) {
        r[0x20] = 1;
        *(void (**)(void))(r + 0x64) = func_L01_0030E7F8;
        s1 = *(u8 **)(r + 0x68);
        if (a2 == -1) {
            t = func_L01_0050D978(a1); t = map[t];
            *(s32 *)(s1 + 0x60) = tb[t].w88;
        } else {
            *(s32 *)(s1 + 0x60) = a2;
        }
        t = D_L01_001D673C;
        *(s32 *)(s1 + 0x68) = a1;
        *(f32 *)(s1 + 0x6C) = (f32)a3;
        if (t != 0) {
            *(f32 *)(s1 + 0x74) = func_L01_0044E300(r + 0x10);
        } else {
            *(f32 *)(s1 + 0x74) = *(f32 *)(r + 0x18);
        }
        func_003C26C8(r);
        func_L01_004475D0(r);
    }
    return r;
}
/* localdecomp:end func_L01_0030EF98 */
