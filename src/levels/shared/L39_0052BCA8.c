#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0052BCA8);

/* localdecomp:start func_L39_0052BD50 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad0[0x290];
    u128_t q290;
    u128_t q2A0;
    char pad1[0x308 - 0x2B0];
    f32 f308;
    f32 f30C;
} B_0052BD50;
typedef struct {
    char pad0[0x1E0];
    s32 i1E0;
    char pad1[0x1F0 - 0x1E4];
    s32 i1F0;
    char pad2[4];
    B_0052BD50 *b;
    u128_t t;
} Q_0052BD50;
extern void func_L01_004450F0(void *, s32, s32);

void func_L39_0052BD50(void *self) {
    char *p = self;
    Q_0052BD50 *q = *(Q_0052BD50 **)(p + 0x68);
    B_0052BD50 *b;
    u128_t t;

    b = q->b;
    q->i1E0 = 0;
    q->i1F0 = 0;
    t = b->q290;
    b->f308 = 50.0f;
    b->f30C = 50.0f;
    *(u128_t *)(p + 0x10) = t;
    *(f32 *)(p + 0x18) -= 1.0f;
    *(u128_t *)(p + 0xF0) = b->q2A0;
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L39_0052BD50 */

INCLUDE_ASM("asm/levels", func_L39_0052BDB8);

INCLUDE_ASM("asm/levels", func_L39_0052CA90);

INCLUDE_ASM("asm/levels", func_L39_0052CB90);

INCLUDE_ASM("asm/levels", func_L39_0052CD40);

/* localdecomp:start func_L39_0052CE80 */
typedef struct { u8 pad[0x180]; s32 f180; } G_0052CE80;
typedef struct { u8 pad[0x90]; s32 f90; } R_0052CE80;
typedef struct { u8 pad[0x1D8]; s32 f1D8; } T_0052CE80;
typedef struct { u8 pad[0x68]; T_0052CE80 *f68; } O_0052CE80;
__asm__(".extern D_L39_00241640, 16");
extern G_0052CE80 *D_L39_00241640;
extern void func_003C2F58(void *, s32, void *);
extern f32 D_L39_0024AAE0;
extern R_0052CE80 *func_L39_005422E8(f32, void *, s32, void *, s32, s32, s32, s32);

void func_L39_0052CE80(O_0052CE80 *arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4, u32 arg5) {
    T_0052CE80 *t = arg0->f68;
    u8 buf[16];
    R_0052CE80 *r;
    if (arg3 == 10) {
        t->f1D8 = 0;
    } else {
        t->f1D8 = 1;
    }
    func_003C2F58(arg0, t->f1D8, buf);
    r = func_L39_005422E8(D_L39_0024AAE0, arg0, arg1, buf, 0x10001, arg2, 1, (D_L39_00241640->f180 != 2) ? arg4 : 0);
    if (r != 0) {
        if (arg5 != 0xFFFFFFFF) {
            r->f90 = arg5;
        }
    }
    t->f1D8 = t->f1D8 ^ 1;
}
/* localdecomp:end func_L39_0052CE80 */

INCLUDE_ASM("asm/levels", func_L39_0052CF70);

INCLUDE_ASM("asm/levels", func_L39_0052D1C0);
