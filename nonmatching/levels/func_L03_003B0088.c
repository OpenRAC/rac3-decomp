/* near miss (level 3, Starship Phoenix): 40 differences: control flow and instruction count match, register allocation and scheduling differ (mask in $t2 not $t1, the s+0x160 pointer in $t1 not $t0, call argument built in $a3 and moved to $a0, sll/addiu order before the mult); about 8 variants tried */
#include "common.h"

/* localdecomp:start func_L03_003B0088 */
typedef struct { int pad[4]; void (*fn)(void *, void *); } S_003B0088;
typedef struct { char pad[0x160]; int idx[6]; } T_003B0088;
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");
extern S_003B0088 D_L03_002BA5F8[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");

void func_L03_003B0088(void *arg0, int arg1, int arg2) {
    T_003B0088 *s = *(T_003B0088 **)((char *)arg0 + 0x68);
    unsigned int i = arg1;
    int mask;
    char *a;
    if (i < 7) {
        mask = D_001DE858_sda;
        if ((((mask >> i) ^ 1) & 1) == 0 && arg2 < 6) {
            int k = s->idx[i];
            S_003B0088 *t = &D_L03_002BA5F8[i];
            char *base = D_L03_001DF99C;
            a = base + (k << 8);
            if (arg2 < 0 || (((mask >> arg2) ^ 1) & 1) != 0) {
                t->fn(a, 0);
            } else {
                t->fn(a, base + (s->idx[arg2] << 8));
            }
        }
    }
}
/* localdecomp:end func_L03_003B0088 */
