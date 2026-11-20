#include "common.h"

/* declared by functions of L21_00336EF0.c, which this file was cut from */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);

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
