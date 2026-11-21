#include "common.h"

/* NTSC-U counterpart of func_L01_003D25D8 (src/levels/shared/L01_003D0D48.c): launch speed 0.3f (60 Hz) for PAL's 0.36f; level data at its NTSC-U addresses */
/* localdecomp:start func_L01_003D0C28 */
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_L01_001E0180;
extern f32 D_L01_001E2AC0[];
extern f32 D_L01_001DF3C0;
__asm__(".extern D_L01_001DF3C0, 4");
extern f32 D_L01_001DF3C4;
__asm__(".extern D_L01_001DF3C4, 4");
extern f32 D_L01_001DF3C8;
__asm__(".extern D_L01_001DF3C8, 4");
extern f32 D_L01_001DF3CC;
__asm__(".extern D_L01_001DF3CC, 4");
extern f32 D_L01_001DF3D0;
__asm__(".extern D_L01_001DF3D0, 4");
extern f32 D_L01_001DF3D4;
__asm__(".extern D_L01_001DF3D4, 4");
extern f32 D_L01_001DF3D8;
__asm__(".extern D_L01_001DF3D8, 4");
extern f32 D_L01_001DF3DC;
__asm__(".extern D_L01_001DF3DC, 4");
extern f32 D_L01_001DF3E0;
__asm__(".extern D_L01_001DF3E0, 4");
extern f32 D_L01_001DF3E4;
__asm__(".extern D_L01_001DF3E4, 4");
extern f32 D_L01_001DF3E8;
__asm__(".extern D_L01_001DF3E8, 4");
extern f32 D_L01_001DF3EC;
__asm__(".extern D_L01_001DF3EC, 4");
extern f32 D_L01_001DF3F0;
__asm__(".extern D_L01_001DF3F0, 4");
extern f32 D_L01_001DF3F4;
__asm__(".extern D_L01_001DF3F4, 4");

void func_L01_003D0C28(u8 *obj,u8 *state,void *target)
{
    extern f32 func_003887A0(void *);
    extern f32 func_00388A28(f32,f32);
    extern f32 func_00389468(f32,f32);
    extern f32 func_00389380(f32,f32);
    extern void func_00388BD0(void *,void *);
    extern void func_00388830(void *,void *,f32);
    extern void func_003886E8(f32 *,f32 *,f32);
    extern f32 func_0037E250(f32,f32);
    extern f32 func_L01_00440918(f32,f32);
    extern void *func_L01_00438488(s32,s32,s32);
    vu0_v4 pos,rot,vel,matrix[3],delta,angles,hero;
    f32 floor,angle,pitch,spread,limit;
    floor=*(f32 *)((*(s32 *)(state+4)<<7)+D_L01_001E0180+0x38)+*(f32 *)(state+0x3C);
    if(target==D_001A4BE0.hero_moby && *(s32 *)(state+0x5C)!=-1) {
        vec_sub_ba(&delta,(void *)((*(s32 *)(state+0x5C)<<7)+D_L01_001E0180+0x30),&D_001A4BE0.pos);
        pitch=func_00388A28(func_003887A0(&delta),delta.z);
        angle=func_00389468(D_L01_001E2AC0[5],-pitch);
        if(D_L01_001DF3DC*0.017453292f<angle) {
            qzero(&angles);
            angles.y=func_00389380(D_L01_001E2AC0[5],D_L01_001DF3DC);
            angles.z=func_00388A28(delta.x,delta.y);
            func_00388BD0(matrix,&angles);
            *(u128_t *)&delta=*(u128_t *)matrix;
        }
        func_00388830(&delta,&delta,D_L01_001DF3D8);
        vec_add_ba(&pos,&delta,&D_001A4BE0.pos);
        spread=func_0037E250(D_L01_001DF3E0*0.017453292f,D_L01_001DF3E4*0.017453292f);
        limit=D_L01_001DF3DC*0.017453292f;
        if(limit*0.3f<angle) spread*= (angle-limit*0.3f)/(limit*0.7f);
    } else {
        func_003886E8((f32 *)&pos,(f32 *)(obj+0xC0),func_0037E250(D_L01_001DF3C0,D_L01_001DF3C4));
        pitch=func_L01_00440918(D_L01_001DF3C8,D_L01_001DF3CC);
        if(target==D_001A4BE0.hero_moby) pitch*=0.25f;
        func_003886E8((f32 *)&delta,(f32 *)(obj+0xD0),pitch);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tlqc2 $vf1, %3\n\tsqc2 $vf1, %1\n\tsqc2 $vf2, %0\n\tlqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(pos), "=m"(hero) : "m"(delta), "m"(D_001A4BE0.pos) : "vf1","vf2");
        if(target && target!=D_001A4BE0.hero_moby)
            pos.z-=func_0037E250(D_L01_001DF3D0,D_L01_001DF3D4)*0.5f;
        else pos.z-=func_0037E250(D_L01_001DF3D0,D_L01_001DF3D4);
        if(target==D_001A4BE0.hero_moby)
            spread=func_0037E250(D_L01_001DF3E0*0.017453292f,D_L01_001DF3E4*0.017453292f);
        else spread=func_0037E250(D_L01_001DF3E8*0.017453292f,D_L01_001DF3EC*0.017453292f);
    }
    if(pos.z<floor) {
        if(D_001A4BE0.pos.z-floor<64.0f) return;
        if(target==D_001A4BE0.hero_moby && D_L01_001DF3D8*0.3f<floor-pos.z) return;
        pos.z=floor;
    }
    qzero(&rot);
    rot.y=spread;
    if(target)
        rot.z=func_00389380(*(f32 *)(obj+0xF8),func_0037E250(D_L01_001DF3F0*0.017453292f,D_L01_001DF3F4*0.017453292f));
    else
        rot.z=func_00389380(*(f32 *)(obj+0xF8),(func_0037E250(D_L01_001DF3F0*0.017453292f,D_L01_001DF3F4*0.017453292f)+3.1415927f)*0.5f);
    func_00388BD0(matrix,&rot);
    func_003886E8((f32 *)&vel,(f32 *)matrix,0.3f);
    (*(s32 (**)(void *,void *,void *,void *,f32))func_L01_00438488(7556,0,4))(obj,target,&pos,&vel,(f32)*(s32 *)(state+0x48));
}
/* localdecomp:end func_L01_003D0C28 */
