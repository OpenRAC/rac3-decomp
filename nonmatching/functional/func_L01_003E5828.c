/* functional: high. 308 diff vs retail (VU0/regs); every spring call arg, offset, constant (2.25,0.4,0.5,20,0.35,0.006) and both collision branches verified vs asm; stack layout of target/height swapped vs retail but used consistently */
/* localdecomp:start func_L01_003E5828 */
#include "vu0.h"
extern s32 D_L01_001DF810[];
extern vu0_v4 D_L01_001EAA20;
void func_L01_003E5828(u8 *cam) {
    extern void func_L01_003E4028(u8 *, u128_t *);
    extern void func_L01_003E48D8(Cam_3E48D8 *);
    extern void func_L01_003E4F20(u8 *, u128_t *);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CF00(f32 *, f32 *);
    extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
    extern void func_L01_0040E020(u8 *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_L01_003E5700(u8 *, s32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern f32 func_0038CEA8(f32 *);
    extern void func_L01_003E8C28(s32, f32, f32);
    vu0_v4 height, target[2], previous, velocity, position, offset, blend, probe, hit, delta, result;
    u8 *entry=(u8 *)&D_L01_001E2A40[*(s32 *)(cam+0x94)];
    u8 *follow=*(u8 **)(cam+0x70);
    u8 *motion=follow+0x60;
    u8 *height_point=follow+0x70;
    u8 *desired=follow+0xC0;
    u8 *basis=entry+0x60;
    u8 *axis=entry+0x90;
    s32 hero_address=(s32)(entry+0x150);
    u8 *springs=follow+0x180;
    float thickness, distance, t, a, b;
    u8 *hero_vars;
    func_L01_003E4028(cam,(u128_t *)&target[0]);
    func_L01_003E48D8((Cam_3E48D8 *)cam);
    func_L01_003E4F20(cam,(u128_t *)&height);
    *(vu0_q *)(height_point)=*(vu0_q *)&height;
    *(vu0_q *)&previous=*(vu0_q *)(follow+0x60);
    t=func_0038CE68((float *)axis,(float *)desired);
    func_0038CE20(&velocity,axis,t);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&position)) : "m"(*(vu0_v4 *)(desired)), "m"(*(vu0_v4 *)(&velocity)) : "vf1", "vf2");
    *(float *)(motion+0x110)=func_0038CF00((float *)&velocity,(float *)(height_point));
    velocity.x=func_00382BC8((float *)(follow+0x100),velocity.x,*(float *)(motion+0x10),*(float *)(motion+0x104),*(float *)(motion+0x108),0.0f);
    velocity.y=func_00382BC8((float *)(follow+0x104),velocity.y,*(float *)(motion+0x14),*(float *)(motion+0x104),*(float *)(motion+0x108),0.0f);
    velocity.z=func_00382BC8((float *)(follow+0x108),velocity.z,*(float *)(motion+0x18),*(float *)(motion+0x104),*(float *)(motion+0x108),0.0f);
    position.x=func_00382BC8((float *)(follow+0xF0),position.x,*(float *)(follow+0x60),*(float *)(motion+0xFC),*(float *)(motion+0x100),0.0f);
    position.y=func_00382BC8((float *)(follow+0xF4),position.y,*(float *)(motion+4),*(float *)(motion+0xFC),*(float *)(motion+0x100),0.0f);
    position.z=func_00382BC8((float *)(follow+0xF8),position.z,*(float *)(motion+8),*(float *)(motion+0xFC),*(float *)(motion+0x100),0.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(motion)) : "m"(*(vu0_v4 *)(motion)), "m"(*(vu0_v4 *)(height_point)) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(desired)) : "m"(*(vu0_v4 *)(&position)), "m"(*(vu0_v4 *)(&velocity)) : "vf1", "vf2");
    func_0038CE20(&offset,entry+0x80,*(float *)(motion+0xD0));
    if (motion[0xF9]) {
        motion[0xF8]++;
        if (*(s16 *)(motion+0x10C)<motion[0xF8]) motion[0xF8]=*(u8 *)(motion+0x10C);
        func_0038CDF8(&blend,motion,desired,(float)motion[0xF8]/(float)*(s16 *)(motion+0x10C));
    } else {
        func_L01_0040E020(follow+0x158);
        func_0038CDF8(&blend,motion,desired,(float)motion[0xF8]/(float)*(s16 *)(motion+0x10C));
    }
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(follow+0xA0)) : "m"(*(vu0_v4 *)(&offset)), "m"(*(vu0_v4 *)(&blend)) : "vf1", "vf2");
    func_L01_003E5700(cam,(s32)&offset);
    if (((u8 *)hero_address)[0x12B]==2) {
        func_0038CE20(&offset,basis+0x20,2.25f);
        axis=basis+0x20;
    } else if (((u8 *)hero_address)[0x12B]==1) {
        func_0038CE20(&offset,basis+0x20,0.4f);
        axis=basis+0x20;
    } else if (*(s32 *)(hero_address+0x104)==17) {
        qzero(&offset);
        axis=basis+0x20;
    } else {
        func_0038CE20(&offset,basis+0x20,0.5f);
        axis=basis+0x20;
    }
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&blend)) : "m"(*(vu0_v4 *)(&target[0])), "m"(*(vu0_v4 *)(&offset)) : "vf1", "vf2");
    func_0038CE20(&offset,axis,*(float *)(springs+0x30));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(motion+0x50)) : "m"(*(vu0_v4 *)(&offset)), "m"(*(vu0_v4 *)(motion)) : "vf1", "vf2");
    hero_vars=*(u8 **)(*(u8 **)((u8 *)&D_L01_001E2A40[*(s32 *)(cam+0x94)]+0x50)+0x70);
    thickness=*(float *)(hero_vars+0x254)* *(float *)(hero_vars+0x24C)*(*(float *)(hero_vars+0x250)-1.0f)+0.35f;
    func_0038CE20(&probe,axis,20.0f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&probe)) : "m"(*(vu0_v4 *)(&blend)), "m"(*(vu0_v4 *)(&probe)) : "vf1", "vf2");
    if (func_003D3CB0(&blend,&probe,D_L01_001DF810[*(s32 *)(cam+0x94)],*(u8 **)(hero_address+0xF0),0)) {
        *(vu0_q *)&hit=*(vu0_q *)&D_L01_001EAA20;
    } else {
        *(vu0_q *)&hit=*(vu0_q *)&probe;
    }
    func_0038CE20(&probe,axis,20.0f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&probe)) : "m"(*(vu0_v4 *)(&blend)), "m"(*(vu0_v4 *)(&probe)) : "vf1", "vf2");
    if (func_003D3CB0(&blend,&probe,D_L01_001DF810[*(s32 *)(cam+0x94)],*(u8 **)(hero_address+0xF0),0)) {
        *(vu0_q *)&probe=*(vu0_q *)&D_L01_001EAA20;
    }
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&delta)) : "m"(*(vu0_v4 *)(&probe)), "m"(*(vu0_v4 *)(&hit)) : "vf1", "vf2");
    if (func_0038CEA8((float *)&delta)<thickness+thickness) {
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&result)) : "m"(*(vu0_v4 *)(&hit)), "m"(*(vu0_v4 *)(&probe)) : "vf1", "vf2");
        func_0038CE20(&result,&result,0.5f);
    } else {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&delta)) : "m"(*(vu0_v4 *)(&hit)), "m"(*(vu0_v4 *)(motion)) : "vf1", "vf2");
        distance=*(float *)(springs+0x30);
        if (func_0038CEA8((float *)&delta)<=distance+thickness) {
            func_0038CE20(&result,axis,thickness);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&result)) : "m"(*(vu0_v4 *)(&hit)), "m"(*(vu0_v4 *)(&result)) : "vf1", "vf2");
        } else {
            a=func_0038CE68((float *)motion,(float *)(basis+0x30));
            b=func_0038CE68((float *)&probe,(float *)(basis+0x30));
            if (b<a) *(vu0_q *)&probe=*(vu0_q *)motion;
            func_0038CE20(&offset,axis,distance);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(motion+0x50)) : "m"(*(vu0_v4 *)(&offset)), "m"(*(vu0_v4 *)(&probe)) : "vf1", "vf2");
            return;
        }
    }
    *(vu0_q *)(motion+0x50)=*(vu0_q *)&result;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&delta)) : "m"(*(vu0_v4 *)(&result)), "m"(*(vu0_v4 *)(motion)) : "vf1", "vf2");
    func_L01_003E8C28(*(s32 *)(cam+0x94),func_0038CE68((float *)&delta,(float *)axis),0.006f);
}
/* localdecomp:end func_L01_003E5828 */
