/* near miss (level 31: 62 diff, address registers) */
#include "common.h"

/* localdecomp:start func_L31_003B4768 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char _pC[4];
    s32 f10;
    char _p14[4];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} S_3B4768;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 D_L31_001DF340 __attribute__((section(".data")));
extern char *D_L31_001DF880 __attribute__((section(".data")));
extern s32 func_00382380(u8 *, s32, s32);
extern void func_003A2B68(s32, s32);

void func_L31_003B4768(S_003B4630_0 *m) {
    S_3B4768 *s = (S_3B4768 *)m->f68;
    u8 *h = D_001A4BE0;
    u8 *g;

    if (*(s32 *)(h + 0x1B04) != 0 && !(*(s32 *)(h + 0x1B38) & 2)) {
        *(s32 *)(h + 0x1B38) |= 2;
        if (D_L31_001DF340 >= 0xB) {
            func_003A2B68((s->f4 & 0x3FFF) + 0x7D0, 0);
            s->f1C = 1;
            return;
        }
    }
    if (s->f24 != -1) {
        g = D_001A4C60;
        if ((func_00382380(g, s->f24, 0) != 0 || *(f32 *)(D_L31_001DF880 + (s->f24 << 7) + 0x30) < *(f32 *)g) &&
            ((g[0x1AB8] ^ 1) & 1) && s->f18 == 0) {
            s->f18 = 1;
            if (D_L31_001DF340 >= 0xB) {
                func_003A2B68((s->f0 & 0x3FFF) + 0x7D0, 0);
                s->f1C = 1;
                return;
            }
        }
    }
    if (s->f20 != -1) {
        g = D_001A4C60;
        if (func_00382380(g, s->f20, 0) != 0 || *(f32 *)(D_L31_001DF880 + (s->f20 << 7) + 0x30) < *(f32 *)g) {
            if (s->f10 == 0) {
                s->f10 = 1;
                func_003A2B68((s->f8 & 0x3FFF) + 0x7D0, 0);
                s->f1C = 1;
            }
        }
    }
}
/* localdecomp:end func_L31_003B4768 */
