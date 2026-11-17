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

/* declared by functions of L40_003EFDE0.c, which this file was cut from */
extern void func_L40_003F19F8(Moby *);
extern u8 *func_L39_0066B870(s32 a0);
extern u8 *func_L39_0066B8A8(u8 *a0, s32 *a1);

/* localdecomp:start func_L40_003F19E0 */
void func_L40_003F19E0(Vec4_003F1538 *a) {
    Vec4_003F1538 v = *a;
}
/* localdecomp:end func_L40_003F19E0 */

/* localdecomp:start func_L40_003F19F8 */
extern u8 *func_L39_0066B870(s32 a0);
extern u8 *func_L39_0066B8A8(u8 *a0, s32 *a1);
extern void func_L39_00557EF0(Moby *, s32);

void func_L40_003F19F8(Moby *self) {
    u8 *v = self->pVar;
    u8 *it;
    u8 *n;
    Moby *e;
    s32 i;

    if (*(s32 *)(v + 0x2AC) == 0xFF) {
        return;
    }
    it = func_L39_0066B870(*(s32 *)(v + 0x2AC));
    for (i = 0; (n = func_L39_0066B8A8(it, &i)) != 0 && (e = *(Moby **)(n + 0x1C)) != 0; i++) {
        if (e == self || e == 0) {
            continue;
        }
        if (e->field_20 == 0xFE) {
            continue;
        }
        if (e->field_20 == 0xFD) {
            continue;
        }
        *(s32 *)((u8 *)e->pVar + 0x264) = 0x539;
        func_L39_00557EF0(e, 1);
        return;
    }
}
/* localdecomp:end func_L40_003F19F8 */

INCLUDE_ASM("asm/levels", func_L40_003F1AD0);
