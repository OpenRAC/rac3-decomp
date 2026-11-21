#include "common.h"

/* NTSC-U counterpart of func_L19_003AF1D0 (src/levels/shared/L19_003AF1D0.c): 0.0004 -> 0.000277778; 33 -> 40 */
/* localdecomp:start func_L19_003AD580 */
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
extern f32 D_L19_001DE608;
__asm__(".extern D_L19_001DE608, 4");
extern f32 D_L19_001DE60C;
__asm__(".extern D_L19_001DE60C, 4");
extern f32 D_L19_001DE610;
__asm__(".extern D_L19_001DE610, 4");
extern f32 D_L19_001DE614;
__asm__(".extern D_L19_001DE614, 16");
extern f32 D_L19_001E2098_003AD580[];
__asm__(".extern D_L19_001E2098_003AD580, 16");
extern f32 D_L19_001E2114_003AD580[];
__asm__(".extern D_L19_001E2114_003AD580, 16");
extern u8 *D_001D52FC;
extern void func_L01_0050D110(void *, s32, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L01_004C3E68(f32, void *, void *, void *, void *, void *, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L01_004F1068(s32, s32);
extern void func_L19_004EECE0(s32, s32);
extern void func_L10_003A52C0(void *);
extern Eff_003AF1D0 *func_L19_003AD7D8(void *, void *, void *);

void func_L19_003AD580(void) {
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
        scale = D_L19_001DE614 * 0.000277777785f;
        yaw = D_L19_001DE60C;
        pitch = D_001A4BE0.f98;
        roll = D_L19_001DE610;
        if (D_001A4BE0.f1A5C != 0.0f) {
            yaw = D_001A4BE0.f1A5C;
        }
        func_L01_0050D110(&va, 1, 0.4f, -0.2f, 0.45f);
        if (D_001A4BE0.w25C4 == 1) {
            f32 lim;

            pitch = D_L19_001E2098_003AD580[0];
            yaw = func_00389380(-D_L19_001E2114_003AD580[0], yaw);
            yaw = func_00389380(yaw, 0.32f);
            lim = D_L19_001DE608;
            if (lim < yaw) {
                yaw = lim;
            }
            if (yaw < -lim) {
                yaw = -lim;
            }
        }
        func_0037E4B8(&vb, roll, pitch, yaw);
        func_L01_004C3E68(scale, &va, &vb, &D_001A4BE0.v1A30, &D_001A4BE0.v1A40, D_001A4BE0.w25C0, 0, (s32)&vc);
        D_001A4BE0.w1A54 = 1;
        k = D_001A4BE0.w25CC;
        if (k == 0 || k == 4 || k == 1) {
            if (func_00388398(&D_001A4BE0.w1A60) != 0 && (*(s32 *)(D_001D52FC + 0x1A4) & 0x28) != 0) {
                func_L01_004F1068(0x19, 0);
                if (D_001A4BE0.w25C4 != 1 && D_001A4BE0.w25C4 != 0x1D && D_001A4BE0.w25CC != 4) {
                    func_L19_004EECE0(0x4F, 1);
                }
                if (D_001A4BE0.eff1A50 != 0) {
                    func_L10_003A52C0(D_001A4BE0.eff1A50);
                    D_001A4BE0.eff1A50 = 0;
                }
                D_001A4BE0.w1A60 = 0x28;
                eff = func_L19_003AD7D8(D_001A4BE0.w25C0, &va, &vb);
                D_001A4BE0.eff1A50 = eff;
                eff->f2C = eff->f2C * 1.7f;
            }
        }
    }
}
/* localdecomp:end func_L19_003AD580 */
