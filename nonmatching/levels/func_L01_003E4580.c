/* PAL near miss (sol-round3-c): 29 words differ with the file's flags; the hero and camera pointers use different saved registers and scalar arguments interleave differently with VU0 operations. */
/* localdecomp:start func_L01_003E4580 */
#include "vu0.h"
typedef union { u128_t q; f32 f[4]; } V_003E4580;
typedef struct { u8 bytes[0xC0]; } Memory_003E4580;
typedef struct { u8 p0[0x30]; V_003E4580 pos; u8 p40[0x30]; u8 *follow; u8 p74[0x20]; s32 player; } O_003E4580;
extern Entry_3E6C58 D_L01_001E2A40[];
extern s32 D_L01_001D673C;
void func_L01_003E4580(O_003E4580 *o,V_003E4580 *movement) {
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *,void *,f32);
    V_003E4580 delta,projection,adjusted,residual,old,duplicate;
    u8 *d,*hero,*entry,*motion,*follow,*ground;
    f32 dz, dot;
    V_003E4580 *dv=&delta;
    *dv=*movement;
    entry=(u8 *)&D_L01_001E2A40[o->player];
    follow=o->follow;
    d=follow+0x60;
    hero=entry+0x150;
    motion=entry+0x60;
    ground=*(u8 **)(hero+0xF8);
    if(ground && !D_L01_001D673C && !*(s16 *)(hero+0x124)) {
        if(ground==*(u8 **)(d+0x118)) {
            dz=*(f32 *)(ground+0x18)-*(f32 *)(d+0x11C);
            if(0.0f<dz) {
                if(dv->f[2]<dz) dv->f[2]=dz;
            }
        } else *(u8 **)(d+0x118)=ground;
        *(f32 *)(d+0x11C)=*(f32 *)(*(u8 **)(hero+0xF8)+0x18);
    } else *(s32 *)(d+0x118)=0;
    {
        vu0_q moved, next;
        __asm__("lqc2 $vf2, %1\n\tlqc2 %0, %2\n\tvadd.xyz %0, %0, $vf2"
            : "=j"(moved) : "m"(o->pos), "m"(*dv) : "vf2");
        __asm__("lqc2 %0, %1" : "=j"(next) : "m"(*dv));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(moved));
        __asm__("lqc2 $vf1, %0\n\tvadd.xyz %1, %1, $vf1\n\tsqc2 %1, %0"
            : "+m"(*(V_003E4580 *)(d + 0x60)), "+j"(next) : : "vf1");
    }
    __asm__("lqc2 $vf2,%0\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*(V_003E4580 *)(d)) : "m"(*dv) : "vf1","vf2");
    __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "+m"(*(V_003E4580 *)(d+0xB0)) : "m"(*dv) : "vf1","vf2");
    __asm__("lqc2 $vf2,%0\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*(V_003E4580 *)(d+0x30)) : "m"(*dv) : "vf1","vf2");
    __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "+m"(*(V_003E4580 *)(follow)) : "m"(*dv) : "vf1","vf2");
    dot=func_0038CE68(dv->f,(f32 *)(motion+0x30));
    func_0038CE20(&projection,motion+0x30,dot);
    __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*(V_003E4580 *)(d+0x10)) : "m"(projection) : "vf1","vf2");
    if(!*(s16 *)(hero+0x124) && (!*(u8 **)(hero+0xF8) || *(s16 *)(*(u8 **)(hero+0xF8)+0xAA)!=0x22D || *(s32 *)(entry+0x454)>=26))
        *(f32 *)(o->follow+0x200)=dv->f[3];
    if((u32)(*(s32 *)(hero+0x100)-11)<2) {
        u8 *later=o->follow;
        *(s16 *)(later+0x10)=0;
        func_0038CE20(&adjusted,motion+0x80,*(f32 *)(motion+0xA4));
        dot=func_0038CE68((f32 *)(motion+0x30),dv->f);
        func_0038CE20(&residual,motion+0x30,dot);
        __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tlqc2 $vf1,%3\n\tsqc2 $vf1,%1\n\tsqc2 $vf2,%0" : "+m"(residual),"=m"(old) : "m"(*dv),"m"(o->pos) : "vf1","vf2");
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%0\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(adjusted) : "m"(residual) : "vf1","vf2");
        __asm__("lqc2 $vf1,%2\n\tlqc2 $vf2,%2\n\tsqc2 $vf1,%0\n\tlqc2 $vf1,%3\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%1" : "=m"(duplicate),"=m"(o->pos) : "m"(adjusted),"m"(old) : "vf1","vf2");
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%0\n\tvadd.xyz $vf1,$vf2,$vf1\n\tsqc2 $vf1,%0" : "+m"(*(V_003E4580 *)(d+0x60)) : "m"(duplicate) : "vf1","vf2");
        __asm__("lqc2 $vf2,%0\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*(V_003E4580 *)(d)) : "m"(adjusted) : "vf1","vf2");
        __asm__("lqc2 $vf1,%0\n\tlqc2 $vf2,%1\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "+m"(*(V_003E4580 *)(d+0xB0)) : "m"(adjusted) : "vf1","vf2");
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%0\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "+m"(*(V_003E4580 *)(later)) : "m"(adjusted) : "vf1","vf2");
    }
}
/* localdecomp:end func_L01_003E4580 */
