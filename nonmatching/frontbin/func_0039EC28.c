/* Near miss of func_0039EC28: tools/check.py reports 65 diff.
   What differs: the prologue
   (retail reads D_001D4CF0 before `addiu $sp`) and the control flow of the early returns
   differ; the globals are written as one alias with a size hint per access. */
#include "common.h"
/* localdecomp:start func_0039EC28 */
extern s32 func_0039EC28(s32, s32);
typedef struct { u8 b[8]; } V8_399C90;
typedef struct { s32 f0, f4, f8, fC; V8_399C90 f10; s32 f18; } E_399C90;
typedef struct { u8 p0[0x18]; s16 h18; u8 p1a[0x16]; E_399C90 e[4]; u8 pA0[0xA8]; s32 f148; s32 f14C; s32 f150; u8 p154[8]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[0x10]; s32 f17C; } S_399C90;
typedef struct { s32 f0; u8 p4[0x2E]; u8 b32; } T_399C90;
extern S_399C90 D_142430_0039EC28;
extern T_399C90 D_142660_0039EC28;
extern u32 D_001D545C;
extern s32 D_001D4CEC_0039EC28a[];
extern s32 D_001D4CF0_0039EC28[];
extern V8_399C90 D_001D4BE0_0039EC28a[];
extern V8_399C90 D_001D4BE0_0039EC28b[];
extern V8_399C90 D_001D4BE0_0039EC28c[];
extern u8 D_001D5570_0039EC28a[];
extern u8 D_001D5570_0039EC28b[];
extern u8 D_1A9318[];
extern u8 D_001C5BD0[];
extern u8 D_001CBBD0[];
extern u8 D_00332388[];
extern u8 D_00332618[];
extern void func_003A0090();
extern u32 D_001D545C_EC28_1;
__asm__(".extern D_001D545C_EC28_1, 16");
extern u32 D_001D545C_EC28_2;
__asm__(".extern D_001D545C_EC28_2, 16");
extern u32 D_001D545C_EC28_3;
__asm__(".extern D_001D545C_EC28_3, 16");
extern u32 D_001D545C_EC28_4;
__asm__(".extern D_001D545C_EC28_4, 16");
extern u32 D_001D545C_EC28_5;
__asm__(".extern D_001D545C_EC28_5, 16");
extern u32 D_001D545C_EC28_6;
__asm__(".extern D_001D545C_EC28_6, 16");
extern u32 D_001D545C_EC28_7;
__asm__(".extern D_001D545C_EC28_7, 16");
extern s32 D_001D4CEC_EC28_8;
__asm__(".extern D_001D4CEC_EC28_8, 16");
extern s32 D_001D5528_EC28_9;
__asm__(".extern D_001D5528_EC28_9, 16");
s32 func_0039EC28(s32 a, s32 b) {
    u8 *q;
    s32 old;
    if ((u32)(D_001D4CF0_0039EC28[0] - 0x1E) < 7) return 0;
    if (b == 0x18) return 0;
    if ((u32)(b - 0x1F) < 5) b = 3;
    if (D_001D545C_EC28_1 == 0x1E) return 0;
    if (D_001D545C_EC28_2 == 0x24) return 0;
    if (b == 0x1E) return 0;
    if (b == 0x24) return 0;
    func_12BE28(D_001D4BE0_0039EC28a);
    func_13AD58(D_001D4BE0_0039EC28b);
    func_003A0090();
    func_0039FA88(D_1A9318 + (D_001D545C_EC28_3 << 11));
    if (D_142430_0039EC28.f148 == -1 || ((S_399C90 *)((u8 *)&D_142430_0039EC28 + D_142430_0039EC28.f148 * 0xA0))->h18 < 0) return a == 0;
    D_142430_0039EC28.f17C |= a;
    if (D_142430_0039EC28.f17C != 0) {
        if (a == 0) D_001D4CEC_EC28_8 = D_001D4CEC_0039EC28a[0] | 0x200;
        if (D_142430_0039EC28.f15C < 3 && D_142430_0039EC28.f164 < 0) {
            D_142430_0039EC28.f150 = D_001D545C_EC28_4;
            old = 0;
            if (b >= 0) {
                D_001D545C_EC28_5 = b;
                q = &D_001D5570_0039EC28a[b];
                old = *q;
                if (old == 0) *q = 1;
            }
            D_142430_0039EC28.e[D_142430_0039EC28.h18].f4 = D_142660_0039EC28.f0;
            D_142430_0039EC28.e[D_142430_0039EC28.h18].f0 = D_001D545C_EC28_6;
            D_142430_0039EC28.e[D_142430_0039EC28.h18].fC = D_001D5528_EC28_9;
            *(V8_399C90 *)((u8 *)&D_142430_0039EC28 + D_142430_0039EC28.h18 * 0x1C + 0x40) = D_001D4BE0_0039EC28c[0];
            D_142430_0039EC28.e[D_142430_0039EC28.h18].f8 = D_142660_0039EC28.b32;
            func_0039E7C8(D_001C5BD0, 0, D_00332388);
            func_0039E7C8(D_001CBBD0, D_142430_0039EC28.f150, D_00332618);
            if (b >= 0) {
                D_001D5570_0039EC28b[D_001D545C] = old;
                D_001D545C_EC28_7 = D_142430_0039EC28.f150;
            }
            if (D_142430_0039EC28.f164 < 0) {
                D_142430_0039EC28.f164 = 0xF;
                D_142430_0039EC28.f168 = D_142430_0039EC28.f148;
            }
        }
    }
    return D_142430_0039EC28.f164 == 0xF;
}
/* localdecomp:end func_0039EC28 */
