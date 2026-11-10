#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067BC58 */
typedef struct S_0067BC58 {
    s16 lo;
    s16 hi;
    u8 pad[12];
} S_0067BC58;

S_0067BC58 *func_L39_0067BC58(s32 key, S_0067BC58 *tab, u32 n) {
    u32 i;
    S_0067BC58 *ret = 0;
    for (i = 0; i < n; i++, tab++) {
        if (tab->lo <= key && key <= tab->hi) {
            ret = tab;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0067BC58 */

INCLUDE_ASM("asm/levels", func_L39_0067BCA8);

INCLUDE_ASM("asm/levels", func_L39_0067BE08);

INCLUDE_ASM("asm/levels", func_L39_0067C408);

/* localdecomp:start func_L39_0067C8E8 */
typedef struct { u8 pad[0x25C]; T t; } S_0067C8E8;
extern S_0067C8E8 D_L39_0025D6C0;
extern void func_L39_0067ED40(void);
extern void func_L39_00685FF0(void);
extern void func_L39_006D78F8(void);
extern void func_00392260(s32, s32, s32);

void func_L39_0067C8E8(void) {
    func_L39_0067ED40();
    func_00392260(D_L39_0025D6C0.t.a, D_L39_0025D6C0.t.b, D_L39_0025D6C0.t.c);
    func_L39_00681470();
    func_L39_00685FF0();
    func_L39_006D78F8();
    func_001953B8(0);
    func_001953D0(0);
}
/* localdecomp:end func_L39_0067C8E8 */
