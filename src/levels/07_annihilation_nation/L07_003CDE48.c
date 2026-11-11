#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003CDE48);

INCLUDE_ASM("asm/levels", func_L07_003CDF40);

INCLUDE_ASM("asm/levels", func_L07_003CE080);

/* localdecomp:start func_L07_003CE2B8 */
extern int D_001A71A0[];
extern int D_L07_001ECC80_003CE2B8[];

int func_L07_003CE2B8(int n, int key) {
    int i;
    int *p;
    int v;
    i = 0;
    if (n > 0) {
        v = D_001A71A0[0];
        p = D_L07_001ECC80_003CE2B8;
        for (; ; ) {
            if (*p == v) return 1;
            i++;
            if (i >= n) break;
            p++;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003CE2B8 */

/* localdecomp:start func_L07_003CE2F8 */
void func_0038CF38(void *, s32);

void func_L07_003CE2F8(void *arg0) {
    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)arg0 + 0x68)) + 0x130);
}
/* localdecomp:end func_L07_003CE2F8 */

/* localdecomp:start func_L07_003CE320 */
void func_L07_003CE320(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    p[0x408] = 0;
    p[0x409] = 0;
}
/* localdecomp:end func_L07_003CE320 */

INCLUDE_ASM("asm/levels", func_L07_003CE330);

INCLUDE_ASM("asm/levels", func_L07_003CE3A8);

INCLUDE_ASM("asm/levels", func_L07_003CE618);

INCLUDE_ASM("asm/levels", func_L07_003CE858);

/* localdecomp:start func_L07_003CE940 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DF458;

void func_L07_003CE940(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 v = *(s32 *)(s + 0x418);
    s32 t;
    u16 *p;
    u8 *e;
    if (v == -1) return;
    p = D_L07_0021C020[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L07_001DF458 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[a0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA) && e[0x20] != 1) {
            t = *(s32 *)(s + 0x418);
            if (t != -1 && t >= v) *(s32 *)(s + 0x418) = t - 1;
        }
        p++;
    }
    *(s32 *)(s + 0x418) = -1;
}
/* localdecomp:end func_L07_003CE940 */

/* localdecomp:start func_L07_003CEA38 */
s32 func_L07_003CEA38(void *arg0) {
    s32 temp_v0;

    temp_v0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x418);
    if (temp_v0 == -1) {
        return 0;
    }
    return temp_v0 < 1;
}
/* localdecomp:end func_L07_003CEA38 */

INCLUDE_ASM("asm/levels", func_L07_003CEA60);
