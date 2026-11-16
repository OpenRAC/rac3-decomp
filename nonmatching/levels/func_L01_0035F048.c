/* PAL near miss (Codex wave 8): near miss: 167 words differ with the file's flags.
 * Worker's note: 22 diff; w381/func_L01_0035F048.02.log and best.log; exploratory divs 2,2 (not validated metadata); three equivalent rewrites retain GPR allocation, table base plus byte offset and VU/callback move scheduling
 */
#include "common.h"
/* localdecomp:start func_L01_0035F048 */
typedef struct { u8 pad[0x57]; u8 player; } State_0035F048;
typedef struct { u8 pad[0x5C]; u8 *id; } Runtime_0035F048;
extern State_0035F048 D_001425C0;
extern Runtime_0035F048 D_L01_00221098;
typedef struct { u8 pad[240]; } Entry_0035F048;
extern Entry_0035F048 D_L01_002C5600[];
extern S_38C110v D_001A4EC0;
void func_L01_0035F048(u8 *moby,s128 *start,s128 *end) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *out,void *in,f32 length);
    extern f32 func_L01_00443A18(f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern s32 func_00382498(s32,s32);
    extern s32 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(S_38C110v *,S_38C110v *,s32,s32,u32,s32,f32,f32,f32,f32,f32);
    S_38C110v a,b,velocity,current,step;
    S_38C110v *v;
    s32 i;
    s32 count;
    s32 kind,life,alpha;
    u32 color;
    u8 type;
    u8 *particle;
    f32 length;
    *(s128 *)&a=*start;
    *(s128 *)&b=*end;
    length=func_0038CEA8(*(void **)(moby+0x68));
    current=b;
    count=(s32)(length/0.1f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(step) : "m"(a), "m"(b) : "vf1","vf2");
    func_0038CF68(&step,&step,length/(f32)count);
    i=0;
    while (i<count-2) {
        kind=(s32)func_L01_00443A18(1.0f,3.0f);
        v=&velocity;
        func_0038CE20((s128 *)v,(s128 *)&D_001A4EC0,-(func_003824E0(0.1f,0.2f)*0.0200000014f));
        life=func_00382498(3,6);
        if (func_0013D3E0()&2) {alpha=0x40;color=0x4080FF;} else {alpha=0x60;color=0x4080FF;}
        type=*((u8 *)&D_L01_002C5600[D_001425C0.player]+1);
        if (type>=3) {
            if (func_0013D3E0()&2) {alpha=0x40;color=0x407FFF;}
            else {alpha=0x60;color=0x4040FF;}
        } else if (type==2) {
            if (func_0013D3E0()&2) {alpha=0x40;color=0x4080FF;}
            else {alpha=0x60;color=0x4080FF;}
        } else if (type==1) {
            if (func_0013D3E0()&2) {alpha=0x40;color=0x407F7F;}
            else {alpha=0x60;color=0x40AFAF;}
        }
        particle=func_L01_0046A610(&current,v,(life*5+2)/6,alpha,color,kind,63000.00390625f,10000.0f,1.0f,0.0f,0.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(current) : "m"(current), "m"(step) : "vf1","vf2");
        if (particle) {
            particle[2]=D_L01_00221098.id[0];
            particle[3]=alpha==0x40?0x48:0x44;
        }
        i++;
    }
}
/* localdecomp:end func_L01_0035F048 */
