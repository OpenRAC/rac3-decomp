#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0039FA88();
/* --- end of declarations from other files --- */

/* declarations of 39E5E0.c's earlier functions */
extern void func_0038CB78(void *, s32, s32);
extern u32 D_001D545C;
extern s32 func_0039F978(s32 bit);

typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_0022CF80_0039FA88;
extern u32 D_001D545C;
extern s32 D_00143140[];
extern void func_0039FB48();
/* localdecomp:start func_0039FA88 */
extern s32 func_0038DD20(void *, s32, s32, s32);
void func_0039FA88(void *arg0) {
    S_39AAF0 *p = &D_0022CF80_0039FA88;
    s32 r;
    if (p->f10 != 0) {
        if (p->f28 == 0) {
            func_0038CB78(arg0, 0, 0x800);
            return;
        }
        func_0039F978(D_001D545C);
        r = func_0038DD20(arg0, 0x800, p->f14, p->fC);
        if (r == -1) func_0039FB48(arg0);
        if (D_00143140[D_001D545C] < r) D_00143140[D_001D545C] = r;
    }
}
/* localdecomp:end func_0039FA88 */

LINKER_REMNANT("asm/remnants", func_0039FB38);

/* PAL candidate for func_0039FB48 (US draft rac3-uya-decomp func_0039ABB0).
   The packing loop builds the byte with each new element on the LEFT of the
   OR, like retail: acc[m] | acc[m+1], then acc[m+2] | that, acc[m+3] | that,
   ...  Written as a right-nested expression so gcc keeps the accumulator in
   the right-hand operand (retail: "or $2, $2, $5"). */


/* localdecomp:start func_0039FB48 */
typedef struct { u8 b[0x40]; } T_39ABB0;
extern T_39ABB0 D_001D6CF8;
extern u8 *D_0022CF8C[];
void func_0039FB48(u8 *out) {
    s32 acc[0x80];
    s32 tbl2[16];
    u8 *src;
    u8 *o;
    s32 i, j, k, m;
    src = D_0022CF8C[0];
    o = out;
    *(T_39ABB0 *)tbl2 = D_001D6CF8;
    for (i = 0; i < 0x200; i++) {
        if (i % 4 == 0) func_0038CB78(acc, 0, 0x200);
        for (k = 0; k < 0x80; k += 2) {
            u8 b = *src++;
            acc[k] += tbl2[b & 0xF];
            acc[k + 1] += tbl2[b >> 4];
        }
        if (i % 4 == 3) {
            for (j = 0; j < 0x80; j++) {
                if (acc[j] < 8) acc[j] = 0;
                else acc[j] = 1 << (j % 8);
            }
            for (m = 0; m < 0x80; m += 8) {
                *o++ = (u8)((u8)acc[m + 7] | ((u8)acc[m + 6] | ((u8)acc[m + 5] | ((u8)acc[m + 4] | ((u8)acc[m + 3] | ((u8)acc[m + 2] | ((u8)acc[m] | (u8)acc[m + 1])))))));
            }
        }
    }
    out[0] &= 0xFE;
}
/* localdecomp:end func_0039FB48 */
TEXT_PADDING(2);
