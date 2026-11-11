#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L10_003C7C28);

INCLUDE_ASM("asm/levels", func_L10_003C7DA0);

/* localdecomp:start func_L10_003C7F18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7F18;
__asm__(".extern D_L10_001DE924, 4");
__asm__(".extern D_L10_001DE928, 4");
__asm__(".extern D_L10_001DE92C, 4");
extern f32 D_L10_001DE924;
extern f32 D_L10_001DE928;
extern f32 D_L10_001DE92C;
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00470668(void *, void *, s32, f32);

void func_L10_003C7F18(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C7F18 a;
    V4_3C7F18 p;
    V4_3C7F18 t;
    s32 i;
    f32 f;

    f = func_003824E0(0.7853982f, -0.7853982f);
    func_0038D890(&a, v, m + 0xD0, f);
    p = *(V4_3C7F18 *)(m + 0x10);
    for (i = 0; i < 2; i++) {
        func_00382580(&t, D_L10_001DE924, D_L10_001DE924);
        vec_add_ab(&t, &t, &a);
        func_0038CE20(&t, &t, func_003824E0(D_L10_001DE928 * 0.75f, D_L10_001DE928 * 1.25f) * 0.020000001f);
        func_L01_00470668(&p, &t, 0x32, D_L10_001DE92C * 0.00040000002f);
    }
}
/* localdecomp:end func_L10_003C7F18 */

INCLUDE_ASM("asm/levels", func_L10_003C8048);

INCLUDE_ASM("asm/levels", func_L10_003C8238);

INCLUDE_ASM("asm/levels", func_L10_003C8428);

/* localdecomp:start func_L10_003C8698 */
typedef struct { u8 pad[0x30]; s32 f30; s32 f34; } S_3C8698;
extern s32 D_L10_001D6694;
extern S_3C8698 D_L10_001E5F00;
extern f32 func_0038DAB8(f32, f32);

void func_L10_003C8698(u8 *m) {
    s32 v = D_L10_001D6694;
    u8 *p;

    if (v == 2) {
        if (D_L10_001E5F00.f30 == v && (u32)(D_L10_001E5F00.f34 - 0x114) < 0x19) {
            *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(m + 0xF8), 0.12566371f);
        }
    } else {
        p = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
    }
}
/* localdecomp:end func_L10_003C8698 */
