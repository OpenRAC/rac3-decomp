#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_00336EF0);

/* localdecomp:start func_L21_00337BB8 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_00337BB8(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) != 0) {
        return 0;
    }
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x7D) = 0;
    func_L01_004450F0((s32) arg0, 1, -1);
    return 1;
}
/* localdecomp:end func_L21_00337BB8 */

INCLUDE_ASM("asm/levels", func_L21_00337BF0);

INCLUDE_ASM("asm/levels", func_L21_00337F08);

/* localdecomp:start func_L21_00338090 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L21_00337F08(void *, s32, s32);
extern s32 D_L21_001DED9C[];

void func_L21_00338090(void *arg0) {
    s32 base;
    s32 k;
    s32 a;
    s32 v;
    u8 *r;

    base = D_L21_001DED9C[0];
    base += *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x68)) + 0x24) << 8;
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    a = func_00382468(2);
    v = 1;
    if (a == 0) {
        v = -1;
    }
    v += ((s32 (*)(s32))(*(void **)(r + 0x2C)))(base);
    if (v >= 6) {
        v = 0;
    } else {
        if (v <= -1) {
            v = 5;
        }
    }
    func_L21_00337F08(arg0, v, 0);
}
/* localdecomp:end func_L21_00338090 */

/* localdecomp:start func_L21_00338150 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 D_L21_001DED9C[];
void func_L21_00338150(void *arg0) {
    u8 *r;
    s32 base;
    base = D_L21_001DED9C[0] + ((*(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x24)) << 8);
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    if (((s32 (*)(s32))(*(void **)(r + 0x30)))(base) != 0) {
        return;
    }
    if (((s32 (*)(s32))(*(void **)(r + 0x34)))(base) != 0) {
        return;
    }
    ((void (*)(s32, s32))(*(void **)(r + 0x8)))(base, 0);
}
/* localdecomp:end func_L21_00338150 */

INCLUDE_ASM("asm/levels", func_L21_003381D8);

INCLUDE_ASM("asm/levels", func_L21_003383A8);

/* localdecomp:start func_L21_00338638 */
typedef struct { void *m[6]; } S_00338638;
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);
extern void func_L21_00337BF0(void *);

void func_L21_00338638(void *arg0, s32 arg1) {
    u8 *p;
    u8 *r;
    S_00338638 *list;
    s32 tries;
    s32 n;
    s32 i;
    void *m;
    s32 buf[6];

    p = *(u8 **)((u8 *)arg0 + 0x68);
    r = (u8 *)func_L01_0043B568(0x1C18, 0, 0x44);
    if (r == 0) {
        return;
    }
    for (tries = 0; p[0x7B] + p[0x7E] < arg1 && p[0x7A] != 0 && tries < 12;) {
        list = (S_00338638 *)(p + 0x60);
        n = 0;
        for (i = 0; i < 6; i++) {
            m = list->m[i];
            if (m == 0) {
                continue;
            }
            if (*(s16 *)((u8 *)m + 0xAA) == 0x1BC5) {
                continue;
            }
            if (((s32 (*)(void *))(*(void **)(r + 0x34)))(m) != 0) {
                continue;
            }
            buf[n++] = i;
        }
        if (n <= 0) {
            return;
        }
        tries++;
        ((void (*)(void *, s32))(*(void **)(r + 0x8)))(list->m[buf[func_00382468(n)]], 1);
        func_L21_00337BF0(arg0);
    }
}
/* localdecomp:end func_L21_00338638 */

INCLUDE_ASM("asm/levels", func_L21_003387B0);
