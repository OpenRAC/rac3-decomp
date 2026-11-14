#include "common.h"

/* NTSC-U counterpart of func_L30_0034BE60 (src/levels/shared/L30_0034BE60.c) */
/* localdecomp:start func_L30_0034AF80 */
#include "vu0.h"
typedef int Quad_34BE60 __attribute__((mode(TI)));
typedef struct Obj_34BE60 {
    u8 pad0[0x10];
    Quad_34BE60 pos;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    u8 *vars;
    u8 pad6C[0xAA - 0x6C];
    u16 hAA;
    u8 padAC[0xF0 - 0xAC];
    f32 fF0;
} Obj_34BE60;
typedef struct Vars_34BE60 {
    Quad_34BE60 v0;
    u8 pad10[4];
    u8 *w14;
    f32 f18;
    u8 pad1C[0x28 - 0x1C];
    s32 w28;
} Vars_34BE60;
typedef struct Hit_34BE60 {
    u8 pad0[0x1A];
    u16 h1A;
    u8 pad1C[0x30 - 0x1C];
} Hit_34BE60;
extern u8 *D_L30_001E9018_0034AF80[4];
__asm__(".extern D_L30_001E9018_0034AF80, 16");
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern s32 func_00388398(void *);
extern void func_L01_00443648(void *, f32, void *, s32, f32, f32, s32, s32, s32);
extern void func_L30_0034CBE0(void *);
extern void func_003BD360(void *);
extern void func_L30_0034B160(void *);
extern void func_L30_0034B208(void *);

void func_L30_0034AF80(Obj_34BE60 *obj) {
    Vars_34BE60 *vars = (Vars_34BE60 *)obj->vars;
    Quad_34BE60 npos[1];
    Hit_34BE60 hit;

    switch (obj->b20) {
    case 0:
        vars->w28 = -1;
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        obj->fF0 = func_00389380(obj->fF0, 0.104719765f);
        vec_add_ba(npos, &obj->pos, &vars->v0);
        func_L01_00443628(&hit, obj, 1, vars->f18, vars);
        hit.h1A = obj->hAA;
        if (func_003CE740((u8 *)obj + 0x10, npos, 0, obj, &hit) != 0
            || func_L01_003F9498((u8 *)obj + 0x10, 0, obj, 0.3f) != 0
            || func_00388398((u8 *)vars + 0x10) != 0) {
            if (D_L30_001E9018_0034AF80[0] != 0) {
                if (D_L30_001E9018_0034AF80[0] == vars->w14 || *(s16 *)(D_L30_001E9018_0034AF80[0] + 0xAA) == 0x15F9) {
                    goto commit;
                }
                func_L01_00443648(obj, 0.5f, (u8 *)obj + 0x10, 1, vars->f18, 1.0f, 0, 1, 0);
            }
            func_L01_00441FB8(obj, 2, -1);
            return;
        }
    commit:
        obj->pos = npos[0];
        break;
    case 2:
        func_L30_0034CBE0(&vars->w28);
        func_003BD360(obj);
        return;
    }
    func_L30_0034B160(obj);
    func_L30_0034B208(obj);
}
/* localdecomp:end func_L30_0034AF80 */
