#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00644D08);

INCLUDE_ASM("asm/levels", func_L39_006461B0);

/* localdecomp:start func_L39_00646660 */
#include "vu0.h"

extern s32 *D_001D5A10_sda;
extern void func_L39_006468F0(u8 *a, u8 *b);
extern void func_0038D590(void *, void *);
extern void func_0038D278(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_003C7DD8(void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00646660;

void func_L39_00646660(u8 *a, s32 alt) {
    u8 *m = *(u8 **)(a + 0x450);
    u8 *src;
    s32 st;
    s32 skip;

    if (m == 0) {
        return;
    }
    st = -1;
    if (*(s32 *)(a + 0x474) == 2) {
        st = *(s32 *)(a + 0x478);
    }
    if (st == 6 || st == 12) {
        skip = 1;
    } else {
        skip = 0;
    }
    if (skip) {
        return;
    }
    if (*(s16 *)(m + 0xAA) == 0x18AB) {
        if (alt) {
            func_L39_006468F0(a, m);
            if (m[0x42] == m[0x43] && m[0x42] == 6) {
                return;
            }
            if (*D_001D5A10_sda < 2) {
                *(f32 *)(m + 0x18) += 0.6f;
            } else {
                *(f32 *)(m + 0x18) += 0.2f;
            }
        } else {
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
        }
        return;
    }
    src = alt ? a + 0x1340 : a + 0x1380;
    func_0038D590(m + 0xC0, src);
    *(V4_00646660 *)(m + 0x10) = *(V4_00646660 *)(src + 0x30);
    if (*(s16 *)(a + 0x2488) != 0 && alt == 0) {
        V4_00646660 rot[3];
        V4_00646660 scale;
        V4_00646660 mtx[3];
        V4_00646660 rel;

        func_0038D278(rot);
        scale = *(V4_00646660 *)(a + 0xF0);
        if (scale.x < 0.0f) {
            scale.x = 0.0f;
        }
        if (scale.y < 0.0f) {
            scale.y = 0.0f;
        }
        if (scale.z < 0.0f) {
            scale.z = 0.0f;
        }
        func_0038CF68(&rot[0], &rot[0], scale.x);
        func_0038CF68(&rot[1], &rot[1], scale.y);
        func_0038CF68(&rot[2], &rot[2], scale.z);
        func_0038D5F0(mtx, rot, a + 0x60);
        func_0038D5F0(mtx, a + 0x20, mtx);
        func_0038D5F0(m + 0xC0, mtx, m + 0xC0);
        vec_sub_ba(&rel, m + 0x10, a + 0xA0);
        func_0038D000(&rel, &rel, mtx);
        vec_add_ab(m + 0x10, &rel, a + 0xA0);
        if (*(f32 *)(a + 0xF0) < 0.1f) {
            *(u16 *)(m + 0x34) |= 0x41;
        }
    }
    func_003C7DD8(m);
    if ((u32)((*(u8 **)(a + 0x2524))[0x42] - 0x40) < 2) {
        *(f32 *)(m + 0xC) += 1800.0f;
    }
}
/* localdecomp:end func_L39_00646660 */
