/* functional: high. Draft near miss (24 words, VU scheduling/regalloc). Re-derived the 4-way branch tree (A=hero+0x2874, state==29, B=+0x16B0, C=+0x1430) from the asm; matches. Constants, offsets, callees verified. */
#include "common.h"
/* localdecomp:start func_L01_0036F120 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_0036F120;
typedef struct {
    u8 pad0[0x10]; void *target; u8 pad14[0x30-0x14];
    Vec_0036F120 direction, endpoint;
} Vars_0036F120;
typedef struct {
    u8 pad0[0x1430]; s32 f1430; u8 pad1434[0x16B0-0x1434]; s32 f16B0;
    u8 pad16B4[0x16D4-0x16B4]; s32 f16D4,f16D8;
    u8 pad16DC[0x25C0-0x16DC]; u8 *f25C0; s32 f25C4;
    u8 pad25C8[0x2874-0x25C8]; s16 f2874;
} Hero_0036F120;
extern Hero_0036F120 D_001A4BE0;
extern Vec_0036F120 D_L01_001E29E0;
static __inline__ void sub_0036F120(Vec_0036F120 *d,Vec_0036F120 *a,Vec_0036F120 *b) {
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
      : "=m"(*d) : "m"(*a), "m"(*b) : "vf1","vf2");
}
static __inline__ void add_0036F120(Vec_0036F120 *d,Vec_0036F120 *a,Vec_0036F120 *b) {
    __asm__("lqc2 $vf1, %1
	lqc2 $vf2, %2
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
      : "=m"(*d) : "m"(*a), "m"(*b) : "vf1","vf2");
}

void func_L01_0036F120(u8 *moby) {
    extern void func_003C2F58(s32,s32,void *);
    extern void func_L01_004CB128(void *,void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_00397A28(void *,void *,void *,void *,void *);
    Vec_0036F120 pos, target;
    Vars_0036F120 *v = *(Vars_0036F120 **)(moby+0x68);
    u8 *shot;
    func_003C2F58((s32)moby,0,&pos);
    if(v->target) {
        func_L01_004CB128(&target,v->target,0);
        sub_0036F120(&v->direction,&target,&pos);
        func_0038CF68(&v->direction,&v->direction,20.0f);
        add_0036F120(&v->endpoint,&v->direction,&pos);
    }
    if(D_001A4BE0.f2874 && D_001A4BE0.f25C4!=29 &&
       (!D_001A4BE0.f16B0 || D_001A4BE0.f1430)) {
        func_0038CF68(&v->direction,moby+0xD0,-20.0f);
        add_0036F120(&v->endpoint,&v->direction,&pos);
        D_001A4BE0.f16D8=0;
        D_001A4BE0.f16D4=0;
    } else if(D_001A4BE0.f25C4==29 ||
       (D_001A4BE0.f16B0 && !D_001A4BE0.f1430)) {
        func_0038CF68(&v->direction,&D_L01_001E29E0,20.0f);
        add_0036F120(&v->endpoint,&v->direction,&pos);
    } else if(D_001A4BE0.f25C4==29 ||
       (D_001A4BE0.f16B0 && D_001A4BE0.f1430)) {
        func_L01_004CB128(&target,v->target,0);
        sub_0036F120(&v->direction,&target,&pos);
        func_0038CF68(&v->direction,&v->direction,20.0f);
        add_0036F120(&v->endpoint,&v->direction,&pos);
    } else if(!v->target) {
        func_0038CF68(&v->direction,D_001A4BE0.f25C0+0xC0,20.0f);
        add_0036F120(&v->endpoint,&v->direction,&pos);
    }
    shot=func_L01_00397A28(moby,&pos,v->target,&v->direction,&v->endpoint);
    if(shot) *(u8 **)(shot+0xB8)=moby;
}
/* localdecomp:end func_L01_0036F120 */
