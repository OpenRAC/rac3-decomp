/* near miss (level 3, Starship Phoenix): 43 differences: logic is right (bit-mask loop over six table entries) but retail reads *q twice without CSE, puts lbu in the i==0 beql delay slot and does the sllv after the join, with registers i=$6, q=$7, s=$5; the C reuses one load and hoists the sllv; continue/&&/while/do-while variants give the same bytes (about 7 compiles) */
#include "common.h"

/* localdecomp:start func_L03_00397B38 */
typedef struct { char pad[0x1D]; unsigned char m1D; unsigned char c1E; } S_00397B38;
typedef struct { char pad[0x68]; S_00397B38 *p68; } O_00397B38;
extern unsigned char D_001DE308_sda[]; __asm__(".extern D_001DE308_sda, 4");
extern unsigned char D_L03_001DE307[]; __asm__(".extern D_L03_001DE307, 1");
extern unsigned char D_001D5530[];
extern struct { char pad[0x54]; unsigned char b54; } D_001426E0;
void func_L03_00397B38(O_00397B38 *a) {
    S_00397B38 *s = a->p68;
    int i = 0;
    unsigned char *q = D_L03_001DE307;
    s->m1D = 0;
    s->c1E = 0;
    do {
        if (D_001D5530[D_001DE308_sda[i]] != 0) {
            if (i == 0 || ((unsigned)(*q - 0x1E) < 8 && !(((D_001426E0.b54 >> (*q - 0x1E)) ^ 1) & 1))) {
                s->m1D |= 1 << i;
                s->c1E++;
            }
        }
        i++;
        q++;
    } while (i < 6);
}
/* localdecomp:end func_L03_00397B38 */
