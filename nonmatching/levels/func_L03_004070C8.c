/* near miss (level 3, Starship Phoenix): 16 differences: instruction sequence and count match, only register allocation differs (retail keeps the table pointer in $v1 with the lui for 0x14 and 0x2D in $v1 and the table base in $a0, and fills the first beqz delay slot with move $v0,$zero); for/while/do-while and pointer init order tried; also (opus-l03b) an indexed walk (23), testing D_L03_002D0900[0].id through the symbol before the pointer (19, retail's lw/beqz order but the early return 0 no longer shares the delay slot), a result variable with break (26) and swapped compares (17); D_001D5570 is core data (below 0x1D5680) */
#include "common.h"

/* localdecomp:start func_L03_004070C8 */
typedef struct { int id; int off; } E_004070C8;
extern int func_L01_0041A4F0(void);
extern E_004070C8 D_L03_002D0900[];
extern unsigned char D_001D5570[];
extern unsigned char D_0014271D; __asm__(".extern D_0014271D, 16");

int func_L03_004070C8(int a, int b) {
    E_004070C8 *e;
    if (func_L01_0041A4F0() != 0) return 1;
    if (a == 0x67) return D_0014271D != 0;
    e = D_L03_002D0900;
    if (e->id == 0) return 0;
    do {
        if (a == e->id) {
            if (e->off != b) {
                if (D_001D5570[e->off] == 0) return 0;
            }
            return 1;
        }
        e++;
    } while (e->id != 0);
    return 0;
}
/* localdecomp:end func_L03_004070C8 */
