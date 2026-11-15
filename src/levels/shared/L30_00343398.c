#include "common.h"

/* localdecomp:start func_L30_00343398 */
#include "vu0.h"
__asm__(".extern D_L30_001DF2C0, 16");
extern s32 D_L30_001DF2C0;
extern void func_L30_00344340(u8 *);
extern void func_L30_00344610(u8 *);
extern void func_L30_003449B0(u8 *);
extern void func_L30_00344E80(u8 *);
extern void func_L01_003500C0(u8 *);
extern void func_L30_00345380(u8 *);
extern void func_L30_00345990(u8 *);
extern void func_L30_00345B68(u8 *);
extern void func_L30_00343CD0(u8 *);
extern void func_003C4DA8(void *, void *, void *, void *);
void func_L30_00343398(u8 *moby) {
    u8 *v = *(u8 **)(moby + 0x68);
    vu0_v4 old;
    vu0_v4 pos;
    vu0_v4 d;
    if (moby[0x20] == 0) {
        func_L30_00344340(moby);
    }
    old = *(vu0_v4 *)(v + 0x130);
    if (v[0x1B1] != 0 && *(s32 *)(v + 0x19C) == 0) {
        *(s32 *)(v + 0x188) = -D_L30_001DF2C0;
    }
    pos = *(vu0_v4 *)(moby + 0xF0);
    switch (*(u32 *)(v + 0x168)) {
    case 0:
        func_L30_00344610(moby);
        break;
    case 1:
        func_L30_003449B0(moby);
        break;
    case 2:
        func_L30_00344E80(moby);
        break;
    case 3:
        func_L01_003500C0(moby);
        break;
    case 4:
        func_L30_00345380(moby);
        break;
    case 5:
        func_L30_00345990(moby);
        break;
    case 6:
        func_L30_00345B68(moby);
        break;
    }
    func_L30_00343CD0(moby);
    vec_sub_ab(&d, v + 0x130, &old);
    if (*(s32 *)(v + 0x168) != 6 || v[0x1B1] == 0) {
        func_003C4DA8(v + 0x30, &d, &pos, moby + 0xF0);
    }
}
/* localdecomp:end func_L30_00343398 */
