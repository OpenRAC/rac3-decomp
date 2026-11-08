/* near miss (level 3, Starship Phoenix): 58 differences, register allocation only: retail keeps the raw argument in $s2 and the object field a->0x68 in $s3 and recomputes s+0xA8 and b<<2 after the calls, the C hoists b*4 into a saved register (about 12 variants: char*/base+offset/array/struct idx[1]/goto loop/header-condition loop); same loop family as func_L03_0032EF78 and func_L03_0032EB30 */
#include "common.h"

/* localdecomp:start func_L03_0032EE30 */
typedef struct { char pad[0x20]; u8 st; } O_0032EE30;
extern short *D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_L03_001DF9D8;
__asm__(".extern D_L03_001DF9D8, 16");
void *func_L03_0032F6A8();
void func_L03_0032F6F8(int, void *);
void func_L03_0032EE30(void *a, int b) {
    char *s = *(char **)((char *)a + 0x68);
    short *p = D_L03_0021C620[*(int *)((char *)(*(char **)((char *)a + 0x68) + 0xA8) + b * 4)];
    while (1) {
        int k = *(int *)((char *)(*(char **)((char *)a + 0x68) + 0xA8) + b * 4);
        O_0032EE30 *o;
        if ((k & 0xFF) == 0xFF) break;
        if (D_L03_001DF9D8 < k) break;
        if (p == 0) break;
        if (p[-1] < 0 && p != D_L03_0021C620[*(int *)((char *)(*(char **)((char *)a + 0x68) + 0xA8) + b * 4)]) break;
        o = (O_0032EE30 *)(D_L03_001DF99C + ((*(unsigned short *)p & 0x7FFF) << 8));
        if (o == 0) break;
        if (o->st >= 2) {
            func_L03_0032F6F8(((int *)func_L03_0032F6A8(o))[2], o);
        }
        p += 1;
    }
}
/* localdecomp:end func_L03_0032EE30 */
