#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* localdecomp:start func_L07_003BAC00 */
s32 func_L07_003BAC00(u8 *self, s32 key) {
    u8 *s = *(u8 **)(self + 0x68);
    s32 i;

    if (self[0x20] != 3) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (*(s32 *)(s + 0x20 + i * 4) == key) {
            return (s[0xAF] >> i) & 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003BAC00 */

INCLUDE_ASM("asm/levels", func_L07_003BAC58);

INCLUDE_ASM("asm/levels", func_L07_003BADA8);

/* localdecomp:start func_L07_003BAEA0 */
u8 *func_L07_003BAEA0(u8 *a0) {
    u8 *s;

    switch (*(s16 *)(a0 + 0xAA)) {
    case 0x1A85:
    case 0x19D2:
    case 0x1D88:
        s = *(u8 **)(a0 + 0x68);
        return s + 0x240;
    case 0x19BD:
    case 0x1ADB:
    case 0x1D8A:
        s = *(u8 **)(a0 + 0x68);
        return s + 0x440;
    default:
        return 0;
    }
}
/* localdecomp:end func_L07_003BAEA0 */

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

/* localdecomp:start func_L07_003BB1A8 */
extern P_003BB1F0 *func_00382348(u8 *);

void func_L07_003BB1A8(u8 *arg0) {
    u8 *p = (u8 *)func_00382348(arg0);
    u16 h;

    p[0xE] = 1;
    p[0x30] = 0;
    p[0x2F] = 0;
    p[0x2E] = 0;
    h = *(u16 *)(arg0 + 0x34);
    h &= 0xFFF9;
    *(u16 *)(arg0 + 0x34) = h;
}
/* localdecomp:end func_L07_003BB1A8 */

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
