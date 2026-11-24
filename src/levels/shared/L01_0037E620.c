#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0037E620 */
extern f32 func_0038DAB8(f32, f32);
extern u8 D_L01_001E1D70[8];
extern u8 D_L01_002B3AC0[];
extern void func_L01_0040B858(void *beam, void *numbers);

void func_L01_0037E620(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    *(f32 *)(s + 0x30) = func_0038DAB8(*(f32 *)(s + 0x30), 0.017453292f);
    func_L01_0040B858(D_L01_001E1D70, D_L01_002B3AC0);
}
/* localdecomp:end func_L01_0037E620 */

/* localdecomp:start func_L01_0037E670 */
typedef struct {
    u8 pad0;
    u8 state;
    u8 pad1[0xEE];
} S_2C5600_0037E670;

typedef struct {
    u8 pad0[0x160];
    u8 *t160;
    u8 pad1[8];
    u8 *t16c;
} S_221098_0037E670;

extern u8 D_001425C0[];
extern S_2C5600_0037E670 D_L01_002C5600[];
extern S_221098_0037E670 D_L01_00221098;
extern u8 D_L01_001D66B0[8];
extern u8 D_L01_001E1D70[8], D_L01_001E1D80[8];

void func_L01_0037E670(void) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
    f32 pos[4] __attribute__((aligned(16)));
    s32 i, size, speed;
    f32 a, b;
    u8 *p;
    u32 color = 0x0040FF20;
    u8 state = (D_001425C0[0x6F] + D_L01_002C5600)->state;

    if (state == 1) color = 0x00404040;
    if (state == 2) color = 0x004080FF;
    if (state == 3) color = 0x00404040;
    if (state >= 4) color = 0x00808080;
    for (i = 39; i >= 0; i--) {
        func_0038CDF8(pos, D_L01_001E1D70, D_L01_001E1D80, func_003824E0(0.0f, 0.75f));
        size = (func_00382498(10, 15) * 5 + 2) / 6;
        speed = func_00382498(-5, 5);
        a = func_003824E0(0.125f, 0.5f) * 210000.0f;
        b = func_003824E0(0.35f, 0.75f) * 210000.0f;
        p = func_L01_004713C8(pos, D_L01_001D66B0, size, color, speed, 47, 0, a, b, 0.0f, 0);
        if (p != 0) {
            p[2] = D_L01_00221098.t160[0];
            if ((D_001425C0[0x6F] + D_L01_002C5600)->state == 1) p[2] = D_L01_00221098.t16c[1];
            if ((D_001425C0[0x6F] + D_L01_002C5600)->state == 2) p[2] = D_L01_00221098.t160[0];
            if ((D_001425C0[0x6F] + D_L01_002C5600)->state == 3) p[2] = D_L01_00221098.t16c[3];
            if ((D_001425C0[0x6F] + D_L01_002C5600)->state >= 4) p[2] = D_L01_00221098.t16c[3];
        }
    }
}
/* localdecomp:end func_L01_0037E670 */
