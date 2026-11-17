#include "common.h"

/* localdecomp:start func_L39_0066DE08 */
typedef struct S_0066DE08e {
    u8 pad0[0x28];
    s32 w28;
} S_0066DE08e;

typedef struct S_0066DE08i {
    u8 pad0[0x2C];
    u8 b2C;
} S_0066DE08i;

typedef struct S_0066DE08 {
    u8 pad0[0x10];
    S_0066DE08e *w10;
    void (*fn14)(S_0066DE08e *, s32);
    s32 w18;
} S_0066DE08;

extern s32 D_001A5DF8[];
extern S_0066DE08e *D_L39_0024BF6C;
extern S_0066DE08i *func_L39_0061D7B0(S_0066DE08e *);

void func_L39_0066DE08(S_0066DE08 *a0) {
    S_0066DE08e *e = a0->w10;
    S_0066DE08i *i;
    if (e != 0) {
        if (a0->fn14 != 0) {
            if (D_001A5DF8[0] > a0->w18 + 0x104) {
                if (e->w28 != 0 || e == D_L39_0024BF6C) {
                    a0->fn14(e, 0);
                } else {
                    i = func_L39_0061D7B0(e);
                    if (i != 0 && i->b2C != 0) {
                        a0->fn14(a0->w10, 0);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0066DE08 */

/* localdecomp:start func_L39_0066DEB0 */
typedef struct S_0066DEB0 {
    u8 pad0[0x20];
    struct S_0066DEB0 *prev;
    struct S_0066DEB0 *next;
    s32 w28;
    s32 w2C;
    s32 w30;
    u8 pad34[0x40 - 0x34];
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    u8 pad50[0x60 - 0x50];
    s32 w60;
    u8 pad64[0x70 - 0x64];
} S_0066DEB0;

extern S_0066DEB0 D_L39_00351360[];
extern S_0066DEB0 D_L39_003512F0[];
extern S_0066DEB0 *D_L39_0024CF78;
extern S_0066DEB0 *D_L39_0024CF7C;

void func_L39_0066DEB0(void) {
    s32 i;
    for (i = 0; i < 50; i++) {
        S_0066DEB0 *p = &D_L39_00351360[i];
        p->w28 = 0;
        p->w4C = 0;
        p->w40 = 0;
        p->w44 = 0;
        p->w48 = 0;
        p->w2C = 0;
        p->w30 = 0;
        p->w60 = 0;
        if (i == 0) {
            D_L39_00351360[0].prev = 0;
        } else {
            p->prev = &D_L39_003512F0[i];
        }
        if (i == 49) {
            (D_L39_00351360 + 49)->next = 0;
        } else {
            p->next = &D_L39_00351360[i + 1];
        }
    }
    D_L39_0024CF7C = 0;
    D_L39_0024CF78 = D_L39_00351360;
}
/* localdecomp:end func_L39_0066DEB0 */
