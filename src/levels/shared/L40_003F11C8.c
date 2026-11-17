#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

/* localdecomp:start func_L40_003F11C8 */
extern s32 *D_00241120;
extern s32 D_001A5DF8[];
extern u8 *func_L39_0061BF38(s32);
extern s32 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, void *);

void func_L40_003F11C8(Moby *self, s32 a1) {
    u8 *v = self->pVar;
    u8 *p = 0;
    s32 *n;
    s32 i;

    if (*(s32 *)(v + 0x264) != 0x539) {
        return;
    }
    if (*(s32 *)(v + 0x304) <= 0) {
        return;
    }
    for (i = 0; i < *D_00241120; i++) {
        p = func_L39_0061BF38(i);
        if (*(s32 *)p == *(s32 *)(v + 0x304)) {
            break;
        }
    }
    if (i == *D_00241120) {
        return;
    }
    if (p[0x1A11] != 2) {
        return;
    }
    n = func_L39_0066C2B8();
    if (n != 0) {
        *n = func_L39_0066C280(1, a1, D_001A5DF8[0], 6, n);
    }
}
/* localdecomp:end func_L40_003F11C8 */
