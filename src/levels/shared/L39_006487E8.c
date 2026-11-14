#include "common.h"

typedef struct { u8 pad[0xA4]; u8 flags[0x100]; } Tab_00648A20;

/* localdecomp:start func_L39_006487E8 */
typedef struct Obj00645F88 Obj00645F88;
typedef struct {
    u8 pad[28];
    s32 (*fn)(Obj00645F88 *, s32);
} VT00645F88;
struct Obj00645F88 {
    u8 pad[20];
    VT00645F88 *vt;
};

extern s32 func_L39_005B8928(u8 *);

s32 func_L39_006487E8(u8 *o, Obj00645F88 *b) {
    if (*(s16 *)(o + 170) == 4253) {
        if (b->vt->fn(b, -1)) {
            return 1;
        }
    }
    return func_L39_005B8928(o) != 0;
}
/* localdecomp:end func_L39_006487E8 */

INCLUDE_ASM("asm/levels", func_L39_00648840);

INCLUDE_ASM("asm/levels", func_L39_006488E8);

INCLUDE_ASM("asm/levels", func_L39_00648960);

/* localdecomp:start func_L39_00648A20 */
extern Tab_00648A20 D_001A5810;
extern void func_L39_00648960(u8 *, u8 *);
extern void func_L39_006488E8(u8 *, u8 *);

void func_L39_00648A20(u8 *self, u8 *arg, u8 *third) {
    if (D_001A5810.flags[*(s32 *)(self + 0x2544)]) {
        func_L39_00648960(self, third);
    } else {
        func_L39_00648960(self, arg);
    }
    func_L39_006488E8(self, arg);
}
/* localdecomp:end func_L39_00648A20 */

/* localdecomp:start func_L39_00648A90 */
extern s32 func_L39_0061D1D8(s32);

s32 func_L39_00648A90(u8 *a0) {
    s32 r;
    if (a0 == 0) {
        r = 0;
    } else {
        r = func_L39_0061D1D8(*(s32 *)(a0 + 144));
    }
    return r;
}
/* localdecomp:end func_L39_00648A90 */

/* localdecomp:start func_L39_00648AB8 */
s32 func_L39_00648AB8(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x2548) == a1;
}
/* localdecomp:end func_L39_00648AB8 */

LINKER_REMNANT("asm/levels", func_L39_00648AC8);

/* localdecomp:start func_L39_00648AE0 */
extern u8 D_L39_00483A00[];

s32 func_L39_00648AE0(u8 *o, s32 sh) {
    u32 buf[2];
    u8 *p;
    u8 *dst;
    u32 n, m, base, t, a, b, q;
    s32 i;
    u16 x;

    p = o + 0x1A41;
    if (o[0x1A41] == 0) {
        x = 0;
    } else {
        n = o[0x1A41];
        m = n + 1;
        base = ((u32)p - n) & 7;
        dst = (u8 *)buf;
        i = 0;
        do {
            t = (base + i) & 7;
            i += 3;
            *dst++ = D_L39_00483A00[t * 209 + m];
        } while (i < 24);
        a = buf[0] ^ (u32)p;
        b = buf[1] ^ a;
        buf[0] = a;
        q = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
        buf[1] = q;
        x = *(u16 *)(buf + 1);
    }
    return ((s16)x >> sh) & 1;
}
/* localdecomp:end func_L39_00648AE0 */

LINKER_REMNANT("asm/levels", func_L39_00648B98);

/* localdecomp:start func_L39_00648BA8 */
s32 func_L39_00648BA8(void) {
    return 0;
}
/* localdecomp:end func_L39_00648BA8 */

/* localdecomp:start func_L39_00648BB0 */
extern s32 func_L01_003EB2D8(s32);

s32 func_L39_00648BB0(u8 *a0) {
    return func_L01_003EB2D8(*(s32 *)(*(u8 **)(*(u8 **)(a0 + 9520) + 80) + 148)) != 0;
}
/* localdecomp:end func_L39_00648BB0 */

LINKER_REMNANT("asm/levels", func_L39_00648BD8);

/* localdecomp:start func_L39_00648BF8 */
/* BLOCKED: retail bytes are 4 linker-remnant pairs (sltu/addiu sp + nop) followed by the real 8-byte `jr; li $v0,1` */
s32 func_L39_00648BF8(void) {
    return 1;
}
/* localdecomp:end func_L39_00648BF8 */

/* localdecomp:start func_L39_00648C00 */
s32 func_L39_00648C00(void) {
    return 1;
}
/* localdecomp:end func_L39_00648C00 */
