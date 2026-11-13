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

/* localdecomp:start func_L40_003F12A0 */
extern u8 D_L40_00249FC0[];
extern s32 func_L40_003F1388(Moby *, s32);
extern void func_L39_00557EF0(Moby *, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L40_003F1AD0(Moby *, void *, s32, s32, s32);
extern void func_L40_003EEE80(s32, Moby *);

s32 func_L40_003F12A0(Moby *self, s32 a1) {
    u8 *v = self->pVar;

    if (self->field_20 == 0) {
        if (func_L40_003F1388(self, a1) != 0) {
            return 1;
        }
        if (*(s32 *)(v + 0x264) == 0x539) {
            func_L39_00557EF0(self, 0);
        }
    }
    *(u16 *)((u8 *)self + 0x34) |= 0x1000;
    if (((u8 *)self)[0x31] != 0) {
        if (func_L01_0040E548(D_L40_00249FC0, &self->pos) < 256.0f) {
            func_L01_004472C0(self);
            ((u8 *)self)[0x6F] = 0xF;
        }
    }
    func_L40_003F1AD0(self, v + 0x160, a1, 0, 0);
    func_L40_003EEE80(a1, self);
    return 0;
}
/* localdecomp:end func_L40_003F12A0 */
