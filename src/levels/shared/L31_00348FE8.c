#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

/* localdecomp:start func_L31_00348FE8 */
typedef struct {
    u8 pad0[0x20];
    u8 unk20;
    u8 pad21[0x43 - 0x21];
    u8 unk43;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
} Moby_00348FE8;

extern f32 D_L31_001DD008;
extern s32 D_L31_001DD028;
extern f32 D_L31_001DD034;
extern s32 D_L31_001DCFFC;
extern s32 D_L31_001DD01C;
extern f32 D_L31_001DD038;
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

void func_L31_00348FE8(void *arg0, s32 a1) {
    Moby_00348FE8 *m = arg0;

    func_L01_004450F0(m, a1, -1);
    switch (m->unk20) {
    case 0:
        break;
    case 1:
        if (m->unk43 != 3) {
            func_003C3A10(m, 3, 7, 2);
        }
        m->unk48 = D_L31_001DD008;
        break;
    case 2:
        if (m->unk43 != 10) {
            func_003C3A10(m, 10, D_L31_001DD034, (D_L31_001DD028 * 5 + 2) / 6);
        }
        func_003A52A0(2, 0, m);
        m->unk48 = 1.0f;
        m->unk44 += m->unk4C;
        break;
    case 3:
        if (m->unk43 != 4) {
            func_003C3A10(m, 4, 0, (D_L31_001DCFFC * 5 + 2) / 6);
        }
        m->unk48 = 1.0f;
        break;
    case 4:
        if (m->unk43 != 7) {
            func_003C3A10(m, 7, 0, (D_L31_001DCFFC * 5 + 2) / 6);
        }
        m->unk48 = 1.0f;
        break;
    case 5:
        if (m->unk43 != 2) {
            func_003C3A10(m, 2, 0, D_L31_001DCFFC);
        }
        break;
    case 7:
        if (m->unk43 != 5) {
            func_003C3A10(m, 5, 3, 2);
        }
        m->unk48 = 1.0f;
        break;
    case 6:
    case 8:
        if (m->unk43 != 6) {
            func_003C3A10(m, 6, 0, (D_L31_001DCFFC * 5 + 2) / 6);
        }
        break;
    case 9:
        if (m->unk43 != 8) {
            func_003C3A10(m, 8, D_L31_001DD038, (D_L31_001DD01C * 5 + 2) / 6);
        }
        m->unk48 = 1.0f;
        func_003A52A0(2, 0, m);
        m->unk44 += m->unk4C;
        break;
    case 10:
        if (m->unk43 != 1) {
            func_003C3A10(m, 1, 0, D_L31_001DCFFC);
        }
        break;
    case 0x42:
        break;
    }
}
/* localdecomp:end func_L31_00348FE8 */
