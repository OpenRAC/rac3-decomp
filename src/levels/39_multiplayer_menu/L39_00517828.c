#include "common.h"

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

/* localdecomp:start func_L39_00517F48 */
typedef struct {
    char _p0[0x30];
    s32 count;
    s32 f34;
    unsigned long *stack;
    s32 f3C;
    s32 f40;
    s32 f44;
    unsigned long regs[16];
} S_00517F48;

s32 func_L39_00517F48(s32 a0, s32 *buf, s32 n) {
    S_00517F48 *p = (S_00517F48 *)a0;
    s32 i;
    if (p->count == 0) {
        return 4;
    }
    for (i = 0; i < n; i++) {
        s32 v = buf[i];
        if (v & 0x80) {
            p->count--;
            *(unsigned long *)((u8 *)p + (v & 0xF) * 8 + 0x48) = p->stack[p->count];
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00517F48 */

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
