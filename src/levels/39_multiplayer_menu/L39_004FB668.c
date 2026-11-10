#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FB668 */
typedef struct {
    s32 f0;
    void *f4;
} S_004FB668;

extern void func_L39_004F9A88(void *);
extern void func_L39_004FA4E8(void *);

void func_L39_004FB668(S_004FB668 *p) {
    void *h;
    if (p != 0) {
        h = p->f4;
        if (h != 0) {
            switch (p->f0) {
            case 6:
                func_L39_004F9A88(h);
                break;
            case 2: case 3: case 4:
            case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:
            case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1C:
            case 0x1E:
            case 0x102:
                func_L39_004FA4E8(p->f4);
                break;
            }
            p->f0 = 0;
            p->f4 = 0;
        }
    }
}
/* localdecomp:end func_L39_004FB668 */

INCLUDE_ASM("asm/levels", func_L39_004FB710);

INCLUDE_ASM("asm/levels", func_L39_004FB898);

INCLUDE_ASM("asm/levels", func_L39_004FB9A0);

INCLUDE_ASM("asm/levels", func_L39_004FBA78);

INCLUDE_ASM("asm/levels", func_L39_004FBBE8);

INCLUDE_ASM("asm/levels", func_L39_004FBDA0);

/* localdecomp:start func_L39_004FBED8 */
typedef struct BN_004FBED8 BN_004FBED8;
extern s32 func_L39_0050A8D8(BN_004FBED8 *, BN_004FBED8 *, const BN_004FBED8 *, const BN_004FBED8 *, void *);

s32 func_L39_004FBED8(BN_004FBED8 *rem, const BN_004FBED8 *m, const BN_004FBED8 *d, void *ctx) {
    return func_L39_0050A8D8(0, rem, m, d, ctx);
}
/* localdecomp:end func_L39_004FBED8 */

INCLUDE_ASM("asm/levels", func_L39_004FBF10);

/* localdecomp:start func_L39_004FC158 */
extern s32 func_L39_0050B060(unsigned long);

s32 func_L39_004FC158(BitSet_004FCA98 *a0) {
    s32 n = a0->f4;
    s32 r = 0;
    if (n != 0) {
        s32 off = (n - 1) << 6;
        r = off + func_L39_0050B060(a0->f0[n - 1]);
    }
    return r;
}
/* localdecomp:end func_L39_004FC158 */

INCLUDE_ASM("asm/levels", func_L39_004FC1A0);

/* localdecomp:start func_L39_004FC228 */
extern void func_L39_004BEF28(void *p);

typedef struct S_004FC228 {
    void *f0;
    char _p4[0xC];
    s32 f10;
} S_004FC228;

void func_L39_004FC228(void *arg0) {
    S_004FC228 *s = (S_004FC228 *)arg0;

    if (s == 0) {
        return;
    }
    if (s->f0 != 0 && !(s->f10 & 2)) {
        func_L39_004BEF28(s->f0);
    }
    s->f10 |= 0x8000;
    if (s->f10 & 1) {
        func_L39_004BEF28(s);
    }
}
/* localdecomp:end func_L39_004FC228 */

INCLUDE_ASM("asm/levels", func_L39_004FC288);
