#include "common.h"

/* NTSC-U counterpart of func_L01_0046CDA8 (src/levels/shared/L01_0046A938.c): 50 -> 60; 100 -> 120; 0.02 -> 0.0166667; 25 -> 30 */
#include "vu0.h"
typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern s32 func_003883C8(s16 *);
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(s16 *);
extern s32 func_0037E1D8(s32);
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(s16 *);

/* localdecomp:start func_L01_004696F8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46CDA8;
extern s32 D_L01_001D7F50_004696F8;
__asm__(".extern D_L01_001D7F50_004696F8, 4");
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
typedef struct { u8 pad[16]; V_46CDA8 pos, vel; } Particle_46CDA8;

void func_L01_004696F8(u8 *obj)
{
    u8 *rec = obj + 0x20;
    u8 *position;

    if (func_003883C8((s16 *)(obj + 0xA))) {
        *(f32 *)(rec + 8) -= *(f32 *)(rec + 0x14);
    }
    vec_add_ab(&((Particle_46CDA8 *)obj)->pos, &((Particle_46CDA8 *)obj)->pos, &((Particle_46CDA8 *)obj)->vel);
    position = obj + 0x10;
    {
        f32 height = *(f32 *)(obj + 0x18);
        obj[8] += 2;
        if (height < *(f32 *)(rec + 0x10)) {
            if (!func_0037E1D8(D_L01_001D7F50_004696F8 - 1)) {
                *(f32 *)(obj + 0x18) = *(f32 *)(rec + 0x10);
                *(f32 *)(obj + 0x20) *= func_0037E250(1.0f, 3.5f);
                *(f32 *)(rec + 4) *= func_0037E250(1.0f, 3.5f);
                *(f32 *)(rec + 8) *= func_0037E250(-1.0f, -1.5f);
                func_L01_00462190(position, rec, *(s32 *)(obj + 4), *(s32 *)(rec + 0x18), func_0037E208(60, 120), 0, obj[2], obj[3], 0, *(f32 *)(obj + 0xC) * 0.5f);
            } else {
                *(f32 *)(obj + 0x18) = *(f32 *)(rec + 0x10);
                *(f32 *)(obj + 0x20) += func_0037E250(-5.0f, 5.0f) * 0.0166666675f;
                *(f32 *)(rec + 4) += func_0037E250(-5.0f, 5.0f) * 0.0166666675f;
                *(f32 *)(rec + 8) *= func_0037E250(-0.5f, -1.0f);
                func_L01_00462190(position, rec, *(s32 *)(obj + 4), *(s32 *)(rec + 0x18), func_0037E208(30, 60), 0, obj[2], obj[3], 0, *(f32 *)(obj + 0xC) * 0.25f);
            }
            func_003C7CE0((Obj *)obj);
        }
    }
}
/* localdecomp:end func_L01_004696F8 */
