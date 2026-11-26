/* PAL near miss (k6 a6, 2026-11-26): func_L01_003A8E50, 8 diff with its file's line
 * (-mvu0-use-vf0-vf2 ... @ps2as). From the Codex wave 8 draft (53): every one-block VU0 asm
 * as vu0.h helpers / j-form (16), the first block's add + copy of m+0x10 in retail's order as
 * j-form statements, the add's result in the first load's variable (12), and
 * func_L01_00446780 called with its real prototype (owner, radius, start, mode, distance, scale,
 * first, second, kind; src/levels/shared/L01_004463D0.c) (8).
 * What differs: in the did_hit branch retail computes &impulse (addiu $s0, $sp, 0x110) at the
 * start of each scale path (the beq to keep_moving has it in its delay slot) and stores
 * impulse.q before the jal with `move $a1, $s0` in the delay slot; this C puts the addiu in the
 * shared tail and the sq in the delay slot. Tried without a gain: impulse.q stored before the
 * if, in each branch, through a pointer local (140), as a by-value Vec4 copy, the scale as ?:,
 * the branches inverted / rewritten as else-if chains (8-21). */
#include "common.h"
/* localdecomp:start func_L01_003A8E50 */
#include "vu0.h"
typedef struct { u8 pad[0x18]; u8 b18,b19; u16 h1A; u8 tail[0x14]; } Hit_003A8E50;
extern u8 *D_L01_001EAA18[];
void func_L01_003A8E50(u8 *m) {
    extern s32 func_L01_00446780(void *,f32,void *,s32,f32,f32,s32,s32,s32);
    extern void func_L01_004450F0(S_3A9AC0m *,int,int);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_0046C470(void *,void *,s32,s32,s32,s32,s32,s32,f32);
    extern void func_L01_00446760(void *,void *,s32,void *,f32);
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *,void *,s32,void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_003D4D00(void *,s32,void *,void *,f32);
    extern void func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,
        s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
    extern void func_L01_003A94A8(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *),u8 *);
    Vec4 pos, direction, up, side, end;
    u8 *position;
    Vec4 *effect;
    Hit_003A8E50 hit;
    Vec4 impulse;
    Hit_003A8E50 hit2;
    Vec4 tmp1,tmp2;
    V_3A7C18 *p=*(V_3A7C18 **)(m+0x68);
    f32 sn,cs;
    s32 did_hit;
    u8 *other;
    if (++p->f18>240) {
        func_L01_00446780(m,0.6f,m+0x10,0x10001,p->f14,0.0f,0,1,0);
        func_L01_004450F0((S_3A9AC0m *)m,1,-1);
    }
    direction.q=p->q0;
    qzero(&up);
    up.f[2]=1.0f;
    func_0038CE90((u8 *)&side,(u8 *)&up,(u8 *)&direction);
    func_0038CF68((u8 *)&side,&side,1.0f);
    position=m+0x10;
    effect=&pos;
    qzero(&pos);
    sn=func_0038D098(p->f20)*0.25f;
    cs=func_0038D0B0(p->f20)*0.25f;
    func_0038CF68((u8 *)&side,&side,sn);
    func_0038CF68((u8 *)&up,&up,cs);
    {
        vu0_q qa, qb, qr, qc;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(up));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(m+0x10)));
        __asm__("sqc2 %1, %0" : "=m"(tmp1) : "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qa));
    }
    vec_add_ba(&pos,&pos,&side);
    vec_add_ba(&pos,&pos,&tmp1);
    func_L01_0046C470(effect,D_L01_001D66B0,0x60202080,16,0,0,64,0,0.75f);
    qzero(&up);qzero(&pos);
    up.f[2]=1.0f;
    func_0038CE90((u8 *)&side,(u8 *)&up,(u8 *)&direction);
    func_0038CF68((u8 *)&side,&side,1.0f);
    func_0038CF68((u8 *)&side,&side,-sn);
    func_0038CF68((u8 *)&up,&up,-cs);
    {
        vu0_q qa, qb, qr, qc;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(up));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(m+0x10)));
        __asm__("sqc2 %1, %0" : "=m"(tmp2) : "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qa));
    }
    vec_add_ba(&pos,&pos,&side);
    vec_add_ab(&pos,&pos,&tmp2);
    func_L01_0046C470(effect,D_L01_001D66B0,0x60202080,16,0,0,64,0,0.75f);
    p->f20-=0.25f;
    if(p->f20 < -3.1415927410125732f) p->f20=3.1415927410125732f;
    switch(m[0x20]) {
    case 0:
    vec_add_ba(&end,(Vec4 *)(m+0x10),(Vec4 *)p);
        func_L01_00446760(&hit,m,(s32)((Vec4 *)p)->f[3],p,p->f14);
        hit.h1A=*(u16 *)(m+0xAA);
        func_L01_004CB320();
        did_hit=func_003D3CB0(position,&end,0,m,&hit);
        if(did_hit) {
            other=D_L01_001EAA18[0];
            if(other && *(s16 *)(other+0xAA)==0x186D && other[0x20]!=2 && other[0x20]!=5) other[0x20]=4;
        }
        func_L01_004CB358();
        if(did_hit) {
            f32 scale;
            if(D_L01_001EAA18[0]) {
                if(D_L01_001EAA18[0]==p->parent) goto keep_moving;
                scale=1.5f;
            } else scale=3.0f;
            impulse.q=p->q0;
            func_0038CE20(&impulse,&impulse,scale);
            impulse.f[2]=1.0f;
            impulse.f[3]=5627.9248046875f;
            func_L01_00446760(&hit2,m,(s32)((Vec4 *)p)->f[3],&impulse,p->f14);
            hit2.b19=1;hit2.h1A=*(u16 *)(m+0xAA);hit2.b18=0;
            func_003D4D00(m+0x10,0,m,&hit2,0.6f);
            func_L01_004450F0((S_3A9AC0m *)m,1,-1);
            return;
        }
keep_moving:
        *(u128_t *)(m+0x10)=end.q;
        func_0038CE20(&impulse,p,-0.5f);
        break;
    case 1:
        func_L01_003303B8(position,0,10,10,10,10,10,0,0.25f,0.0f,0.0f,2.0f,
            0,1,0,0,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0);
        func_003C2880((Obj_003A5118 *)m);
        return;
    }
    func_L01_00404A10(func_L01_003A94A8,m);
}
/* localdecomp:end func_L01_003A8E50 */
