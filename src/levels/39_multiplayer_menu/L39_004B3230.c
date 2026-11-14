#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004B3230);

INCLUDE_ASM("asm/levels", func_L39_004B3910);

INCLUDE_ASM("asm/levels", func_L39_004B3950);

INCLUDE_ASM("asm/levels", func_L39_004B3B18);

INCLUDE_ASM("asm/levels", func_L39_004B3E10);

/* localdecomp:start func_L39_004B3F28 */
extern s32 D_L39_00453FAC;
extern u8 D_L39_004646B0[];

s32 func_L39_004B3F28(u8 *p)
{
    s32 saved = *(s32 *)(p + 0xC);
    u8 *src;
    u32 i;

    if (p == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    src = D_L39_004646B0;
    for (i = 0; i < 16; i++) {
        p[i] = src[i];
    }
    *(s32 *)(p + 0xC) = saved;
    return 0;
}
/* localdecomp:end func_L39_004B3F28 */

/* localdecomp:start func_L39_004B3F88 */
typedef struct {
    u8 pad0[0x204];
    s8 buf[0x200];
    s32 mode;
    u16 len;
} S_004B3F88;

extern s32 D_L39_00453FAC;
extern S_004B3F88 D_L39_00453FB0;
extern void func_00120D28(void *, void *, s32);

s32 func_L39_004B3F88(s32 mode, void *src, u16 len)
{
    if (src == 0 || len == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    if (mode == 1) {
        func_00120D28(D_L39_00453FB0.buf, src, 0x200);
        D_L39_00453FB0.len = len;
        if (D_L39_00453FB0.buf[0x1FF] != 0) {
            return -5;
        }
        D_L39_00453FB0.mode = mode;
    } else {
        D_L39_00453FB0.mode = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004B3F88 */

INCLUDE_ASM("asm/levels", func_L39_004B4020);

/* localdecomp:start func_L39_004B40C8 */
extern u32 func_L39_004B5938(u32);

s32 func_L39_004B40C8(u16 *s)
{
    s[0] = func_L39_004B5938(2);
    s[1] = func_L39_004B5938(5);
    return 4;
}
/* localdecomp:end func_L39_004B40C8 */

INCLUDE_ASM("asm/levels", func_L39_004B4108);

INCLUDE_ASM("asm/levels", func_L39_004B4208);

INCLUDE_ASM("asm/levels", func_L39_004B4310);

INCLUDE_ASM("asm/levels", func_L39_004B4420);

INCLUDE_ASM("asm/levels", func_L39_004B4520);

INCLUDE_ASM("asm/levels", func_L39_004B4620);

INCLUDE_ASM("asm/levels", func_L39_004B4700);

INCLUDE_ASM("asm/levels", func_L39_004B4800);

INCLUDE_ASM("asm/levels", func_L39_004B48E0);

INCLUDE_ASM("asm/levels", func_L39_004B49C0);

INCLUDE_ASM("asm/levels", func_L39_004B4AA0);

INCLUDE_ASM("asm/levels", func_L39_004B4BA0);

INCLUDE_ASM("asm/levels", func_L39_004B4C88);

INCLUDE_ASM("asm/levels", func_L39_004B4D90);

INCLUDE_ASM("asm/levels", func_L39_004B4E98);

INCLUDE_ASM("asm/levels", func_L39_004B5000);

INCLUDE_ASM("asm/levels", func_L39_004B5118);

INCLUDE_ASM("asm/levels", func_L39_004B5200);

INCLUDE_ASM("asm/levels", func_L39_004B5308);

INCLUDE_ASM("asm/levels", func_L39_004B53E8);

INCLUDE_ASM("asm/levels", func_L39_004B54C8);

INCLUDE_ASM("asm/levels", func_L39_004B5630);

INCLUDE_ASM("asm/levels", func_L39_004B5748);
