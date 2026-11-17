#include "common.h"

/* localdecomp:start func_L19_003AF1D0 */
typedef struct V4_003AF1D0 {
    f32 x, y, z, w;
} V4_003AF1D0;
typedef struct Eff_003AF1D0 {
    u8 pad0[0x2C];
    f32 f2C;
} Eff_003AF1D0;
typedef struct Hero_003AF1D0 {
    u8 pad0[0x98];
    f32 f98;
    u8 pad9C[0x1A30 - 0x9C];
    V4_003AF1D0 v1A30;
    V4_003AF1D0 v1A40;
    Eff_003AF1D0 *eff1A50;
    s32 w1A54;
    u8 pad1A58[4];
    f32 f1A5C;
    s32 w1A60;
    u8 pad1A64[0x25C0 - 0x1A64];
    void *w25C0;
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
} Hero_003AF1D0;
extern Hero_003AF1D0 D_001A4BE0;
extern f32 D_L19_001DE5C8;
__asm__(".extern D_L19_001DE5C8, 4");
extern f32 D_L19_001DE5CC;
__asm__(".extern D_L19_001DE5CC, 4");
extern f32 D_L19_001DE5D0;
__asm__(".extern D_L19_001DE5D0, 4");
extern f32 D_L19_001DE5D4;
__asm__(".extern D_L19_001DE5D4, 16");
extern f32 D_L19_001E2098[];
__asm__(".extern D_L19_001E2098, 16");
extern f32 D_L19_001E2114[];
__asm__(".extern D_L19_001E2114, 16");
extern u8 *D_001D52FC;
extern void func_L01_005110E8(void *, s32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_004C7A18(f32, void *, void *, void *, void *, void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L19_004F32A0(s32, s32);
extern void func_L10_003A7160(void *);
extern Eff_003AF1D0 *func_L19_003AF428(void *, void *, void *);

void func_L19_003AF1D0(void) {
    V4_003AF1D0 va;
    V4_003AF1D0 vb;
    V4_003AF1D0 vc;
    f32 yaw;
    f32 pitch;
    f32 roll;
    f32 scale;
    Eff_003AF1D0 *eff;
    s32 k;

    if (D_001A4BE0.b25E4 == 1) {
        scale = D_L19_001DE5D4 * 0.00040000002f;
        yaw = D_L19_001DE5CC;
        pitch = D_001A4BE0.f98;
        roll = D_L19_001DE5D0;
        if (D_001A4BE0.f1A5C != 0.0f) {
            yaw = D_001A4BE0.f1A5C;
        }
        func_L01_005110E8(&va, 1, 0.4f, -0.2f, 0.45f);
        if (D_001A4BE0.w25C4 == 1) {
            f32 lim;

            pitch = D_L19_001E2098[0];
            yaw = func_0038DAB8(-D_L19_001E2114[0], yaw);
            yaw = func_0038DAB8(yaw, 0.32f);
            lim = D_L19_001DE5C8;
            if (lim < yaw) {
                yaw = lim;
            }
            if (yaw < -lim) {
                yaw = -lim;
            }
        }
        func_00382760(&vb, roll, pitch, yaw);
        func_L01_004C7A18(scale, &va, &vb, &D_001A4BE0.v1A30, &D_001A4BE0.v1A40, D_001A4BE0.w25C0, 0, (s32)&vc);
        D_001A4BE0.w1A54 = 1;
        k = D_001A4BE0.w25CC;
        if (k == 0 || k == 4 || k == 1) {
            if (func_0038CAD0(&D_001A4BE0.w1A60) != 0 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x28) != 0) {
                func_L01_004F4E70(0x19, 0);
                if (D_001A4BE0.w25C4 != 1 && D_001A4BE0.w25C4 != 0x1D && D_001A4BE0.w25CC != 4) {
                    func_L19_004F32A0(0x4F, 1);
                }
                if (D_001A4BE0.eff1A50 != 0) {
                    func_L10_003A7160(D_001A4BE0.eff1A50);
                    D_001A4BE0.eff1A50 = 0;
                }
                D_001A4BE0.w1A60 = 0x21;
                eff = func_L19_003AF428(D_001A4BE0.w25C0, &va, &vb);
                D_001A4BE0.eff1A50 = eff;
                eff->f2C = eff->f2C * 1.7f;
            }
        }
    }
}
/* localdecomp:end func_L19_003AF1D0 */

INCLUDE_ASM("asm/levels", func_L19_003AF428);
