/* near miss (level 3, Starship Phoenix): 5 differences: retail has `beqz $v0` with `lui $a0` in the delay slot, then `b`, then `lw $a1, 0x60`, the C has `beql` with the `lw` in the delay slot; and the `lh` destination is $v1 in retail, $v0 in the C; about 8 rewrites tried */
#include "common.h"

/* localdecomp:start func_L03_003220D8 */
typedef struct S_003220D8 {
    u8 pad0[0x20];
    s32 f20;
    u8 pad24[0x30];
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
} S_003220D8;

extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern u8 D_001A4C60[];
extern s16 D_001CD018;
__asm__(".extern D_001CD018, 16");
extern s32 func_L03_0032F660(u8 *);
extern s32 func_00382380(u8 *, s32, s32);
extern void func_L01_0045F1E8(s32, s32);

void func_L03_003220D8(void *a) {
    S_003220D8 *p = *(S_003220D8 **)((u8 *)a + 0x68);
    s32 v = p->f54;

    if (func_L03_0032F660(D_L03_001DF99C + (p->f20 << 8)) != 0) {
        v = p->f58;
    } else if (func_00382380(D_001A4C60, p->f60, 0) != 0) {
        v = p->f5C;
    }
    if (D_001CD018 != v) {
        func_L01_0045F1E8(v, -1);
    }
}
/* localdecomp:end func_L03_003220D8 */
