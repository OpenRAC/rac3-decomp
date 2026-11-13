/* func_L14_0040F1B8: near miss, 98 diff: needs the divs_nops row "func_L14_0040F1B8 2" (file already VU0 + @ps2as); blocked: retail reads the 16-byte .lit vectors D_L14_001D6BE0/6BF0 through $gp (addiu $gp, lqc2/lq off $gp), which no assembler does for a 16-byte symbol under -G8 (section(".sdata") gives the lui $at macro); also left: vsub operand registers (vf1/vf2 swapped)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
extern vu0_v4 D_L14_001E20C0;
extern u8 D_L14_001EF150[];
extern vu0_v4 D_L14_001D6BE0 __attribute__((section(".sdata")));
extern vu0_v4 D_L14_001D6BF0 __attribute__((section(".sdata")));
extern f32 D_L14_001D6C1C;
__asm__(".extern D_L14_001D6C1C, 4");
extern void func_003C4C18(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
void func_L14_0040F1B8(u8 *a0, u32 idx) {
    u8 *e;
    u8 *v;
    u8 *r;
    vu0_v4 tmp;
    vu0_v4 z;
    f32 t;
    if (idx < 15) {
        e = D_L14_001EF150 + idx * 0x30;
        if (*(s32 *)(e + 0x24) > 0) {
            return;
        }
        tmp = D_L14_001D6BE0;
        vec_add_ba(&tmp, &D_L14_001D6BE0, &D_L14_001D6BF0);
        v = D_L14_001EF150 + 0x10 + idx * 0x30;
        *(vu0_v4 *)e = tmp;
        vec_sub_ab(v, &D_L14_001E20C0, &tmp);
        func_003C4C18((f32 *)v, 40.0f);
        func_0038CF68(v, v, func_003824E0(40.0f, 60.0f));
        vec_add_ba(v, v, &tmp);
        *(f32 *)(e + 0x20) = func_003824E0(0.05f, 0.3f);
        *(s32 *)(e + 0x24) = 200;
        qzero(&z);
        r = func_L01_003F79D8(a0, 2, *(s16 *)(a0 + 0xAA), idx, a0 + 0x10, a0 + 0xF0, &z, 0xFF,
                              func_003824E0(-D_L14_001D6C1C, D_L14_001D6C1C), 0.0f, 0xB4, 0, 0x80);
        if (r != 0) {
            t = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
            *(f32 *)(r + 0x2C) = *(f32 *)(*(u8 **)(r + 0x24) + 0x24) * t + func_003824E0(0.0f, 0.1f);
        }
    }
}
