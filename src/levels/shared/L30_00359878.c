#include "common.h"

/* localdecomp:start func_L30_00359878 */
extern u8 D_001A4C60[];
extern s32 D_L30_001DF2C0;
extern u8 *D_L30_001DF71C;
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_004AA7E8(void *, s32);

typedef struct {
    u8 pad0[0x10];
    u8 pos[0x24];
    u16 flags;
    u8 pad36[0x62];
    s32 x98;
    u8 pad9c[0x64];
} Ent_00359878;

void func_L30_00359878(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    func_00382380(D_001A4C60, *(s32 *)(v + 0x40), 0);
    if (*(s32 *)(v + 4) != 0 && D_L30_001DF2C0 < 30) {
        if (func_0038CF00(*(u8 **)(D_001A4C60 + 0x2540) + 0x10, ((Ent_00359878 *)D_L30_001DF71C)[*(s32 *)(v + 4)].pos) < 10.0f) {
            ((Ent_00359878 *)D_L30_001DF71C)[*(s32 *)(v + 4)].flags |= 0x41;
            ((Ent_00359878 *)D_L30_001DF71C)[*(s32 *)(v + 4)].flags &= 0xEFFF;
            ((Ent_00359878 *)D_L30_001DF71C)[*(s32 *)(v + 4)].x98 = 0;
            func_L01_004AA7E8(&((Ent_00359878 *)D_L30_001DF71C)[*(s32 *)(v + 4)], 1);
            ((Ent_00359878 *)D_L30_001DF71C)[*(s32 *)(v + 4)].flags |= 2;
        }
    }
}
/* localdecomp:end func_L30_00359878 */
