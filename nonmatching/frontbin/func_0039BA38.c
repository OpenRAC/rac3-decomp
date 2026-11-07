/* Near miss of func_0039BA38: tools/check.py reports 8 diff.
   What differs: same as
   func_0039B9B0: retail loads the flag word first and builds the struct base after it; gcc
   builds the base first. The scalar-with-size-hint variant fixes the order but changes the
   registers (12 diff). */
#include "common.h"
typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_0039BA38[];
extern void (*D_001D62F8)();
extern s32 D_001D4CEC_g;
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_r_0039BA38;
extern s32 D_001D4CEC_w_0039BA38;
extern s32 D_001D4CE8_a_0039BA38;
__asm__(".extern D_001D4CEC_r_0039BA38, 16");
__asm__(".extern D_001D4CEC_w_0039BA38, 16");
__asm__(".extern D_001D4CE8_a_0039BA38, 16");
void func_0039BA38(void) {
    s32 v;
    S_00396C48 *p;
    v = D_001D4CEC_r_0039BA38 & ~2;
    D_001D4CEC_g = v;
    p = D_00142430_0039BA38;
    if (p->f15C == 2) {
        if (p->f164 < 0) {
            if (p->f16C != 0 || p->f24 != 0) {
                p->f17C = 0;
                D_001D4CEC_w_0039BA38 = v | 0x440;
                D_001D4CE8_g = 0x18;
            } else {
                p->f17C = 1;
                D_001D4CE8_a_0039BA38 = 1;
            }
            if (D_001D62F8 != 0) {
                D_001D62F8();
                D_001D62F8 = 0;
            }
        }
    }
}
