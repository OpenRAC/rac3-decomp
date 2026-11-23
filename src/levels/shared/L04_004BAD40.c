#include "common.h"

/* localdecomp:start func_L04_004BAD40 */
typedef struct {
    u8 active;
    s8 b1;
    s8 b2;
    s8 b3;
    u16 id;
    u8 pad6[2];
    f32 f8;
    s32 wC;
    u32 w10;
    s32 w14;
    s32 w18;
    u8 pad1C[0x44];
} S_004BAD40;

extern S_004BAD40 D_L04_00239370[];
extern u16 D_L04_001D96B6 __attribute__((section(".sdata")));

static __inline__ void init_004BAD40(S_004BAD40 *p) {
    p->b1 = -1;
    p->b2 = -1;
    p->b3 = -1;
    p->id = 0xFFFF;
    p->wC = 0;
    p->f8 = 0;
    p->w10 = 0xFFFFFFFF;
    p->w14 = 0;
    p->w18 = -1;
}

u8 *func_L04_004BAD40(void) {
    u16 i;
    S_004BAD40 *p;

    for (i = 0; D_L04_00239370[i].active != 0 && i < 12; i++) {
    }
    if (i == 12) {
        return 0;
    }
    init_004BAD40(&D_L04_00239370[i]);
    p = &D_L04_00239370[i];
    p->id = D_L04_001D96B6++;
    p->active = 1;
    return (u8 *)p;
}
/* localdecomp:end func_L04_004BAD40 */
