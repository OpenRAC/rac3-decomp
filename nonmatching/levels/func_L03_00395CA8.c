/* Level 03 (Starship Phoenix), PAL. 11 diff with check.py --target level_03 (file flags -mvu0-use-vf0-vf2 ... @ps2as, divs_nops row `func_L03_00395CA8 2`). Registers (i in $s0, p in $s1, a in $s2) and the loop match; left: prologue scheduling. Retail stores $s0,$s2, sets $s0=0, stores $f21, sets $s2=$a0, stores $s1 and puts `lw $s1,0x68($s2)` in the jal delay slot, then loads 0x3C($s1) before the 2*pi constant; this C puts `move $s2,$a0` first, `move $s0,$zero` in the delay slot, and the constant before the 0x3C load. About 8 wordings tried (do-while vs for, i init, local n). */
#include "common.h"
typedef struct { u8 pad0[0x30]; f32 f30; u8 pad34[8]; s32 i3C; } P_00395CA8;
extern void func_L03_00396190(void *, f32);
extern void func_L03_00395D60(void *, f32);
extern f32 func_0038DAB8(f32, f32);
void func_L03_00395CA8(void *a) {
    P_00395CA8 *p;
    s32 i;
    f32 f20;
    f32 f21;
    func_L03_00396190(a, 0.15f);
    p = *(P_00395CA8 **)((u8 *)a + 0x68);
    f21 = 6.2831855f / (f32)p->i3C;
    f20 = p->f30;
    for (i = 0; i < p->i3C; i++) {
        func_L03_00395D60(a, f20);
        f20 = func_0038DAB8(f20, f21);
    }
}
