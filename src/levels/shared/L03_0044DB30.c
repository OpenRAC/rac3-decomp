#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0044DB30);

/* localdecomp:start func_L03_0044DC40 */
typedef char *va_list_44A4C8;
extern void func_L03_0044DC88(s32, s32, va_list_44A4C8);
void func_L03_0044DC40(s32 a0, s32 a1, ...) {
    va_list_44A4C8 ap;
    ap = (char *)__builtin_next_arg(a1)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    func_L03_0044DC88(a0, a1, ap);
}
/* localdecomp:end func_L03_0044DC40 */

/* localdecomp:start func_L03_0044DC88 */
extern void func_0011BB58(char *, char *, int);
extern void func_L01_003242C8(char *, int, int);

/* from rac2-decomp's func_L01_00324410, renamed */
void func_L03_0044DC88(s32 a0, s32 a1, va_list_44A4C8 a2)
{
    char *out = (char *)a0;
    char *src = (char *)a1;
    int *nums = (int *)a2;
    int tab[10];
    unsigned char buf[32];
    int i;
    int *p;
    int *q;
    unsigned char *s;
    char *w;
    int n;
    int cnt;
    int v;

    p = nums;
    i = 0;
    func_0011BB58((char *)0x70000000, src, 0xFF);

    q = tab;
    for (;;) {
        p += 2;
        v = p[-2];
        if (v == -1)
            break;
        *q++ = v;
        i++;
        if (i >= 10)
            break;
    }

    s = (unsigned char *)0x70000000;
    w = out;
    cnt = 0;
    while (*s != 0) {
        if (*s == '%') {
            if (s[1] == 'd') {
                v = cnt++;
                s += 2;
            } else {
                v = s[1] - '0';
                s += 3;
            }
            func_L01_003242C8((char *)buf, tab[v], 0);
            n = 0;
            if (*buf != 0) {
                while (buf[n] != 0 && n < 32) {
                    *w = buf[n];
                    n++;
                    w++;
                }
            }
            *w = 0;
        } else {
            *w = *s;
            s++;
            w++;
        }
    }
    *w = 0;
}
/* localdecomp:end func_L03_0044DC88 */

LINKER_REMNANT("asm/levels", func_L03_0044DDC8);
