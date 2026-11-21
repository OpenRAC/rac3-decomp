/* functional: medium. Hero hit/damage handler: aligned diff is block layout (branch/jump placement), delay-slot fill and lui rematerialisation only; instruction multiset otherwise equal. VU0 inline asm per the rules. */
#include "common.h"
/* localdecomp:start func_L01_004ED8A8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x10];
    vu0_v4 direction;
    u8 *source;
    u32 flags;
    u8 type;
    u8 pad29[3];
    f32 damage;
    u32 mode;
    u32 pad34;
    u8 *moby;
    u32 pad3C;
} Hit_004ED8A8;
typedef struct {
    u8 pad0[0x80];
    vu0_v4 position;
    u8 pad90[0x14C];
    s16 cooldown;
    u8 pad1DE[0x3E];
    s16 timer;
    u8 pad21E[0x16];
    s32 giant;
    u8 pad238[0x3F6];
    s16 hit_flag;
    u8 pad630[0x34];
    Hit_004ED8A8 * hit;
    u8 pad668[0xE11];
    u8 ground;
    u8 pad147A[0x236];
    s32 hand;
    u8 pad16B4[0xF0C];
    u8 * moby;
    s32 state;
    u8 pad25C8[0x4];
    s32 mode;
    u8 pad25D0[0x14];
    u8 kind;
    u8 pad25E5[0x223];
    u8 * source;
    u8 pad280C[0x44];
    s32 health;
} Hero_004ED8A8;
extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern s16 D_001426A0[];
extern char D_001A4CD0[];
extern s32 D_L01_001D6694;
extern Hit_004ED8A8 D_L01_001EEC80[];
s32 func_L01_004ED8A8(s32 apply) {
    extern s32 func_L01_0041A4F0(void);
    extern f32 func_L01_004C93D8(void);
    extern f32 func_L01_004C9360(f32);
    extern f32 func_L01_004DFE88(s32);
    extern void func_L01_004E1560(void);
    extern void func_L01_005110E8(s32, s32, f32, f32, f32);
    extern void func_L01_005003D0(s32, s32);
    extern u8 *func_L01_00447490(u8 *, s32, s32);
    extern void func_L01_004DFEA0(s32 damage);
    extern void func_L01_003F1F20(s32, s32);
    extern void func_L01_004F4E70(s32, s32);
    extern void func_L01_004ED838(s32 a0, s32 a1, f32 f12, f32 f13);
    extern void func_L01_00511618(s32, s32, f32);
    vu0_v4 delta;
    vu0_v4 kept;
    Hero_004ED8A8 *hero=(Hero_004ED8A8 *)D_001A4BE0;
    Hit_004ED8A8 *hit;
    u8 *moby;
    if (hero->mode==20 || hero->mode==7) return 0;
    if (hero->state==0x74) return 0;
    if (hero->state==0x31 || hero->cooldown!=0 || D_L01_001D6694!=0) return 0;
    hero->source=0;
    moby=hero->moby;
    if (moby[0xA8]==255) return 0;
    hit=&D_L01_001EEC80[moby[0xA8]];
    if (hit->moby!=moby || !(hit->flags&9) || hero->giant) return 0;
    if (hit->damage!=0.0f && func_L01_0041A4F0() && hero->kind!=5) {
        D_00142660[0x5A]=0;
        D_00142660[0x5B]=0;
    }
    if (func_L01_004C93D8()!=0.0f && ((Hero_004ED8A8 *)D_001A4BE0)->kind==0 && !(hit->flags&0x20000000)) {
        if ((hit->damage=func_L01_004C9360(hit->damage))==0.0f) return 0;
    }
    if ((hit->flags&0x20000000) && ((Hero_004ED8A8 *)D_001A4BE0)->kind==0) {
        s32 n=D_001426A0[0];
        if (n>4) n=4;
        if (n<0) n=0;
        hit->damage/=func_L01_004DFE88(n);
    }
    ((Hero_004ED8A8 *)D_001A4BE0)->source=hit->source;
    if (((Hero_004ED8A8 *)D_001A4BE0)->mode==15) {
        ((Hero_004ED8A8 *)D_001A4BE0)->hit=hit;
        ((Hero_004ED8A8 *)D_001A4BE0)->hit_flag=1;
        return 0;
    }
    if (apply) {
        s32 special=0;
        func_L01_004E1560();
        if (hit->mode&1) {
            delta=hit->direction;
            if (hit->direction.w==5627.9248046875f) special=1;
        } else if (hit->source) {
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(((Hero_004ED8A8 *)D_001A4BE0)->position), "m"(*(vu0_v4 *)(hit->source+0x10)) : "vf1", "vf2");
        } else {
            func_L01_005110E8((s32)&delta,0,-1.0f,0.0f,0.0f);
        }
        switch (((Hero_004ED8A8 *)D_001A4BE0)->kind) {
        case 0:
            if (((Hero_004ED8A8 *)D_001A4BE0)->source) {
                s32 type=*(s16 *)(((Hero_004ED8A8 *)D_001A4BE0)->source+0xAA);
                if (type==0x4EB || type==0x558 || type==0x1C5F) {
                    func_L01_005003D0(0x82,1);
                    return 1;
                }
            }
            if ((((Hero_004ED8A8 *)D_001A4BE0)->state==1 || ((Hero_004ED8A8 *)D_001A4BE0)->state==29 || ((Hero_004ED8A8 *)D_001A4BE0)->hand==2) && !(hit->flags&8)) {
                u8 *d=func_L01_00447490(((Hero_004ED8A8 *)D_001A4BE0)->moby,1,0);
                if (d) func_L01_004DFEA0(*(f32 *)(d+0x2C));
                if (((Hero_004ED8A8 *)D_001A4BE0)->health==0) func_L01_005003D0(0x16,1);
                else func_L01_003F1F20(0x12,0);
                ((Hero_004ED8A8 *)D_001A4BE0)->cooldown=64;
                if (((Hero_004ED8A8 *)D_001A4BE0)->timer==0) ((Hero_004ED8A8 *)D_001A4BE0)->timer=15;
                func_L01_004F4E70(20,0);
                return 0;
            }
            if (((Hero_004ED8A8 *)D_001A4BE0)->mode==18) func_L01_005003D0(0x77,1);
            else if (((Hero_004ED8A8 *)D_001A4BE0)->mode==17) func_L01_005003D0(0x78,1);
            else if (hit->flags&8) func_L01_005003D0(0x91,1);
            else func_L01_005003D0(0x16,1);
            if (((Hero_004ED8A8 *)D_001A4BE0)->state==0x91) {
                qzero(&delta);
            } else {
                f32 gain=0.06600000709295273f;
                if (((Hero_004ED8A8 *)D_001A4BE0)->ground) gain=0.0f;
                func_L01_004ED838((s32)&delta,special,gain,0.03400000184774399f);
                if (special && hit->type==4) func_L01_00511618((s32)&delta,(s32)&delta,2.0f);
            }
            break;
        case 1:
            func_L01_005003D0(0x42,1);
            func_L01_004ED838((s32)&delta,special,0.06000000238418579f,0.06000000238418579f);
            break;
        case 3:
            func_L01_005003D0(0x55,1);
            func_L01_004ED838((s32)&delta,special,0.10000000894069672f,0.04800000414252281f);
            break;
        }
        __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, 0(%3)\n\tsqc2 $vf1, %0\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, 0(%3)\n\tlqc2 $vf1, 32(%3)\n\tlqc2 $vf2, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 32(%3)" : "=m"(kept), "+m"(*(vu0_v4 (*)[3])D_001A4CD0) : "m"(delta), "r"(D_001A4CD0) : "vf1", "vf2");
    } else {
        if (((Hero_004ED8A8 *)D_001A4BE0)->cooldown==0) {
            u8 *d=func_L01_00447490(((Hero_004ED8A8 *)D_001A4BE0)->moby,1,0);
            if (d) func_L01_004DFEA0(*(f32 *)(d+0x2C));
            else func_L01_004DFEA0(1);
            ((Hero_004ED8A8 *)D_001A4BE0)->cooldown=64;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_004ED8A8 */
