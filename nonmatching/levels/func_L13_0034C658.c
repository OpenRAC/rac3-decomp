/* near miss (level 13: 36 diff, a constant-zero loop flag and register numbering) */
#include "common.h"

/* localdecomp:start func_L13_0034C658 */
typedef struct {
    char _p0[0x20];
    u8 f20;
    char _p21[0xAA - 0x21];
    s16 fAA;
} M_34C658;

extern u16 *D_L13_0021C2A0[];
extern s32 D_L13_001DF5D8 __attribute__((section(".data")));
extern char *D_L13_001DF59C __attribute__((section(".data")));

M_34C658 *func_L13_0034C658(s32 id) {
    u16 *p = D_L13_0021C2A0[id];
    u8 b = id & 0xFF;
    M_34C658 *m;
    s32 k;

    if (b != 0xFF && D_L13_001DF5D8 >= id && p != 0) {
        u8 c = b;
        char *base = D_L13_001DF59C;

        k = 0;
        do {
            m = (M_34C658 *)(base + ((*p & 0x7FFF) << 8));
            if (m == 0) {
                return 0;
            }
            if ((m->fAA == 0x16BD || m->fAA == 0x1BA0) && m->f20 == 0x12) {
                return m;
            }
            if (c == 0xFF) {
                return 0;
            }
            p++;
            if (k != 0 || p == 0) {
                return 0;
            }
        } while ((s16)p[-1] >= 0 || p == D_L13_0021C2A0[id]);
    }
    return 0;
}
/* localdecomp:end func_L13_0034C658 */
