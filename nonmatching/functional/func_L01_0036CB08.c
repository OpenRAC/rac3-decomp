/* functional: high. Draft near miss (209 words, VU0 scheduling/frame size); every arg, offset, constant, loop bound and callee re-verified against PAL asm; vf adds kept as VU0 inline asm. */
#include "common.h"
/* localdecomp:start func_L01_0036CB08 */
#include "vu0.h"
extern u8 D_001A52A0[];
void func_L01_0036CB08(void *unused, vu0_q *input) {
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_004669B0(void *, s32, void *, s32, s32, f32, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern u32 func_L01_00448D88(u32, s32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00465738(void *, void *, u32, u32, s32, s32, s32, s32, s32, f32);
    struct { vu0_q matrix; vu0_v4 direction, base, position, velocity, point, inherited, offset, extra; } local;
    u8 *basis=D_001A52A0;
    u8 *hero=basis-0x6C0;
    u8 *particle,*vars;
    u8 *source;
    s32 i, spin, life;
    f32 angle=0.0f, pitch, heading, radius;
    u32 head,tail;
    *(vu0_q *)&local.base=0;
    *(vu0_q *)&local.position=*input;
    local.base.y=-1.0f;
    local.base.x=0.3f;
    local.base.w=1.0f;
    func_0038D890(&local.base,basis,basis+0x10,0.3490658402442932f);
    local.direction=local.base;
    qzero(&local.inherited);
    if(*(s32 *)(hero+0x360)) func_0038CE20(&local.inherited,hero+0x110,1.7f);
    func_0038CE20(&local.offset,basis,0.4f);
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(local.position) : "m"(local.offset) : "vf1", "vf2");
    source=hero+0x110;
    for(i=19;i>=0;i--) {
        angle=func_0038DAB8(angle,func_003824E0(0.0f,0.6283185482025146f));
        func_0038CE20(&local.velocity,&local.direction,func_003824E0(0.24000000953674316f,0.320000022649765f));
        __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(local.velocity) : "m"(local.inherited) : "vf1", "vf2");
        local.point.x=local.position.x+func_L01_00443A18(0.0f,0.3f);
        local.point.y=local.position.y+func_L01_00443A18(0.0f,0.3f);
        local.point.z=local.position.z+func_L01_00443A18(0.0f,0.3f);
        spin=(s32)func_L01_00443A18(1.0f,2.0f);
        particle=func_L01_004669B0(&local.point,spin,source,0x7FFFFFFF,0,0.0f,1.0f,1.01f,func_003824E0(0.2f,0.75f)*210000.0f);
        if(particle) {
            *(s16 *)(particle+0xA)=50;
            particle[3]=0x48;
            vars=particle+0x20;
            particle[9]=0x44;
            *(f32 *)(vars+0x1C)=4.0f;
            *(s32 *)(vars+4)=3;
            vars[0xA]=0x30;
            vars[0xB]=particle[0xA];
        }
        local.point.x=local.position.x+func_L01_00443A18(0.0f,0.6f);
        local.point.y=local.position.y+func_L01_00443A18(0.0f,0.6f);
        local.point.z=local.position.z+func_L01_00443A18(0.0f,0.6f);
        radius=func_003824E0(0.2f,1.75f);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(local.point) : "m"(local.velocity) : "vf1", "vf2");
        func_L01_0046A610(&local.point,&local.velocity,5,127,0x404040,spin,radius*210000.0f,500.0f,0.95f,0.0f,0.0f);
        if (fabs_asm(angle)>0.00001f) {
            func_003C4840(&local.matrix,source+0x5B0,angle);
            func_0038D850(&local.direction,&local.base,&local.matrix);
        }
    }
    func_0038CE20(&local.base,source+0x5B0,func_003824E0(8.0f,12.0f)*0.020000001415610313f);
    for(i=1;i>=0;i--) {
        pitch=func_003824E0(0.2617993950843811f,1.3962633609771729f);
        heading=func_00382538();
        radius=func_003824E0(7.0f,10.5f)*0.020000001415610313f;
        func_00382760(&local.extra,0.5f*radius,heading,pitch);
        __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(local.extra) : "m"(local.base) : "vf1", "vf2");
        local.extra.z+=0.06000000238418579f;
        head=func_L01_00448D88(0x4F007FFF,0);
        tail=func_L01_00448D88(0x1F00007F,0);
        life=func_00382498(50,100);
        func_L01_00465738(input,&local.extra,head,tail,life,1,-1,-1,0,0.5f*40000.0f);
    }
}
/* localdecomp:end func_L01_0036CB08 */
