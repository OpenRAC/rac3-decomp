#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0011AF48();
extern s32 func_0013C578(s32, s32, void *, s32, long);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0013CB20 */
extern char D_001D52C8[];

void func_0013CB20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j, s32 k, long l) {
    s32 pkt[8];
    if (a == 0) {
        func_0011AF48(D_001D52C8);
    }
    pkt[0] = a;
    pkt[1] = b;
    pkt[2] = (e << 16) | (c & 0xFFFF);
    pkt[3] = (f << 16) | (d & 0xFFFF);
    pkt[4] = g;
    pkt[5] = h;
    pkt[6] = i;
    pkt[7] = j;
    func_0013C578(0x2C, 0x20, pkt, k, l);
}
/* localdecomp:end func_0013CB20 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CC00);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CC08);
