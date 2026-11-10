/* near miss (level 3, Starship Phoenix): 12 differences, all register choices in the two blocks that call func_L03_003B2DA8 and func_L03_003B1198: the C puts `sll j,2` in $v0 where retail uses $v1 (the register that held the mask), shifting the addu/lw/sll/addu/addiu registers by one; temp, pointer, typed arr[1], split and inverted-condition variants tried (sibling func_L03_003AFFB8 has the same prologue and matched) */
#include "common.h"

/* localdecomp:start func_L03_003B0140 */
typedef struct { char pad[0x160]; int a160[6]; int a178[7]; } S_003B0140;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");
void func_L03_003B2E38(void *a);
void func_L03_003B2DA8(void *a, void *b);
void func_L03_003B11A8(void *a);
void func_L03_003B1198(void *a, void *b);

void func_L03_003B0140(char *arg0, int i, int j) {
    S_003B0140 *s = *(S_003B0140 **)(arg0 + 0x68);
    u8 *t = D_L03_001DF99C;
    u8 *p = t + (s->a178[i] << 8);
    if ((unsigned)i < 7) {
        int m = D_001DE858_sda;
        if (((m >> i) ^ 1) & 1) return;
        if (j >= 6) return;
        if (i == 0) {
            if (j < 0 || ((m >> j) ^ 1) & 1) {
                func_L03_003B2E38(p);
            } else {
                func_L03_003B2DA8(p, t + (s->a160[j] << 8) + 0x10);
            }
        } else {
            if (j < 0 || ((m >> j) ^ 1) & 1) {
                func_L03_003B11A8(p);
            } else {
                func_L03_003B1198(p, t + (s->a160[j] << 8) + 0x10);
            }
        }
    }
}
/* localdecomp:end func_L03_003B0140 */
