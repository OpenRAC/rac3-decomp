#include "common.h"

/* NTSC-U counterpart of func_L39_006C40A8 (src/levels/39_multiplayer_menu/L39_006C40A8.c) */
/* localdecomp:start func_L39_006C1590 */
__asm__(".extern D_L39_0024D860, 16");
extern u8 *D_L39_0024D860;
extern s32 func_00388398(void *);
extern void func_L39_006CC290(void *, s32);
extern s32 func_L39_006D0790(void *, void *, void *);
extern void func_L39_006C0C60(void *, s32, s32, s32);

s32 func_L39_006C1590(u8 *obj) {
    s32 buf[2];
    void *h = *(void **)(D_L39_0024D860 + 0x38);
    func_00388398(obj + 0x2C4);
    if (*(s32 *)(obj + 0x2C4) <= 0) {
        s32 r;
        func_L39_006CC290(h, 0);
        if (*(s32 *)(obj + 0x2CC) == 2) {
            if (func_L39_006D0790(h, &buf[0], &buf[1]) == 0) {
                func_L39_006C0C60(obj, 1, 0, -1);
                return 1;
            }
            r = 900;
        } else {
            r = 36000;
        }
        *(s32 *)(obj + 0x2C4) = r;
    }
    return 0;
}
/* localdecomp:end func_L39_006C1590 */
