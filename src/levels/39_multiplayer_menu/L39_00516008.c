#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00516008);

INCLUDE_ASM("asm/levels", func_L39_005161F8);

/* localdecomp:start func_L39_00516228 */
/* from rac4-decomp's func_L00_00552038, renamed */
s32 func_L39_00516228(u8 *a0, s32 a1) {
    *(s32 *)(a0 + 0xC8) = a1;
    return 0;
}
/* localdecomp:end func_L39_00516228 */

INCLUDE_ASM("asm/levels", func_L39_00516238);

INCLUDE_ASM("asm/levels", func_L39_00516498);

INCLUDE_ASM("asm/levels", func_L39_005164E8);

INCLUDE_ASM("asm/levels", func_L39_00516570);

INCLUDE_ASM("asm/levels", func_L39_005165D0);

/* localdecomp:start func_L39_00516620 */
extern u8 D_L39_0046F470[];

void *func_L39_00516620(void) {
    return D_L39_0046F470;
}
/* localdecomp:end func_L39_00516620 */

INCLUDE_ASM("asm/levels", func_L39_0051662C);

INCLUDE_ASM("asm/levels", func_L39_0051665C);

INCLUDE_ASM("asm/levels", func_L39_0051682C);

INCLUDE_ASM("asm/levels", func_L39_00516838);

INCLUDE_ASM("asm/levels", func_L39_0051695C);

INCLUDE_ASM("asm/levels", func_L39_00516A84);

INCLUDE_ASM("asm/levels", func_L39_00516BB4);

INCLUDE_ASM("asm/levels", func_L39_00516CB8);

INCLUDE_ASM("asm/levels", func_L39_00516DC4);

INCLUDE_ASM("asm/levels", func_L39_00516E6C);

INCLUDE_ASM("asm/levels", func_L39_00516E78);

INCLUDE_ASM("asm/levels", func_L39_00516FC4);

INCLUDE_ASM("asm/levels", func_L39_00516FD8);

/* localdecomp:start func_L39_00517068 */
typedef struct {
    char _p0[0xC];
    void (**fC)(void);
} T1_00517068;

/* from rac4-decomp's func_L00_005285D8 */
void func_L39_00517068(T1_00517068 *arg0) {
    (*arg0->fC)();
}
/* localdecomp:end func_L39_00517068 */

INCLUDE_ASM("asm/levels", func_L39_00517090);

INCLUDE_ASM("asm/levels", func_L39_005170D8);

/* localdecomp:start func_L39_00517118 */
s32 func_L39_00517118(void) {
    return 0x217;
}
/* localdecomp:end func_L39_00517118 */

INCLUDE_ASM("asm/levels", func_L39_00517120);

INCLUDE_ASM("asm/levels", func_L39_00517180);

INCLUDE_ASM("asm/levels", func_L39_005171E0);

INCLUDE_ASM("asm/levels", func_L39_00517250);

INCLUDE_ASM("asm/levels", func_L39_00517308);

INCLUDE_ASM("asm/levels", func_L39_00517408);

INCLUDE_ASM("asm/levels", func_L39_00517510);

INCLUDE_ASM("asm/levels", func_L39_005175B0);

/* localdecomp:start func_L39_00517678 */
typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

/* from rac4-decomp's func_L00_00553488, renamed */
void func_L39_00517678(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0->f0 = arg2;
    arg0->f4 = arg3;
    if (arg1 == 0) {
        arg0->fC = 2;
    } else {
        arg0->fC = 0;
    }
    arg0->f8 = arg1;
}
/* localdecomp:end func_L39_00517678 */

INCLUDE_ASM("asm/levels", func_L39_005176A0);

INCLUDE_ASM("asm/levels", func_L39_00517780);

INCLUDE_ASM("asm/levels", func_L39_005177C0);

/* localdecomp:start func_L39_00517828 */
void func_L39_00517828(u8 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 bits = (arg1 & 0xC0) | (arg3 & 0x2F);
    arg0[0x14] = bits;
    arg0[0x16] |= 8;
    if ((arg1 & 0xC0) == 0) {
        if ((u32)(arg2 - 0x10) < 2) {
            arg0[0x14] = bits | 0x20;
        }
    }
    *(u32 *)(arg0 + 0x10) = arg2;
}
/* localdecomp:end func_L39_00517828 */

/* localdecomp:start func_L39_00517868 */
typedef struct {
    unsigned long f0;
    s32 f8;
    u8 padC[0xA];
    u8 flags;
} S_00517868;

/* from rac4-decomp's func_L00_00553678 */
void func_L39_00517868(S_00517868 *p, s32 a, u32 b) {
    p->f0 = b;
    p->f8 = a;
    p->flags |= 8;
}
/* localdecomp:end func_L39_00517868 */

INCLUDE_ASM("asm/levels", func_L39_00517888);

INCLUDE_ASM("asm/levels", func_L39_00517B64);

INCLUDE_ASM("asm/levels", func_L39_00517E58);

INCLUDE_ASM("asm/levels", func_L39_00517F48);

/* localdecomp:start func_L39_00517FB8 */
extern s32 func_L39_00517E58(s32, s32 *, s32);
extern s32 func_L39_00517F48(s32, s32 *, s32);
s32 func_L39_00517FB8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 buf[3];
    s32 r;
    buf[0] = a2; buf[1] = a3; buf[2] = a4;
    if (a1 == 0) {
        r = func_L39_00517E58(a0, buf, 3);
        if (r != 0) return r;
    } else if (a1 == 1) {
        r = func_L39_00517F48(a0, buf, 3);
        if (r != 0) return r;
    } else {
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L39_00517FB8 */

INCLUDE_ASM("asm/levels", func_L39_0051801C);

INCLUDE_ASM("asm/levels", func_L39_00518150);

/* localdecomp:start func_L39_005181D8 */
void func_L39_005181D8(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x18);
    *(void **)((u8 *)arg1 + 0x18) = temp_v1;
    if (temp_v1 != 0) {
        *(u8 *)((u8 *)temp_v1 + 0x16) = (u8) ((*(u8 *)((u8 *)temp_v1 + 0x16)) | 8);
    }
    *(void **)((u8 *)arg1 + 0x1C) = (void *) (*(void **)((u8 *)arg0 + 0x1C));
    *(void **)((u8 *)arg0 + 0x1C) = arg1;
}
/* localdecomp:end func_L39_005181D8 */

/* localdecomp:start func_L39_00518200 */
s32 func_L39_00518200(u8 *arg0, u8 *arg1) {
    unsigned long w = *(unsigned long *)(arg0 + 0x10);
    unsigned long mask = 0x9000;
    mask <<= 22;
    if (w & mask) {
        *(u8 **)(arg1 + 0x18) = arg0;
        *(u32 *)(arg1 + 0x1C) = *(u32 *)(arg0 + 0x20);
        *(u8 **)(arg0 + 0x20) = arg1;
        arg0[0x16] |= 8;
        return 0;
    }
    return 4;
}
/* localdecomp:end func_L39_00518200 */

INCLUDE_ASM("asm/levels", func_L39_00518240);

/* localdecomp:start func_L39_00518440 */
typedef struct Type1_518440 {
    unsigned long f0;
    char _p8[0x16 - 0x8];
    u8 f16;
    u8 f17;
} Type1_518440;

/* from rac4-decomp's func_L00_00554250 */
void func_L39_00518440(Type1_518440 *arg0, s32 arg1) {
    if ((arg0->f16 & 4) == 0) {
        arg0->f16 |= 4;
        arg0->f0++;
    }
    arg0->f17 = arg1;
}
/* localdecomp:end func_L39_00518440 */

INCLUDE_ASM("asm/levels", func_L39_00518468);

INCLUDE_ASM("asm/levels", func_L39_005185C8);

INCLUDE_ASM("asm/levels", func_L39_00518670);
