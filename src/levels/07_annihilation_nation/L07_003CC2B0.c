#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

INCLUDE_ASM("asm/levels", func_L07_003CC2B0);

INCLUDE_ASM("asm/levels", func_L07_003CCAF0);

INCLUDE_ASM("asm/levels", func_L07_003CCD40);

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

INCLUDE_ASM("asm/levels", func_L07_003CD6A8);

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

INCLUDE_ASM("asm/levels", func_L07_003CD9F8);

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
