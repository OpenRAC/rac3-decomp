#include "common.h"

typedef struct { u8 pad[0x240]; s32 f240; u8 pad2[0xC]; f32 f250; f32 f254; } S_003AEF78;
typedef struct { u8 pad[0x68]; S_003AEF78 *s68; } O_003AEF78;

/* localdecomp:start func_L07_003AEF78 */
extern s32 D_L07_001DEF40[1];
extern f32 func_0038DB00(f32, f32);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);
extern void func_L07_00333DB8(s32, void *, s32, s32, f32);

void func_L07_003AEF78(O_003AEF78 *a0, f32 *a1) {
    S_003AEF78 *s = a0->s68;
    f32 f = func_0038DB00(s->f250, s->f254);
    s32 g;
    s32 b;
    func_L01_0045A7A8(a0, a1, f * 0.4f);
    g = D_L07_001DEF40[0] & 0xF;
    b = ((s32)a0 >> 8) & 0xF;
    if (g == b) {
        func_L07_00333DB8(s->f240, a0, 0, 0, 8.0f);
    }
}
/* localdecomp:end func_L07_003AEF78 */

INCLUDE_ASM("asm/levels", func_L07_003AF010);

INCLUDE_ASM("asm/levels", func_L07_003AF0B0);

INCLUDE_ASM("asm/levels", func_L07_003AF240);

INCLUDE_ASM("asm/levels", func_L07_003AF2B8);
