/* NTSC-U draft (Claude wave K): C of func_L39_006B90F0, the NTSC-U twin of func_L39_006BBC08, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 79 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L39_006B90F0", whose code is not the PAL one).
 * Worker's note: 79 diff (shape right, every block offset shifted): menu validity check s32 f(u8 *self): func_00388398(self+0x310); >0 -> return 1; reset timer 0x384; s1 = *(D_L39_0024D860+0x38); switch self->0x2F0: 1 ok, 2 func_L39_006CC290(s1,0) then *s1<0 -> msg 0x1732, 3 ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006BBB38 (src/levels/39_multiplayer_menu/L39_006BBB38.c) */
/* localdecomp:start func_L39_006B90F0 */
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_00247A74, 16");
extern u8 *D_L39_0024D860;
extern u8 *D_L39_00247A74;
extern u8 *D_001DC1E4_sda;
extern u8 D_L39_002495B8[];
extern s32 func_00388398(void *);
extern void func_L39_006CC290(void *, s32);
extern s32 func_L39_006D0790(void *, void *, void *);
extern u8 *func_0037DF98(s32);
extern void func_L39_006847C8(void *, void *, void *, s32, s32, f32);

s32 func_L39_006B90F0(u8 *self) {
    u8 *s1;
    u8 *s0;
    s32 s3;
    s32 x[2];
    s32 v;
    s32 id;

    func_00388398(self + 0x310);
    if (*(s32 *)(self + 0x310) > 0) {
        return 1;
    }
    *(s32 *)(self + 0x310) = 0x384;
    s1 = *(u8 **)(D_L39_0024D860 + 0x38);
    s3 = 1;
    switch (*(s32 *)(self + 0x2F0)) {
    case 1:
        break;
    case 2:
        func_L39_006CC290(s1, 0);
        if (*(s32 *)s1 >= 0) {
            break;
        }
        id = 0x1732;
        goto msg;
    case 3:
        func_L39_006CC290(s1, 0);
        if (*(s32 *)s1 < 0) {
            id = 0x1732;
            goto msg;
        }
        if (func_L39_006D0790(*(u8 **)(D_L39_0024D860 + 0x38), &x[0], &x[1]) == 0 || x[0] != *(s32 *)(self + 0x308)) {
            id = 0x1733;
            goto msg;
        }
        break;
    default:
        s3 = 0;
        break;
    }
    if (0) {
    msg:
        s0 = D_L39_00247A74;
        s3 = 0;
        func_L39_006847C8(s0, func_0037DF98(id), D_L39_002495B8, 4, 0, 0.6f);
    }
    if (s3 != 0) {
        return 1;
    }
    if (*(u32 *)(self + 0x2F0) < 2) {
        v = 0x19;
    } else if (*(s32 *)s1 < 0) {
        v = 0x19;
    } else if (s1[0x34] == 0) {
        v = 6;
    } else {
        v = 9;
    }
    *(s32 *)(D_001DC1E4_sda + 0x284) = v;
    return 0;
}
/* localdecomp:end func_L39_006B90F0 */
