#include "common.h"

/* localdecomp:start func_L27_0039F6A8 */
void func_L22_003B6EE8(s32, s32);
void func_L01_004450F0(void *, s32, s32);
void func_L01_00456230(void *, s32);

void func_L27_0039F6A8(void *arg0) {
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    if ((arg0 != 0) && (temp_v0 != 0) && ((*(s32 *)((u8 *)temp_v0 + 0x48C)) != 0) && ((*(u8 *)((u8 *)arg0 + 0x95)) != 6)) {
        func_L22_003B6EE8((s32) arg0, 0);
        func_L01_00456230(arg0, 0);
        func_L01_004450F0(arg0, 0x20, 6);
    }
}
/* localdecomp:end func_L27_0039F6A8 */

/* localdecomp:start func_L27_0039F718 */
typedef struct { u8 p0[0x47C]; void *f47C; u8 p480[0x14]; s32 f494; s32 f498; s32 f49C; u8 p4A0[0x88]; f32 f528; } S_F718_D;
typedef struct S_F718_O { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[8]; u8 b20; u8 p21[0x47]; S_F718_D *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_F718_O;
extern f32 func_0038D160(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

extern void func_L27_0039F718(S_F718_O *, S_F718_O *);
void func_L27_0039F718(S_F718_O *a0, S_F718_O *a1) {
    S_F718_D *d = a0->f68;
    if (a0 == 0) return;
    if (a0->b20 == 0xFE) return;
    if (a0->b20 == 0xFD) return;
    if (a1 == 0) return;
    if (a1->b20 == 0xFE) return;
    if (a1->b20 == 0xFD) return;
    if (a0->b20 == 6) return;
    if (a0->b95 != 1) return;
    if (a1->b20 == 6) return;
    if (a1->b95 != a0->b95) return;
    if (a0->h96 < a1->h96) {
        func_L27_0039F718(a1, a0);
        return;
    }
    d->f528 = func_0038D160(a1->f10 - a0->f10, a1->f14 - a0->f14);
    {
        s32 r = func_00382498(0x15, 0x18);
        d->f47C = a1;
        d->f494 = 0;
        d->f49C = -0x18;
        d->f498 = r;
    }
    func_L01_004450F0(a0, 6, -1);
}
/* localdecomp:end func_L27_0039F718 */
