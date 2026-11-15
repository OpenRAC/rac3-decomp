#include "common.h"

/* localdecomp:start func_L33_003A2838 */
typedef struct S_003A2838 {
    s32 cls;
    s32 cls2;
    s32 f8;
} S_003A2838;

extern u8 *D_001A71A0[];
extern u8 D_L33_001E2720[];
extern u8 D_L33_001D66B0;
extern s32 D_L33_001DEB00;
__asm__(".extern D_L33_001DEB00, 4");

extern void func_L01_00445F40(void *, s32);
extern void func_003C7DD8(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, f32, f32, f32, f32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L33_003A2838(u8 *moby) {
    S_003A2838 *pv = *(S_003A2838 **)(moby + 0x68);
    u8 v[16] __attribute__((aligned(16)));
    u8 *r;
    s32 flag;
    s16 t;
    s32 n;

    switch (moby[0x20]) {
    case 0:
        n = pv->cls;
        if (n != *(s16 *)(moby + 0xAA) && n > 0) {
            func_L01_00445F40(moby, n);
            func_003C7DD8(moby);
            moby[0x40] = 0;
            moby[0x41] = 0;
            *(u16 *)(moby + 0x34) &= 0xFFFA;
        }
        func_L01_004450F0(moby, 1, -1);
        break;
    case 1:
        flag = 0;
        if (pv->f8 != 0) {
            *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
            r = func_L01_00447490(moby, 0x10000, 0);
            if (r != 0) {
                moby[0xA8] = 0xFF;
                if (0.0f < *(f32 *)(r + 0x2C)) {
                    t = *(s16 *)(*(u8 **)(r + 0x20) + 0xAA);
                    if (t == *(s16 *)(D_001A71A0[0] + 0xAA) || t == 0x173F || t == 0x1F01) {
                        flag = 1;
                    }
                }
            }
        }
        if (func_L01_00456250(moby) != 0 || flag != 0) {
            if (pv->cls == 0x1985) {
                func_L01_004AAC98(1, 0, moby, 0x1985);
            }
            if (pv->cls == 0x1C5D) {
                func_L01_004AAC98(0, 0, moby, 0x1C5D);
            }
            func_L01_004450F0(moby, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(moby) != 0) {
            func_0038CF68(v, D_L33_001E2720, 0.014f);
            func_003A52A0(0, 0, moby);
            func_L01_00451FE0(moby, 0x1F, v, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f,
                              0x50, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            if (*(s16 *)(moby + 0xAA) == 0x1907) {
                func_L02_00429840(moby, moby + 0x10, func_00382498(10, 13), 1, &D_L33_001D66B0,
                                  1.5f, 3.0f, 1.75f, 2.5f, D_L33_001DEB00, 0, 0x46);
            }
            if (pv->cls2 >= 0) {
                func_L01_00445F40(moby, pv->cls2);
                func_003C7DD8(moby);
                moby[0x41] = 0;
                moby[0x40] = 0;
                *(u16 *)(moby + 0x34) &= 0xFFFA;
            } else {
                *(s32 *)(moby + 0x98) = 0;
                *(u16 *)(moby + 0x34) = (*(u16 *)(moby + 0x34) | 0x41) & 0xEFFF;
                func_L01_004AA7E8(moby, 1);
            }
        }
        break;
    }
}
/* localdecomp:end func_L33_003A2838 */
