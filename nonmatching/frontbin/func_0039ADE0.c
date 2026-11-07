/* Near miss of func_0039ADE0: tools/check.py reports 4 diff.
   What differs: retail reads the
   flag word at 0x1D4CEC again after writing it (`sw` then `lui $a0`/`lw $a0`); the C reads it
   before the write. Without `volatile` gcc either drops the reload (same alias) or schedules it
   first (distinct aliases), and nothing in plain C pins it after the store. */
#include "common.h"
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x10]; s32 f24; u8 p28[0x144]; s32 f16C; } S_395FF0;
extern S_395FF0 D_00142430_0039ADE0[];
extern u8 D_001D9FA8_0039ADE0;
extern s32 D_001D4CE8_g_0039ADE0;
extern s32 D_001D4CE8_a_0039ADE0;
extern s32 D_001D4CE8_b_0039ADE0;
extern s32 D_001D4CE8_r_0039ADE0;
extern s32 D_001D4CE8_s_0039ADE0;
extern s32 D_001D4CEC_r1_0039ADE0;
extern s32 D_001D4CEC_r2_0039ADE0;
extern s32 D_001D4CEC_w1_0039ADE0;
extern s32 D_001D4CEC_w2_0039ADE0;
extern s32 D_001D9FA4_g_0039ADE0;
extern s32 D_001D9FA4_r_0039ADE0;
extern s32 D_001D9FA4_z_0039ADE0;
extern void (*D_003322F8[])(void);
__asm__(".extern D_001D4CE8_g_0039ADE0, 4");
__asm__(".extern D_001D9FA4_g_0039ADE0, 4");
__asm__(".extern D_001D9FA8_0039ADE0, 16");
__asm__(".extern D_001D9FA4_r_0039ADE0, 16");
__asm__(".extern D_001D9FA4_z_0039ADE0, 16");
__asm__(".extern D_001D4CE8_a_0039ADE0, 16");
__asm__(".extern D_001D4CE8_b_0039ADE0, 16");
__asm__(".extern D_001D4CE8_r_0039ADE0, 16");
__asm__(".extern D_001D4CE8_s_0039ADE0, 16");
__asm__(".extern D_001D4CEC_r1_0039ADE0, 16");
__asm__(".extern D_001D4CEC_r2_0039ADE0, 16");
__asm__(".extern D_001D4CEC_w1_0039ADE0, 16");
__asm__(".extern D_001D4CEC_w2_0039ADE0, 16");
void func_0039ADE0(void) {
    S_395FF0 *s = D_00142430_0039ADE0;
    s32 old;
    s32 v;
    if (s->f16C != 0 || (s->f8 == 2 && s->f10 != 0) || s->f24 > 0) {
        D_001D9FA8_0039ADE0 = 1;
    }
    v = D_001D4CEC_r1_0039ADE0;
    old = D_001D4CE8_g_0039ADE0;
    if (v & 0x80) {
        D_001D4CE8_a_0039ADE0 = 0x18;
        D_001D4CEC_w1_0039ADE0 = (v & -129) | 0x40;
        v = D_001D4CEC_r2_0039ADE0;
    }
    if (v & 0x100) {
        D_001D4CE8_b_0039ADE0 = 0x16;
        D_001D4CEC_w2_0039ADE0 = (v & -257) | 0x40;
    }
    D_003322F8[D_001D4CE8_r_0039ADE0]();
    D_001D9FA4_g_0039ADE0 = D_001D9FA4_r_0039ADE0 + 1;
    if (D_001D4CE8_s_0039ADE0 != old) {
        D_001D9FA4_z_0039ADE0 = 0;
    }
}
