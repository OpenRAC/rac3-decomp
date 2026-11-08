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

INCLUDE_ASM("asm/levels", func_L07_003CE320);

INCLUDE_ASM("asm/levels", func_L07_003CE330);

INCLUDE_ASM("asm/levels", func_L07_003CE3A8);

INCLUDE_ASM("asm/levels", func_L07_003CE618);

INCLUDE_ASM("asm/levels", func_L07_003CE858);

INCLUDE_ASM("asm/levels", func_L07_003CE940);

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

/* localdecomp:start func_L07_003CEC48 */
extern s32 D_L07_001DF41C;
s32 func_L07_003BAC58(s32);
s32 func_L07_003BADA8(void);

s32 func_L07_003CEC48(void *arg0) {
    void *p;
    s32 a;

    p = *(void **)((u8 *)arg0 + 0x68);
    if (*(s16 *)((u8 *)p + 0x144) != 1) {
        return 0;
    }
    a = *(s32 *)((u8 *)p + 0x420);
    if (a != -1) {
        if (func_L07_003BAC58(D_L07_001DF41C + (a << 8)) == 0) {
            return 0;
        }
    }
    a = *(s32 *)((u8 *)p + 0x424);
    if (a != -1) {
        if (func_L07_003BADA8() == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003CEC48 */

INCLUDE_ASM("asm/levels", func_L07_003CECD0);
