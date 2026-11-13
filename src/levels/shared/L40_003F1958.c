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

/* localdecomp:start func_L40_003F1958 */
extern f32 D_L40_00246E70;
extern f32 D_L40_00246E74;
__asm__(".extern D_L40_00246E70, 4");
__asm__(".extern D_L40_00246E74, 4");
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern s32 func_L40_003F1908(u8 *a0, u128_3F1460 *a1);

void func_L40_003F1958(Moby *self) {
    u8 *v = self->pVar;
    f32 z = self->pos.z;
    f32 g = D_L40_00246E70 * 0.00040000002f;
    u128_3F1460 tmp;

    func_L01_004482A0(&self->pos.z, (f32 *)(v + 0x268), *(f32 *)(v + 0x2E8), g, g, D_L40_00246E74 * 0.020000001f);
    tmp = *(u128_3F1460 *)&self->pos;
    if (func_L40_003F1908((u8 *)self, &tmp) == 0) {
        self->pos.z = z;
    }
}
/* localdecomp:end func_L40_003F1958 */
