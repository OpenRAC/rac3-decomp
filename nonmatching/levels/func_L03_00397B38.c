/* near miss (level 3, Starship Phoenix): 29 differences, one cause: gcc's interblock scheduler (haifa) moves the `1 << i` sllv speculatively into the `i == 0` test block, retail computes it in the shared set block after `lbu 0x1D`; with -fno-sched-spec the same C is 12 differences (the order of the hoisted loop invariants). Found: the gp table needs a sized `[4]` declaration (gp+0x1A58 address) and the range test written `*q >= 0x1E && *q < 0x26` keeps retail's two reads of *q (43 -> 29). The table is named D_001DE308_sda_00397B38 because func_L03_00397698 in the same file declares D_001DE308_sda as a scalar; continue/goto/flag/switch forms of the condition and the mask written in other ways do not change it */
#include "common.h"

/* localdecomp:start func_L03_00397B38 */
typedef struct { char pad[0x1D]; unsigned char m1D; unsigned char c1E; } S_00397B38;
typedef struct { char pad[0x68]; S_00397B38 *p68; } O_00397B38;
extern unsigned char D_001DE308_sda_00397B38[4]; __asm__(".extern D_001DE308_sda_00397B38, 4");
extern unsigned char D_L03_001DE307[]; __asm__(".extern D_L03_001DE307, 1");
extern unsigned char D_001D5530[];
extern struct { char pad[0x54]; unsigned char b54; } D_001426E0_00397B38;
void func_L03_00397B38(void *arg) {
    O_00397B38 *a = arg;
    S_00397B38 *s = a->p68;
    int i = 0;
    unsigned char *q = D_L03_001DE307;
    s->m1D = 0;
    s->c1E = 0;
    do {
        if (D_001D5530[D_001DE308_sda_00397B38[i]] != 0) {
            if (i == 0 || (*q >= 0x1E && *q < 0x26 && !(((D_001426E0_00397B38.b54 >> (*q - 0x1E)) ^ 1) & 1))) {
                s->m1D |= 1 << i;
                s->c1E++;
            }
        }
        i++;
        q++;
    } while (i < 6);
}
/* localdecomp:end func_L03_00397B38 */
