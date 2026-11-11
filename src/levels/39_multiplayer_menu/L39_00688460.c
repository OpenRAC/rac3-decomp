#include "common.h"

/* localdecomp:start func_L39_00688460 */
typedef struct {
    u8 pad0[0x64];
    s32 unk64[0x29];
} S_00688460;
extern s32 func_L39_0067F1B0(void);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E51F8(s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 D_L39_0024736C;
__asm__(".extern D_L39_0024736C, 16");
extern s32 D_001DBC5C_sda;
void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5) {
    S_00688460 *p = (S_00688460 *)a0;
    s32 i;

    p->unk64[0] = *(s32 *)p5 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p5, 0x3F, 0x80000000, f1, f2, f3 + 0.006f, f4 + 0.006f, f5);
    func_003E8630(D_L39_0024736C, *(s32 *)p5);
    p->unk64[1] = *(s32 *)p3 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p3, 0x3F, 0x331465B7, f1, f2, f3 + 0.001f, f4 + 0.001f, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p3);
    p->unk64[2] = *(s32 *)p4 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p4, 0x40, 0x802299DE, f1, f2, f3, f4, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p4);
    p->unk64[3] = *(s32 *)p1 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p1, 0x3D, 0x332299DE, f1, f2, f3, f4, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p1);
    p->unk64[4] = *(s32 *)p2 = func_L39_0067F1B0();
    func_003E8EF0(*(s32 *)p2, 0x3E, 0x332299DE, f1, f2, f3, f4, f5);
    func_003E8630(D_001DBC5C_sda, *(s32 *)p2);
    p->unk64[5] = func_L39_0067F1B0();
    func_003E51F8(p->unk64[5]);
    func_L01_00516AA0(p->unk64[5], 1, 0);
    func_L01_00516C78(p->unk64[5], 3, 3);
    func_003E8630(D_L39_0024736C, p->unk64[5]);
    p->unk64[6] = func_L39_0067F1B0();
    func_003E8EF0(p->unk64[6], 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, 1.0f, 0.5f);
    func_L01_00516AA0(p->unk64[6], 1, 0);
    func_003E8630(D_L39_0024736C, p->unk64[6]);
    p->unk64[7] = func_L39_0067F1B0();
    func_003E8EF0(p->unk64[7], 0x80, 0x332299DE, 0.5f, 0.5f, 1.0f, -1.0f, 0.5f);
    func_L01_00516AA0(p->unk64[7], 1, 0);
    func_003E8630(D_L39_0024736C, p->unk64[7]);
    for (i = 0; i < 30; i++) {
        p->unk64[8 + i] = func_L39_0067F1B0();
        func_003E51F8(p->unk64[8 + i]);
        func_L01_00516AA0(p->unk64[8 + i], 1, 0);
        func_L01_00516C78(p->unk64[8 + i], 3, 3);
        func_003E8630(D_L39_0024736C, p->unk64[8 + i]);
    }
    for (i = 0; i < 1; i++) {
        p->unk64[0x26 + i] = func_L39_0067F1B0();
        func_003E9270(p->unk64[0x26 + i], 0x332299DE, 0.5f, 0.5f, 0.5f, 0.5f, 0.05f, 0.05f);
        func_L01_00516AA0(p->unk64[0x26 + i], 1, 0);
        func_003E8630(D_L39_0024736C, p->unk64[0x26 + i]);
    }
    for (i = 0; i < 2; i++) {
        p->unk64[0x27 + i] = func_L39_0067F1B0();
        func_003E51F8(p->unk64[0x27 + i]);
        func_L01_00516AA0(p->unk64[0x27 + i], 1, 0);
        func_L01_00516C78(p->unk64[0x27 + i], 3, 3);
        func_003E8630(D_L39_0024736C, p->unk64[0x27 + i]);
    }
}
/* localdecomp:end func_L39_00688460 */

INCLUDE_ASM("asm/levels", func_L39_006888B8);
