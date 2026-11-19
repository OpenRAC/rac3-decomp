/* functional: high. 112 diff words are scheduling/regalloc; VU0 vadd kept as inline asm; constants and offsets checked vs asm */
#include "common.h"
/* localdecomp:start func_L01_004CA478 */
#include "vu0.h"
typedef struct { u8 alpha; u8 pad1; u8 type; u8 pad3[6]; u8 layer; } P_004CA478;
extern Vec4_004C4AD8 D_L01_001E29E0;
extern u8 D_L01_001E1134 __attribute__((section(".data")));
extern s16 D_L01_001E1102;
extern f32 D_L01_001E1104;
extern f32 D_001DB028_sda;
__asm__(".extern D_001DB028_sda, 4");
extern Vec4_004C4AD8 D_L01_001D66B0;
extern u8 *D_L01_0022116C;
static __inline__ void emit_004CA478(Vec4_004C4AD8 *pos, f32 scale, u32 color, s32 phase) {
    extern P_004CA478 *func_L01_0046FB40(void *,void *,f32,f32,f32,s32,u32,s32,s32,s32,s32);
    P_004CA478 *p = func_L01_0046FB40(pos,&D_L01_001D66B0,scale,scale,0.0f,3,color,phase,127,127,0);
    if (p) {
        u8 type;
        p->alpha = 255;
        type = D_L01_0022116C[0];
        p->layer = 64;
        p->type = type;
    }
}
void func_L01_004CA478(void) {
    extern void func_0038CE20(Vec4_004C4AD8 *,Vec4_004C4AD8 *,f32);
    extern void func_0038CDF8(void *,void *,void *,f32);
    Vec4_004C4AD8 temp;
    Vec4_004C4AD8 far;
    Vec4_004C4AD8 near;
    Vec4_004C4AD8 pos;
    Vec4_004C4AD8 *direction = &D_L01_001E29E0;
    s32 phase = D_L01_001E1134;
    f32 scale;
    func_0038CE20(&temp, direction, 9.0f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(far) : "m"(temp), "m"(*(Vec4_004C4AD8 *)((u8 *)direction - 0x20)) : "vf1", "vf2");
    func_0038CE20(&temp, direction, 0.1f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(near) : "m"(temp), "m"(*(Vec4_004C4AD8 *)((u8 *)direction - 0x20)) : "vf1", "vf2");
    func_0038CDF8(&pos, &near, &far, (f32)D_L01_001E1102 * D_L01_001E1104);
    scale = D_001DB028_sda * 210000.0f;
    emit_004CA478(&pos, scale, 0x804020, phase);
    phase = (phase + 128) % 255;
    emit_004CA478(&pos, scale, 0x804020, phase);
    scale *= 0.5f;
    emit_004CA478(&pos, scale, 0xBFBFBF, phase);
    D_L01_001E1134++;
}
/* localdecomp:end func_L01_004CA478 */
