#include "common.h"

/* localdecomp:start func_L13_003C62A8 */
typedef struct { f32 x; f32 y; f32 z; f32 w; } __attribute__((aligned(16))) Q_003C62A8;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_0044A7D0(u8 *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);

u8 *func_L13_003C62A8(u8 *parent, Q_003C62A8 *pos, Q_003C62A8 *rot) {
    Q_003C62A8 p;
    Q_003C62A8 r;
    u8 *m;
    u8 *v;
    Q_003C62A8 *rp = &r;

    p = *pos;
    r = *rot;
    m = func_003C24B0(0x1EA5, 0x70);
    if (m != 0) {
        func_L01_00456160(m, parent);
        *(Q_003C62A8 *)(m + 0x10) = p;
        func_L01_0044A7D0(m);
        v = *(u8 **)(m + 0x68);
        *(Q_003C62A8 *)(v + 0x0) = r;
        *(Q_003C62A8 *)(v + 0x10) = r;
        *(f32 *)(v + 8) = func_0038DAB8(*(f32 *)(v + 8), func_L01_00443A18(2.0f, 25.0f) * 0.017453292f);
        *(f32 *)(m + 0xF4) = -func_0038D160(func_0038CED8(rp), rp->z);
        *(f32 *)(m + 0xF8) = func_0038D160(r.x, rp->y);
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.75f;
    }
    return m;
}
/* localdecomp:end func_L13_003C62A8 */

INCLUDE_ASM("asm/levels", func_L13_003C63A8);
