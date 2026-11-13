/* Level 3. File L03_003AAD60.c (@ps2as). check.py: 75 diff, first draft. Retail reads the class at 0xAA with lhu (for the folded 0x1C04..0x1C06 range test) and sign-extends it for the seven other compares; every wording here (s16, u16 + s16 copy, range written out or as == chain) gives lh and no sll/sra, which shifts the rest of the moby loop. The callback loop after it is also not checked yet (its hoisted 0x20000 halves sit in other saved registers). */
#include "common.h"

extern void func_003C7C38(u8 *);
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;
typedef struct { void (*a)(void); void (*b)(void); } Cb_3AD580;
typedef struct { u8 pad[0x24E10]; Cb_3AD580 cb[3]; } G_3AD580;
extern G_3AD580 *D_001D67C8;

void func_L03_003AD580(void) {
    u8 *p;
    s32 i;
    s16 c;
    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            c = *(s16 *)(p + 0xAA);
            if (c == 0x1C04 || c == 0x1C05 || c == 0x1C06 || c == 0x1C16 || c == 0x1C19 || c == 0x1C01 || c == 0x1C40 || c == 0x1C3F || c == 0x1C3E || c == 0x1C4F) {
                (*(void (**)(u8 *))(p + 0x64))(p);
                if (*(s32 *)(p + 0x24) != 0) {
                    func_003C7C38(p);
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_001D67C8->cb[i].a != 0) {
            D_001D67C8->cb[i].a();
        }
        if (D_001D67C8->cb[i].b != 0) {
            D_001D67C8->cb[i].b();
        }
    }
}
