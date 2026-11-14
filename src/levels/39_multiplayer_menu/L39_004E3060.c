#include "common.h"

/* localdecomp:start func_L39_004E3060 */
extern void func_L39_004FC228(void *);
extern void func_L39_004FCD30(void *);
extern void func_L39_004BEF28(void *);

typedef struct E_004E3060 {
    char a[0x14];
} E_004E3060;

typedef struct S_004E3060 {
    char _p0[0x4];
    char f4[0x14];
    char f18[0x14];
    char f2C[0x14];
    s32 f40;
    E_004E3060 *f44;
    char _p48[0x8];
    void **f50;
    void *f54;
} S_004E3060;

typedef struct O_004E3060 {
    char _p0[0x8];
    S_004E3060 *f8;
} O_004E3060;

s32 func_L39_004E3060(O_004E3060 *arg0) {
    S_004E3060 *p = arg0->f8;
    s32 n;
    s32 i;

    if (p == 0) {
        return 0;
    }
    n = p->f40;
    func_L39_004FC228(p->f4);
    func_L39_004FC228(p->f18);
    func_L39_004FC228(p->f2C);
    for (i = 0; i < n; i++) {
        func_L39_004FC228(&p->f44[i * 3]);
        func_L39_004FC228(&p->f44[i * 3 + 1]);
        func_L39_004FC228(&p->f44[i * 3 + 2]);
        if (p->f50[i] != 0) {
            func_L39_004FCD30(p->f50[i]);
        }
    }
    if (p->f44 != 0) {
        func_L39_004BEF28(p->f44);
    }
    if (p->f50 != 0) {
        func_L39_004BEF28(p->f50);
    }
    if (p->f54 != 0) {
        func_L39_004FCD30(p->f54);
    }
    func_L39_004BEF28(p);
    return 0;
}
/* localdecomp:end func_L39_004E3060 */

INCLUDE_ASM("asm/levels", func_L39_004E3178);
