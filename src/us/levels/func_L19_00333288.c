#include "common.h"

typedef struct { u8 pad[0x330]; s32 ids[8]; } Grp_003345D0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_003347B0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} GroupState_00334958;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_00334B10;

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00332BA8;
extern s32 fe_func_00382380(void *, s32, s32);
/* localdecomp:start func_L19_00333288 */
extern s32 func_L01_004576E8(void *);
extern s32 func_00388398(void *);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L19_003330A8(void *, void *);
extern s32 D_001A4CC0[];

/* Updates a moby's look-around: runs func_L01_004576E8, and when its timer ends picks random yaw
 * and pitch targets and a new wait, or a follow-hero mode that calls func_L19_003330A8; otherwise
 * copies the target angles into its joints. */
void func_L19_00333288(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 0x68);

    func_L01_004576E8(a0);
    if (a0[0x31] == 0) {
        return;
    }
    if (func_00388398(s0 + 0x374) != 0) {
        if (a0[0x95] == 2) {
            *(f32 *)(s0 + 0x378) = func_L01_00440918(0.08726646f, 1.0471976f);
            *(f32 *)(s0 + 0x37C) = func_0037E250(-0.34906584f, 0.0f);
            *(s32 *)(s0 + 0x374) = func_0037E208(30, 45);
            *(s32 *)(s0 + 0x380) = 0;
        } else if (func_0037E1D8(4) == 0) {
            *(s32 *)(s0 + 0x380) = 1;
            *(s32 *)(s0 + 0x374) = func_0037E208(180, 300);
        } else {
            *(f32 *)(s0 + 0x378) = func_L01_00440918(0.08726646f, 0.34906584f);
            *(f32 *)(s0 + 0x37C) = func_0037E250(-0.2617994f, 0.08726646f);
            *(s32 *)(s0 + 0x374) = func_0037E208(60, 120);
            *(s32 *)(s0 + 0x380) = 0;
        }
    }
    if (*(s32 *)(s0 + 0x380) != 0) {
        func_L19_003330A8(a0, D_001A4CC0);
    } else {
        f32 u = *(f32 *)(s0 + 0x37C);
        f32 v = *(f32 *)(s0 + 0x378);
        *(f32 *)(s0 + 0x314) = u;
        *(f32 *)(s0 + 0x318) = v;
        *(f32 *)(s0 + 0x294) = u;
        *(f32 *)(s0 + 0x298) = v;
    }
}
/* localdecomp:end func_L19_00333288 */
