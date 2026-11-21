#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003AF878);

extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA088_003AF890;
extern s32 D_001DA09C_003AF890;
extern s32 D_001DA0B0_003AF890;
extern s32 D_001DA0B4_003AF890;
extern s32 D_001DA0B8_003AF890;
extern s32 D_001DA0C0[];
extern s32 D_001D4D40;
extern void func_003914A0();
extern s32 func_003AFA58();
extern void func_003AFFA8();
extern void func_003AFDD0();
/* localdecomp:start func_003AF890 */
extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
s32 func_003AF890(s32 a, s32 b, s32 (*alloc)(s32, s32), s32 c, s32 flag) {
    s32 i;
    s32 *p;
    s32 r;
    D_001DA08C = alloc(0x1A0000, 0x40);
    p = D_001DA0C0;
    D_001DA090 = alloc(0x4FC80, 0x40);
    D_001DA094 = alloc(0x1010, 0x40);
    D_001DA088_003AF890 = alloc(0x14, 0x40);
    D_001DA098 = alloc(0xEC800, 0x40);
    D_001DA09C_003AF890 = alloc(0x5000C, 0x40);
    D_001DA0A0 = alloc(0xC000, 0x40);
    D_001DA0A4 = alloc(0x80000, 0x40);
    D_001DA0A8 = alloc(0x4000, 0x40);
    D_001DA0AC = alloc(0x3000, 0x40);
    D_001DA0B0_003AF890 = alloc(0xC, 0x40);
    D_001DA0B4_003AF890 = alloc(0xB8, 0x40);
    D_001DA0B8_003AF890 = alloc(0x68, 0x40);
    for (i = 1; i >= 0; i--) {
        *p++ = alloc(0x4000, 0x80);
    }
    func_003914A0(flag != 0, flag != 0);
    func_003AFDD0(a, b, c);
    r = func_003AFA58(D_001DA0B4_003AF890, D_001DA09C_003AF890, D_001DA0B0_003AF890);
    func_003AFFA8();
    D_001D4D40 = D_001D4D40 & ~0x80;
    return r;
}
/* localdecomp:end func_003AF890 */
