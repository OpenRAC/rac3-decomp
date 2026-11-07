#include "common.h"

/* localdecomp:start func_L03_0032EDE0 */
void func_L03_0032EE30(void *a, int b);
void func_L03_0032EDE0(void *a) {
    int i;
    for (i = 0; i < 3; i++) {
        func_L03_0032EE30(a, i);
    }
}
/* localdecomp:end func_L03_0032EDE0 */

INCLUDE_ASM("asm/levels", func_L03_0032EE30);

/* localdecomp:start func_L03_0032EF78 */
typedef struct { char pad[0xC0]; int idx; } S_0032EF78;
extern short *D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
void func_L02_003A0200(void *a);
void func_L03_0032EF78(void *a) {
    S_0032EF78 *s = *(S_0032EF78 **)((char *)a + 0x68);
    short *p = D_L03_0021C620[s->idx];
    while (1) {
        int k = s->idx;
        char *q;
        if ((k & 0xFF) == 0xFF) break;
        if (D_001DF9D8_sda < k) break;
        if (p == 0) break;
        if (p[-1] < 0 && p != D_L03_0021C620[k]) break;
        q = D_L03_001DF99C + ((*(unsigned short *)p & 0x7FFF) << 8);
        if (q == 0) break;
        p += 1;
        func_L02_003A0200(q);
    }
}
/* localdecomp:end func_L03_0032EF78 */

INCLUDE_ASM("asm/levels", func_L03_0032F038);

INCLUDE_ASM("asm/levels", func_L03_0032F520);
