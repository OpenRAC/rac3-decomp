#include "common.h"

/* NTSC-U counterpart of func_L08_003C73B8 (src/levels/shared/L08_003C73B8.c) */
/* localdecomp:start func_L08_003C50F0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003C73B8;
typedef struct { u8 pad0[0x10]; u8 *f10; } S_003C73B8;
__asm__(".extern D_L08_001DE8B8, 4");
__asm__(".extern D_L08_001DE8BC, 4");
__asm__(".extern D_L08_001DE8C0, 4");
__asm__(".extern D_L08_001DE8C4, 4");
__asm__(".extern D_L08_001DE8C8, 4");
__asm__(".extern D_L08_001DE8CC, 4");
__asm__(".extern D_L08_001DE8D0, 4");
__asm__(".extern D_L08_001DE8D4, 4");
__asm__(".extern D_L08_001DE8D8, 4");
__asm__(".extern D_L08_001DE8DC, 4");
__asm__(".extern D_L08_001DE8E0, 4");
extern s32 D_L08_001DE8B8;
extern s32 D_L08_001DE8BC;
extern s32 D_L08_001DE8C0;
extern s32 D_L08_001DE8C4;
extern s32 D_L08_001DE8C8;
extern s32 D_L08_001DE8CC;
extern f32 D_L08_001DE8D0;
extern f32 D_L08_001DE8D4;
extern f32 D_L08_001DE8D8;
extern f32 D_L08_001DE8DC;
extern f32 D_L08_001DE8E0;
extern S_003C73B8 D_L08_0021EB18_003C50F0;
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0046CF70(void *, void *, s32, f32);

void func_L08_003C50F0(u8 *m, V4_003C73B8 *a, V4_003C73B8 *b) {
    V4_003C73B8 pos;
    V4_003C73B8 vel;
    u8 *p;
    s32 i;
    s32 col;
    u8 alpha;
    f32 t;
    u8 *e;

    p = *(u8 **)(m + 0x68);
    pos = *a;
    if (*(s32 *)(p + 0x10) < 50) {
        alpha = (*(s32 *)(p + 0x10) * 127.0f) / 50.0f;
    } else {
        alpha = 127;
    }
    for (i = 0; i < D_L08_001DE8B8; i++) {
        t = D_L08_001DE8D8 * *(f32 *)(p + 0x14);
        func_0037E2F0(&vel, t * 0.5f, t);
        vec_add_ab(&vel, &vel, b);
        func_00388830(&vel, &vel, func_0037E250(D_L08_001DE8DC * 0.5f, D_L08_001DE8DC) * 0.016666668f);
        if (func_0037E1D8(4) != 0) {
            col = D_L08_001DE8CC;
        } else {
            col = D_L08_001DE8C4;
        }
        col |= alpha << 24;
        e = func_L01_00472438(&pos, &vel, D_L08_001DE8BC, func_0037E208(-2, 2), col, D_L08_001DE8C8,
                              D_L08_001DE8D0 * 210000.0f, D_L08_001DE8D4 * 210000.0f,
                              func_0037E250(D_L08_001DE8E0 * 0.3f, D_L08_001DE8E0), 0);
        if (e != 0) {
            e[2] = *D_L08_0021EB18_003C50F0.f10;
            e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
        }
    }
    if (func_0037E1D8(6) == 0) {
        func_L01_0046CF70(&pos, &vel, func_0037E208(D_L08_001DE8C0 - 5, D_L08_001DE8C0), func_0037E250(40.0f, 80.0f) * 0.00027777778f);
    }
}
/* localdecomp:end func_L08_003C50F0 */
