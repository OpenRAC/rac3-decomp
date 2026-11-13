#include "common.h"

/* localdecomp:start func_L39_0059F0B8 */
typedef struct { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fA; s16 *fC; u8 pad10[0x30 - 0x10]; } S_0059F0B8;
typedef struct { u8 pad0[0x1A]; u16 f1A; u8 pad1C[4]; } E_0059F0B8;
extern S_0059F0B8 D_L39_002668C0[];
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_0024C9E4, 16");
extern s32 *D_L39_00241120;
extern E_0059F0B8 *D_L39_0024C9E4;
extern E_0059F0B8 *D_L39_0024CA38[];
extern s32 func_003DE9F8(s16 *, s16 *, s32);
extern s32 func_003E1238(s16 *, s16 *, s32);
extern void func_003D0A08(s16 *, s16 *, s32);

void func_L39_0059F0B8(s32 idx) {
    S_0059F0B8 *s = &D_L39_002668C0[idx];
    s32 i;
    s32 j;
    if (s->fC) {
        func_003DE9F8(s->fC + s->f0, s->fC + s->f0 + s->f2, idx);
        if (*D_L39_00241120 >= 2) {
            for (i = 1; i < *D_L39_00241120; i++) {
                s16 *p = s->fC + s->f0;
                E_0059F0B8 *dst = D_L39_0024CA38[i];
                for (j = 0; j < s->f2; j++) {
                    dst[*p].f1A = D_L39_0024C9E4[*p].f1A;
                    p++;
                }
            }
        }
        s->f0 = 0;
        s->f2 = 0;
        func_003E1238(s->fC + s->f4, s->fC + s->f4 + s->f6, idx);
        s->f4 = 0;
        s->f6 = 0;
        func_003D0A08(s->fC + s->f8, s->fC + s->f8 + s->fA, idx);
        s->f8 = 0;
        s->fA = 0;
    }
}
/* localdecomp:end func_L39_0059F0B8 */
