/* PAL near miss (Codex wave 6): near miss: 11 words differ with the file's flags.
 * Worker's note: 11 instruction differences, size unchanged: build/codex/w276/func_L01_00474078.baseline.log. Ten snippet compiles; header constant/store scheduling and scale-call argument order remain; typed fields and store permutations regress. Fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_L01_00474078 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_00474078;
typedef struct { f32 length,scale,rate; u16 life; } Trail_00474078;
extern u8 *D_L01_00221268;
Part_00470258 *func_L01_00474078(s128_00470258 *pos,void *velocity,s32 life,s32 rgba,s32 end_rgba,s32 spin,s32 texture,f32 width,f32 drag,f32 length,f32 rate) {
    extern Part_00470258 *func_L01_004618E0(s32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *,f32,void *);
    Vec_00474078 delta;
    u8 *p=(u8 *)func_L01_004618E0(116);
    Trail_00474078 *trail;
    if (p) {
        p[9]=34;
        *(s32 *)(p+4)=rgba;
        p[1]=3;
        p[3]=72;
        *(s32 *)(p+12)=end_rgba;
        trail=(Trail_00474078 *)((u8 *)p+0x30);
        p[2]=D_L01_00221268[texture];
        trail->length=func_0038CEA8(velocity);
        *(s128_00470258 *)(p+0x10)=*pos;
        func_0038CF68(&delta,length,velocity);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(Vec_00474078 *)&*(s128_00470258 *)(p+0x20)) : "m"(*(Vec_00474078 *)pos), "m"(delta) : "vf1","vf2");
        *(s16 *)(p+10)=life;
        ((f32 *)&*(s128_00470258 *)(p+0x20))[3]=drag;
        p[8]=spin;
        ((f32 *)&*(s128_00470258 *)(p+0x10))[3]=width;
        trail->scale=width;
        trail->rate=rate;
        trail->life=*(s16 *)(p+10);
    }
    return (Part_00470258 *)p;
}
/* localdecomp:end func_L01_00474078 */
