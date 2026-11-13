#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004C36A8);

/* localdecomp:start func_L39_004C37E0 */
typedef struct {
    u8 b[32];
} B_004C37E0;
typedef struct S_004C37E0 S_004C37E0;
typedef struct {
    char _p0[0x4];
    s32 (*f4)(S_004C37E0 *);
} V_004C37E0;
typedef struct {
    char _p0[0x10];
    void *f10;
} K_004C37E0;
typedef struct {
    K_004C37E0 *f0;
    char _p4[0x8 - 0x4];
    u64 f8;
    char _p10[0x78 - 0x10];
    char f78[0xA0 - 0x78];
    char *fA0;
    char _pA4[0xA8 - 0xA4];
    s32 fA8;
    s32 fAC;
    s32 fB0;
    s32 fB4;
    B_004C37E0 fB8;
} A_004C37E0;
typedef struct {
    char _p0[0x114];
    s32 f114;
    s32 f118;
} D_004C37E0;
struct S_004C37E0 {
    char _p0[0x8];
    V_004C37E0 *f8;
    char _pC[0x24 - 0xC];
    s32 f24;
    char _p28[0x84 - 0x28];
    char *f84;
    s32 f88;
    s32 f8C;
    B_004C37E0 f90;
    char _pB0[0xB4 - 0xB0];
    s32 fB4;
    s32 fB8;
    s32 fBC;
    char _pC0[0xDC - 0xC0];
    D_004C37E0 *fDC;
    char _pE0[0xE8 - 0xE0];
    u64 fE8;
    char fF0[0xFC - 0xF0];
    s32 fFC;
    u64 f100;
    char _p108[0x110 - 0x108];
    s32 f110;
    s32 f114;
    char _p118[0x128 - 0x118];
    void *f128;
    char _p12C[0x130 - 0x12C];
};

extern char D_L39_00475A58[];
extern s32 *func_L39_004CBF60(void);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void func_0011D534(void *, s32, s32);
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void *func_L39_004DE940(void);
extern void func_L39_004DE9B8(void *);
extern void func_L39_004C46A8(A_004C37E0 *);
extern s32 func_L39_004C4BF8();
extern void func_L39_004C36A8(S_004C37E0 *, s32);
extern void func_L39_004DEF48(s32, S_004C37E0 *, void *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

S_004C37E0 *func_L39_004C37E0(A_004C37E0 *arg0) {
    S_004C37E0 *p;
    s32 g;
    D_004C37E0 *d;
    void *r;

    g = *func_L39_004CBF60();
    if (arg0 == 0) {
        func_L39_004BC6C8(0x14, 0xBA, 0xC3, 0, 0);
        return 0;
    }
    if (arg0->f0 == 0) {
        func_L39_004BC6C8(0x14, 0xBA, 0xE4, 0, 0);
        return 0;
    }
    p = func_L39_004BEED8(sizeof(S_004C37E0));
    if (p != 0) {
        func_0011D534(p, 0, sizeof(S_004C37E0));
        if (arg0->fA0 != 0) {
            func_L39_004BECF0(arg0->fA0 + 0x6C, 1, 0xD, D_L39_00475A58, 0x121);
            p->f84 = arg0->fA0;
        } else {
            p->f84 = 0;
        }
        p->f8C = arg0->fB4;
        p->f90 = arg0->fB8;
        p->fB4 = arg0->fAC;
        p->fB8 = arg0->fA8;
        p->fBC = arg0->fB0;
        func_L39_004BECF0(arg0->f78, 1, 0xC, D_L39_00475A58, 0x12C);
        p->fDC = (D_004C37E0 *)arg0;
        p->fE8 = 0;
        p->f8 = (V_004C37E0 *)arg0->f0;
        r = func_L39_004DE940();
        p->f128 = r;
        if (r == 0 || p->f8->f4(p) == 0) {
            if (p->f128 != 0) {
                func_L39_004DE9B8(p->f128);
            }
            func_L39_004C46A8(arg0);
            func_L39_004BEF28(p);
            func_L39_004BC6C8(0x14, 0xBA, 0x21, 0, 0);
            return 0;
        }
        p->fFC = 1;
        p->f24 = arg0->f0->f10 != func_L39_004C4BF8;
        p->f100 = arg0->f8;
        d = p->fDC;
        p->f114 = d->f118;
        p->f110 = d->f114;
        p->f88 = 0;
        func_L39_004C36A8(p, 1);
        func_L39_004DEF48(g, p, p->fF0);
        return p;
    }
    func_L39_004BC6C8(0x14, 0xBA, 0x21, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004C37E0 */

INCLUDE_ASM("asm/levels", func_L39_004C39F8);

INCLUDE_ASM("asm/levels", func_L39_004C3BB8);

INCLUDE_ASM("asm/levels", func_L39_004C3CC0);
