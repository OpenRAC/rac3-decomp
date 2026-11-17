/* NTSC-U draft (Claude wave B8): C of func_L01_0046AB08, the NTSC-U twin of func_L01_0046E1B8, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L01_0046AB08", whose code is not the PAL one).
 * Worker's note: flags: needs -mvu0-use-vf0-vf2 (vec_add_ba/vec_add_ab on the velocity and position; the helper asm does not compile without it) which the worklist flags (BASE @ps2as, no alt) lack. With it: 66 diff positional (was 68), 114 insns mine vs 112 retail, 98 equal ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046AB08 */
typedef struct Vec3_46AB08 {
    f32 x;
    f32 y;
    f32 z;
} Vec3_46AB08;

typedef struct Cfg_46AB08 {
    s32 w0;
    s32 w4;
    s16 h8;
    s16 hA;
    s32 wC;
} Cfg_46AB08;

typedef struct Target_46AB08 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 b20;
} Target_46AB08;

typedef struct Sub_46AB08 {
    f32 f0;
    f32 f4;
    f32 f8;
    Target_46AB08 *target;
    Vec3_46AB08 vel;
    u8 pad1C[0];
    Cfg_46AB08 *cfg;
} Sub_46AB08;

typedef struct Obj_46AB08 {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
    Sub_46AB08 sub;
} Obj_46AB08;

extern s32 D_L01_001D6694_0046AB08;

extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_003C7CE0(void *);
extern s32 func_L01_00444338(s32, s32, f32);
extern s32 func_003883C8(void *);

void func_L01_0046AB08(Obj_46AB08 *obj) {
    Sub_46AB08 *sub = &obj->sub;
    Cfg_46AB08 *cfg;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;

    if (sub != 0) {
        cfg = sub->cfg;
        obj->fC = (f32)((cfg->h8 * (cfg->wC - obj->hA)) / cfg->wC + cfg->hA) * 1000.0f;
        v0.x = sub->f0;
        v0.y = sub->f4;
        v0.z = sub->f8;
        func_003886E8(&v0, &v0, 0.98f);
        sub->f0 = v0.x;
        sub->f4 = v0.y;
        sub->f8 = v0.z;
        if (D_L01_001D6694_0046AB08 == 0 && sub->target != 0) {
            if (sub->target->b20 == 0xFE) {
                goto kill;
            }
            if (sub->target->b20 == 0xFD) {
kill:
                func_003C7CE0(obj);
                return;
            }
            v10.x = sub->vel.x;
            v10.y = sub->vel.y;
            v10.z = sub->vel.z;
            vec_add_ba(&v10, &v10, &v0);
            sub->vel.x = v10.x;
            sub->vel.y = v10.y;
            sub->vel.z = v10.z;
            func_003888C8(&v20, &v10, (u8 *)sub->target + 0xC0);
            vec_add_ba(&obj->pos, &sub->target->pos, &v20);
        } else {
            vec_add_ab(&obj->pos, &obj->pos, &v0);
        }
        obj->b8++;
        obj->w4 = func_L01_00444338(cfg->w4, cfg->w0, (f32)obj->hA / (f32)cfg->wC);
        if (func_003883C8(&obj->hA) != 0) {
            func_003C7CE0(obj);
        }
    }
}
/* localdecomp:end func_L01_0046AB08 */
