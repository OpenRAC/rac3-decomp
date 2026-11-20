#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AA060.c's earlier functions */
extern u8 D_001D8064;

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA380);

/* US draft of func_003AA6D8 (rac3-uya-decomp func_003AA588, commit 13cf5c5), names moved to PAL addresses
   where known. The called helper is func_003AA780 in PAL (func_003AA630 in the US build). */


/* localdecomp:start func_003AA6D8 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0038D680();
extern void func_003AA780(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003AA6D8(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0038D680(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003AA780(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003AA6D8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AA780);
