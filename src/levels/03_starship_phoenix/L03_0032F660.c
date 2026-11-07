#include "common.h"

/* localdecomp:start func_L03_0032F660 */
s32 func_L03_0032F660(void *arg0) {
    return (u32) ((*(u8 *)((u8 *)arg0 + 0x20)) - 4) < 8U;
}
/* localdecomp:end func_L03_0032F660 */

/* localdecomp:start func_L03_0032F670 */
typedef struct { char pad[0x18]; s32 id; char pad2[0xC]; } S_0032F670;
extern S_0032F670 D_L03_002AE4D0_0032F670[];
s32 func_L03_0032F670(s32 arg0) {
    s32 i;
    for (i = 9; i < 27; i++) {
        if (D_L03_002AE4D0_0032F670[i].id == arg0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L03_0032F670 */

/* localdecomp:start func_L03_0032F6A8 */
void *func_L03_0032F6A8(void *arg0) {
    switch (*(s16 *)((u8 *)arg0 + 0xAA)) {
    case 0x197A:
        return (u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x250;
    case 0x197B:
        return (u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x250;
    case 0x197C:
        return (u8 *)*(void **)((u8 *)arg0 + 0x68) + 0x250;
    }
    return 0;
}
/* localdecomp:end func_L03_0032F6A8 */

/* localdecomp:start func_L03_0032F6F8 */
void func_L03_0032F6F8(void (*f)(void *), void *a) {
    f(a);
}
/* localdecomp:end func_L03_0032F6F8 */

INCLUDE_ASM("asm/levels", func_L03_0032F718);

/* localdecomp:start func_L03_0032F790 */
s32 func_L03_0032F790(unsigned char *p, int limit, int n) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += p[i];
        if (limit < sum) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L03_0032F790 */

/* localdecomp:start func_L03_0032F7D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_0032F7D0;
extern float D_001DD13C_sda; __asm__(".extern D_001DD13C_sda, 4");
extern float D_001DD140_sda; __asm__(".extern D_001DD140_sda, 4");
extern int func_0038DC20(V4_0032F7D0 *v, float f);
int func_L03_0032F7D0(float *a, char *b) {
    V4_0032F7D0 v;
    *(u128_t *)&v = *(u128_t *)(b + 0x10);
    v.z = a[6];
    v.w = D_001DD13C_sda;
    return func_0038DC20(&v, D_001DD140_sda) != -1;
}
/* localdecomp:end func_L03_0032F7D0 */

INCLUDE_ASM("asm/levels", func_L03_0032F810);

/* localdecomp:start func_L03_0032F930 */
extern u8 D_0014271D[];
u8 func_L03_0032F930(s32 a0) {
    if (a0 == 0) {
        return D_0014271D[0];
    }
    return 1;
}
/* localdecomp:end func_L03_0032F930 */

INCLUDE_ASM("asm/levels", func_L03_0032F948);

/* localdecomp:start func_L03_0032FA18 */
extern unsigned char D_001426E0[];
void func_L03_0032FA18(int i) {
    if (i < 9) {
        int k = i + 0x85;
        unsigned char c = D_001426E0[k];
        if (c < 255) D_001426E0[k] = c + 1;
    }
}
/* localdecomp:end func_L03_0032FA18 */

/* localdecomp:start func_L03_0032FA50 */
extern unsigned char D_001426E0[];
unsigned char func_L03_0032FA50(int i) {
    if (i < 9) {
        return D_001426E0[i + 0x85];
    }
    return 0;
}
/* localdecomp:end func_L03_0032FA50 */

/* localdecomp:start func_L03_0032FA78 */
extern u8 D_L03_002AE4D0[];

void func_L03_0032FA78(s32 arg0, s32 *arg1, s32 *arg2) {
    void *temp_a0;

    temp_a0 = (arg0 * 0x28) + D_L03_002AE4D0;
    *arg1 = (~(*(s32 *)((u8 *)temp_a0 + 0x14)) == 0) ? 0 : 0xEC5A;
    *arg2 = (~(*(s32 *)((u8 *)temp_a0 + 0x18)) == 0) ? 0 : 0xEC58;
}
/* localdecomp:end func_L03_0032FA78 */
