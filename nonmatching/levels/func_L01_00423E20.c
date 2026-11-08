/* Level 01. 42 diff, all from one extra instruction: this C emits "por $v0,$zero,$zero; sq $v0,0x30($sp)" where retail has a single "sq $zero,0x30($sp)", which shifts the rest by one word. Needs @ps2as on L01_00423E20.c. */
#include "common.h"
typedef struct { s16 f0; s16 pad; f32 f4; f32 f8; f32 fC; u32 f10; u32 f14; u32 f18; u32 f1C; } S_A;
typedef int u128 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; } S_B;
typedef struct { u8 p[0x10]; V4 v; u8 q[0x8A]; s16 fAA; u8 r[0x50]; } S_Obj;
extern S_Obj *D_001E001C;
extern S_Obj *D_001E0020;
extern u32 D_001E6F20_h[];
__asm__(".extern D_001E6F20_h, 16");
extern S_Obj *D_001E0020_sda;
__asm__(".extern D_001E0020_sda, 4");
extern u8 D_001D6AC0_sda;
__asm__(".extern D_001D6AC0_sda, 4");
extern f32 func_0040E518(void *, void *);
extern s32 func_00443948(s32);
extern void func_0044BF48(void *, f32);
extern void func_L01_004637C8(void *, void *, u32, u32, s32, s32, s32, s32);
void func_L01_00423E20(void) {
    S_Obj *p = D_001E001C;
    u8 *hero = (u8 *)D_001E6F20_h[0];
    S_Obj *best = 0;
    f32 bd = 9999.0f;
    S_A a;
    V4 va;
    V4 vb;
    s32 r;
    if (p < D_001E0020) {
        do {
            if (p->fAA == 0x19B1) {
                f32 d = func_0040E518(hero + 0x10, (u8 *)p + 0x10);
                if (d < bd) { bd = d; best = p; }
            }
            p++;
        } while (p < D_001E0020_sda);
    }
    if (best != 0) {
        a = *(S_A *)&D_001D6AC0_sda;
        a.f14 = 0x20406070;
        a.f18 = 0x152030;
        a.f0 = 0x50;
        a.f4 = 120.0f;
        a.f8 = 80.0f;
        a.fC = 0.080000005f;
        r = func_00443948(0x32);
        va = best->v;
        va.z -= 2.8f;
        *(u128 *)&vb = 0;
        func_0044BF48(&vb, a.fC);
        vb.z = 0;
        func_L01_004637C8(&va, &vb, a.f14, a.f18, a.f0, (s32)(a.f8 + r), (s32)(a.f4 + r), func_00443948(2));
    }
}
