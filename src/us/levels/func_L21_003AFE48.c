#include "common.h"

/* NTSC-U counterpart of func_L21_003B1A00 (src/levels/21_obani_draco/L21_003B1A00.c) */
#include "vu0.h"
void func_L21_003AFFA0(void *, void *);

/* localdecomp:start func_L21_003AFE48 */
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);

typedef unsigned long u_long_003B1A00;

typedef struct {
    f32 w[0x1C];
    f32 h70;
    void *owner;
    s16 h78;
    s16 h7A;
    f32 h7C;
} S_003B1A00;

u8 *func_L21_003AFE48(u8 *arg0, vu0_v4 *pos, f32 a, f32 b) {
    vu0_v4 v;
    u8 *m;
    S_003B1A00 *s;
    s32 i;

    v = *pos;
    m = func_003BCFB0(0x1C6D, 0x80);
    if (m != 0) {
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        s = *(S_003B1A00 **)(m + 0x68);
        *(u_long_003B1A00 *)(m + 0x38) = *(u_long_003B1A00 *)(arg0 + 0x38);
        *(vu0_v4 *)(m + 0x10) = v;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = a;
        s->h70 = 0.1666666716f;
        s->owner = arg0;
        s->h7C = b;
        s->h78 = 0;
        s->h7A = 0;
        for (i = 0; i < 0x1C; i++) {
            s->w[i] = func_0037E250(-4.0f, 4.0f) * 0.4f / 120.0f;
            if (i == 0 || i == 0x1B) {
                s->w[i] = 0.0f;
            }
        }
        func_L21_003AFFA0(m, s);
    }
    return m;
}
/* localdecomp:end func_L21_003AFE48 */
