#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

INCLUDE_ASM("asm/levels", func_L07_003CC2B0);

INCLUDE_ASM("asm/levels", func_L07_003CCAF0);

/* localdecomp:start func_L07_003CCD40 */
typedef int Q_003CCD40 __attribute__((mode(TI)));
void func_L07_003CCD40(u8 *m,s32 which) {
    extern void func_L07_003BB1A8(u8 *);
    extern void func_L07_003CD2E8(void *,s32);
    u8 *d=*(u8 **)(m+0x68);
    u8 *object;
    if(*(u8 *)((s32)d+which+0x2a0)) {
        func_L07_003BB1A8(m);
        object=*(u8 **)(m+0x24);
        *(f32 *)(m+0x2c)=*(f32 *)(object+0x24);
        *(Q_003CCD40 *)(m+0x10)=*(Q_003CCD40 *)(d+0x280);
        *(Q_003CCD40 *)(m+0xf0)=*(Q_003CCD40 *)(d+0x290);
        *(u16 *)(m+0x34)&=0xfffd;
        if(*(s32 *)(d+0x428)!=-1) {
            func_L07_003CD2E8(m,3);
        } else {
            *(u16 *)(m+0x34)&=0xffbe;
            *(u16 *)(m+0x34)|=*(u16 *)(object+0x44)&0x1000;
            *(s32 *)(m+0x98)=*(s32 *)(object+0x10);
            func_L07_003CD2E8(m,5);
        }
    }
}
/* localdecomp:end func_L07_003CCD40 */

/* localdecomp:start func_L07_003CCDF8 */
void func_L07_003BB1F0();
void func_L07_003CD2E8(void *, s32);

void func_L07_003CCDF8(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L07_003BB1F0();
    *(s32 *)((u8 *)temp_s1 + 0x414) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x406) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x404) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x405) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x407) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x410) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x418) = -1;
    func_L07_003CD2E8(arg0, 0x19);
}
/* localdecomp:end func_L07_003CCDF8 */

/* localdecomp:start func_L07_003CCE58 */
s32 func_L07_003CCE58(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 0x19;
}
/* localdecomp:end func_L07_003CCE58 */

INCLUDE_ASM("asm/levels", func_L07_003CCE68);

INCLUDE_ASM("asm/levels", func_L07_003CD2E8);

INCLUDE_ASM("asm/levels", func_L07_003CD610);

/* localdecomp:start func_L07_003CD6A8 */
extern S_003CD938 D_L07_001DE6F4_sdata[] __attribute__((section(".sdata")));
void func_L07_003CD610(void *);
f32 func_L07_003CE2F8(void *);
s32 func_L07_003CE858(void *);
s32 func_L07_003CEA38(void *);
void func_L07_003CD2E8(void *, s32);

void func_L07_003CD6A8(void *arg0, f32 f1) {
    void *s = *(void **)((u8 *)arg0 + 0x68);
    f32 v;

    func_L07_003CD610(arg0);
    v = func_L07_003CE2F8(arg0);
    if (0.0f < f1) {
        if (v < D_L07_001DE6F4_sdata[*(u8 *)((u8 *)s + 0x404)].f0) {
            if (*(s32 *)((u8 *)s + 0x418) == -1) {
                *(s32 *)((u8 *)s + 0x418) = func_L07_003CE858(arg0);
            }
            if (func_L07_003CEA38(arg0)) {
                func_L07_003CD2E8(arg0, *(u8 *)((u8 *)s + 0x404) + 0xC);
            }
        } else if (f1 + D_L07_001DE6F4_sdata[*(u8 *)((u8 *)s + 0x404)].f0 < v) {
            func_L07_003CD2E8(arg0, 9);
        }
    } else {
        if (v < D_L07_001DE6F4_sdata[*(u8 *)((u8 *)s + 0x404)].f0) {
            if (*(s32 *)((u8 *)s + 0x418) == -1) {
                *(s32 *)((u8 *)s + 0x418) = func_L07_003CE858(arg0);
            }
            if (func_L07_003CEA38(arg0)) {
                func_L07_003CD2E8(arg0, 0xB);
            }
        }
    }
}
/* localdecomp:end func_L07_003CD6A8 */

INCLUDE_ASM("asm/levels", func_L07_003CD7E0);

/* localdecomp:start func_L07_003CD938 */
extern S_003CD938 D_L07_001DE6F4[];
extern f32 func_L07_003CE2F8(void *);
extern void func_L07_003CD2E8(void *, s32);

void func_L07_003CD938(void *arg0) {
    void *temp_s1;
    f32 d;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    d = func_L07_003CE2F8(arg0) - D_L07_001DE6F4[*(u8 *)((u8 *)temp_s1 + 0x404)].f0;
    if (d < 4.0f) {
        func_L07_003CD2E8(arg0, 7);
        return;
    }
    if (d < 8.0f) {
        func_L07_003CD2E8(arg0, 8);
        return;
    }
    if (*(u8 *)((u8 *)temp_s1 + 0x430) != 0) {
        func_L07_003CD2E8(arg0, 0x10);
        return;
    }
    func_L07_003CD2E8(arg0, 9);
}
/* localdecomp:end func_L07_003CD938 */

/* localdecomp:start func_L07_003CD9F8 */
extern S_003CD938 D_L07_001DE6F0[1];
extern S_003CD938 D_L07_001DE6F4_sdata[] __attribute__((section(".sdata")));
extern f32 func_L07_003CE2F8(void *);
extern s32 func_00382498(s32, s32);

s32 func_L07_003CD9F8(void *arg0, s32 arg1) {
    u8 *child = *(u8 **)((u8 *)arg0 + 0x68);
    u8 flag = arg1;
    s32 bits = 0;
    s32 n = 5;
    s32 k;
    s32 idx;
    f32 thr;

    if (child[0x41C] != 0) {
        bits = 0x10;
        n = 4;
    }
    thr = func_L07_003CE2F8(arg0);
    while (n > 0) {
        n--;
        idx = func_00382498(0, n) & 0xFF;
        k = 0;
        while (k < 5) {
            if (idx < k) {
                k++;
                continue;
            }
            if ((bits >> k) & 1) {
                idx = (idx + 1) & 0xFF;
            }
            k++;
        }
        if (D_L07_001DE6F0[idx].f0 <= thr) {
            if (flag == 0) {
                return idx;
            }
            if (idx != child[0x404] && thr <= D_L07_001DE6F4_sdata[idx].f0) {
                return idx;
            }
        }
        bits = (bits | (1 << idx)) & 0xFF;
    }
    return -1;
}
/* localdecomp:end func_L07_003CD9F8 */

INCLUDE_ASM("asm/levels", func_L07_003CDB30);

/* localdecomp:start func_L07_003CDC48 */
extern int func_00382498(int, int);
extern void func_L07_003CD2E8(void *, int);
void func_L07_003CDC48(void *arg0) {
    func_L07_003CD2E8(arg0, func_00382498(0, 1) + 0x15);
}
/* localdecomp:end func_L07_003CDC48 */

INCLUDE_ASM("asm/levels", func_L07_003CDC80);

/* localdecomp:start func_L07_003CDDC0 */
void func_L07_003CDC48(void *);
void func_L07_003CD2E8(void *, s32);

void func_L07_003CDDC0(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x60) & 0x2) {
        if (*(u8 *)((u8 *)temp_s0 + 0x406) != 0) {
            func_L07_003CDC48(arg0);
            *(u8 *)((u8 *)temp_s0 + 0x406) = 0;
        } else {
            func_L07_003CD2E8(arg0, 0x6);
        }
    }
}
/* localdecomp:end func_L07_003CDDC0 */

/* localdecomp:start func_L07_003CDE10 */
extern void func_L07_003CD2E8(void *, int);
void func_L07_003CDE10(char *a0)
{
    char *s = *(char **)(a0 + 0x68);
    if (a0[0x60] & 2) {
        s[0x407] = 0;
        func_L07_003CD2E8(a0, 6);
    }
}
/* localdecomp:end func_L07_003CDE10 */
