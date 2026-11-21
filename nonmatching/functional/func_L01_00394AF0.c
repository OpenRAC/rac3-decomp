/* functional: medium. 273-word diff is allocation/scheduling around VU0 sequences; instruction multiset equal to retail except an address-fold (lbu off 1 vs addiu+lbu); D_L01_002C5600 is u8[] in context so row index written as *240+1. */
#include "common.h"
/* localdecomp:start func_L01_00394AF0 */
#include "vu0.h"
extern s32 D_L01_001DFB40;
extern u8 D_0014263F[];
typedef struct { u8 pad[0x20]; f32 strength; s32 pad24; s32 frames, timer; } Effect_00394AF0;
extern Effect_00394AF0 D_L01_001E2A40;
extern s32 D_L01_001D673C;
extern vu0_q D_L01_001EAA20;
void func_L01_00394AF0(u8 *m) {
    extern s32 func_L01_004CB2D8(void *);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C8668(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_00395020(void *);
    extern void func_L01_003303B8(void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_003D5630(void);
    extern void func_L01_00395288(void *, s32);
    extern f32 func_003824E0(f32, f32);
    extern u8 *func_L01_003016B0(void *, s32, f32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C2880(u8 *);
    vu0_v4 ray, delta, origin;
    vu0_q impact;
    u8 *p = *(u8 **)(m + 0x68);
    s32 old, kind, cheap, small, surface, rest, next;
    vu0_v4 *position;
    u8 *spawned;
    if (func_L01_004CB2D8(m)) func_L01_004CAB30(m + 0x10, m + 0x10);
    switch (m[0x20]) {
    case 0:
        func_L01_004C8688(*(s32 *)(p + 0x4C), p, 0);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(vu0_v4 *)(m + 0x10)) : "m"(*(vu0_v4 *)p), "m"(*(vu0_v4 *)(m + 0x10)) : "vf1", "vf2");
        rest = D_L01_001DFB40 % 3;
        position = (vu0_v4 *)(m + 0x10);
        old = *(s32 *)(p + 0x34);
        next = old + 1;
        *(s32 *)(p + 0x34) = next;
        if (rest == 0 && next >= 9) {
            if ((u32)(old - 9) < 2) {
                D_L01_001E2A40.strength = 0.45f;
                D_L01_001E2A40.frames = 21;
                D_L01_001E2A40.timer = 0;
            }
            kind = D_L01_002C5600[D_0014263F[0] * 240 + 1];
            func_L01_004C7D98(position, &ray);
            func_0038CF68(&ray, &ray, -10.0f);
            func_0038CF68(&delta, p, -6.0f);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(origin) : "m"(delta), "m"(*(vu0_v4 *)(m + 0x10)) : "vf1", "vf2");
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(ray) : "m"(ray), "m"(origin) : "vf1", "vf2");
            if (func_003D3CB0(&origin, &ray, 0, m, 0)) {
                impact = D_L01_001EAA20;
                small = kind < 4;
                cheap = D_L01_001D673C == 0;
                if (!small) {
                    func_L01_00395020(&impact);
                    func_L01_003303B8(&impact, 0.5f, 0.0f, 0.0f, 2.0f, 0, 2, 2, 2, 5, 2, 0, cheap, 0, 0, 0, 0, 0, 0x10000, 0, 0x00FF2E10, 0x00FF8020, 0x00FF7F40, 0x00FF3020, 0x00FF8F5F, 0x00FF8020, 0x7FFF3030, 0x28FF8020, 0x00FF8040, 0);
                    func_L01_00446780(m, &impact, 0x210000, 0, 1, 0, 2.0f, *(f32 *)(p + 0x3C) * 0.5f, 0.5f);
                } else {
                    func_L01_003303B8(&impact, 0.5f, 0.0f, 0.0f, 2.0f, 0, 2, 2, 2, 5, 2, 0, cheap, 0, 0, 0, 0, 0, 0x10000, 0, 0x00FF2E10, 0x00FF8020, 0x00FF7F40, 0x00FF3020, 0x00FF8F5F, 0x00FF8020, 0x7FFF3030, 0x28FF8020, 0x00FF8040, 0);
                    func_L01_00446780(m, &impact, 0x210000, 0, 1, 0, 2.0f, *(f32 *)(p + 0x3C) * 0.5f, 0.5f);
                }
                surface = func_003D5630();
                if ((u32)surface >= 2 && surface != 11) func_L01_00395288(&impact, !small);
                spawned = func_L01_003016B0(&impact, 5, func_003824E0(3.5f, 4.5f), 1.04f);
                if (spawned) {
                    if (!small) func_L01_0043B9E8(spawned, 64, 16, 255);
                    else func_L01_0043B9E8(spawned, 16, 16, 255);
                }
            }
        }
        if (*(s32 *)(p + 0x34) >= 34 || *(f32 *)(m + 0x10) < 2.0f || *(f32 *)(m + 0x10) > 1021.0f ||
            *(f32 *)(m + 0x14) < 2.0f || *(f32 *)(m + 0x14) > 1021.0f ||
            *(f32 *)(m + 0x18) < 2.0f || *(f32 *)(m + 0x18) > 1021.0f) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        func_L01_004C8668(*(s32 *)(p + 0x4C));
        func_003C2880(m);
        break;
    }
}
/* localdecomp:end func_L01_00394AF0 */
