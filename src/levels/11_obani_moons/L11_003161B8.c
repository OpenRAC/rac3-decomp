#include "common.h"

/* localdecomp:start func_L11_003161B8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3161B8;
typedef struct { u8 pad0[0x30]; V4_3161B8 pos; u8 pad40[0x30]; V4_3161B8 rot; } N_3161B8;
typedef struct { u8 pad0[0x28]; s32 from; s32 to; s32 f30; s32 f34; } Vars_3161B8;
__asm__(".extern D_L11_001DE75C, 16");
extern s32 D_L11_001DE75C;
__asm__(".extern D_L11_001DEF00, 16");
extern N_3161B8 *D_L11_001DEF00;
extern void func_L01_003EB5E0(s32, s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);

void func_L11_003161B8(u8 *a0)
{
    Vars_3161B8 *v = *(Vars_3161B8 **)(a0 + 0x68);
    V4_3161B8 pos;
    V4_3161B8 rot;
    V4_3161B8 a;
    V4_3161B8 b;
    f32 f;

    if (*(u16 *)(a0 + 0x96) < 0xAA) {
        *(u16 *)(a0 + 0x96) += 1;
    } else {
        func_L01_003EB5E0(0, 0);
        D_L11_001DE75C = 0;
        v->f34 = 0;
        *(u16 *)(a0 + 0x96) = 0xAA;
    }
    f = (f32)*(u16 *)(a0 + 0x96) / 170.0f;
    func_0038CDF8(&pos, &D_L11_001DEF00[v->from].pos, &D_L11_001DEF00[v->to].pos, f);
    a = D_L11_001DEF00[v->from].rot;
    b = D_L11_001DEF00[v->to].rot;
    rot.z = func_0038DAB8(func_0038DB00(b.z, a.z) * f, a.z);
    rot.y = func_0038DAB8(func_0038DB00(b.y, a.y) * f, a.y);
    rot.x = func_0038DAB8(func_0038DB00(b.x, a.x) * f, a.x);
    func_L01_003EB350(0, &pos);
    func_L01_003EB3C0(0, &rot);
}
/* localdecomp:end func_L11_003161B8 */

INCLUDE_ASM("asm/levels", func_L11_00316318);
