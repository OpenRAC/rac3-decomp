/* PAL near miss (Codex wave 6): near miss: 113 words differ with the file's flags.
 * Worker's note: 113 instruction differences in func_L07_00332CF0.wrap1.log: fixed-flags VU0 block scheduling, prologue and one extra instruction; j-class helpers do not compile with this file line (check3.log). Retained complete fresh PAL draft.
 */
#include "common.h"
/* localdecomp:start func_L07_00332CF0 */
typedef int Q_00332CF0 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00332CF0;
extern V_00332CF0 D_L07_001D9AE0;
typedef struct { u8 pad[0x18]; u8 *moby; } Hit_00332CF0;
extern Hit_00332CF0 D_L07_001E8C00;
static __inline__ void sub_00332CF0(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_00332CF0*)d) : "m"(*(V_00332CF0*)a),"m"(*(V_00332CF0*)b) : "vf1","vf2");
}
static __inline__ void add_00332CF0(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_00332CF0*)d) : "m"(*(V_00332CF0*)a),"m"(*(V_00332CF0*)b) : "vf1","vf2");
}
static __inline__ void add2_00332CF0(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(*(V_00332CF0*)d) : "m"(*(V_00332CF0*)a),"m"(*(V_00332CF0*)b) : "vf1","vf2");
}
static __inline__ void sub2_00332CF0(void *d,void *a,void *b) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(V_00332CF0*)d) : "m"(*(V_00332CF0*)a),"m"(*(V_00332CF0*)b) : "vf1","vf2");
}
f32 func_L07_00332CF0(u8 *a,u8 *b,V_00332CF0 *c,f32 angle) {
    extern s32 func_L07_00332A90(u8*);
    extern void func_0038CF68(void*,void*,f32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_L07_00332F90(u8*,u8*,void*,f32);
    extern void func_0038CE90(void*,void*,void*);
    extern f32 func_L07_00333858(void*);
    extern s32 func_003D3CB0(void*,void*,s32,void*,s32);
    extern s32 func_L07_00333878(u8*);
    extern f32 func_L07_003330E8(u8*,u8*,void*,f32,f32);
    extern void func_L07_00332BE0(u8*);
    V_00332CF0 diff,offset,end,side,start,finish;
    s32 hit;
    f32 original,adjusted,radius,result;
    hit=func_L07_00332A90(a);
    sub_00332CF0(&diff,c,b+0x10);
    func_0038CF68(&diff,&diff,10.0f);
    original=func_0038D160(diff.x,diff.y);
    adjusted=func_0038DAB8(original,angle);
    *(Q_00332CF0*)&end=0;
    end.x=func_0038D098(adjusted)*10.0f;
    end.y=func_0038D0B0(adjusted)*10.0f;
    *(Q_00332CF0*)&offset=*(Q_00332CF0*)&end;
    add2_00332CF0(&end,&offset,b+0x10);
    if(!hit)return func_L07_00332F90(a,b,&end,angle);
    func_0038CE90(&side,&offset,&D_L07_001D9AE0);
    radius=func_L07_00333858(b);
    func_0038CF68(&side,&side,radius);
    add_00332CF0(&start,b+0x10,&side);
    func_0038CF68(&side,b+0xC0,radius);
    add_00332CF0(&start,&start,&side);
    add2_00332CF0(&finish,&side,&end);
    if(func_003D3CB0(&start,&finish,9,b,0) && D_L07_001E8C00.moby && func_L07_00333878(D_L07_001E8C00.moby)) {
        result=func_L07_003330E8(b,D_L07_001E8C00.moby,c,original,adjusted);
    } else {
        sub_00332CF0(&start,b+0x10,&side);
        sub2_00332CF0(&finish,&end,&side);
        if(func_003D3CB0(&start,&finish,9,b,0) && D_L07_001E8C00.moby && func_L07_00333878(D_L07_001E8C00.moby))
            result=func_L07_003330E8(b,D_L07_001E8C00.moby,c,original,adjusted);
        else result=func_L07_00332F90(a,b,&end,angle);
    }
    func_L07_00332BE0(a);
    return result;
}
/* localdecomp:end func_L07_00332CF0 */
