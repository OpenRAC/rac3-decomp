#include "common.h"

/* NTSC-U counterpart of func_L31_00348FE8 (src/levels/shared/L31_00348FE8.c) */
/* localdecomp:start func_L31_00348488 */
typedef struct {
    u8 pad0[0x20];
    u8 unk20;
    u8 pad21[0x43 - 0x21];
    u8 unk43;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
} Moby_00348FE8;

extern f32 D_L31_001DD048;
extern s32 D_L31_001DD068;
extern f32 D_L31_001DD074;
extern s32 D_L31_001DD03C;
extern s32 D_L31_001DD05C;
extern f32 D_L31_001DD078;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);

void func_L31_00348488(void *arg0, s32 a1) {
    Moby_00348FE8 *m = arg0;

    func_L01_00441FB8(m, a1, -1);
    switch (m->unk20) {
    case 0:
        break;
    case 1:
        if (m->unk43 != 3) {
            func_003BE4F0(m, 3, 7, 2);
        }
        m->unk48 = D_L31_001DD048;
        break;
    case 2:
        if (m->unk43 != 10) {
            func_003BE4F0(m, 10, D_L31_001DD074, D_L31_001DD068);
        }
        func_0039FE80(2, 0, m);
        m->unk48 = 1.0f;
        m->unk44 += m->unk4C;
        break;
    case 3:
        if (m->unk43 != 4) {
            func_003BE4F0(m, 4, 0, D_L31_001DD03C);
        }
        m->unk48 = 1.0f;
        break;
    case 4:
        if (m->unk43 != 7) {
            func_003BE4F0(m, 7, 0, D_L31_001DD03C);
        }
        m->unk48 = 1.0f;
        break;
    case 5:
        if (m->unk43 != 2) {
            func_003BE4F0(m, 2, 0, D_L31_001DD03C);
        }
        break;
    case 7:
        if (m->unk43 != 5) {
            func_003BE4F0(m, 5, 3, 3);
        }
        m->unk48 = 1.0f;
        break;
    case 6:
    case 8:
        if (m->unk43 != 6) {
            func_003BE4F0(m, 6, 0, D_L31_001DD03C);
        }
        break;
    case 9:
        if (m->unk43 != 8) {
            func_003BE4F0(m, 8, D_L31_001DD078, D_L31_001DD05C);
        }
        m->unk48 = 1.0f;
        func_0039FE80(2, 0, m);
        m->unk44 += m->unk4C;
        break;
    case 10:
        if (m->unk43 != 1) {
            func_003BE4F0(m, 1, 0, D_L31_001DD03C);
        }
        break;
    case 0x42:
        break;
    }
}
/* localdecomp:end func_L31_00348488 */
