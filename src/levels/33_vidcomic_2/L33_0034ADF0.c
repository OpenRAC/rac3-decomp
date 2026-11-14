#include "common.h"

/* localdecomp:start func_L33_0034ADF0 */
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0x2D];
} E_0034ADF0;

typedef struct {
    E_0034ADF0 e[8];
    s16 s180[8];
    s32 f190;
    s32 f194;
    s32 f198;
    s32 pad19C;
    s32 f1A0;
    u8 f1A4;
    u8 f1A5;
} P_0034ADF0;

extern void func_L01_004AA7E8(void *, s32);

void func_L33_0034ADF0(u8 *a0) {
    P_0034ADF0 *p = *(P_0034ADF0 **)(a0 + 0x68);
    s32 i;
    E_0034ADF0 *e;

    p->f1A4 = 8;
    p->f194 = 0;
    e = p->e;
    for (i = 0; i < 8 && p->f1A4 == 8; i++, e++) {
        if (e->b2 == 0xFF) {
            p->f1A4 = i;
        } else {
            p->f194 += e->b2;
        }
    }
    p->f190 = 0;
    p->f1A5 = 8;
    p->f1A0 = 0;
    p->f198 = 0;
    for (i = 0; i < 8 && p->f1A5 == 8; i++) {
        if (p->s180[i] <= 0) {
            p->f1A5 = i;
        } else {
            p->f1A0 += p->s180[i];
        }
    }
    *(s32 *)(a0 + 0x98) = 0;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
    func_L01_004AA7E8(a0, 1);
}
/* localdecomp:end func_L33_0034ADF0 */
