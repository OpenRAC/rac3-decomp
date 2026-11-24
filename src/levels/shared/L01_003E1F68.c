#include "common.h"

/* localdecomp:start func_L01_003E1F68 */
typedef struct M_003E0480 M_003E0480;
typedef struct V_003E0480 V_003E0480;
typedef struct Obj_003E1328 Obj_003E1328;

extern f32 D_L01_001DF590;
__asm__(".extern D_L01_001DF590, 4");
extern f32 D_L01_001DF594;
__asm__(".extern D_L01_001DF594, 4");
extern f32 D_L01_001DF598;
__asm__(".extern D_L01_001DF598, 4");
extern f32 D_L01_001DF59C;
__asm__(".extern D_L01_001DF59C, 4");
extern f32 D_L01_001DF5A0;
__asm__(".extern D_L01_001DF5A0, 4");
void func_L01_003E1F68(u8 *m) {
    extern void func_L01_003E2418(M_003E0480 *, V_003E0480 *);
    extern void func_L01_003E2BD8(u8 *, u8 *);
    extern void func_L01_004450F0(M_003E0480 *, s32, s32);
    extern void func_L01_003E2DB8(u8 *);
    extern void func_L01_004048D0(void (*)(s32), s32);
    extern void func_003C2880(Obj_003E1328 *);
    u8 *vars = *(u8 **)(m + 0x68);
    s32 i;
    s32 alpha;
    u8 **children;

    switch (m[0x20]) {
    case 1:
        *(f32 *)(vars + 8) += D_L01_001DF590;
        if (*(f32 *)(vars + 8) >= 1.0f) {
            *(f32 *)(vars + 8) = 0.0f;
            func_L01_004450F0((M_003E0480 *)m, 2, -1);
        } else {
            func_L01_003E2418((M_003E0480 *)m, (V_003E0480 *)vars);
            func_L01_004048D0((void (*)(s32))func_L01_003E2DB8, (s32)m);
            break;
        }
        /* Fall through. */
    case 2:
        *(f32 *)(vars + 8) += D_L01_001DF594;
        if (*(f32 *)(vars + 8) >= 1.0f) {
            (*(u8 **)(m + 0xB8))[0x23] = 128;
            for (i = 0; i < *(s32 *)(vars + 0xC); i++) {
                (*(u8 **)(vars + 0x20 + i * 4))[0x23] = 128;
            }
            *(f32 *)(vars + 8) = 0.0f;
            func_L01_004450F0((M_003E0480 *)m, 3, -1);
        } else {
            func_L01_003E2BD8(m, vars);
            if (*(f32 *)(vars + 8) <= D_L01_001DF59C) {
                alpha = 0;
            } else if (*(f32 *)(vars + 8) >= D_L01_001DF5A0) {
                alpha = 128;
            } else {
                alpha = (s32)((*(f32 *)(vars + 8) - D_L01_001DF59C) /
                              (D_L01_001DF5A0 - D_L01_001DF59C) * 128.0f);
            }
            if (alpha >= 2) {
                *(u16 *)(*(u8 **)(m + 0xB8) + 0x34) &= ~1;
                (*(u8 **)(m + 0xB8))[0x31] = 1;
                (*(u8 **)(m + 0xB8))[0x23] = alpha;
                for (i = 0; i < *(s32 *)(vars + 0xC); i++) {
                    children = (u8 **)(vars + 0x20 + i * 4);
                    *(u16 *)(*children + 0x34) &= ~1;
                    (*children)[0x31] = 1;
                    (*children)[0x23] = alpha;
                }
            }
            func_L01_004048D0((void (*)(s32))func_L01_003E2DB8, (s32)m);
            break;
        }
        /* Fall through. */
    case 3:
        *(f32 *)(vars + 8) += D_L01_001DF598;
        if (*(f32 *)(vars + 8) >= 1.0f) {
            func_003C2880((Obj_003E1328 *)m);
        } else {
            func_L01_003E2BD8(m, vars);
        }
        break;
    }
}
/* localdecomp:end func_L01_003E1F68 */
