/* functional: high. Camera ray-march collision: marches the camera along its follow direction in steps (count from steer+0x40), at each step trying func_003E4168/func_003FB640/func_003E7F48/func_003E7B80 to resolve contacts, nudging steer+0x30/0x34 on hero-state hits and re-deriving the spring; sets/clears flag 0x20 in D_001DF818[player] in modes 48/28; returns whether a hit occurred. Branches, constants and callee args checked against retail */
#include "vu0.h"
extern s32 D_001D545C;
extern s32 D_L01_001DF818[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001EAA20;
s32 func_L01_003E7FA8(u8 *obj)
{
    extern s32 func_L01_003E4168(q128 *);
    extern s32 func_L01_003FB640(void *,s32,s32,f32);
    extern s32 func_L01_003E7F48(void *,s32,void *,f32);
    extern s32 func_L01_003E7B80(void *,void *,s32,f32,f32);
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern f32 func_0038CE68(f32 *,f32 *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    vu0_v4 initial,pos,dir,hit,old,delta;
    u8 *look;
    s32 collided=0,changed=0;
    u8 *follow=*(u8 **)(obj+0x70);
    u8 *springs=follow+0x180;
    u8 *steer=follow+0x210;
    u8 *entry=(u8 *)&D_L01_001E2A40[*(s32 *)(obj+0x94)];
    u8 *hero=entry+0x150;
    s32 i;
    f32 dist,total=0.0f;
    look=follow+0x60;
    initial=*(vu0_v4 *)springs;
    pos=*(vu0_v4 *)(follow+0xB0);
    func_0038CF68((f32 *)&dir,(f32 *)&initial,1.0f);
    dist=0.35f;
    if(D_001D545C==48 || D_001D545C==28) {
        s32 *flags=&D_L01_001DF818[*(s32 *)(obj+0x94)];
        if(!(*flags&0x20)) { changed=1; *flags|=0x20; }
    }
    for(i=0;i<(s32)(*(f32 *)(steer+0x40)-1.0f);i++) {
        if(i>0 && !func_L01_003E4168((q128 *)&pos) &&
           func_L01_003FB640(&pos,D_L01_001DF818[*(s32 *)(obj+0x94)],*(s32 *)(hero+0xF0),dist) &&
           !func_L01_003E7F48(obj,i,&pos,dist)) {
            hit=D_L01_001EAA20;
            old=pos;
            if(func_L01_003E7B80(obj,&pos,i,total,dist)) {
                collided=1;
                if(hero[0x12B]!=2 && fabs_asm(*(f32 *)(*(u8 **)(hero+0x134)+0x100))>0.05f) {
                    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(delta) : "m"(hit),"m"(old) : "vf1","vf2");
                    func_0038CF68((f32 *)&delta,(f32 *)&delta,1.0f);
                    if(fabs_asm(func_0038CE68((f32 *)(entry+0x90),(f32 *)&delta))<0.75f) {
                        *(s16 *)(steer+0x34)=0x719;
                        *(f32 *)(steer+0x30)+=0.09f;
                        if(*(f32 *)(springs+0x2C)-*(f32 *)(steer+0x30)<0.2f)
                            *(f32 *)(steer+0x30)=*(f32 *)(springs+0x2C)-0.2f;
                    }
                }
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(delta) : "m"(pos),"m"(*(vu0_v4 *)(look+0x50)) : "vf1","vf2");
                func_0038CF68((f32 *)springs,(f32 *)&delta,*(f32 *)(springs+0x2C)-*(f32 *)(steer+0x30));
                func_0038CF68((f32 *)&dir,(f32 *)springs,1.0f);
            }
        }
        dist+=*(f32 *)(steer+0x44)**(f32 *)(steer+0x3C);
        total+=dist;
        func_0038CE20((f32 *)&hit,(f32 *)&dir,dist*((*(f32 *)(springs+0x2C)-*(f32 *)(steer+0x30))/ *(f32 *)(springs+0x2C)));
        __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(pos) : "m"(hit) : "vf1","vf2");
    }
    if(D_001D545C==48 || D_001D545C==28) {
        if(changed) { s32 *flags=&D_L01_001DF818[*(s32 *)(obj+0x94)]; *flags&=~0x20; }
    }
    return collided;
}
