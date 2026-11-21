#include "common.h"

/* NTSC-U counterpart of func_L39_0063EA20 (src/levels/shared/L39_0063EA20.c) */
/* localdecomp:start func_L39_0063C1D8 */
#include "vu0.h"

typedef struct {
    u8 pad0;
    u8 flag;
    u8 pad1[0x1E];
    f32 f20, f24, f28;
    u8 pad2[0x14];
    f32 f40, f44, f48;
    u8 pad3[4];
    f32 f50, f54, f58;
    u8 pad4[4];
    f32 f60, f64, f68;
    u8 pad5[0x34];
    s16 sA0;
    s16 sA2;
    f32 fA4, fA8, fAC;
} S_0063EA20;

extern s32 func_L39_0063C1A0(u8 *, s32);
extern void func_003BD778(void *, void *);
extern void func_L01_00437350(s32, s32, void *);
extern f32 func_L01_004455F0(f32 *, f32, f32 *, f32, f32, f32, s32);
extern void func_003BEA80(void *, void *);

void func_L39_0063C1D8(u8 *a0, u8 *p) {
    S_0063EA20 *s = (S_0063EA20 *)p;
    s32 r = func_L39_0063C1A0(a0, s->sA2);

    if (r != 0) {
        if (s->f60 == 0.0f && s->f64 == 0.0f && s->f68 == 0.0f && s->fAC == 1.0f
            && fabs_asm(s->f40) < 0.005f && fabs_asm(s->f44) < 0.005f && fabs_asm(s->f48) < 0.005f) {
            if (s->flag != 0) {
                func_003BD778((void *)r, s);
            }
        } else {
            func_L01_004455F0(&s->f40, s->f60, &s->f50, s->fA4, s->fA8, 0.0f, 2);
            func_L01_004455F0(&s->f44, s->f64, &s->f54, s->fA4, s->fA8, 0.0f, 2);
            func_L01_004455F0(&s->f48, s->f68, &s->f58, s->fA4, s->fA8, 0.0f, 2);
            if (s->flag == 0) {
                func_L01_00437350(r, s->sA0, s);
            }
            func_003BEA80(p + 0x10, &s->f40);
            s->f28 = s->f24 = s->f20 = s->fAC;
        }
        qzero(&s->f60);
        s->fAC = 1.0f;
    }
}
/* localdecomp:end func_L39_0063C1D8 */
