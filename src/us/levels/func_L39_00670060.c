#include "common.h"

/* NTSC-U counterpart of func_L39_006729B0 (src/levels/shared/L39_00672828.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L39_00670060 */
typedef struct S_006729B0 {
    s16 h0[25];
    u8 pad32[2];
    f32 f34[25];
    u8 pad98[0x160 - 0x98];
    f32 f160[25];
    f32 f1C4;
    f32 f1C8;
    f32 f1CC;
    f32 f1D0;
    f32 f1D4;
    s32 w1D8;
} S_006729B0;

typedef struct E_006729B0 {
    u8 pad0[0x1E];
    s16 h1E;
    u8 pad20[4];
    f32 f24;
    f32 f28;
    u8 pad2C[4];
    f32 f30[2];
    u8 pad38[0x80 - 0x38];
} E_006729B0;

extern S_006729B0 D_001A6F10;
extern E_006729B0 D_L39_0049C950_00670060[];
extern f32 D_001A6FA8[] __attribute__((section(".sdata")));
extern f32 D_001A700C[] __attribute__((section(".sdata")));
extern f32 D_L39_0024ACE4_00670060;
extern f32 D_L39_0024ACEC_00670060;
extern f32 D_L39_0024AFE8_00670060;
extern f32 D_L39_0024AEA4;
extern f32 D_L39_0024ABF0_00670060;

extern s32 func_L39_0066FDB0(void);
extern void func_L39_0066FED8(s32, s16 *, s16);
extern void func_L39_0066FF48(s32, f32, f32 *);
extern void func_L39_0066FFE0(f32 *, s32, f32);

void func_L39_00670060(void) {
    s32 i;

    if (func_L39_0066FDB0() == D_001A6F10.w1D8) {
        for (i = 0; i < 25; i++) {
            if (D_001A6F10.h0[i] > 0) {
                func_L39_0066FED8(i, &D_L39_0049C950_00670060[i].h1E, D_001A6F10.h0[i]);
            }
            if (D_001A6F10.f34[i] > 0.0f) {
                func_L39_0066FF48(i, D_001A6F10.f34[i], &D_L39_0049C950_00670060[i].f24);
            }
            if (D_001A6FA8[i] > 0.0f) {
                func_L39_0066FF48(i, D_001A6FA8[i], &D_L39_0049C950_00670060[i].f28);
            }
            if (D_001A700C[i] > 0.0f) {
                func_L39_0066FF48(i, D_001A700C[i], &D_L39_0049C950_00670060[i].f30[0]);
            }
            if (D_001A6F10.f160[i] > 0.0f) {
                func_L39_0066FF48(i, D_001A6F10.f160[i], &D_L39_0049C950_00670060[i].f30[1]);
            }
        }
        if (D_001A6F10.f1C4 > 0.0f) {
            func_L39_0066FFE0(&D_L39_0024ACE4_00670060, 0x107C, D_001A6F10.f1C4);
        }
        if (D_001A6F10.f1C8 > 0.0f) {
            func_L39_0066FFE0(&D_L39_0024ACEC_00670060, 0x107C, D_001A6F10.f1C8);
        }
        if (D_001A6F10.f1CC > 0.0f) {
            func_L39_0066FFE0(&D_L39_0024AFE8_00670060, 0x107E, D_001A6F10.f1CC);
        }
        if (D_001A6F10.f1D0 > 0.0f) {
            func_L39_0066FFE0(&D_L39_0024AEA4, 0x107E, D_001A6F10.f1D0);
        }
        if (D_001A6F10.f1D4 > 0.0f) {
            func_L39_0066FFE0(&D_L39_0024ABF0_00670060, 0x10C2, D_001A6F10.f1D4);
        }
    }
}
/* localdecomp:end func_L39_00670060 */
