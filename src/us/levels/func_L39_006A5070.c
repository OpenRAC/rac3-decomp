#include "common.h"

/* NTSC-U counterpart of func_L39_006A7928 (src/levels/39_multiplayer_menu/L39_006A7928.c) */
/* localdecomp:start func_L39_006A5070 */
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_00247A74, 16");
extern s32 **D_L39_0024D860;
extern s32 *D_L39_00247A74;
extern s32 D_001A5E50[];
extern s32 *D_001DC1E4_sda;
extern void func_00199190(void);
extern void func_L39_006D1928(s32);
extern void func_L39_006D7B28(s32, s32, s32);
extern void func_L39_006BA8F0(s32, s32);

void func_L39_006A5070(void)
{
    s32 s;

    func_00199190();
    if (D_001A5E50[0x174 / 4] != 0) {
        D_001DC1E4_sda[0x284 / 4] = 0x15;
    } else {
        func_L39_006D1928(((s32 *)D_L39_0024D860)[0x3C / 4]);
        s = D_L39_00247A74[0xE0 / 4];
        func_L39_006D7B28(((s32 *)D_L39_0024D860)[0x4C / 4], D_001A5E50[0x78 / 4], 0);
        func_L39_006BA8F0(s, D_001A5E50[0x78 / 4]);
        D_L39_00247A74[0x284 / 4] = 0x1F;
    }
}
/* localdecomp:end func_L39_006A5070 */
