#include "common.h"
#include "vu0.h"

/* declared by functions of L31_003A4280.c, which this file was cut from */
typedef int u128_3A3890 __attribute__((mode(TI)));

/* localdecomp:start func_L31_003A5488 */
extern u8 *D_L31_001DF880;
extern void func_L31_00346998(void *, void *);
extern void func_L30_0034CCD0(u8 *, f32 *, f32 *, f32 *, f32 *);
extern f32 func_L31_003A51C8(void *, s32, void *, f32);

void func_L31_003A5488(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    f32 f[4];

    func_L31_00346998(o, v + 0x150);
    *(u128_3A3890 *)(v + 0x180) = *(u128_3A3890 *)(o + 0x10);
    if (*(s32 *)(v + 0x1B0) != -1) {
        *(u8 **)(v + 0x1B4) = D_L31_001DF880 + *(s32 *)(v + 0x1B0) * 0x80;
    } else {
        *(u8 **)(v + 0x1B4) = 0;
    }
    if (*(s32 *)(v + 0x1B8) != -1) {
        *(u8 **)(v + 0x1BC) = D_L31_001DF880 + *(s32 *)(v + 0x1B8) * 0x80;
    } else {
        *(u8 **)(v + 0x1BC) = 0;
    }
    *(s32 *)(v + 0x1C4) = 0;
    func_L30_0034CCD0(*(u8 **)(v + 0x1B4), &f[0], &f[1], &f[2], &f[3]);
    *(u128_3A3890 *)(v + 0x190) = *(u128_3A3890 *)(o + 0x10);
    *(f32 *)(v + 0x190) = f[0];
    *(f32 *)(v + 0x198) = f[2];
    *(f32 *)(v + 0x198) = func_L31_003A51C8(v + 0x190, 0, o, f[3] - f[2]);
    *(u128_3A3890 *)(v + 0x1A0) = *(u128_3A3890 *)(o + 0x10);
    *(f32 *)(v + 0x1A0) = f[1];
    *(f32 *)(v + 0x1A8) = f[2];
    *(f32 *)(v + 0x1A8) = func_L31_003A51C8(v + 0x1A0, 0, o, f[3] - f[2]);
}
/* localdecomp:end func_L31_003A5488 */

/* localdecomp:start func_L31_003A55A0 */
typedef struct S_003A55A0 {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x43 - 0x21];
    u8 anim;
    f32 f44;
    f32 f48;
    f32 f4C;
} S_003A55A0;
extern s32 D_L31_001DE9B4;
extern s32 D_L31_001DE9B8;
extern f32 D_L31_001DE96C;
extern f32 D_L31_001DE970;
extern f32 D_L31_001DE974;
extern f32 D_L31_001DE98C;
extern f32 D_L31_001DE994;
extern f32 D_L31_001DE998;
extern f32 D_L31_001DE9A4;
extern f32 D_L31_001DE9A8;
extern f32 D_L31_001DE9AC;
extern f32 D_L31_001DEA00;
__asm__(".extern D_L31_001DE9B4, 4");
__asm__(".extern D_L31_001DE9B8, 4");
__asm__(".extern D_L31_001DE96C, 4");
__asm__(".extern D_L31_001DE970, 4");
__asm__(".extern D_L31_001DE974, 4");
__asm__(".extern D_L31_001DE98C, 4");
__asm__(".extern D_L31_001DE994, 4");
__asm__(".extern D_L31_001DE998, 4");
__asm__(".extern D_L31_001DE9A4, 4");
__asm__(".extern D_L31_001DE9A8, 4");
__asm__(".extern D_L31_001DE9AC, 4");
__asm__(".extern D_L31_001DEA00, 4");
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L31_003A55A0(u8 *a0, s32 a1) {
    S_003A55A0 *m = (S_003A55A0 *)a0;
    s32 t;

    func_L01_004450F0(m, a1, -1);
    switch (m->state) {
    case 0:
        break;
    case 1:
        if (m->anim != 1) func_003C3A10(m, 1, 0, D_L31_001DE9B4);
        break;
    case 2:
        if (m->anim != 10) func_003C3A10(m, 10, 0, D_L31_001DE9B8);
        break;
    case 3:
        if (m->anim != 3) func_003C3A10(m, 3, 0, D_L31_001DE9B4);
        m->f48 = D_L31_001DE96C;
        break;
    case 4:
        if (m->anim != 5) func_003C3A10(m, 5, D_L31_001DE974, 4);
        m->f48 = D_L31_001DE970;
        break;
    case 5:
        if (m->anim != 8) func_003C3A10(m, 8, D_L31_001DE994, D_L31_001DE998);
        m->f48 = D_L31_001DE98C;
        m->f44 = m->f44 + m->f4C;
        break;
    case 6:
        if (m->anim != 10) func_003C3A10(m, 10, 0, D_L31_001DE9B8);
        break;
    case 7:
        t = D_L31_001DE9B4;
        if (m->anim == 10) t = D_L31_001DE9B8;
        if (m->anim != 1) func_003C3A10(m, 1, 0, t);
        m->f48 = 1.0f;
        break;
    case 8:
        t = D_L31_001DE9B4;
        if (m->anim == 10 || m->anim == 7) t = D_L31_001DE9B8;
        if (m->anim != 2) func_003C3A10(m, 2, 0, t);
        break;
    case 9:
        if (m->anim != 0) func_003C3A10(m, 0, 0, D_L31_001DE9B4);
        m->f48 = 1.0f;
        break;
    case 10:
        func_003C3A10(m, 7, D_L31_001DE9A8, D_L31_001DE9AC);
        m->f48 = D_L31_001DE9A4;
        m->f44 = m->f44 + m->f4C;
        break;
    case 11:
        if (m->anim != 6) func_003C3A10(m, 6, 0, D_L31_001DE9B4);
        m->f48 = D_L31_001DEA00;
        break;
    case 12:
        if (m->anim != 2) func_003C3A10(m, 2, 0, D_L31_001DE9B4);
        break;
    case 13:
        if (m->anim != 1) func_003C3A10(m, 1, 0, D_L31_001DE9B4);
        m->f48 = 1.0f;
        break;
    case 66:
        break;
    }
}
/* localdecomp:end func_L31_003A55A0 */
