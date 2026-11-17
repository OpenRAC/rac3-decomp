#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* func_003BEDB0: from the US C of func_003B98B8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003BEDB0 */
extern s32 D_001D9348_003BEDB0;
__asm__(".extern D_001D9348_003BEDB0, 16");
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
extern V8_3B98B8 D_001D8D80[];
extern M4_3B98B8 D_001D8D90[];
__asm__(".extern D_001D8DD0, 1");
extern u8 D_001D8DD0;
extern s32 D_001D9348;
/* Retail writes this address through lui $at/lo, not through $gp: the store
   goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did); the read keeps the sized global, through $gp. */
extern void func_003C2FE8();
extern void func_003D9450();
extern void func_003D2DA0();
void func_003BEDB0(void *p) {
    V8_3B98B8 v;
    u8 buf[0x80];
    M4_3B98B8 m;
    u8 out[0x90];
    s32 i;
    u8 *r;
    u8 *b = buf;
    v = D_001D8D80[0];
    func_003C2FE8(p, 2, &v, b);
    r = b;
    m = D_001D8D90[0];
    for (i = 1; i >= 0; i--) {
        func_003D9450(out, 0x16, 0x80808080, &D_001D8DD0, &m, 1);
        func_003D2DA0(out, r, 0);
        r += 0x40;
    }
    D_001D9348_003BEDB0 = D_001D9348 | 1;
}
/* localdecomp:end func_003BEDB0 */
