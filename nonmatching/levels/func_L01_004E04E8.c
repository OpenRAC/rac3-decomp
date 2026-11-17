/* PAL near miss (Claude wave S2/pal): near miss: 18 words differ with the file's flags.
 * Worker's note: 18 diff: retail keeps two strength-reduced pointers (s0 = record, s1 = record + 0x40 used for the 3 qzero and for the exit test, s2 = base + 0x1DD0, signed slt) and mine folds them onto one register (4 loop forms tried: index loop 35 diff, two-pointer for 22, ...
 */
#include "common.h"

typedef struct { u8 pad[0xB0]; } S_4DC790;
extern S_4DC790 D_L01_002F4540[];
extern s32 func_L01_004E0100(s32 a0);

/* localdecomp:start func_L01_004E04E8 */
#include "vu0.h"
extern void func_003C2C98(void *, void *);

void func_L01_004E04E8(void) {
    s32 i;

    for (i = 0; i < 43; i++) {
        u8 *rec = (u8 *)&D_L01_002F4540[i];
        u8 *q = rec + 0x40;
        s32 o;

        if (rec[1] != 0) {
            o = func_L01_004E0100(*(s16 *)(rec + 0xA2));
            if (o != 0) {
                func_003C2C98((void *)o, rec);
            }
        }
        qzero(q);
        qzero(q + 0x20);
        qzero(q + 0x50);
        *(f32 *)(rec + 0xAC) = 1.0f;
    }
}
/* localdecomp:end func_L01_004E04E8 */
