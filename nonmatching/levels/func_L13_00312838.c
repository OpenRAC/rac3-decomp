/* near miss (level 13): 25 differences with @ps2as on L13_00312838.c (check.py --as ps2as), down from 63. With @ps2as, plain scalar externs give retail's lui/op assembler macros (D_001D545C) and unsized arrays give gcc's split form where retail splits with two registers (D_0014275D, D_00142C48, D_001A8370); that fixed the two flag-table arms. Left: retail reads D_001D553B with the lui/lbu macro (so reorg fills the beqz delay slot with the epilogue's ld $s0); as a scalar u8 Ps2EeAs makes it $gp-relative (even with .extern D_001D553B, 16 before it), as an array or with section(".data") gcc splits it and reorg puts the lui in the delay slot, which shifts the rest by one instruction. */
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
extern u16 D_001A8370[];
extern u8 D_00142CBD[];
extern u8 D_0014275D[];
extern s32 D_00142C48[];
extern u8 D_001D553B[];
extern s32 D_001D545C;
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
            D_0014275D[0] = 1;
        }
        if (D_00142C48[0] & 0x100) {
            if (D_001D553B[0] == 0) {
                if (func_L01_004BA800() == 0) {
                    if (D_001A8370[0] == 0) {
                        func_L01_0041A5B0(0xCC8, 0x72);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L13_00312838 */
