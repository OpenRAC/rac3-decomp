#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_0039B9B0;
extern s32 D_001D4CEC_0039B9B0;
extern s32 D_001D4CE8_0039B9B0;
/* localdecomp:start func_0039B9B0 */
void func_0039B9B0(void) {
    S_396BC0 *s;
    s32 f;
    f = D_001D4CEC_0039B9B0 & ~4;
    D_001D4CEC_0039B9B0 = f;
    s = &D_142430_0039B9B0;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CEC_0039B9B0 = f | 0x40;
            D_001D4CE8_0039B9B0 = 0x16;
        } else {
            D_001D4CE8_0039B9B0 = s->f15C;
        }
    }
}
/* localdecomp:end func_0039B9B0 */

/* Candidate for func_0039BA10 (PAL retail).
   The retail accesses both globals in the assembler's "lui + 16-bit offset"
   form with the destination reused: through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039BA10 */
extern s32 D_001D4CEC_0039BA10;
extern s32 D_001D4CE8_0039BA10;
__asm__(".extern D_001D4CEC_0039BA10, 16");
__asm__(".extern D_001D4CE8_0039BA10, 16");
void func_0039BA10(void) {
    if (!(D_001D4CEC_0039BA10 & 0x40)) D_001D4CE8_0039BA10 = 4;
}
/* localdecomp:end func_0039BA10 */

typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_0039BA38[];
extern void (*D_001D62F8)();
extern s32 D_001D4CE8_0039BA38;
extern s32 D_001D4CEC_0039BA38;
/* localdecomp:start func_0039BA38 */
__asm__(".extern D_001D62F8, 4");
void func_0039BA38(void) {
    S_00396C48 *p = D_00142430_0039BA38;
    s32 v = D_001D4CEC_0039BA38 & ~2;
    D_001D4CEC_0039BA38 = v;
    if (p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                D_001D4CEC_0039BA38 = v | 0x440;
                D_001D4CE8_0039BA38 = 0x18;
            } else {
                p->f17C = 1;
                D_001D4CE8_0039BA38 = 1;
            }
            if (D_001D62F8 != 0) {
                D_001D62F8();
                D_001D62F8 = 0;
            }
        }
    }
}
/* localdecomp:end func_0039BA38 */
