/* near miss (level 3, Starship Phoenix): 2 differences: retail has `move $s2,$zero` before `sd $s0,0($sp)` in the prologue, the C emits them in the other order; about 15 variants of the declaration and init order of the result, u8 vs s32 and callee return types tried */
#include "common.h"

/* localdecomp:start func_L03_003302D0 */
typedef struct S_003302D0b { u8 pad00[0xF1]; u8 fF1; } S_003302D0b;
typedef struct S_003302D0 { u8 pad00[0x68]; S_003302D0b *f68; } S_003302D0;
extern u8 D_L03_001E1218;
__asm__(".extern D_L03_001E1218, 16");
extern u8 D_L03_001E1228;
__asm__(".extern D_L03_001E1228, 16");
typedef struct S_003302D0c { u8 pad00[0x14]; s32 f14; u8 pad18[0x10]; } S_003302D0c;
extern S_003302D0c D_L03_002AE4D0[];
void func_L03_003AECB0(void *);
void func_L01_00516FD8(s32, void *);
void func_L01_00517190(s32, s32);
void func_L03_003AF098(s32);
void func_L03_00330380(void *);
void func_L03_003302D0(S_003302D0 *a) {
    S_003302D0b *b;
    s32 r = 0;
    b = a->f68;
    func_L03_003AECB0(a);
    func_L01_00516FD8(0x150006, &D_L03_001E1218);
    func_L01_00516FD8(0x150007, &D_L03_001E1228);
    if ((b->fF1 + D_L03_002AE4D0)->f14 != -1) {
        func_L01_00517190(0x150008, 0xEC5A);
        r = 1;
    }
    func_L03_003AF098(r);
    func_L03_00330380(a);
}
/* localdecomp:end func_L03_003302D0 */
