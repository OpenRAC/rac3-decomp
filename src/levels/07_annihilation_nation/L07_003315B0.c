#include "common.h"

typedef struct S_L07_00331EE8 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_L07_00331EE8;

/* localdecomp:start func_L07_003315B0 */
extern int *func_L07_00333918(void *);
extern void func_L01_004443E8(void *, int, int);
extern s32 func_L07_00333D40(void *, void *);
void func_L07_003315B0(void *a) {
    int *r = func_L07_00333918(a);
    func_L01_004443E8(a, 0, 3);
    func_L07_00333D40((void *)r[2], a);
}
/* localdecomp:end func_L07_003315B0 */

INCLUDE_ASM("asm/levels", func_L07_00331600);

/* localdecomp:start func_L07_00331890 */
void func_L03_0032ED88(s32);
void func_L07_003318D8(s32);
void func_L07_00331908();
void func_L07_00331B10(s32);
void func_L07_00332298(s32);

void func_L07_00331890(s32 arg0) {
    func_L07_00331908();
    func_L07_00331B10(arg0);
    func_L03_0032ED88(arg0);
    func_L07_00332298(arg0);
    func_L07_003318D8(arg0);
}
/* localdecomp:end func_L07_00331890 */

/* localdecomp:start func_L07_003318D8 */
extern s32 D_L07_001DF600;

void func_L07_003318D8(s32 a) {
    u8 *q = *(u8 **)((u8 *)a + 0x68);
    s32 *p = &D_L07_001DF600;
    s32 i;

    for (i = 1; i >= 0; i--) {
        if (*p) {
            *p = 0;
        }
        p++;
    }
    q[0xA9] = 0;
}
/* localdecomp:end func_L07_003318D8 */

INCLUDE_ASM("asm/levels", func_L07_00331908);

INCLUDE_ASM("asm/levels", func_L07_003319C8);

INCLUDE_ASM("asm/levels", func_L07_00331B10);

INCLUDE_ASM("asm/levels", func_L07_00331BB0);

/* localdecomp:start func_L07_00331EE8 */
extern S_L07_00331EE8 D_L07_002B0D40[];
extern s32 D_001DF41C;
extern s32 func_L07_00333B68(void *);
extern s32 func_L07_00333D40(void *, void *);

s32 func_L07_00331EE8(void *arg0) {
    s32 i;
    u8 *q;
    s32 idx;
    void *obj;
    void *s;
    s32 r;

    obj = *(void **)((u8 *)arg0 + 0x68);
    idx = *(u8 *)((u8 *)obj + 0x9E);
    q = (u8 *)(D_L07_002B0D40[idx].f4) + (*(u8 *)((u8 *)obj + 0x9F) * 12) + 9;
    for (i = 0; i < 3; i++) {
        if (q[i] != 0) {
            s = (u8 *)D_001DF41C + (*(s32 *)((u8 *)obj + 0x18) << 8);
            r = func_L07_00333B68(s);
            *((u8 *)r + i + 0x13) = 1;
            return func_L07_00333D40((void *)*(s32 *)((u8 *)r + 8), s);
        }
    }
    return (s32)(q + i);
}
/* localdecomp:end func_L07_00331EE8 */

/* localdecomp:start func_L07_00331FA0 */
extern s32 D_L07_001DF41C_00331FA0;
__asm__(".extern D_L07_001DF41C_00331FA0, 16");
extern s32 func_L07_00331FF0(u8 *);

s32 func_L07_00331FA0(void *arg0) {
    u8 *q = *(u8 **)((u8 *)arg0 + 0x68);

    if (func_L07_00331FF0(arg0) != 0) {
        return 1;
    }
    return *(u8 *)((u8 *)D_L07_001DF41C_00331FA0 + (*(s32 *)(q + 0x18) << 8) + 0x20) != 1;
}
/* localdecomp:end func_L07_00331FA0 */

/* localdecomp:start func_L07_00331FF0 */
extern u8 *D_L07_001DF41C_00331FF0;
__asm__(".extern D_L07_001DF41C_00331FF0, 16");
s32 func_L07_00331FF0(u8 *arg0) {
    s32 *q = *(s32 **)(arg0 + 0x68);
    s32 i;
    for (i = 0; i < 6; i++) {
        if ((D_L07_001DF41C_00331FF0 + (q[i] << 8))[0x20] != 1) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_00331FF0 */
