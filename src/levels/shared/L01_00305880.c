#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00305880 */
#include "vu0.h"
typedef struct { u8 b[0xF0]; } RecF0_00305880;
typedef struct { s32 v[2]; } Pair_00305880;
extern u8 D_001425C0[];
extern RecF0_00305880 D_L01_002C5600[];
extern Pair_00305880 D_L01_001DC5D0 __attribute__((section(".data")));
extern s32 D_L01_001DC5D8;
__asm__(".extern D_L01_001DC5D8, 4");
extern void *func_L01_00472F58(void *, void *, f32, s32);

void func_L01_00305880(void *self, void *pos) {
    u8 *v = *(u8 **)((u8 *)self + 0x68);
    Vec4 vel;
    Pair_00305880 tbl;
    qzero(&vel);
    tbl = D_L01_001DC5D0;
    if ((D_L01_002C5600 + D_001425C0[0x11])->b[1] >= 4) {
        func_L01_00472F58(pos, &vel, *(f32 *)(v + 0x50) * 0.25f * 0.1f, 0x48);
    } else {
        func_L01_00472F58(pos, &vel, *(f32 *)(v + 0x50) * 0.25f * 0.1f, tbl.v[D_L01_001DC5D8 % 2]);
    }
    D_L01_001DC5D8++;
}
/* localdecomp:end func_L01_00305880 */

/* localdecomp:start func_L01_00305970 */
extern s32 D_L01_001DC5DC;
__asm__(".extern D_L01_001DC5DC, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);

void func_L01_00305970(void *self, void *pos, void *dir) {
    u8 *v = *(u8 **)((u8 *)self + 0x68);
    Vec4 vel;
    Pair_00305880 tbl;
    vel.q = *(u128_t *)dir;
    func_0038CF68(&vel, &vel, 0.05f);
    tbl = D_L01_001DC5D0;
    if ((D_L01_002C5600 + D_001425C0[0x11])->b[1] >= 4) {
        func_L01_00472F58(pos, &vel, func_003824E0(0.05f, 0.1f) * *(f32 *)(v + 0x50) * 0.1f, 0x48);
    } else {
        func_L01_00472F58(pos, &vel, func_003824E0(0.05f, 0.1f) * *(f32 *)(v + 0x50) * 0.1f, tbl.v[D_L01_001DC5DC % 2]);
    }
    D_L01_001DC5DC++;
}
/* localdecomp:end func_L01_00305970 */

/* localdecomp:start func_L01_00305AB8 */
extern void func_003A9440(s32, unsigned long);
extern void func_L01_00305F00(void *, s32, s32, f32);
extern void func_L01_00305D30(f32, void *, f32 *, s32);
extern void func_L01_00306A98(void *);

void func_L01_00305AB8(void *self) {
    u8 *v = *(u8 **)((u8 *)self + 0x68);
    f32 *pos;

    func_003A9440(0x47, 0x53001);
    if ((D_L01_002C5600 + D_001425C0[0x11])->b[1] >= 4) {
        func_L01_00305F00(self, 0x7F7F7F7F, 0x4B, 0.1f);
    } else {
        func_L01_00305F00(self, 0x7F7F7F7F, 0x4B, 0.05f);
    }
    if (*(f32 *)(v + 0x50) != 0.0f) {
        pos = (f32 *)(v + 0x10);
        if ((D_L01_002C5600 + D_001425C0[0x11])->b[1] >= 4) {
            func_L01_00305D30(0.25f, self, pos, 0x7F7F3010);
            func_L01_00305D30(0.5f, self, pos, 0x3F3F1808);
        } else {
            func_L01_00305D30(0.25f, self, pos, 0x7F10307F);
            func_L01_00305D30(0.5f, self, pos, 0x3F08183F);
        }
    }
    func_L01_00306A98(self);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_00305AB8 */
