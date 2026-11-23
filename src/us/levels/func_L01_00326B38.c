#include "common.h"

/* NTSC-U counterpart of func_L01_00327038 (src/levels/shared/L01_003241A0.c): times scaled by 60, not 50 */
/* localdecomp:start func_L01_00326B38 */
typedef struct {
    u8 pad0[36];
    s32 w36;
    u8 pad28[68];
    s32 w108;
    u8 pad70[6];
    s16 h118;
    u8 pad78[28];
    s32 w148;
    s16 h152;
    u8 pad9A[4];
    s16 h158;
} S_001CCFD0;
typedef struct {
    u8 pad0[132];
    s32 w132;
    s32 w136;
    s32 w140;
    s32 arr144[16];
    s32 arr208[16];
} Obj_003260C8;
typedef struct { u8 p0[0x6C]; u8 reset; u8 p6D[0x43]; s32 ids[4], times[4], flags[4], mobys[4]; } State_00326B38;
extern S_001CCFD0 D_001CCFD0;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 *D_L01_001E009C;
extern s32 func_L01_003252E8(void);
extern s32 func_L01_003B4340(u8 *);
extern f32 func_L01_003B4480(u8 *, s32, s32, s32, s32);
extern s32 func_L01_003B4700(u8 *);
extern s32 func_L01_003B4730(u8 *, s32);

void func_L01_00326B38(u8 *obj)
{
    u8 *owner = (u8 *)func_L01_003252E8();
    State_00326B38 *in = *(State_00326B38 **)(obj + 0x68);
    Obj_003260C8 *save = *(Obj_003260C8 **)(owner + 0x68);
    s32 i, j;
    S_001CCFD0 *camera;
    u8 *moby;
    if (in->reset) {
        for (j = 15; j >= 0; j--) save->arr144[j] = -1;
        save->w132 = -1;
        save->w140 = 0;
        save->w136 = 0;
        camera = &D_001CCFD0;
        if ((u32)(*(u16 *)&camera->h118 - 6) >= 2) *(u16 *)&camera->h118 = 5;
        if ((u32)(*(u16 *)&camera->h158 - 6) >= 2) *(u16 *)&camera->h158 = 5;
    }
    for (i = 0; i < 4; i++) {
        if (in->ids[i] == -1) continue;
        if (in->flags[i] != -1 && (D_001BBC40[in->flags[i] + (D_001D545C << 4)] & 0x80)) continue;
        if (in->mobys[i] != -1) {
            moby = D_L01_001E009C + (in->mobys[i] << 8);
            if (*(s16 *)(moby + 0xAA) == 0x19E5) {
                if (func_L01_003B4340(moby)) {
                    if (func_L01_003B4480(moby, 0, 0, 0, 0) == 1.0f) continue;
                } else if (func_L01_003B4700(moby)) {
                    if (func_L01_003B4730(moby, 0)) continue;
                }
            } else if (moby == 0 || moby[0x20] == 0xFE || moby[0x20] == 0xFD) continue;
        }
        for (j = 0; j < 16; j++) {
            if (save->arr144[j] == -1) {
                save->arr144[j] = in->ids[i];
                save->arr208[j] = in->times[i] * 60;
                break;
            }
        }
        save->w136 = 1;
    }
}
/* localdecomp:end func_L01_00326B38 */
