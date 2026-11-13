#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_0040DA90 */
typedef struct {
    u8 pad_0[0x20];
    vu0_v4 *f20;
    f32 f24;
    f32 f28;
    u8 pad_2C[0x14];
    s32 f40[4];
} Tr_40DA90;

typedef struct {
    u8 pad_0[0x34];
    s32 f34;
    u8 pad_38[0x18];
    Tr_40DA90 *f50;
    u8 pad_54[0x14C];
    s32 f1A0[1];
} Gl_40DA90;

extern Gl_40DA90 D_L03_001E6880;
extern Tr_40DA90 D_L03_002E5CE0;
extern s32 D_L03_001D6AD0;
__asm__(".extern D_L03_001D6AD0, 4");
extern u8 D_L03_001D6AC5;
__asm__(".extern D_L03_001D6AC5, 1");

extern f32 func_00388800(void *, void *);
extern void func_L01_004207D0(void *, s32 *);
extern void func_L01_00420818(void *, s32 *);
extern void func_L01_00402498(void (*)(void), s32);
extern void func_L01_00420868(void);
extern void func_L01_00420978(void);

void func_L03_0040DA90(u8 *a, s32 *b, s32 *c, s32 d) {
    s32 ok = 1;
    s32 i;
    s32 j;
    f32 m1;
    f32 m2;

    if (D_L03_001E6880.f34 >= *(s32 *)(a + 0x50) && D_L03_001E6880.f34 <= *(s32 *)(a + 0x54)) {
        m1 = (func_00388800(a, a + 0x20) + func_00388800(a + 0x10, a + 0x30)) * 0.5f;
        m2 = (func_00388800(a, a + 0x10) + func_00388800(a + 0x10, a + 0x20)) * 0.5f;
        if (D_L03_002E5CE0.f20 == 0) {
            D_L03_002E5CE0.f20 = (vu0_v4 *)&D_L03_001D6AD0;
        }
        if (m2 < m1) {
            D_L03_002E5CE0.f24 = 1.0f;
            D_L03_002E5CE0.f28 = m2 / m1;
        } else {
            D_L03_002E5CE0.f28 = 1.0f;
            D_L03_002E5CE0.f24 = m1 / m2;
        }
        *(vu0_v4 *)&D_L03_002E5CE0 = *(vu0_v4 *)(a + 0x40);
        for (i = 0; i < 4; i++) {
            D_L03_002E5CE0.f20[i] = ((vu0_v4 *)a)[i];
        }
        if (b != 0) {
            if (b[0] <= D_L03_001E6880.f34 && D_L03_001E6880.f34 <= b[1]) {
                func_L01_004207D0(D_L03_002E5CE0.f20, b);
                func_L01_00402498(func_L01_00420868, 0);
                if (b[5] == 0) {
                    ok = 0;
                }
            }
        }
        if (c != 0 && d != 0) {
            func_L01_00420818(D_L03_002E5CE0.f20, c);
            func_L01_00402498(func_L01_00420978, 0);
            if (D_L03_001D6AC5 != 0) {
                ok = 0;
            }
        }
    } else {
        ok = 0;
    }
    if (ok != 0 && *(s32 *)(a + 0x58) >= 0) {
        D_L03_001E6880.f50 = &D_L03_002E5CE0;
        for (j = 0; j < 4; j++) {
            s32 idx = ((s32 *)(a + 0x58))[j];
            if (idx >= 0) {
                D_L03_001E6880.f50->f40[j] = D_L03_001E6880.f1A0[idx];
            } else {
                D_L03_001E6880.f50->f40[j] = 0;
            }
        }
    } else {
        D_L03_001E6880.f50 = 0;
    }
}
/* localdecomp:end func_L03_0040DA90 */
