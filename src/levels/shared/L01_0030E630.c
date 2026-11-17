#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;

INCLUDE_ASM("asm/levels", func_L01_0030E630);

INCLUDE_ASM("asm/levels", func_L01_0030EAE8);

INCLUDE_ASM("asm/levels", func_L01_0030F0B0);

INCLUDE_ASM("asm/levels", func_L01_0030F288);

LINKER_REMNANT("asm/levels", func_L01_0030F4E0);

INCLUDE_ASM("asm/levels", func_L01_0030F4E8);

INCLUDE_ASM("asm/levels", func_L01_0030F6C0);

LINKER_REMNANT("asm/levels", func_L01_003104A0);

INCLUDE_ASM("asm/levels", func_L01_003104B8);

INCLUDE_ASM("asm/levels", func_L01_00310538);

LINKER_REMNANT("asm/levels", func_L01_003107A8);

/* localdecomp:start func_L01_003107C8 */
typedef int u128_3107C8 __attribute__((mode(TI)));
typedef union { u128_3107C8 q; f32 f[4]; } Vec4_3107C8;
typedef struct {
    u8 pad0[0x10];
    Vec4_3107C8 v10;
    u8 b20;
    u8 pad21[0x2C - 0x21];
    f32 f2C;
    u8 pad30[0x68 - 0x30];
    u8 *p68;
} O_3107C8;
extern void func_L01_00310DB8(f32, f32, f32, Vec4_3107C8 *, u8 *, s32, s32);
extern void func_L01_00310A88(Vec4_3107C8 *, f32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00310C38(Vec4_3107C8 *, f32, s32, s32, f32, s32, s32, u8 *);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
void func_L01_003107C8(O_3107C8 *o) {
    u8 *p = o->p68;
    Vec4_3107C8 tmp;
    switch (o->b20) {
    case 1: {
        f32 a;
        s32 n;
        tmp = o->v10;
        func_L01_00310DB8(0.0f, 0.85f, 0.25f, &tmp, p + 0x10, 0x103080, 4);
        a = o->f2C * 95.0f;
        n = func_00382498(0x5F, 0x6F) >> 2;
        func_L01_00310A88(&o->v10, a, 0x103080, n, func_00382538(), -1.0f, 0xB, 2);
        break;
    }
    case 2: {
        s32 t = *(s32 *)(p + 0x6C) - 1;
        *(s32 *)(p + 0x6C) = t;
        if (t <= 0) {
            *(s32 *)(p + 0x6C) = 0;
        }
        tmp = o->v10;
        func_L01_00310DB8(0.0f, 0.85f, 0.25f, &tmp, p + 0x10, 0x103080, 4);
        if (*(s32 *)(p + 0x7C) == 0) {
            func_L01_00310C38(&o->v10, o->f2C * 45.0f, 0x103080, *(s32 *)(p + 0x6C), 0.0f, 0xB, 2, p + 0x50);
            func_L01_00310C38(&o->v10, o->f2C * 45.0f * 0.75f, 0x3F3F3F, *(s32 *)(p + 0x6C), 0.0f, 0xB, 2, p + 0x50);
        }
        break;
    }
    }
}
/* localdecomp:end func_L01_003107C8 */
