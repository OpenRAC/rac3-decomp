#include "common.h"

/* NTSC-U counterpart of func_L39_006AEF70 (src/levels/39_multiplayer_menu/L39_006AEF70.c) */
extern s32 *D_L39_002412A0;
extern u8 *func_00381FF0(s32);

/* localdecomp:start func_L39_006AC620 */
__asm__(".extern D_L39_00247A74, 16");
extern s32 *D_L39_00247A74;
extern s32 *D_001DC1E4_sda;
extern s32 *D_L39_002412A0;
extern u8 D_L39_00248CD8[];
extern s32 func_L39_006847C8(s32 *, u8 *, u8 *, s32, s32, f32);
extern void func_00196128(void);
extern void func_00199190(void);
extern s32 func_L39_005BFA18(s32, s32, s32);
s32 func_L39_006AC620(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 != 0) {
        s32 *m = D_L39_00247A74;
        u8 *b = D_L39_00248CD8;
        u8 *t = func_00381FF0(0x1643);

        if (func_L39_006847C8(m, b, t, 3, 0, 0.6f) != 1) {
            return 0;
        }
    }
    func_00196128();
    func_00199190();
    *D_L39_002412A0 = 1;
    if (arg3 >= 0) {
        s32 *m = D_001DC1E4_sda;
        u8 *b = D_L39_00248CD8;
        u8 *t = func_00381FF0(arg3);

        func_L39_006847C8(m, b, t, 4, 0, 0.6f);
    }
    D_L39_00247A74[0x284 / 4] = 0x15;
    func_L39_005BFA18(0, 0, 0x400);
    return 1;
}
/* localdecomp:end func_L39_006AC620 */
