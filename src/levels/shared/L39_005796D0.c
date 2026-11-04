#include "common.h"

typedef struct {
    u8 pad0[0x30];
    f32 pos[3];
    u8 pad3C[0x28];
    f32 last[3];
    u8 pad70[0x1C];
    s16 kind;
    u8 pad8E[0x22];
} Obj_005796D0;
typedef struct {
    u8 pad0[0x50];
    Obj_005796D0 *cur;
    u8 pad54[0x460 - 0x54];
} Cam_005796D0;
typedef struct {
    s32 e[5];
} Disp_005796D0;
typedef void (*ObjFn_005796D0)(Obj_005796D0 *);

/* localdecomp:start func_L39_005796D0 */
extern Cam_005796D0 D_L39_0024DE80[];
extern Obj_005796D0 D_L39_0024F110[];
extern u8 D_L39_00259A90[];
extern Disp_005796D0 D_L39_004B2F80[];

extern void func_L01_003F3D10(Obj_005796D0 *);
extern s32 func_L39_005794E0(s32, Obj_005796D0 *, Obj_005796D0 *);
extern void func_00382E10(Obj_005796D0 *, s32);
extern void func_00382D48(s32, void *);
extern void func_L39_00578DB8(s32);

s32 func_L39_005796D0(s32 arg0) {
    Obj_005796D0 *best = ((Cam_005796D0 *)((u8 *)D_L39_0024DE80 + arg0 * 0x460))->cur;
    s32 changed;
    s32 i;
    ObjFn_005796D0 cb;
    Obj_005796D0 *o;
    u8 *act;

    func_L01_003F3D10(best);
    changed = 0;
    for (i = 0; i < 48; i++) {
        if (D_L39_00259A90[arg0 * 48 + i] != 0 && &D_L39_0024F110[arg0 * 48 + i] != best && func_L39_005794E0(arg0, &D_L39_0024F110[arg0 * 48 + i], best)) {
            best = &D_L39_0024F110[arg0 * 48 + i];
            changed = 1;
        }
    }
    if (changed) func_00382E10(best, 0);
    cb = (ObjFn_005796D0)D_L39_004B2F80[best->kind].e[3];
    func_00382D48(arg0, best);
    if (cb != 0) cb(best);
    {
        f32 *src = best->pos;
        f32 *dst = best->last;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
    }
    func_L39_00578DB8(arg0);
    return -1;
}
/* localdecomp:end func_L39_005796D0 */
