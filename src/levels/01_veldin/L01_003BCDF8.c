#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003BCDF8);

INCLUDE_ASM("asm/levels", func_L01_003BD608);

/* localdecomp:start func_L01_003BD7D8 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;
typedef struct { char p0[0x18]; float f18; } B;
typedef struct S {
    char p0[0x30]; float f30; char p1[0xa]; unsigned char b3e; char p2[0x20]; unsigned char b5f; char p3[6]; short h66;
    char p4[0xf8]; char r160[0x190]; int w2f0; float f2f4; int w2f8; float f2fc; char p6[0x20]; int w320;
} S;
extern B *D_L01_0021F6C0[];
extern int func_L01_003BD9A8(void);
extern int func_L01_00452FB0(A *, void *, int, int, int);
extern void func_L01_003BD608(A *, S *);
extern void func_L01_003BDC88(A *, int);
extern void func_L01_00456BD0(A *, int);
extern void func_L01_00456C98(A *, int, int, int, int, int, int, int, int, int, float, float, float);
int func_L01_003BD7D8(A *a) {
    S *s = (S *)a->p68;
    if (a->b20 == 0 && func_L01_003BD9A8()) return 1;
    if (func_L01_00452FB0(a, s->r160, 0, 0, 0)) {
        if (s->h66 < 3) s->h66++;
    }
    if (0.0f < s->f30) func_L01_003BD608(a, s);
    if (s->b3e == 2) func_L01_003BDC88(a, 1);
    if (s->b5f) func_L01_00456BD0(a, 5); else func_L01_00456BD0(a, 3);
    if (s->w320 != -1) a->f18 = D_L01_0021F6C0[s->w320]->f18;
    if (s->b5f) {
        if (a->b95 == 0) func_L01_00456C98(a, s->w2f0, 0, 0, 0, 0, 3, 0, 0, 0, s->f2f4, 10.0f, 1.0f);
        else func_L01_00456C98(a, s->w2f8, 0, 0, 0, 0, 3, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    } else {
        func_L01_00456C98(a, s->w2f8, 0, 0, 0, 0, 1, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L01_003BD7D8 */

INCLUDE_ASM("asm/levels", func_L01_003BD9A8);

INCLUDE_ASM("asm/levels", func_L01_003BDC88);
