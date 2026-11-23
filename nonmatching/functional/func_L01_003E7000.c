/* functional: high. Camera follow-state init for object obj (skipped when obj+0x86 is nonzero): seeds look/spring/target vectors in the follow block (obj+0x70) from the per-player D_001E2B90 table entry and the unit direction; all vector stores mirror retail, only VU0 scheduling differs */
#include "vu0.h"
extern u8 D_L01_001E2B90[];
void func_L01_003E7000(u8 *object) {
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    f32 direction[4] __attribute__((aligned(16)));
    f32 temp[4] __attribute__((aligned(16)));
    f32 dot;
    u8 *entry;
    u8 *follow;
    Look_3E5E50 *look;
    Springs_3E5E50 *springs;
    if (*(s16 *)(object+0x86)!=0) return;
    entry=D_L01_001E2B90+*(s32 *)(object+0x94)*0x460;
    follow=*(u8 **)(object+0x70);
    springs=(Springs_3E5E50 *)(follow+0x180);
    look=(Look_3E5E50 *)(follow+0x60);
    func_0038CE20(direction,(f32 *)(entry+0x80),-1.0f);
    *(u128_t *)(follow+0xC0)=*(u128_t *)look=*(u128_t *)(entry+0x40);
    dot=func_0038CE68((f32 *)look,direction);
    func_0038CE20((f32 *)(follow+0x70),direction,dot);
    qzero(follow+0xF0);
    qzero(follow+0x100);
    qzero(follow+0x120);
    func_0038CE20(temp,direction,springs->height);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(follow+0xB0)) : "m"(*(vu0_v4 *)(temp)), "m"(*(vu0_v4 *)(look)) : "vf1", "vf2");
    func_0038CE20(temp,direction,look->height);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(follow+0x110)) : "m"(*(vu0_v4 *)(temp)), "m"(*(vu0_v4 *)(look)) : "vf1", "vf2");
    *(u128_t *)(follow+0xA0)=*(u128_t *)(follow+0x110);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(springs)) : "m"(*(vu0_v4 *)(object+0x30)), "m"(*(vu0_v4 *)(follow+0xB0)) : "vf1", "vf2");
    *(u128_t *)(follow+0x190)=*(u128_t *)springs;
    *(u128_t *)follow=*(u128_t *)(object+0x30);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(follow+0x230)) : "m"(*(vu0_v4 *)(follow+0xB0)), "m"(*(vu0_v4 *)(springs)) : "vf1", "vf2");
    *(s32 *)(follow+0x260)=0;
}
