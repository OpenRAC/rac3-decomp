#include "common.h"

/* NTSC-U counterpart of func_L01_005070E0 (src/levels/shared/L01_005063E8.c) */
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern s32 func_003CE740(void *from, void *to, s32 mask, void *skip, s32 unk);
extern u8 D_001A4BE0[];

/* localdecomp:start func_L01_00503188 */
typedef int Q_005070E0 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_005070E0;
typedef struct {
    u8 pad0[0x80]; V_005070E0 pos; u8 pad90[8]; f32 yaw;
    u8 pad9C[0x74]; f32 vx,vy; u8 pad118[0x5C]; f32 speed;
    u8 pad178[0x10C]; f32 radius; u8 pad288[0x2338]; void *moby;
    u8 pad25C4[0x30]; u8 held;
} H_005070E0;
extern u8 D_001A4BE0[];
extern V_005070E0 D_L01_001EAAA0;
s32 func_L01_00503188(void)
{
    extern f32 func_00388A28(f32,f32);
    extern f32 func_00389468(f32,f32);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    H_005070E0 *h = (H_005070E0 *)D_001A4BE0;
    V_005070E0 pos, end;
    f32 distance;
    if (h->held == 2) return 0;
    if (h->speed < h->radius / 20.0f) return 0;
    if (func_00389468(func_00388A28(h->vx,h->vy),h->yaw) > 0.5235987901687622f) return 0;
    *(Q_005070E0 *)&pos = *(Q_005070E0 *)&h->pos;
    pos.x += func_00388960(h->yaw) * (h->radius * 0.75f);
    pos.y += func_00388978(h->yaw) * (h->radius * 0.75f);
    *(Q_005070E0 *)&end = *(Q_005070E0 *)&pos;
    pos.z += 0.4950000047683716f;
    end.z -= 1.0f;
    if (func_003CE740(&pos,&end,2,h->moby,0)) {
        distance = D_L01_001EAAA0.z - h->pos.z;
        if (distance < 0.39500001072883606f && distance > -1.0f) return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00503188 */
