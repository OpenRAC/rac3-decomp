#include "common.h"

/* declared by functions of L39_004BCDE0.c, which this file was cut from */
typedef struct S_004BCDE0 {
    u8 _00[0x88];
    long f88;
    long f90;
    u8 _98[8];
    s32 fA0;
} S_004BCDE0;
extern s32 **func_L39_004BD178(S_004BCDE0 *, s32, s32 *);

/* localdecomp:start func_L39_004BD280 */
/* ee29 near miss (needs @ee29 without -fopt-stack): only diff is $s0/$s1 swap (retail h in $s0, s in $s1; move s1,a0 before move s0,zero); tried h=0 after check, local copy of s (gives h in s0 but s copied late), for/while forms, char types */
extern long func_001306F8(long, long);

unsigned long func_L39_004BD280(s8 *s)
{
    unsigned long h = 0;
    long k;
    unsigned long v;
    s32 r;

    if (s == 0 || *s == 0) {
        return 0;
    }
    k = 0x100;
    do {
        v = k | *s++;
        r = (s32)((v >> 2) ^ v) & 0xF;
        k += 0x100;
        h = (h << r) | (h >> (32 - r));
        h = h & 0xFFFFFFFF;
        h = h ^ func_001306F8(v, v);
    } while (*s != 0);
    return (h >> 16) ^ h;
}
/* localdecomp:end func_L39_004BD280 */

INCLUDE_ASM("asm/levels", func_L39_004BD350);

INCLUDE_ASM("asm/levels", func_L39_004BD428);

INCLUDE_ASM("asm/levels", func_L39_004BD4E0);

INCLUDE_ASM("asm/levels", func_L39_004BD5B8);

INCLUDE_ASM("asm/levels", func_L39_004BD658);

INCLUDE_ASM("asm/levels", func_L39_004BD6F8);

INCLUDE_ASM("asm/levels", func_L39_004BD7A8);

INCLUDE_ASM("asm/levels", func_L39_004BD858);

INCLUDE_ASM("asm/levels", func_L39_004BD930);

INCLUDE_ASM("asm/levels", func_L39_004BD9F0);

INCLUDE_ASM("asm/levels", func_L39_004BDAF0);

INCLUDE_ASM("asm/levels", func_L39_004BDC08);

INCLUDE_ASM("asm/levels", func_L39_004BDCE0);

INCLUDE_ASM("asm/levels", func_L39_004BDD80);

INCLUDE_ASM("asm/levels", func_L39_004BDE20);

INCLUDE_ASM("asm/levels", func_L39_004BDEE0);

INCLUDE_ASM("asm/levels", func_L39_004BDFA0);

INCLUDE_ASM("asm/levels", func_L39_004BE078);

INCLUDE_ASM("asm/levels", func_L39_004BE150);

INCLUDE_ASM("asm/levels", func_L39_004BE260);

INCLUDE_ASM("asm/levels", func_L39_004BE388);

/* localdecomp:start func_L39_004BEC38 */
typedef struct {
    s32 num;
    char **data;
} STK_004BEC38;

extern char D_L39_00475580[];
extern char *D_L39_00464828[];
extern STK_004BEC38 *D_L39_00464894 __attribute__((section(".data")));

char *func_L39_004BEC38(s32 n) {
    char *r;

    if (n < 0)
        r = D_L39_00475580;
    else if (n < 27)
        r = D_L39_00464828[n];
    else if (D_L39_00464894 == 0)
        r = D_L39_00475580;
    else if (n - 27 >= D_L39_00464894->num)
        r = D_L39_00475580;
    else
        r = D_L39_00464894->data[n - 27];
    return r;
}
/* localdecomp:end func_L39_004BEC38 */

LINKER_REMNANT("asm/levels", func_L39_004BECA0);
