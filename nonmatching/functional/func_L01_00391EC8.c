/* functional: high. 32 diff = scheduling only. D_L01_0029F1E0 is typed Effect_00391BD0[] in file context so cast to local Effect_00391EC8; verified slot stride 0x50, owner at +0x44, gp 0x1744 arg */
#include "common.h"
#include "vu0.h"
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x10];
    f32 radius0, radius1, unk28, scale;
    s32 unk30, strength, color, unk3C, unk40;
    u8 *owner;
    s32 unk48, unk4C;
} Effect_00391EC8;
__asm__(".extern D_001DDFF4_sda, 4");
extern s32 D_001DDFF4_sda;
void func_L01_00391EC8(u8 *owner) {
    extern void func_L01_00392130(void *, f32, s32, s32, f32, s32, s32, f32);
    Effect_00391EC8 *p;
    vu0_v4 pos;
    p = (Effect_00391EC8 *)D_L01_0029F1E0;
    do {
        if (p->owner == owner) {
            __asm__ volatile ("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(pos) : "m"(p->pos), "m"(*(vu0_v4 *)(owner + 0x10)) : "vf1", "vf2");
            func_L01_00392130(&pos, p->radius0, 0x7F7F7F, p->strength, p->scale, D_001DDFF4_sda, 2, 0.001f);
            func_L01_00392130(&pos, p->radius1, p->color, p->strength >> 1, p->scale, D_001DDFF4_sda, 2, 0.001f);
        }
        p++;
    } while ((s32)p < (s32)D_L01_0029F1E0 + 0x2800);
}
