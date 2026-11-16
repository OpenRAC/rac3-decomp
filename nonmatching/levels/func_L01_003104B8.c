/* NTSC-U draft (Codex wave 4): C of func_L01_003101C8, the NTSC-U twin of func_L01_003104B8, with NTSC-U names and addresses.
 * near miss: 13 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003101C8").
 * Worker's note: sister build/codex/pool/X4/us_func_L01_003101C8_rac2.c; best log build/codex/w184/func_L01_003101C8-01.log; 13 diff: explicit absolute first load plus gp loop loads keeps table in v1 and hoists it before saves; three equivalent pointer/local forms retain ...
 */
#include "common.h"
/* localdecomp:start func_L01_003101C8 */
typedef struct { int a, b, c, d; } Ent_003101C8;
extern Ent_003101C8 *D_L01_001E17AC[];
extern Ent_003101C8 *D_001E17AC_sda;

/* Clears the entry with this key from a table of ten once it has finished. */

void func_L01_003101C8(int key) {
    extern int func_00388398(void *);
    int i;
    Ent_003101C8 *table;
    for (i = 0, table = D_L01_001E17AC[0]; i < 10; i++, table = D_001E17AC_sda) {
        if (table[i].b == key && func_00388398(&table[i].c)) {
            D_001E17AC_sda[i].b = 0;
            D_001E17AC_sda[i].a = 0;
        }
    }
}
/* localdecomp:end func_L01_003101C8 */
