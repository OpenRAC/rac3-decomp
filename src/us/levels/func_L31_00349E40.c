#include "common.h"

/* NTSC-U counterpart of func_L31_0034AA20 (src/levels/shared/L31_0034AA20.c) */
/* localdecomp:start func_L31_00349E40 */
typedef struct {
    u8 pad0[0x20];
    u8 state;           /* 0x20 */
    u8 pad21[0x43 - 0x21];
    u8 anim;            /* 0x43 */
    f32 f44;
    f32 f48;
    f32 f4C;
} M_0034AA20;

extern f32 D_L31_001DD160;
extern f32 D_L31_001DD170_00349E40;
extern f32 D_L31_001DD174_00349E40;
extern f32 D_L31_001DD178;
extern s32 D_L31_001DD17C;
extern f32 D_L31_001DD188;
extern f32 D_L31_001DD18C;
extern s32 D_L31_001DD194_00349E40;
extern f32 D_L31_001DD198_00349E40;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L31_00349E40(M_0034AA20 *m, s32 arg) {
    func_L01_00441FB8(m, arg, -1);
    switch (m->state) {
    case 0:
        break;
    case 0x42:
        m->f48 = 0.0f;
        break;
    case 1:
        if (m->anim != 6) {
            func_003BE4F0(m, 6, D_L31_001DD198_00349E40, D_L31_001DD194_00349E40);
        }
        m->f48 = D_L31_001DD170_00349E40;
        m->f44 += m->f4C;
        break;
    case 2:
        if (m->anim != 4) {
            func_003BE4F0(m, 4, 0, D_L31_001DD17C);
        }
        m->f48 = D_L31_001DD178;
        break;
    case 3:
        if (m->anim != 1) {
            func_003BE4F0(m, 1, 0, D_L31_001DD17C);
        }
        m->f48 = D_L31_001DD174_00349E40;
        break;
    case 4:
        func_003BE4F0(m, 5, D_L31_001DD188, D_L31_001DD18C);
        m->f44 += m->f4C;
        break;
    case 5:
        if (m->anim != 1) {
            func_003BE4F0(m, 1, 0, D_L31_001DD17C);
        }
        m->f48 = D_L31_001DD160;
        break;
    }
}
/* localdecomp:end func_L31_00349E40 */
