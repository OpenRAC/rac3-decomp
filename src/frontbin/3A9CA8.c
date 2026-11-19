#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A9CA8 */
extern u8 D_001D8064;
void func_003A9CA8(u8 a) { D_001D8064 = a; }
/* localdecomp:end func_003A9CA8 */

/* localdecomp:start func_003A9CB0 */
extern u8 D_001D8064;
u8 func_003A9CB0(void) {
    return D_001D8064;
}
/* localdecomp:end func_003A9CB0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A9CB8);

typedef struct { u8 p0[0x16]; s16 h16; } F_3A4860;
typedef struct { u8 p0[4]; s16 n; u8 p6[2]; s16 nframes; s16 stride; u8 pC[0x14]; u8 *data; } A_3A4860;
typedef struct { f32 m[16]; } M_3A4860;
extern void func_0038DA10();
extern void func_0038DA68(void *, void *, void *, f32);
extern void func_0038D978();
extern void func_0038D640();
INCLUDE_ASM("asm/nonmatchings/text", func_003A9DB0);

extern int D_001DA050[];
/* localdecomp:start func_003A9F70 */
extern int D_001DA050[];
extern u32 *D_001DA050_g;
extern u8 D_001D8030;
void func_003A9F70(void) {
    ((u32 *)D_001DA050[0])[0] = 0x30000003;
    ((u32 *)D_001DA050[0])[1] = (u32)&D_001D8030;
    ((u32 *)D_001DA050[0])[2] = 0;
    ((u32 *)D_001DA050[0])[3] = 0x50000003;
    D_001DA050_g = (u32 *)D_001DA050[0] + 4;
}
/* localdecomp:end func_003A9F70 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A9FC8);

/* PAL draft of func_003AA320 (rac3-uya-decomp func_003A4DC8, commit 13cf5c5), names moved to PAL addresses
   where known. The US callee func_003A4E70 is func_003AA3C8 in PAL. */


/* localdecomp:start func_003AA320 */
typedef struct { u8 p0[0xC]; f32 fC; } O_A4DC8;
extern void func_0038D2A0();
extern void func_003AA3C8(O_A4DC8 *, f32, f32, s32, f32, f32 *);
void func_003AA320(O_A4DC8 *o, s32 flag, f32 a, f32 b, f32 c, f32 d, f32 e) {
    f32 m[16];
    if ((flag >> 24) != 0) {
        func_0038D2A0(m);
        m[0] = c * o->fC;
        m[10] = d * o->fC;
        func_003AA3C8(o, a, b, flag, e, m);
    }
}
/* localdecomp:end func_003AA320 */

INCLUDE_ASM("asm/nonmatchings/text", func_003AA3C8);
