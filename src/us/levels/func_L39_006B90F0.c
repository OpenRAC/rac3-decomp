#include "common.h"

/* NTSC-U counterpart of func_L39_006BBC08 (src/levels/39_multiplayer_menu/L39_006BBC08.c): retry timer 900 frames (PAL 750) */
/* localdecomp:start func_L39_006B90F0 */
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_00247A74_006B90F0, 16");
extern u8 *D_L39_0024D860;
extern s32 *D_L39_00247A74_006B90F0;
extern u8 *D_001E2050_sda;
extern u8 *D_001DC204_sda;
extern u8 D_L39_002495B8[];
extern s32 func_00388398(void *);
extern s32 func_0037DF98(s32);
extern s32 func_L39_006CC290(void *, s32);
extern s32 func_L39_006D0790(void *, void *, void *);
typedef struct {
    u8 pad0[0x2F0];
    s32 f2F0;
    u8 pad2F4[0x308 - 0x2F4];
    s32 f308;
    u8 pad30C[4];
    s32 f310;
} S_006B90F0;

extern s32 func_L39_006847C8(void *, s32, void *, s32, s32, f32);

s32 func_L39_006B90F0(void *self) {
    S_006B90F0 *arg0 = self;
    s32 buf[2];
    s32 ok;
    u8 *net;

    func_00388398(&arg0->f310);
    if (arg0->f310 > 0) {
        return 1;
    }
    arg0->f310 = 0x384;
    ok = 1;
    net = *(u8 **)(D_L39_0024D860 + 0x38);
    switch (arg0->f2F0) {
    case 1:
        break;
    case 3:
        func_L39_006CC290(net, 0);
        if (*(s32 *)net < 0) {
            s32 *p = D_L39_00247A74_006B90F0;

            ok = 0;
            func_L39_006847C8(p, func_0037DF98(0x1732), D_L39_002495B8, 4, 0, 0.6f);
        } else if (!func_L39_006D0790(*(void **)(D_001E2050_sda + 0x38), &buf[0], &buf[1])
                   || buf[0] != arg0->f308) {
            s32 *p = D_L39_00247A74_006B90F0;

            ok = 0;
            func_L39_006847C8(p, func_0037DF98(0x1733), D_L39_002495B8, 4, 0, 0.6f);
        }
        break;
    case 2:
        func_L39_006CC290(net, 0);
        if (*(s32 *)net < 0) {
            s32 *p = D_L39_00247A74_006B90F0;

            ok = 0;
            func_L39_006847C8(p, func_0037DF98(0x1732), D_L39_002495B8, 4, 0, 0.6f);
        }
        break;
    default:
        ok = 0;
        break;
    }
    if (!ok) {
        u8 *g = D_001DC204_sda;

        if ((u32)arg0->f2F0 >= 2) {
            if (*(s32 *)net < 0) {
                *(s32 *)(g + 0x284) = 0x19;
            } else if (net[0x34] != 0) {
                *(s32 *)(g + 0x284) = 9;
            } else {
                *(s32 *)(g + 0x284) = 6;
            }
        } else {
            *(s32 *)(g + 0x284) = 0x19;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_006B90F0 */
