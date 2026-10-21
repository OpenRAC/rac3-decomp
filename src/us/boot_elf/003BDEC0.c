#include "common.h"

/* NTSC-U version of func_003BDFB0 (boot_elf): 80 -> 96 */
/* localdecomp:start func_U_003BDEC0 */
extern void func_U_0039A958(s32);
extern void func_U_003BBB28(s32);
extern s32 func_U_003BD928(void);
extern void func_U_003BDD20(void);
extern s32 D_U_001D8D0C;
extern s32 D_0016C5E4[];
typedef struct { u8 pad0[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; } S_003B8700;
extern S_003B8700 D_U_00225780[];
s32 func_U_003BDEC0(void) {
    S_003B8700 *p = D_U_00225780;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    var_17 = 0;
        p->f38 = p->f38 + 1;
        temp_3 = p->f34 + 1;
        p->f34 = temp_3;
    if (temp_3 == 1) {
        func_U_003BBB28(D_0016C5E4[0]);
    }
    if (p->f40 >= p->f34) {
        if (p->f38 >= 0x60) {
            temp_4 = p->f3C + 1;
            p->f3C = temp_4;
            func_U_0039A958(temp_4);
        }
        func_U_003BD928();
        func_U_003BDD20();
    } else {
        var_17 = 1;
        D_U_001D8D0C = D_U_001D8D0C + 1;
    }
    return var_17;
}
/* localdecomp:end func_U_003BDEC0 */
