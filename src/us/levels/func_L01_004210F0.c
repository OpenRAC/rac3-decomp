#include "common.h"

/* NTSC-U counterpart of func_L01_00423E20 (src/levels/01_veldin/L01_00423E20.c): 0.08 -> 0.0666667 */
#include "vu0.h"

/* localdecomp:start func_L01_004210F0 */
typedef struct { s16 f0; s16 pad; f32 f4; f32 f8; f32 fC; u32 f10; u32 f14; u32 f18; u32 f1C; } S_A_423E20;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_423E20;
typedef struct { V4_423E20 a; V4_423E20 b; } S_B_423E20;
typedef struct { u8 p[0x10]; V4_423E20 v; u8 q[0x8A]; s16 fAA; u8 r[0x50]; } S_Obj_423E20;
extern S_Obj_423E20 *D_L01_001E009C;
extern S_Obj_423E20 *D_L01_001E00A0;
extern u32 D_L01_001E6FA0[];
__asm__(".extern D_L01_001E6FA0, 16");
extern S_Obj_423E20 *D_001E00A0_sda;
__asm__(".extern D_001E00A0_sda, 4");
extern u8 D_001D6AC0_sda_004210F0;
__asm__(".extern D_001D6AC0_sda_004210F0, 4");
extern f32 func_00388800(void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_00460318(void *, void *, u32, u32, s32, s32, s32, s32);
void func_L01_004210F0(void) {
    S_Obj_423E20 *p = D_L01_001E009C;
    u8 *hero = (u8 *)D_L01_001E6FA0[0];
    S_Obj_423E20 *best = 0;
    f32 bd = 9999.0f;
    S_A_423E20 a;
    V4_423E20 va;
    V4_423E20 vb;
    s32 r;
    if (p < D_L01_001E00A0) {
        do {
            if (p->fAA == 0x19B1) {
                f32 d = func_00388800(hero + 0x10, (u8 *)p + 0x10);
                if (d < bd) { bd = d; best = p; }
            }
            p++;
        } while (p < D_001E00A0_sda);
    }
    if (best != 0) {
        a = *(S_A_423E20 *)&D_001D6AC0_sda_004210F0;
        a.f14 = 0x20406070;
        a.f18 = 0x152030;
        a.f0 = 0x50;
        a.f4 = 120.0f;
        a.f8 = 80.0f;
        a.fC = 0.0666666701f;
        r = func_0037E1D8(0x32);
        va = best->v;
        va.z -= 2.8f;
        qzero(&vb);
        func_003BF6A8(&vb, a.fC);
        vb.z = 0;
        func_L01_00460318(&va, &vb, a.f14, a.f18, a.f0, (s32)(a.f8 + r), (s32)(a.f4 + r), func_0037E1D8(2));
    }
}
/* localdecomp:end func_L01_004210F0 */
