#include "common.h"

/* NTSC-U counterpart of func_L01_003DEF68 (src/levels/shared/L01_003D9510.c) */
#include "vu0.h"

/* localdecomp:start func_L01_003DD310 */
typedef struct {
    u8 p0[0x1210];
    s32 w1210;
    u8 p1214[0xC];
    s32 w1220;
} S_003DEF68;
extern S_003DEF68 D_001A4BE0;
extern s32 D_L01_001D6694_003DD310;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_0039BEC0(s32, s32, s32, s32, s32);

void func_L01_003DD310(u8 *obj) {
    if (obj[0x20] == 0) {
        obj[0x20] = 1;
    }
    if (D_L01_001D6694_003DD310 == 0) {
        u8 *hero = D_001D52FC;
        if ((*(s32 *)(hero + 0x1A4) & D_001A4BE0.w1210) != 0) {
            if (D_001A4BE0.w1220 >= 0x17) {
                func_0039BEC0(5, 1, 4, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_003DD310 */
