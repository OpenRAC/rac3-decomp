/* functional: high. Per-frame update of the hero-attached camera: samples the current pose (func_003C47E8), sets the per-player view-tilt D_001D5FF0 from the camera-setting table, eases the vertical offset cam+0x98 toward the per-player target (rate limited by D_001DF6C4*0.02, snapping to 0 when the target is 0), builds the look direction from the target plus the player table entry (w = angle diff from func_0038DAB8), runs the camera sub-steps (4580, 6120, 5828, A648, 5E50), then while follow+0x10F (signed byte) is positive decrements it and blends from the old pose to the new one (func_0038D6C8/D830/D590) and copies the basis to +0x40, else clears follow+0x10E. Constants, gp globals and calls checked against PAL asm */
#include "vu0.h"
extern u8 D_001439F4[];
extern s32 D_00143AD0[][8];
extern f32 D_L01_001D5FF0[2];
extern Ent1120 D_L01_001E2C00[];
extern u8 D_L01_001E2E50[];
extern f32 D_001DF6C4_sda;
extern s32 D_001DF658_sda;
extern f32 D_001DF65C_sda;
extern s32 D_L01_001D673C;
__asm__(".extern D_001DF6C4_sda, 4");
__asm__(".extern D_001DF658_sda, 4");
__asm__(".extern D_001DF65C_sda, 4");
void func_L01_003EA6E8(u8 *cam)
{
    extern void func_003C47E8(void *,void *);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_L01_003E4580(u8 *,void *);
    extern void func_L01_003E6120(u8 *);
    extern void func_L01_003E5828(u8 *);
    extern void func_L01_003EA648(u8 *);
    extern void func_L01_003E5E50(Update_3E5E50 *);
    extern void func_0038D6C8(void *,void *,void *,f32);
    extern void func_0038D830(void *,void *);
    extern void func_0038D590(void *,void *);
    vu0_v4 old;
    vu0_v4 blended;
    vu0_v4 fresh;
    vu0_v4 direction;
    vu0_v4 target;
    f32 matrix[4][4];
    u8 *follow=*(u8 **)(cam+0x70)+0x60;
    f32 delta;
    u8 *row;
    f32 angle;
    func_003C47E8(&old,cam);
    D_L01_001D5FF0[*(s32 *)(cam+0x94)] = (f32)D_00143AD0[D_001439F4[0]][0]/100.0f*0.05672320351f+0.021816615f;
    *(u128_t *)&target=*(u128_t *)&D_L01_001E2C00[*(s32 *)(cam+0x94)];
    delta=target.z-*(f32 *)(cam+0x98);
    if(delta>0.0f) {
        f32 limit=D_001DF6C4_sda*0.0200000014f;
        if(delta>limit) delta=limit;
    } else if(delta<0.0f) {
        f32 limit=- (D_001DF6C4_sda*0.0200000014f);
        if(delta<limit) delta=limit;
    }
    *(f32 *)(cam+0x98)+=delta;
    if(target.z==0.0f && fabs_asm(*(f32 *)(cam+0x98))<=D_001DF6C4_sda*0.0200000014f)
        *(f32 *)(cam+0x98)=0.0f;
    target.z=*(f32 *)(cam+0x98);
    row=(*(s32 *)(cam+0x94)*1120)+(D_L01_001E2E50-0x410);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
      : "=m"(direction) : "m"(target),"m"(*(vu0_v4 *)(row+0x410)) : "vf1","vf2");
    angle=*(f32 *)(row+0x1cc);
    if(D_L01_001D673C) angle=0.0f;
    direction.w=func_0038DAB8(angle,*(f32 *)(row+0x41c));
    func_L01_003E4580(cam,&direction);
    func_L01_003E6120(cam);
    func_L01_003E5828(cam);
    func_L01_003EA648(cam);
    func_L01_003E5E50((Update_3E5E50 *)cam);
    if(*(s8 *)(follow+0x10f)>0) {
        follow[0x10f]--;
        func_003C47E8(&fresh,cam);
        func_0038D6C8(&blended,&old,&fresh,D_001DF65C_sda+(1.0f-D_001DF65C_sda)*(1.0f-(f32)*(s8 *)(follow+0x10f)/(f32)D_001DF658_sda));
        func_0038D830(&blended,matrix);
        func_0038D590(cam,matrix);
        *(u128_t *)(cam+0x40)=*(u128_t *)cam;
    } else follow[0x10e]=0;
}
