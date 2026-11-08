/* near miss (level 3, Starship Phoenix): 5 differences: do-while over 0x50-byte entries with three null-checked stores of 0x7F; only the third pointer check differs (retail: bnel with the sb in the delay slot, then addiu; slt; gcc hoists the loop increment into the branch); inline increment, while(1)+break, continue, loading the pointers up front all tried */
#include "common.h"

/* localdecomp:start func_L03_003A2B48 */
typedef struct S_003A2B48 {
    u8 pad0[0x23];
    u8 b23;
    u8 pad24[0x10];
    u16 h34;
} S_003A2B48;
typedef struct G_003A2B48 {
    u8 pad0[0x25C0];
    S_003A2B48 *q;
} G_003A2B48;
extern G_003A2B48 D_001A4BE0;

void func_L03_003A2B48(void) {
    G_003A2B48 *g = &D_001A4BE0;
    s32 c;
    s32 end;
    s32 i = 0;
    g->q->b23 = 0x7F;
    g->q->h34 &= 0xDFFF;
    c = (s32)g;
    end = c + 0x230;
    do {
        S_003A2B48 *a = *(S_003A2B48 **)(c + 0x1200);
        S_003A2B48 *b, *d;
        if (a) a->b23 = 0x7F;
        b = *(S_003A2B48 **)(c + 0x1204);
        if (b) b->b23 = 0x7F;
        d = *(S_003A2B48 **)(c + 0x1208);
        if (d != 0) d->b23 = 0x7F;
        c = c + 0x50;
    } while (c < end);
}
/* localdecomp:end func_L03_003A2B48 */
