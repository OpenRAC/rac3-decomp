#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;


/* localdecomp:start func_L07_003BB360 */
extern u8 D_001A4C60[];
s32 func_00382380(void *, s32, s32);

void func_L07_003BB360(void *arg0) {
    u8 *p;
    s32 *q;
    s32 i;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    *(u16 *)(p + 0xA0) = 0;
    q = (s32 *)(p + 0x50);
    i = 0;
    do {
        do {
            if (((((*(s16 *)(p + 0xA2)) >> i) ^ 1) & 1) != 0) {
                if (func_00382380(D_001A4C60, *q, 0) != 0) {
                    *(u16 *)(p + 0xA0) |= (1 << i);
                }
            }
        } while (0);
        i++;
        q++;
    } while (i < 16);
    *(u16 *)(p + 0xA2) |= *(u16 *)(p + 0xA0);
}
/* localdecomp:end func_L07_003BB360 */

INCLUDE_ASM("asm/levels", func_L07_003BB410);

/* localdecomp:start func_L07_003BB768 */
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003BB768(s32 arg0) {
    func_L07_003A2380(func_00382498(0x62, 0x69) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_003BB768 */

/* localdecomp:start func_L07_003BB7A8 */
s32 func_00382468(s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003BB7A8(void *arg0) {
    S_003BB7A8 *st = *(S_003BB7A8 **)((u8 *)arg0 + 0x68);

    if (func_00382468(2) != 0) {
        if (st->flags & 0x10) {
            return;
        }
        ((long (*)(s32, s32, s32, s32))func_L07_003A2380)(0x41, (s32)arg0, 0, 0x64);
        st->flags |= 0x10;
    } else {
        if (st->flags & 0x20) {
            return;
        }
        ((long (*)(s32, s32, s32, s32))func_L07_003A2380)(0x42, (s32)arg0, 0, 0x64);
        st->flags |= 0x20;
    }
}
/* localdecomp:end func_L07_003BB7A8 */

INCLUDE_ASM("asm/levels", func_L07_003BB840);

INCLUDE_ASM("asm/levels", func_L07_003BBAC8);

INCLUDE_ASM("asm/levels", func_L07_003BBBA8);

INCLUDE_ASM("asm/levels", func_L07_003BC4D8);

INCLUDE_ASM("asm/levels", func_L07_003BC6C0);

INCLUDE_ASM("asm/levels", func_L07_003BCB10);
