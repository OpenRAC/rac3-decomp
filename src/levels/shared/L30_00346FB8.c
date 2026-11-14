#include "common.h"

/* declared by functions of L30_003468C8.c, which this file was cut from */
extern f32 D_L30_001DCF40;

/* localdecomp:start func_L30_00346FB8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    vu0_v4 v80;
    vu0_v4 v90;
} S_00346FB8;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    S_00346FB8 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_00346FB8;

extern s32 D_L30_001DCFF0;
extern f32 D_L30_001DCF40;
extern M_00346FB8 *D_L30_001E9018 __attribute__((section(".data")));
typedef struct { u8 pad0[0x84]; f32 f84; u8 pad88[0x25C0 - 0x88]; u8 *p25C0; } H_00346FB8;
extern H_00346FB8 D_001A4BE0;
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);

s32 func_L30_00346FB8(M_00346FB8 *a) {
    S_00346FB8 *s = a->p68;
    M_00346FB8 *m;

    if (D_L30_001DCFF0 == 0) {
        vec_add_ba(&s->v90, &s->v90, &s->v80);
        vec_add_ba(&a->pos, &a->pos, &s->v90);
    }
    if (func_L01_003FB640(&a->pos, 0x10, D_001A4BE0.p25C0, D_L30_001DCF40) != 0
        && ((m = D_L30_001E9018) == 0 || m->hAA != 0x15AD)) {
        return 1;
    }
    a->pos.y = D_001A4BE0.f84;
    return 0;
}
/* localdecomp:end func_L30_00346FB8 */

INCLUDE_ASM("asm/levels", func_L30_00347060);

INCLUDE_ASM("asm/levels", func_L30_003472E8);
