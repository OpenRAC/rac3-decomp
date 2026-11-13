/* near miss (level 13: 63 diff, hoisted lui and register numbering) */
#include "common.h"

/* localdecomp:start func_L13_00312838 */
typedef struct {
    s32 f0;
    s32 f4;
    char _p8[4];
    s16 fC;
} P_312838;
typedef struct {
    char _p0[0x20];
    u8 f20;
    char _p21[0x30 - 0x21];
    u8 f30;
    char _p31[0x68 - 0x31];
    P_312838 *f68;
} S_312838;

extern u8 D_001A4C60[];
extern s32 D_001A8738[];
extern u16 D_001A8370 __attribute__((section(".data")));
extern u8 D_00142CBD[];
extern u8 D_0014275D __attribute__((section(".data")));
extern s32 D_00142C48 __attribute__((section(".data")));
extern u8 D_001D553B __attribute__((section(".data")));
extern s32 D_001D545C __attribute__((section(".data")));
extern s32 func_00382380(u8 *, s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern s32 func_L01_004BA800(void);

void func_L13_00312838(S_312838 *s) {
    P_312838 *p = s->f68;
    u8 st;

    if (s->f20 == 0) {
        s->f30 = 0xFF;
        p->fC = 0;
        s->f20 = 1;
    }
    st = s->f20;
    if (st == 1) {
        if (func_00382380(D_001A4C60, p->f0, 0)) {
            if (D_00142CBD[0]) {
                if (*(s32 *)(D_001A4C60 + 0x1630) == 0) {
                    if (!(D_001A8738[0] & (st << D_001D545C))) {
                        func_L01_0041A5B0(0x1053, 0xC2);
                    }
                } else {
                    if (!(D_001A8738[3] & (st << D_001D545C))) {
                        func_L01_0041A5B0(0x1054, 0xC3);
                    }
                }
            }
        }
        if (func_00382380(D_001A4C60, p->f4, 0)) {
            D_0014275D = 1;
        }
        if (D_00142C48 & 0x100) {
            if (D_001D553B == 0) {
                if (func_L01_004BA800() == 0) {
                    if (D_001A8370 == 0) {
                        func_L01_0041A5B0(0xCC8, 0x72);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L13_00312838 */
