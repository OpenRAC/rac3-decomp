#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BEE98.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);

extern u8 D_001DA2D4_003BEF00;
extern volatile u8 D_001DA300_003BEF00;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BEF00;
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BE168();
extern void func_003BB968();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_00387EF0();
extern void func_003BDF60();
/* localdecomp:start func_003BEF00 */
__asm__(".extern D_001D8D40, 4");
extern void func_003BE528();
void func_003BEF00(s32 a0) {
    s32 v;
    if (D_001DA2D4_003BEF00 != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) {
            func_003BE168();
        }
        if (func_003BDF10() > 0 && func_003BDF18() != 0) {
            func_003BB968();
        }
        if ((&D_001DA2D4_003BEF00)[0x2C] == 0) {
            v = 0;
            if (func_003BDF10() > 0 && a0 != 0) {
                switch (D_001DA2D0) {
                case 0:
                    v = D_001D8D28;
                    break;
                case 1:
                    v = D_001D8D40;
                    break;
                }
                (&D_001DA2D4_003BEF00)[0x2C] = 1;
            } else {
                v = func_003BDD38();
            }
            func_003BDE60(v);
            func_003BE308(func_003BE528);
            func_003BDF40();
            func_00387EF0();
        }
    }
    func_003BDF60(D_00225700_003BEF00.f34, D_00225700_003BEF00.h40, 0xC, 0xC);
}
/* localdecomp:end func_003BEF00 */
