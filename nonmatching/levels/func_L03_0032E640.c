/* near miss (level 3, Starship Phoenix): 2 differences: two adjacent instructions before the inner loop are swapped (retail: addiu $t0,$zero,-1 then move $v1,$a0); about 25 variants tried (declaration places of q, i/id order, short id, ++q, array form) */
#include "common.h"

/* localdecomp:start func_L03_0032E640 */
typedef struct S_0032E640 {
    char pad0[0x10];
    float f10;
    char pad14[0xC];
    unsigned char t20;
    char pad21[7];
    struct S_0032E640 *next;
    char pad2C[0x7E];
    short s_aa;
} S_0032E640;
extern S_0032E640 *D_L03_001DF9A8;
__asm__(".extern D_L03_001DF9A8, 16");
int func_L03_0032E640(int *ids) {
    S_0032E640 *p;
    for (p = D_L03_001DF9A8; p != 0; p = p->next) {
        if (p->f10 > 450.0f && p != 0 && p->t20 != 0xFE && p->t20 != 0xFD) {
            int i = 0;
            int id = p->s_aa;
            if (ids[0] != -1) {
                int *q = ids;
                do {
                    if (*q == id) return 1;
                    i++;
                    q++;
                } while (i < 3 && *q != -1);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L03_0032E640 */
