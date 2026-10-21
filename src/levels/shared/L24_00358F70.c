#include "common.h"

/* localdecomp:start func_L24_00358F70 */
void func_L24_00358F70(f32 *m, s32 a1, f32 a, f32 b, f32 c, f32 d, f32 e) {
    s32 i;
    if (a1 != 0) {
        m[20] = a;
        m[22] = b;
        m[21] = c;
        m[25] = d;
        m[24] = a;
        m[26] = b;
        m[23] = c;
        m[27] = d;
        return;
    }
    for (i = 3; i >= 0; i--) {
        m[i * 4 + 1] = e;
    }
    m[0] = a;
    m[4] = b;
    m[2] = c;
    m[10] = d;
    m[8] = a;
    m[12] = b;
    m[6] = c;
    m[14] = d;
}
/* localdecomp:end func_L24_00358F70 */

LINKER_REMNANT("asm/levels", func_L24_00358FE0);

/* localdecomp:start func_L24_00358FE8 */
void func_L24_00358FE8(u8 *a0) {
    *(unsigned long *)(a0 + 0) = 0x8000000044UL;
    *(unsigned long *)(a0 + 8) = 0;
    *(unsigned long *)(a0 + 24) = 0xFF9000000260UL;
    *(unsigned long *)(a0 + 16) = 13835;
    *(s32 *)(a0 + 32) = 22;
}
/* localdecomp:end func_L24_00358FE8 */

/* localdecomp:start func_L24_00359020 */
extern long func_00389598(s32);
extern void func_003A9440(s32, long);

void func_L24_00359020(long *a, u8 *b) {
    *(long *)(b + 136) = a[0];
    *(long *)(b + 112) = a[1];
    *(long *)(b + 120) = func_00389598(*(s32 *)(a + 4));
    *(long *)(b + 128) = a[3];
    func_003A9440(71, a[2]);
}
/* localdecomp:end func_L24_00359020 */
