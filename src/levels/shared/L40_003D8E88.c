#include "common.h"

/* declared by functions of L40_003D88A8.c, which this file was cut from */
extern void func_0038CB78(void *, s32, s32);

/* localdecomp:start func_L40_003D8E88 */
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0xF];
    u8 f30;
    u8 pad31;
    u16 f32;
    u16 f34;
    u8 pad36[0x2C];
    u8 f62;
    u8 pad63[5];
    u8 *f68;
} M_003D8E88;
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;
extern s32 func_L40_0053F2D8(u8 *msg);
extern M_003D8E88 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_003C7C38(void *m);
extern void func_0038CB78(void *, s32, s32);

M_003D8E88 *func_L40_003D8E88(s32 a0, s32 a1, u8 *msg) {
    M_003D8E88 *m;
    u8 *v;
    f32 f20, f21;
    s32 sc, s17;

    s32 index = *(s32 *)(msg + 0x18);
    s32 *h = (s32 *)(msg + 8);
    m = func_L40_0053F570(0x19F6, h[1], *(s32 *)(msg + 4), func_L40_0053F2D8(msg), index);
    if (m != 0) {
        m->f30 = 0x7F;
        m->f32 = 0x7F;
        m->f34 |= 0x20;
        v = m->f68;
        if (*D_L40_00241120 >= 2) {
            m->f62 = 1;
        }
        *(s32 *)(v + 0x1C0) = 0;
        m->f20 = 0;
        *(s32 *)(v + 0x1B4) = 0;
        f20 = *(f32 *)(v + 0x1C4);
        sc = *(s32 *)(v + 0x1CC);
        f21 = *(f32 *)(v + 0x1C8);
        s17 = *(s32 *)(v + 0x1D0);
        func_0038CB78(v + 0x1A4, 0, 0x48);
        *(s32 *)(v + 0x1D0) = s17;
        *(s32 *)(v + 0x1B0) = 2;
        *(f32 *)(v + 0x1C8) = f21;
        *(f32 *)(v + 0x1C4) = f20;
        *(f32 *)(v + 0x30) = f20;
        *(s32 *)(v + 0x1CC) = (sc > 0xF9) ? sc : 0xFA;
        *(s16 *)(v + 0x34) = (s32)f20;
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L40_003D8E88 */
