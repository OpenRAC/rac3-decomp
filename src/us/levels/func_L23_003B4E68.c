#include "common.h"

/* NTSC-U counterpart of func_L23_003B67B0 (src/levels/23_holostar_studios_clank/L23_003B3BB8.c): 0.00502655 -> 0.00349066; 0.125664 -> 0.10472 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    u8 pad0[0xA8];
    s32 xA8;
    u8 padAC[0x2C8 - 0xAC];
    s32 x2C8;
    u8 pad2CC[0x310 - 0x2CC];
    u128_t x310;
    V4 x320;
} Vars_3B67B0;
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
#include "structs/hero.h"
#include "vu0.h"
extern void func_L23_003B4E68(void *owner, void *p, int z, float f, float g);
extern void func_L23_003B4E68(void *, void *, int, float, float);

/* localdecomp:start func_L23_003B4E68 */
/* MATCH: needs -mvu0-use-vf0-vf2 on L23_003B3BB8.c (vec_* helpers) */
#include "vu0.h"

extern f32 D_L23_001DE4BC;
__asm__(".extern D_L23_001DE4BC, 4");
extern s32 D_L23_001DE480;
__asm__(".extern D_L23_001DE480, 4");
extern f32 D_L23_001DE4A0[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE4A0, 4");
extern f32 D_L23_001DE488[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE488, 4");
extern f32 D_L23_001DE4D8;
__asm__(".extern D_L23_001DE4D8, 4");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00457440(void *, void *);
extern void func_L01_00457708(void *, f32);
extern s32 func_L01_00458A08(void *, f32);
extern s32 func_L01_00457728(u8 *, u128_t *);
extern void func_003886E8(void *, void *, f32);

void func_L23_003B4E68(void *owner, void *p, int z, float f, float g)
{
    u8 *m = owner;
    Vars_3B67B0 *v = *(Vars_3B67B0 **)(m + 0x68);
    V4 d;
    u128_t e;
    f32 t;

    if (z != v->x2C8) {
        if (z == 2) {
            *(f32 *)(m + 0x48) = D_L23_001DE4BC;
        }
        if (D_L23_001DE480 != 0) {
            *(f32 *)(m + 0x48) = 0.1f;
        }
        func_L01_00458A70(m, D_L23_001DE4A0[z] * *(f32 *)(m + 0x48), D_L23_001DE488[z] * *(f32 *)(m + 0x48),
                          *(f32 *)(m + 0x48) * 0.00349065871f, *(f32 *)(m + 0x48) * 0.104719765f);
        if (z == 3) {
            v->x310 = *(u128_t *)(m + 0x10);
            v->xA8 = 0x514;
        } else {
            v->xA8 = 0;
        }
    }
    v->x2C8 = z;
    switch (z) {
    case 0:
        func_L01_00457708(m, f);
        func_L01_00458A08(m, f);
        break;
    case 1:
    case 2:
        func_L01_00457440(m, p);
        break;
    case 3:
        t = g + g - 1.0f;
        t = (1.0f - t * t) * D_L23_001DE4D8;
        vec_sub_ba(&d, &v->x320, &v->x310);
        func_003886E8(&d, &d, g);
        vec_add_ba(&d, &d, &v->x310);
        d.z += t;
        vec_sub_ba(&e, &d, m + 0x10);
        func_L01_00457728(m, &e);
        break;
    }
}
/* localdecomp:end func_L23_003B4E68 */
