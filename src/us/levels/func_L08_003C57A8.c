#include "common.h"

/* NTSC-U counterpart of func_L08_003C7AC0 (src/levels/08_aquatos/L08_003C7660.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
#include "vu0.h"
#include "structs/hero.h"
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L08_003C57A8 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 b21; u8 p22[0x74]; u16 h96; u8 p98[0x24]; u8 bBC; u8 pBD[3];
    vu0_v4 vC0; u8 pD0[0x10]; vu0_v4 vE0;
} M_003C7AC0;
extern u8 D_001A4C60[];
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00442AA8(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);

void func_L08_003C57A8(M_003C7AC0 *a0) {
    vu0_v4 a;
    vu0_v4 b;

    if (a0->b20 == 0) {
        if (a0->b21 != 0xFF) {
            if (a0->bBC != 0) {
                if (a0->bBC != 2) {
                    func_0039FE80(0, 0, a0);
                    func_L01_00442AA8(a0->b21, 2);
                }
                func_L01_00441FB8(a0, 1, -1);
                func_L01_00452F40(a0, 1);
            }
        } else if (func_00388800(&a0->pos, D_001A4C60) < 7.0f) {
            func_0039FE80(0, 0, a0);
            func_L01_00441FB8(a0, 1, -1);
            func_L01_00452F40(a0, 1);
        }
    }
    if (a0->b20 == 1) {
        a0->h96++;
        func_00388830(&a, &a0->vE0, 0.058333337f);
        func_00388830(&b, &a0->vC0, -0.058333337f);
        vec_add_ab(&a0->pos, &a0->pos, &a);
        vec_add_ab(&a0->pos, &a0->pos, &b);
        if (a0->h96 > 30) {
            func_L01_00441FB8(a0, 2, -1);
        }
    }
}
/* localdecomp:end func_L08_003C57A8 */
