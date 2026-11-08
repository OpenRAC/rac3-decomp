/* Near miss of func_0039FA88: tools/check.py reports 3 diff.
   What differs: gcc puts `sll $a0,
   $a0, 2` right after the `lw $a0` of the index and before the `lui`/`addiu` of the table
   address; retail has the `lui`/`addiu` first. The registers are retail's. The table is a
   scalar with a large `.extern` size hint so the assembler expands its address in place (an
   unsized array gives `$v0` for the base instead of `$v1`). */
#include "common.h"
typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_0022CF80_0039FA88;
extern u32 D_001D545C;
extern u32 D_001D545C_0039FA88;
extern s32 D_00143140_0039FA88;
extern s32 func_0038DD20();
extern void func_0039FB48();
__asm__(".extern D_001D545C_0039FA88, 16");
__asm__(".extern D_00143140_0039FA88, 448");
void func_0039FA88(void *arg0) {
    S_39AAF0 *p = &D_0022CF80_0039FA88;
    s32 r;
    u32 i;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_0038CB78(arg0, 0, 0x800);
            return;
        }
        func_0039F978(D_001D545C);
        r = func_0038DD20(arg0, 0x800, p->f14, p->fC);
        if (r == -1) {
            func_0039FB48(arg0);
            i = D_001D545C_0039FA88;
        } else {
            i = D_001D545C;
        }
        {
            s32 *t = &D_00143140_0039FA88;
            if (t[i] < r) t[i] = r;
        }
    }
}
