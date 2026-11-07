#include "common.h"

typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_001CCFD0_003AFF18;

/* localdecomp:start func_L03_003AF410 */
s32 func_L03_003AF410(void *arg0) {
    s32 temp_a0;

    temp_a0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x13C);
    switch (temp_a0) {                              /* irregular */
    case 4:
        return 4;
    case 6:
        return 3;
    default:
        return -1;
    }
}
/* localdecomp:end func_L03_003AF410 */

INCLUDE_ASM("asm/levels", func_L03_003AF450);

INCLUDE_ASM("asm/levels", func_L03_003AF7F0);

INCLUDE_ASM("asm/levels", func_L03_003AF848);

/* localdecomp:start func_L03_003AFC08 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC08(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 6, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 6;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFC08 */

/* localdecomp:start func_L03_003AFC50 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC50(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 4, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 4;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFC50 */

/* localdecomp:start func_L03_003AFC98 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC98(s32 arg0) {
    func_L01_00445130(arg0, 8, -1);
}
/* localdecomp:end func_L03_003AFC98 */

/* localdecomp:start func_L03_003AFCB8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFCB8(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003AFCB8 */

/* localdecomp:start func_L03_003AFCD8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFCD8(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 7, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 7;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFCD8 */

/* localdecomp:start func_L03_003AFD20 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad100[0x100]; u128_t v100; char pad[0x34]; int f144; } S_003AFD20;
typedef struct { void *pad[0x1A]; S_003AFD20 *p68; } T_003AFD20;
void func_L03_003AFD20(T_003AFD20 *a, u128_t *b) {
    S_003AFD20 *s = a->p68;
    if (b == 0) { s->f144 = 0; return; }
    s->f144 = 1;
    s->v100 = b[1];
}
/* localdecomp:end func_L03_003AFD20 */

INCLUDE_ASM("asm/levels", func_L03_003AFD48);

INCLUDE_ASM("asm/levels", func_L03_003AFE60);

/* localdecomp:start func_L03_003AFF18 */
extern S_001CCFD0_003AFF18 D_001CCFD0;
void func_003A1798(void);

void func_L03_003AFF18(void) {
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L03_003AFF18 */

INCLUDE_ASM("asm/levels", func_L03_003AFF68);

INCLUDE_ASM("asm/levels", func_L03_003AFFB8);

INCLUDE_ASM("asm/levels", func_L03_003B0088);

INCLUDE_ASM("asm/levels", func_L03_003B0140);

INCLUDE_ASM("asm/levels", func_L03_003B0238);

INCLUDE_ASM("asm/levels", func_L03_003B0290);

/* localdecomp:start func_L03_003B05B0 */
s32 func_L03_003B05B0(s32 *a, s32 n) {
    s32 v = a[n];
    s32 i;
    for (i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = v;
    return v;
}
/* localdecomp:end func_L03_003B05B0 */

/* localdecomp:start func_L03_003B05F0 */
s32 func_00382468(s32);

void func_L03_003B05F0(s32 arg0, s32 arg1) {
    s32 *temp_s0_2;
    s32 *temp_v0;
    s32 temp_a0;
    s32 temp_s0;
    s32 var_s1;

    if (arg1 > 0) {
        var_s1 = arg1;
        do {
            var_s1 -= 1;
            temp_s0 = func_00382468(arg1);
            temp_v0 = (func_00382468(arg1) * 4) + arg0;
            temp_s0_2 = (temp_s0 * 4) + arg0;
            temp_a0 = *temp_s0_2;
            *temp_s0_2 = *temp_v0;
            *temp_v0 = temp_a0;
        } while (var_s1 != 0);
    }
}
/* localdecomp:end func_L03_003B05F0 */

INCLUDE_ASM("asm/levels", func_L03_003B0670);

INCLUDE_ASM("asm/levels", func_L03_003B06F0);

/* localdecomp:start func_L03_003B0760 */
extern s32 D_L03_002A2430[];
extern s32 D_L03_001DE830;
extern s32 D_L03_001DE840;
void func_L03_003B05F0(s32, s32);

void func_L03_003B0760(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 off;
    s32 *q;
    s32 *base;
    s32 m = 0x78;
    s32 n = 0x78;

    base = D_L03_002A2430;
    i = 0;
    do {
        off = i * n;
        j = i + 1;
        q = (s32 *)(off + (s32)base);
        q += 29;
        for (k = 0x1d; k >= 0; k--) {
            *q = k;
            q--;
        }
        func_L03_003B05F0((s32)((u8 *)base + i * m), 30);
        i = j;
    } while (i < 6);
    func_L03_003B05F0((s32)&D_L03_001DE830, 4);
    func_L03_003B05F0((s32)&D_L03_001DE840, 6);
}
/* localdecomp:end func_L03_003B0760 */

INCLUDE_ASM("asm/levels", func_L03_003B0810);

/* localdecomp:start func_L03_003B0ED8 */
extern s32 D_L03_001DE858;

void func_L03_003B0ED8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_L03_001DE858 |= 1 << arg0;
        return;
    }
    D_L03_001DE858 &= ~(1 << arg0);
}
/* localdecomp:end func_L03_003B0ED8 */
