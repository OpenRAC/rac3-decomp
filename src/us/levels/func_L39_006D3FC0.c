#include "common.h"

/* NTSC-U counterpart of func_L39_006D6750 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
/* localdecomp:start func_L39_006D3FC0 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} Loc_006D3FC0;
typedef struct {
    u8 f00;
    u8 pad01[7];
    u8 f08;
    u8 pad09[3];
    s32 f0C;
    u8 pad10[0x4C];
    s32 f5C;
    s32 f60;
    s32 f64;
} S_006D3FC0;
extern u16 D_L39_00249EE8_006D3FC0[];
extern u8 D_00197DF8[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern s32 func_0017FAB0(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006D3FC0(S_006D3FC0 *p, s32 a, s32 b, s32 c) {
    s32 r = 1;
    Loc_006D3FC0 loc;
    u8 buf[0x10];

    if (p->f00 != 0) {
        p->f60 = b;
        p->f5C = a;
        loc.f00 = D_L39_00249EE8_006D3FC0[0];
        loc.f18 = a;
        loc.f1C = b;
        loc.f20 = c;
        loc.f24 = p->f64;
        p->f08 = 1;
        p->f0C = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf);
        func_001962D8(func_0017FAB0(&loc, D_00197DF8, 0));
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D3FC0 */
