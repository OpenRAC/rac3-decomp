/* functional: high. Block-scope extern with 3 args (file context declares 00511588 with 2). Scheduling only after alignment. */
#include "common.h"
/* localdecomp:start func_L01_004E7780 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
typedef struct {
    u8 p0[0x40]; u8 matrix[0x40]; vu0_v4 position; vu0_v4 rotation;
    u8 pA0[0xF0-0xA0]; vu0_v4 velocity;
    u8 p100[0x110-0x100]; vu0_v4 motion;
    u8 p120[0x1D4-0x120]; s32 next_state;
    u8 p1D8[0x210-0x1D8]; s16 timer;
    u8 p212[0x260-0x212]; vu0_v4 capsule;
    u8 p270[0x284-0x270]; f32 radius;
    u8 p288[0x2A4-0x288]; u8 contactA,contactB;
    u8 p2A6[0x2B4-0x2A6]; void *hit_moby;
    u8 p2B8[0x33C-0x2B8]; f32 f33C;
    u8 p340[0x4B0-0x340]; vu0_v4 normal;
    u8 p4C0[0x4CC-0x4C0]; f32 old_heading;
    u8 p4D0[0x4F0-0x4D0]; f32 gravity;
    u8 p4F4[0x528-0x4F4]; s32 disabled;
    u8 p52C[0x25C4-0x52C]; s32 state;
    u8 p25C8[4]; s32 mode;
    u8 p25D0[4]; s32 previous_mode;
    u8 p25D8[8]; s32 third_mode;
    u8 p25E4[0x25F4-0x25E4]; u8 special;
    u8 p25F5[0x285C-0x25F5]; s16 attached;
    u8 kind, blocked; f32 reach;
} Hero_004E7780;
typedef struct { u8 p0[0x18]; void *moby; s32 count; S_4E56A8vec position; u8 p30[16]; S_4E56A8vec normal; } Hit_004E7780;
extern Hit_004E7780 D_L01_001EAA00;
void func_L01_004E7780(void) {
    extern f32 func_L01_005114B0(void *);
    extern void func_L01_00511508(s32,s32,f32);
    extern void func_L01_00511588(s32,s32,f32);
    extern void func_L01_00511158(void *,void *,f32);
    extern s32 func_L01_004E8318(void *,void *,s32);
    extern s32 func_L01_004E63F0(s32,f32,f32);
    extern u8 *func_003C4D58(void *);
    extern void func_L01_00511038(void *,s32,f32,f32,f32);
    extern s32 func_003D3CB0(void *,void *,s32,s32,s32);
    extern s32 func_003D5630(void);
    extern f32 func_L01_00511848(void *);
    extern void func_0038D028(Vec4 *,void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DBA0(f32,f32);
    extern f32 func_0038CF38(S_4E56A8vec *,S_4E56A8vec *);
    extern void func_0038CF68(void *,s32,float);
    vu0_v4 pos;
    vu0_v4 delta;
    Vec4 local_normal;
    u8 *material;
    f32 distance, limit;
    s32 type;
    if ((*(Hero_004E7780 *)D_001A4BE0).f33C < 0.4f) return;
    if (func_L01_005114B0(&(*(Hero_004E7780 *)D_001A4BE0).velocity) < -0.40000003576278687f) return;
    if ((*(Hero_004E7780 *)D_001A4BE0).special || D_001D545C == 28) return;
    if ((*(Hero_004E7780 *)D_001A4BE0).disabled) { (*(Hero_004E7780 *)D_001A4BE0).next_state=0; return; }
    *(vu0_q *)&pos=*(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).position;
    *(vu0_q *)&delta=*(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).motion;
    func_L01_00511508((s32)&delta,(s32)&delta,0.0f);
    func_L01_00511588((s32)&delta,(s32)&delta,17.0f);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(pos) : "m"(pos),"m"(delta) : "vf1","vf2");
    func_L01_00511158(&pos,&pos,func_L01_005114B0(&(*(Hero_004E7780 *)D_001A4BE0).velocity)*17.0f-(*(Hero_004E7780 *)D_001A4BE0).gravity*17.0f*17.0f*0.5f);
    if (func_L01_004E8318(&pos,&(*(Hero_004E7780 *)D_001A4BE0).rotation,0)) { (*(Hero_004E7780 *)D_001A4BE0).next_state=0;(*(Hero_004E7780 *)D_001A4BE0).timer=19;return; }
    if (!func_L01_004E63F0(0,0.3f,1.0f)) return;
    material=0;
    if (D_L01_001EAA00.moby) material=func_003C4D58(D_L01_001EAA00.moby);
    distance=1.7f;
    if (material && (*(s32 *)(material+0x3C)&0x20)) distance=0.5f;
    else if ((*(Hero_004E7780 *)D_001A4BE0).state!=17 && (!(*(Hero_004E7780 *)D_001A4BE0).contactB || (*(Hero_004E7780 *)D_001A4BE0).contactA)) distance=3.0f;
    func_L01_00511038(&pos,1,0.0f,0.0f,distance);
    func_L01_00511038(&delta,1,(*(Hero_004E7780 *)D_001A4BE0).radius+1.4f,0.0f,distance);
    if (!func_003D3CB0(&pos,&delta,2,0,0)) return;
    type=func_003D5630();
    if (type==10 || type==12) return;
    (*(Hero_004E7780 *)D_001A4BE0).hit_moby=D_L01_001EAA00.moby;
    if (func_L01_00511848(&D_L01_001EAA00.normal)<1.3089969158172607f) return;
    func_0038D028(&local_normal,&D_L01_001EAA00.normal,(*(Hero_004E7780 *)D_001A4BE0).matrix);
    if (func_0038DBA0(func_0038D160(local_normal.f[0],local_normal.f[1]),3.1415927410125732f)>0.8726646304130554f) return;
    limit=0.72f;
    if ((*(Hero_004E7780 *)D_001A4BE0).state==17) limit=0.95f;
    func_L01_00511038(&pos,1,0.0f,0.0f,0.2f);
    func_L01_00511038(&delta,1,(*(Hero_004E7780 *)D_001A4BE0).radius+1.4f,0.0f,0.2f);
    if (!func_003D3CB0(&pos,&delta,2,0,0)) return;
    if (func_0038CF38(&D_L01_001EAA00.position,(S_4E56A8vec *)&pos)>limit) return;
    *(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).normal=*(vu0_q *)&D_L01_001EAA00.normal;
    (*(Hero_004E7780 *)D_001A4BE0).normal.w=func_0038D160(D_L01_001EAA00.normal.x,D_L01_001EAA00.normal.y);
    (*(Hero_004E7780 *)D_001A4BE0).reach=5.0f;
    *(vu0_q *)&pos=*(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).capsule;
    func_0038CF68(&delta,(s32)&D_L01_001EAA00.normal,10.0f);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(delta) : "m"(delta),"m"(pos) : "vf1","vf2");
    if (func_003D3CB0(&pos,&delta,2,0,0)) (*(Hero_004E7780 *)D_001A4BE0).reach=func_0038CF38((S_4E56A8vec *)&pos,(S_4E56A8vec *)&delta);
    if ((*(Hero_004E7780 *)D_001A4BE0).mode==4 || (*(Hero_004E7780 *)D_001A4BE0).previous_mode==4 || (*(Hero_004E7780 *)D_001A4BE0).third_mode==4) {
        if ((*(Hero_004E7780 *)D_001A4BE0).attached && func_0038DBA0((*(Hero_004E7780 *)D_001A4BE0).old_heading,(*(Hero_004E7780 *)D_001A4BE0).normal.w)<2.96705961227417f) return;
        (*(Hero_004E7780 *)D_001A4BE0).kind=0;
        if(type==15) (*(Hero_004E7780 *)D_001A4BE0).kind=1;
        else if((*(Hero_004E7780 *)D_001A4BE0).blocked) return;
        if ((*(Hero_004E7780 *)D_001A4BE0).state==17) (*(Hero_004E7780 *)D_001A4BE0).next_state=6;
        else (*(Hero_004E7780 *)D_001A4BE0).next_state=5;
    }
}
/* localdecomp:end func_L01_004E7780 */
