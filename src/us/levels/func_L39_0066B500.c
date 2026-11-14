#include "common.h"

/* NTSC-U counterpart of func_L39_0066DE08 (src/levels/shared/L39_0066DE08.c) */
/* localdecomp:start func_L39_0066B500 */
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

extern s32 D_001A5F78[];
extern S_0066DE08e *D_L39_0024C06C;
extern S_0066DE08i *func_L39_0061B038(S_0066DE08e *);

void func_L39_0066B500(S_0066DE08 *a0) {
    S_0066DE08e *e = a0->w10;
    S_0066DE08i *i;
    if (e != 0) {
        if (a0->fn14 != 0) {
            if (D_001A5F78[0] > a0->w18 + 0x104) {
                if (e->w28 != 0 || e == D_L39_0024C06C) {
                    a0->fn14(e, 0);
                } else {
                    i = func_L39_0061B038(e);
                    if (i != 0 && i->b2C != 0) {
                        a0->fn14(a0->w10, 0);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0066B500 */
