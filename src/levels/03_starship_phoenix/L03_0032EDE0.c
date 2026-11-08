#include "common.h"

/* localdecomp:start func_L03_0032EDE0 */
extern void func_L03_0032EE30(char *, int);

void func_L03_0032EDE0(char *a)
{
    int i;
    for (i = 0; i < 3; i++)
        func_L03_0032EE30(a, i);
}
/* localdecomp:end func_L03_0032EDE0 */

INCLUDE_ASM("asm/levels", func_L03_0032EE30);

/* localdecomp:start func_L03_0032EF78 */
extern u16 *D_L03_0021C620[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern s32 D_L03_001DF9D8;
extern void func_L02_003A0200(u8 *);
void func_L03_0032EF78(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p = D_L03_0021C620[*(s32 *)(s + 0xC0)];
    s32 k;
    u8 *e;
    while (1) {
        k = *(s32 *)(s + 0xC0);
        if ((k & 0xFF) == 0xFF) break;
        if (D_L03_001DF9D8 < k) break;
        if (p == 0) break;
        if (!((s16)p[-1] >= 0 || p == D_L03_0021C620[k])) break;
        e = D_L03_001DF99C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        func_L02_003A0200(e);
    }
}
/* localdecomp:end func_L03_0032EF78 */

INCLUDE_ASM("asm/levels", func_L03_0032F038);

INCLUDE_ASM("asm/levels", func_L03_0032F520);
