#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

INCLUDE_ASM("asm/levels", func_L07_003BAC00);

INCLUDE_ASM("asm/levels", func_L07_003BAC58);

INCLUDE_ASM("asm/levels", func_L07_003BADA8);

INCLUDE_ASM("asm/levels", func_L07_003BAEA0);

INCLUDE_ASM("asm/levels", func_L07_003BAF28);

INCLUDE_ASM("asm/levels", func_L07_003BB038);

/* localdecomp:start func_L07_003BB148 */
void func_003A4F28(u32);
int func_L01_004AA710(int, int);

void func_L07_003BB148(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_L01_004AA710(arg0, var_s0) != 0) {
            func_003A4F28(var_s0);
        }
        var_s0 += 1;
    } while (var_s0 < 0x34);
}
/* localdecomp:end func_L07_003BB148 */

INCLUDE_ASM("asm/levels", func_L07_003BB1A8);

/* localdecomp:start func_L07_003BB1F0 */
extern P_003BB1F0 *func_00382348(u8 *);
extern u8 *func_L01_00448FF0(u8 *);
extern u8 *func_L01_00449020(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L07_003BB148(s32);
extern u8 *D_001DE508;

void func_L07_003BB1F0(u8 *arg0) {
    P_003BB1F0 *q;
    u8 *r;
    u8 *s;
    u8 *p;
    u8 *g;
    u16 h;

    q = func_00382348(arg0);
    q->f0 = (f32)q->h4;
    r = func_L01_00448FF0(arg0);
    if (r != 0) {
        *(s16 *)(r + 0x38) = 0;
        *(u8 *)(r + 7) = 0;
        *(u8 *)(r + 9) = 0;
        *(u8 *)(r + 8) = 0;
    }
    s = func_L01_00449020(arg0);
    *(s16 *)(s + 0x14) = 0;
    func_L07_003BB148((s32)arg0);
    h = *(u16 *)(arg0 + 0x34);
    *(u8 *)(arg0 + 0x7F) = 0;
    *(u8 *)(arg0 + 0xA8) = 0xFF;
    *(s32 *)(arg0 + 0x98) = 0;
    *(u16 *)(arg0 + 0x34) = (h | 0x41) & 0xEFFF;
    func_L01_004AA7E8(arg0, 1);
    h = *(u16 *)(arg0 + 0x34) | 6;
    g = D_001DE508;
    *(u16 *)(arg0 + 0x34) = h;
    p = *(u8 **)(g + 0x68);
    *(u16 *)(p + 0xAC) += 1;
}
/* localdecomp:end func_L07_003BB1F0 */

INCLUDE_ASM("asm/levels", func_L07_003BB2A8);

INCLUDE_ASM("asm/levels", func_L07_003BB328);

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

INCLUDE_ASM("asm/levels", func_L07_003BCBE8);

/* localdecomp:start func_L07_003BCC30 */
void func_L07_003BB038(s32);
void func_L07_003BCB10(void *, s32);
void func_L07_003BCBE8(void *);

void func_L07_003BCC30(void *arg0) {
    void *handle = *(void **)((u8 *)arg0 + 0x68);

    func_L07_003BB038((s32)arg0);
    if (*(s32 *)((u8 *)handle + 0x294) != -1) {
        func_L07_003BCB10(arg0, 6);
    } else {
        func_L07_003BCBE8(arg0);
    }
}
/* localdecomp:end func_L07_003BCC30 */

/* localdecomp:start func_L07_003BCC88 */
void func_L07_003BCB10(void *, s32);

void func_L07_003BCC88(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x294)) != -1) {
        func_L07_003BCB10(arg0, 9);
        return;
    }
    func_L07_003BCB10(arg0, 0xA);
}
/* localdecomp:end func_L07_003BCC88 */

INCLUDE_ASM("asm/levels", func_L07_003BCCD0);

/* localdecomp:start func_L07_003BCD80 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003BB038(s32);
void func_L07_003BCD80(s32 arg0) {
    func_L07_003BB1F0((u8 *)arg0);
    func_L07_003BB038(arg0);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003BCD80 */
