/* functional: high. Retail uses two strength-reduced pointers and a different loop form (18 words differ); same 43 records, same reads, writes and calls. */
typedef struct { u8 pad[0xB0]; } S_4DC790;
extern S_4DC790 D_L01_002F4540[];
extern s32 func_L01_004E0100(s32 a0);
#include "vu0.h"
extern void func_003C2C98(void *, void *);

void func_L01_004E04E8(void) {
    s32 i;

    for (i = 0; i < 43; i++) {
        u8 *rec = (u8 *)&D_L01_002F4540[i];
        u8 *q = rec + 0x40;
        s32 o;

        if (rec[1] != 0) {
            o = func_L01_004E0100(*(s16 *)(rec + 0xA2));
            if (o != 0) {
                func_003C2C98((void *)o, rec);
            }
        }
        qzero(q);
        qzero(q + 0x20);
        qzero(q + 0x50);
        *(f32 *)(rec + 0xAC) = 1.0f;
    }
}
