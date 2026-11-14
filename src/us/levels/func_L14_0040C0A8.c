#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L14_0040EF88 (src/levels/14_koros/L14_0040E918.c): queues one spark at a random
 * point on a cone around the centre, into the D_L14_001EEC50_0040C0A8 record list */

/* localdecomp:start func_L14_0040C0A8 */
extern s32 D_001D6BE0_sda;
__asm__(".extern D_001D6BE0_sda, 4");
extern s32 D_001D6BF0_sda;
__asm__(".extern D_001D6BF0_sda, 4");
extern f32 D_001D6BBC_sda;
__asm__(".extern D_001D6BBC_sda, 4");
extern f32 D_001D6BB8_sda;
__asm__(".extern D_001D6BB8_sda, 4");
extern s32 D_001D6C00_sda;
__asm__(".extern D_001D6C00_sda, 4");
extern f32 D_001D6C08_sda;
__asm__(".extern D_001D6C08_sda, 4");
extern f32 D_001D6C10_sda;
__asm__(".extern D_001D6C10_sda, 4");
extern f32 D_001D6C14_sda;
__asm__(".extern D_001D6C14_sda, 4");
extern f32 D_001D6BD0_sda;
__asm__(".extern D_001D6BD0_sda, 4");
extern s32 D_001D6BCC_sda;
__asm__(".extern D_001D6BCC_sda, 4");
extern s32 D_001D6BC8_sda;
__asm__(".extern D_001D6BC8_sda, 4");

extern s32 D_L14_001E64B4_0040C0A8[];
extern u8 D_L14_001E20E0_0040C0A8[];
extern u8 D_L14_001D66B0_0040C0A8;
extern u8 D_L14_001EEC50_0040C0A8[];

extern void func_00388E38(void *, void *);
extern void func_L14_003F73B0(void *, void *, f32);
extern s32 func_L14_0040BB18(void);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L14_0040BD90(void *);

void func_L14_0040C0A8(f32 a, f32 b, void *o, s32 base, s32 flag) {
    u8 vA[16] __attribute__((aligned(16)));
    u8 vB[16] __attribute__((aligned(16)));
    f32 dir[4];
    u8 sum[16] __attribute__((aligned(16)));
    f32 m[16];
    u8 ev[16] __attribute__((aligned(16)));
    s32 dt;
    s32 idx;
    f32 x;
    f32 y;
    f32 s;
    f32 c;
    u8 *e;

    dt = D_L14_001E64B4_0040C0A8[0] - base;
    *(vu0_q *)vA = *(vu0_q *)&D_001D6BE0_sda;
    x = a * 0.017453292f;
    vec_add_ab(vA, &D_001D6BE0_sda, &D_001D6BF0_sda);
    y = b * 0.017453292f;
    func_00388E38(m, D_L14_001E20E0_0040C0A8);
    *(vu0_q *)(m + 12) = *(vu0_q *)&D_L14_001D66B0_0040C0A8;
    func_L14_003F73B0(m, m, D_001D6BBC_sda);
    if (dt < D_001D6C00_sda) {
        idx = func_L14_0040BB18();
        if (idx != -1) {
            *(vu0_q *)vB = *(vu0_q *)vA;
            if (flag != 0) {
                s = (f32)dt;
                x = func_00389380(x, s * D_001D6C08_sda * 0.017453292f);
                s = s * D_001D6C10_sda;
                y = func_00389380(y, s * 0.017453292f);
            } else {
                s = (f32)dt;
                x = func_003893C8(x, s * D_001D6C08_sda * 0.017453292f);
                s = s * D_001D6C10_sda;
                y = func_003893C8(y, s * 0.017453292f);
            }
            c = func_00388978(y);
            dir[0] = D_001D6BB8_sda * c * func_00388960(x);
            dir[1] = D_001D6BB8_sda * c * func_00388978(x);
            dir[2] = D_001D6BB8_sda * func_00388960(y);
            func_003BF6A8(dir, D_001D6C14_sda);
            vec_add_ab(sum, vB, dir);
            e = D_L14_001EEC50_0040C0A8 + (idx << 5);
            *(vu0_q *)e = *(vu0_q *)sum;
            *(f32 *)(e + 0xC) = D_001D6BD0_sda;
            *(s32 *)(e + 0x10) = func_0037E208(D_001D6BCC_sda, D_001D6BC8_sda);
            *(vu0_q *)ev = *(vu0_q *)e;
            func_L14_0040BD90(ev);
        }
    }
}
/* localdecomp:end func_L14_0040C0A8 */
