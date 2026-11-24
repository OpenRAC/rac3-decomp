/* Unlinked regional matching draft. PAL: 114 to 55 words; alpha clamp adds one word and final interpolation scheduling differs. */
#include "common.h"

extern f32 D_L32_001DE8C0;
extern f32 D_L32_001DE8D4;
extern f32 D_L32_001DE8C8;
extern f32 D_L32_001DE8C4;
extern s32 D_L32_001DE8A8;
extern s32 D_L32_001DE8AC;
extern f32 D_L32_001DE8B0;
extern f32 D_L32_001DE8D0;
extern f32 D_L32_001DE8D8;
extern u8 D_L32_002A2E40[];
__asm__(".extern D_L32_001DE8C0, 4");
__asm__(".extern D_L32_001DE8D4, 4");
__asm__(".extern D_L32_001DE8C8, 4");
__asm__(".extern D_L32_001DE8C4, 4");
__asm__(".extern D_L32_001DE8A8, 4");
__asm__(".extern D_L32_001DE8AC, 4");
__asm__(".extern D_L32_001DE8B0, 4");
__asm__(".extern D_L32_001DE8D0, 4");
__asm__(".extern D_L32_001DE8D8, 4");
extern void func_L02_003BAFA0(void *, void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

typedef struct { u8 pad00[0x68]; u8 *vars; } Owner_003A7F48;
typedef struct {
    Owner_003A7F48 *owner;
    void *system;
    s16 life;
    u16 flags;
    s16 threshold;
    u16 color;
    f32 speedY, speedX, speedX2, speedZ;
} Params_003A7F48;
typedef struct {
    u8 pad00[4];
    u32 color;
    u8 alpha;
    u8 pad09;
    s16 age;
    f32 size, x, y, z;
} Particle_003A7F48;

void func_L32_003A7F48(Particle_003A7F48 *a0, Params_003A7F48 *a1) {
    Owner_003A7F48 *o;
    u8 *v;
    void *t;
    f32 k, y;
    f32 r, f1, lo, x, one;
    s32 al;
    s32 hi;
    if (a1 != 0) {
        o = a1->owner;
        t = a1->system;
        if (o != 0) {
            v = o->vars;
            if (v != 0 && t != 0) {
                if (a1->flags & 1) {
                    func_L02_003BAFA0(o, D_L32_002A2E40, &a0->x, &a1->speedX, 0.0f);
                    a0->y = a0->y + D_L32_001DE8C0;
                    a1->speedY = 0.0f;
                    k = D_L32_001DE8D4;
                    a1->speedX2 = k * *(f32 *)(v + 0x90);
                    a1->speedZ = k * *(f32 *)(v + 0x98);
                    a0->color = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L32_001DE8A8, D_L32_001DE8AC);
                    y = func_003824E0(D_L32_001DE8C8, D_L32_001DE8C4);
                    a0->size = y;
                    a1->threshold = func_00382498(0, a1->life);
                }
                one = 1.0f;
                r = func_L03_0034B440((f32)a0->age, (f32)a1->life, one, 1, 0, 0);
                if (a0->age < a1->threshold) {
                    a1->speedY = a1->speedY + D_L32_001DE8B0;
                    a0->z = a0->z + a1->speedY;
                    a0->x = a0->x + a1->speedX2;
                    a0->z = a0->z + a1->speedZ;
                }
                f1 = (one - r) / D_L32_001DE8D0;
                al = a0->color & 0xFFFFFF;
                a0->color = al | ((one < f1) ? 0x80000000 : (u32)(s32)(f1 * 128.0f) << 24);
                {
                    u16 color = a1->color;
                    hi = color >> 8;
                    lo = (f32)(color & 0xFF);
                }
                x = lo + (lo + D_L32_001DE8D8 * (f32)a1->life * (f32)hi * 0.00390625f);
                a0->alpha = func_003C4088(lo, x, func_L03_0034B148(a0->age, a1->life, 0.0f));
            }
        }
    }
}
